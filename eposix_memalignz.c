/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void libsimple_eposix_memalignz(void **, int, size_t, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr = NULL;

	libsimple_eposix_memalignz(&ptr, 1, 2 * sizeof(void *), 8);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		assert(info->alignment == 2 * sizeof(void *));
		assert(info->zeroed == 8);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	libsimple_eposix_memalignz(&ptr, 0, 4 * sizeof(void *), 4);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4);
		assert(info->alignment == 4 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		libsimple_default_failure_exit = 102;
		alloc_fail_in = 1;
		assert_exit(libsimple_eposix_memalignz(&ptr, 1, sizeof(void *), 4));
		assert(exit_status == 102);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		libsimple_default_failure_exit = 103;
		alloc_fail_in = 1;
		assert_exit(libsimple_eposix_memalignz(&ptr, 0, sizeof(void *), 4));
		assert(exit_status == 103);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
