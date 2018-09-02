/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


struct memalloc_state {
	int zero_init;
	int if_zero;
	int round_up_size;
	int have_size;
	size_t alignment;
	size_t elem_size;
	size_t size_prod;
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

void *
libsimple_vmemalloc(size_t n, va_list ap) /* TODO test ([v]{mem,array}alloc) */
{
	struct memalloc_state state;
	size_t misalignment, size;
	void *ptr = NULL;
	int saved_errno;

	state.zero_init     = -1;
	state.if_zero       = -1;
	state.round_up_size = 0;
	state.have_size     = 0;
	state.alignment     = 0;
	state.elem_size     = 0;
	state.size_prod     = 1;

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
