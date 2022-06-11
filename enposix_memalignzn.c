/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void libsimple_enposix_memalignzn(int, void **, int, size_t, size_t, ...);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr = NULL;

	libsimple_enposix_memalignzn(1, &ptr, 0, sizeof(void *), 5, 3, 0);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 15);
		assert(info->alignment == sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	libsimple_enposix_memalignzn(1, &ptr, 1, 2 * sizeof(void *), 5, 4, 0);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 20);
		assert(info->alignment == 2 * sizeof(void *));
		assert(info->zeroed == 20);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit(libsimple_enposix_memalignzn(3, &ptr, 0, 4 * sizeof(void *), 4, 0));
		assert(exit_status == 3);
		stderr_buf[stderr_n] = 0;
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit(libsimple_enposix_memalignzn(5, &ptr, 1, 4 * sizeof(void *), 2, 0));
		assert(exit_status == 5);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	assert_exit(libsimple_enposix_memalignzn(13, &ptr, 0, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 13);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	assert_exit(libsimple_enposix_memalignzn(15, &ptr, 1, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 15);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	return 0;
}

#endif
