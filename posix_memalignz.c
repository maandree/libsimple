/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_posix_memalignz(void **, int, size_t, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *volatile info;
	void *ptr;
	DEFINE_CACHELINE;

	assert(!libsimple_posix_memalignz(&ptr, 0, 8 * sizeof(void *), 8));
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		ASSERT_ALIGNMENT(info, 8 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert(!libsimple_posix_memalignz(&ptr, 1, 4 * sizeof(void *), 16));
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 16);
		ASSERT_ALIGNMENT(info, 4 * sizeof(void *));
		assert(info->zeroed == 16);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert(libsimple_posix_memalignz(&ptr, 0, 4 * sizeof(void *), 8) == ENOMEM && !errno);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(libsimple_posix_memalignz(&ptr, 1, 16 * sizeof(void *), 16) == ENOMEM && !errno);
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
