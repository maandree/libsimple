/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


static inline size_t
alloc_size_product(int *errp, size_t n, va_list ap)
{
	size_t prod = n;
	if (!n) {
		*errp = EINVAL;
		return 0;
	}
	for (;;) {
		n = va_arg(ap, size_t);
		if (!n)
			break;
		if (n >= SIZE_MAX / prod) {
			*errp = ENOMEM;
			return 0;
		}
		prod *= n;
	}
	return prod;
}

void *
libsimple_vmalloczn(int clear, size_t n, va_list ap)
{
	n = alloc_size_product(&errno, n, ap);
	return !n ? NULL : clear ? calloc(1, n) : malloc(n);
}

void *
libsimple_vreallocn(void *ptr, size_t n, va_list ap)
{
	n = alloc_size_product(&errno, n, ap);
	return !n ? NULL : realloc(ptr, n);
}

void *
libsimple_valigned_alloczn(int clear, size_t alignment, size_t n, va_list ap)
{
	void *ret;
	n = alloc_size_product(&errno, n, ap);
	ret = !n ? NULL : aligned_alloc(alignment, n);
	if (ret && clear)
		memset(ret, 0, n);
	return ret;
}

int
libsimple_vposix_memalignzn(void **memptr, int clear, size_t alignment, size_t n, va_list ap)
{
	int ret = 0;
	n = alloc_size_product(&ret, n, ap);
	if (ret)
		return ret;
	ret = posix_memalign(memptr, alignment, n);
	if (!ret && clear)
		memset(*memptr, 0, n);
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr, *old;

	assert(!libsimple_malloczn(0, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_malloczn(1, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_mallocn(0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_callocn(0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_reallocn(NULL, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_aligned_alloczn(0, 128, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_aligned_alloczn(1, 128, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_aligned_allocn(128, 0) && errno == EINVAL);
	errno = 0;
	assert(libsimple_posix_memalignzn(&ptr, 0, 128, 0) == EINVAL && !errno);
	assert(libsimple_posix_memalignzn(&ptr, 1, 128, 0) == EINVAL && !errno);
	assert(libsimple_posix_memalignn(&ptr, 128, 0) == EINVAL && !errno);

	assert(!libsimple_malloczn(0, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_malloczn(1, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_mallocn(SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_callocn(SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_reallocn(NULL, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_aligned_alloczn(0, 1024, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_aligned_alloczn(1, 1024, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_aligned_allocn(1024, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(libsimple_posix_memalignzn(&ptr, 0, 1024, SIZE_MAX, 2, 0) == ENOMEM && !errno);
	assert(libsimple_posix_memalignzn(&ptr, 1, 1024, SIZE_MAX, 2, 0) == ENOMEM && !errno);
	assert(libsimple_posix_memalignn(&ptr, 1024, SIZE_MAX, 2, 0) == ENOMEM && !errno);

	assert((ptr = libsimple_malloczn(0, 10, 10, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 100);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_malloczn(1, 20, 20, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 400);
		assert(info->zeroed == 400);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_mallocn(11, 11, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 121);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_callocn(22, 22, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 484);
		assert(info->zeroed == 484);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_reallocn(NULL, 5, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5);
		assert(!info->zeroed);
		info->refcount += 1;
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_reallocn(old = ptr, 10, 0)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 10);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		assert(ptr != old);
		free(old);
	}
	free(ptr);

	assert((ptr = libsimple_aligned_alloczn(0, 8, 12, 12, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 144);
		assert(info->alignment == 8);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_aligned_alloczn(1, 16, 12, 12, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 288);
		assert(info->alignment == 16);
		assert(info->zeroed == 288);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_aligned_allocn(32, 12, 12, 4, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 576);
		assert(info->alignment == 32);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert(!libsimple_posix_memalignzn(&ptr, 0, sizeof(void *), 12, 12, 0));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 144);
		assert(info->alignment == sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert(!libsimple_posix_memalignzn(&ptr, 1, 2 * sizeof(void *), 12, 12, 2, 0));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 288);
		assert(info->alignment == 2 * sizeof(void *));
		assert(info->zeroed == 288);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert(!libsimple_posix_memalignn(&ptr, 2 * sizeof(void *), 12, 12, 3, 0));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 432);
		assert(info->alignment == 2 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert(!errno);

	return 0;
}

#endif
