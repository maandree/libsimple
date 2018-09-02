/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void
libsimple_enposix_memalignz(int status, void **memptr, int clear, size_t alignment, size_t n)
{
	int err = libsimple_posix_memalignz(memptr, clear, alignment, n);
	if (err) {
		errno = err;
		enprintf(status, "posix_memalign:");
	}
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr = NULL;

	libsimple_enposix_memalignz(1, &ptr, 1, sizeof(void *), 8);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		assert(info->alignment == sizeof(void *));
		assert(info->zeroed == 8);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

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

	libsimple_enposix_memalignz(1, &ptr, 0, 2 * sizeof(void *), 8);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		assert(info->alignment == 2 * sizeof(void *));
		assert(!info->zeroed);
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

	libsimple_enposix_memalign(1, &ptr, sizeof(void *), 8);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		assert(info->alignment == sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	libsimple_eposix_memalign(&ptr, 8 * sizeof(void *), 4);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4);
		assert(info->alignment == 8 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit(libsimple_enposix_memalignz(3, &ptr, 1, sizeof(void *), 4));
		assert(exit_status == 3);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 102;
		alloc_fail_in = 1;
		assert_exit(libsimple_eposix_memalignz(&ptr, 1, sizeof(void *), 4));
		assert(exit_status == 102);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit(libsimple_enposix_memalignz(5, &ptr, 0, sizeof(void *), 4));
		assert(exit_status == 5);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 103;
		alloc_fail_in = 1;
		assert_exit(libsimple_eposix_memalignz(&ptr, 0, sizeof(void *), 4));
		assert(exit_status == 103);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit(libsimple_enposix_memalign(7, &ptr, sizeof(void *), 4));
		assert(exit_status == 7);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 104;
		alloc_fail_in = 1;
		assert_exit(libsimple_eposix_memalign(&ptr, sizeof(void *), 4));
		assert(exit_status == 104);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
