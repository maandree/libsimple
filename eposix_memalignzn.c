/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void libsimple_eposix_memalignzn(void **, int, size_t, size_t, ...);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr = NULL;

	libsimple_eposix_memalignzn(&ptr, 0, 4 * sizeof(void *), 2, 5, 3, 0);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 30);
		assert(info->alignment == 4 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	libsimple_eposix_memalignzn(&ptr, 1, sizeof(void *), 2, 5, 4, 0);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 40);
		assert(info->alignment == sizeof(void *));
		assert(info->zeroed == 40);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		libsimple_default_failure_exit = 23;
		assert_exit(libsimple_eposix_memalignzn(&ptr, 0, sizeof(void *), 4, 0));
		assert(exit_status == 23);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		libsimple_default_failure_exit = 25;
		assert_exit(libsimple_eposix_memalignzn(&ptr, 1, sizeof(void *), 2, 0));
		assert(exit_status == 25);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	libsimple_default_failure_exit = 33;
	assert_exit(libsimple_eposix_memalignzn(&ptr, 0, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 33);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	libsimple_default_failure_exit = 35;
	assert_exit(libsimple_eposix_memalignzn(&ptr, 1, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 35);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	return 0;
}

#endif
