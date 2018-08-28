/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


static inline size_t
alloc_size_product(size_t n, va_list ap)
{
	size_t prod = n;
	if (!n) {
		errno = EINVAL;
		return 0;
	}
	for (;;) {
		n = va_arg(ap, size_t);
		if (!n)
			break;
		if (n >= SIZE_MAX / prod) {
			errno = ENOMEM;
			return 0;
		}
		prod *= n;
	}
	return prod;
}

void *
libsimple_vmalloczn(int clear, size_t n, va_list ap)
{
	n = alloc_size_product(n, ap);
	return !n ? NULL : clear ? calloc(1, n) : malloc(n);
}

void *
libsimple_vreallocn(void *ptr, size_t n, va_list ap)
{
	n = alloc_size_product(n, ap);
	return !n ? NULL : realloc(ptr, n);
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

	assert((ptr = libsimple_malloczn(0, 10, 10, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 100);
		assert(!info->zeroed);
	}
	free(ptr);

	assert((ptr = libsimple_malloczn(1, 20, 20, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 400);
		assert(info->zeroed == 400);
	}
	free(ptr);

	assert((ptr = libsimple_mallocn(11, 11, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 121);
		assert(!info->zeroed);
	}
	free(ptr);

	assert((ptr = libsimple_callocn(22, 22, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 484);
		assert(info->zeroed == 484);
	}
	free(ptr);

	assert((ptr = libsimple_reallocn(NULL, 5, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5);
		assert(!info->zeroed);
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_reallocn(old = ptr, 10, 0)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 10);
		assert(!info->zeroed);
		assert(ptr != old);
		free(old);
	}
	free(ptr);

	assert(!errno);

	return 0;
}

#endif
