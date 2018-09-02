/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void
libsimple_envposix_memalignzn(int status, void **memptr, int clear, size_t alignment, size_t n, va_list ap)
{
	int err = libsimple_vposix_memalignzn(memptr, clear, alignment, n, ap);
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

		alloc_fail_in = 1;
		assert_exit(libsimple_enposix_memalignn(9, &ptr, 4 * sizeof(void *), 1, 0));
		assert(exit_status == 9);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	assert_exit(libsimple_enposix_memalignzn(13, &ptr, 0, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 13);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	assert_exit(libsimple_enposix_memalignzn(15, &ptr, 1, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 15);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	assert_exit(libsimple_enposix_memalignn(19, &ptr, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 19);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	ptr = NULL;

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

	libsimple_eposix_memalignn(&ptr, 2 * sizeof(void *), 2, 4, 3, 0);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 24);
		assert(info->alignment == 2 * sizeof(void *));
		assert(!info->zeroed);
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

		alloc_fail_in = 1;
		libsimple_default_failure_exit = 29;
		assert_exit(libsimple_eposix_memalignn(&ptr, sizeof(void *), 1, 0));
		assert(exit_status == 29);
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

	libsimple_default_failure_exit = 39;
	assert_exit(libsimple_eposix_memalignn(&ptr, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 39);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	return 0;
}

#endif
