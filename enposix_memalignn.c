/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void libsimple_enposix_memalignn(int, void **, size_t, size_t, ...);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr = NULL;

	libsimple_enposix_memalignn(1, &ptr, 4 * sizeof(void *), 4, 3, 0);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 12);
		assert(info->alignment == 4 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit(libsimple_enposix_memalignn(9, &ptr, 4 * sizeof(void *), 1, 0));
		assert(exit_status == 9);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	assert_exit(libsimple_enposix_memalignn(19, &ptr, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 19);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	return 0;
}

#endif
