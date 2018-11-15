/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#include <stdalign.h>
#ifndef TEST


struct memalloc_state {
	size_t alignment;
	size_t elem_size;
	size_t size_prod;
	char zero_init;
	char if_zero;
	char round_up_size;
	char have_size;
	char cache_align;
	char cache_split;
	char pad__[(4 * sizeof(size_t) - 6) % sizeof(size_t)];
};

static int
vmemalloc_parse_size_prod(struct memalloc_state *state, size_t n, size_t arg, va_list ap)
{
	if (state->have_size++)
		goto inval;
	state->elem_size = arg;
	if (n) {
		for (n--; n--;) {
			arg = va_arg(ap, size_t);
			if (!state->elem_size)
				continue;
			if (arg > SIZE_MAX / state->elem_size) {
				errno = ENOMEM;
				return -1;
			}
			state->elem_size *= arg;
		}
	} else {
		if (!arg)
			goto inval;
		for (;;) {
			arg = va_arg(ap, size_t);
			if (!arg)
				break;
			if (arg > SIZE_MAX / state->elem_size) {
				errno = ENOMEM;
				return -1;
			}
			state->elem_size *= arg;
		}
	}

	return 0;
inval:
	errno = EINVAL;
	return -1;
}

static int
vmemalloc_parse_args(struct memalloc_state *state, size_t n, va_list ap)
{
	enum libsimple_memalloc_option opt;
	long int page_size;
	va_list *subapp;
	size_t arg;

	for (;;) {
		opt = va_arg(ap, enum libsimple_memalloc_option);
		switch (opt) {
		case LIBSIMPLE_MEMALLOC_END:
			return 0;

		case LIBSIMPLE_MEMALLOC_ZERO_INIT:
			if (state->zero_init >= 0)
				goto inval;
			state->zero_init = 1;
			break;

		case LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT:
			if (state->zero_init >= 0)
				goto inval;
			state->zero_init = va_arg(ap, int);
			state->zero_init = !!state->zero_init;
			break;

		case LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO:
		case LIBSIMPLE_MEMALLOC_NULL_IF_ZERO:
			if (state->if_zero >= 0)
				goto inval;
			state->if_zero = (opt == LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO);
			break;

		case LIBSIMPLE_MEMALLOC_ALIGNMENT:
			if (state->alignment)
				goto inval;
			state->alignment = va_arg(ap, size_t);
			if (!state->alignment)
				goto inval;
			break;

		case LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT:
			if (state->alignment)
				goto inval;
			page_size = sysconf(_SC_PAGESIZE);
			if (page_size <= 0)
				return -1;
			state->alignment = (size_t)page_size;
			break;

		case LIBSIMPLE_MEMALLOC_ALIGNMENT_TO_CACHE_LINE:
			if (state->cache_align++)
				goto inval;
			break;

		case LIBSIMPLE_MEMALLOC_ALLOW_CACHE_LINE_SPLITTING:
			if (state->cache_split++)
				goto inval;
			break;

		case LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT:
			if (state->round_up_size++)
				goto inval;
			break;

		case LIBSIMPLE_MEMALLOC_ELEMENT_SIZE:
			if (state->elem_size)
				goto inval;
			state->elem_size = va_arg(ap, size_t);
			if (!state->elem_size)
				goto inval;
			break;

		case LIBSIMPLE_MEMALLOC_PRODUCT_SIZE:
			arg = va_arg(ap, size_t);
			if (vmemalloc_parse_size_prod(state, n, arg, ap))
				return -1;
			break;

		case LIBSIMPLE_MEMALLOC_VA_PRODUCT_SIZE:
			subapp = va_arg(ap, va_list *);
			arg = va_arg(*subapp, size_t);
			if (vmemalloc_parse_size_prod(state, n, arg, *subapp))
				return -1;
			break;

		case LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE:
			arg = va_arg(ap, size_t);
			subapp = va_arg(ap, va_list *);
			if (vmemalloc_parse_size_prod(state, n, arg, *subapp))
				return -1;
			break;

		case LIBSIMPLE_MEMALLOC_VA_LIST:
			subapp = va_arg(ap, va_list *);
			if (vmemalloc_parse_args(state, n, *subapp))
				return -1;
			break;

		default:
			goto inval;
		}
	}

	return 0;
inval:
	errno = EINVAL;
	return -1;
}

static size_t
gcd(size_t u, size_t v)
{
	size_t t;
	int shift = 0;
	/* Not needed because u>0, v>0: if (!(u | v)) return u + v; */
	while (!((u | v) & 1)) u >>= 1, v >>= 1, shift++;
	while (!(u & 1))       u >>= 1;
	do {
		while (!(v & 1)) v >>= 1;
		if (u > v)       t = u, u = v, v = t;
	} while (v -= u);
	return u << shift;
}

void *
libsimple_vmemalloc(size_t n, va_list ap) /* TODO test ([v]{mem,array}alloc) */
{
	struct memalloc_state state;
	size_t misalignment, size, cacheline, min, max;
	void *ptr = NULL;
	int saved_errno;
	long int tmp;

	state.alignment     = 0;
	state.elem_size     = 0;
	state.size_prod     = 1;
	state.zero_init     = -1;
	state.if_zero       = -1;
	state.round_up_size = 0;
	state.have_size     = 0;
	state.cache_align   = 0;
	state.cache_split   = 0;

	if (vmemalloc_parse_args(&state, n, ap))
		return NULL;

	state.elem_size = state.elem_size ? state.elem_size : 1;
	state.zero_init = state.zero_init >= 0 ? state.zero_init : 0;
	n = state.have_size ? state.size_prod : n;
	if (state.elem_size > 1) {
		if (n > SIZE_MAX / state.elem_size) {
			errno = ENOMEM;
			return NULL;
		}
		n *= state.elem_size;
	}
	if (state.round_up_size) {
		if (!state.alignment) {
			errno = EINVAL;
			return NULL;
		}
		if ((misalignment = n % state.alignment))
			n += state.alignment - misalignment;
	}
	if (!n && state.if_zero == 0)
		return NULL;
	n = n ? n : (state.if_zero > 0);

	if (state.cache_align || !state.cache_split) {
		tmp = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
		cacheline = (size_t)(tmp < 1 ? 64L : tmp);
	}

	if (state.cache_align) {
		if (!state.alignment)
			state.alignment = alignof(max_align_t);
	align_to_cacheline:
		if (!(cacheline % state.alignment)) {
			state.alignment = cacheline;
		} else if (state.alignment % cacheline) {
			min = MIN(state.alignment, cacheline);
			max = MAX(state.alignment, cacheline);
			size = max / gcd(state.alignment, cacheline);
			if (size > SIZE_MAX / min) {
				errno = ENOMEM;
				return NULL;
			}
			state.alignment = size = min;
		}
	} else if (!state.cache_split) {
		if (!state.alignment)
			state.alignment = alignof(max_align_t);
		misalignment = cacheline - state.alignment % cacheline;
		if (n % cacheline + misalignment % cacheline > cacheline)
			goto align_to_cacheline;
	}

	saved_errno = errno;
	errno = 0;
	if (state.alignment) {
		if (state.alignment % sizeof(void *)) {
			size = n;
			if ((misalignment = size % state.alignment))
				size += state.alignment - misalignment;
			ptr = aligned_alloc(state.alignment, size);
		} else {
			errno = posix_memalign(&ptr, state.alignment, n);
		}
		if (ptr && state.zero_init)
			memset(ptr, 0, n);
	} else {
		ptr = state.zero_init ? calloc(n, 1) : malloc(n);
	}
	if (!ptr && n) {
		if (!errno)
			errno = ENOMEM;
		return NULL;
	}
	errno = errno ? errno : saved_errno;

	return ptr;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
