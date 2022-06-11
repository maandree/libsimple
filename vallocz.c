/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_vallocz(int, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *volatile info;
	void *ptr;
	DEFINE_PAGESIZE;
	DEFINE_CACHELINE;

	assert((ptr = libsimple_vallocz(0, 9)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 9 || info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_vallocz(1, 7)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 7 || info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == 7 || info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_vallocz(1, 3 * pagesize)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 3 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == 3 * pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_vallocz(0, 4 * pagesize)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert(!libsimple_vallocz(0, 8) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(!libsimple_vallocz(1, 16) && errno == ENOMEM);
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
