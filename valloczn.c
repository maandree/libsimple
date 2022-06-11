/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_valloczn(int, size_t, ...);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *volatile info;
	void *ptr;
	DEFINE_PAGESIZE;
	DEFINE_CACHELINE;

	assert((ptr = libsimple_valloczn(1, 3 * pagesize, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 6 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == 6 * pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_valloczn(0, 4 * pagesize, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert(!libsimple_valloczn(0, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_valloczn(1, 0) && errno == EINVAL);
	errno = 0;

	assert(!libsimple_valloczn(0, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_valloczn(1, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;

	assert((ptr = libsimple_valloczn(0, 9, 9, pagesize - 1, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 81 * (pagesize - 1));
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_valloczn(1, 9, 8, pagesize - 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 72 * (pagesize - 2));
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	return 0;
}

#endif
