/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_envaligned_alloczn(int status, int clear, size_t alignment, size_t n, va_list ap)
{
	void *ret = libsimple_valigned_alloczn(clear, alignment, n, ap);
	if (!ret)
		enprintf(status, "aligned_alloc:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr;

	assert((ptr = libsimple_enaligned_alloczn(1, 0, 8, 4, 4, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 16);
		assert(info->alignment == 8);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_enaligned_alloczn(1, 1, 16, 32, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 64);
		assert(info->alignment == 16);
		assert(info->zeroed == 64);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_enaligned_allocn(1, 32, 8, 16, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 128);
		assert(info->alignment == 32);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_alloczn(3, 0, 32, 256, 0));
		assert(exit_status == 3);
		stderr_buf[stderr_n] = 0;
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_alloczn(5, 1, 32, 128, 0));
		assert(exit_status == 5);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_allocn(9, 32, 64, 0));
		assert(exit_status == 9);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	assert_exit_ptr(libsimple_enaligned_alloczn(13, 0, 8, SIZE_MAX, 2, 0));
	assert(exit_status == 13);
	assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));

	assert_exit_ptr(libsimple_enaligned_alloczn(15, 1, 8, SIZE_MAX, 2, 0));
	assert(exit_status == 15);
	assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));

	assert_exit_ptr(libsimple_enaligned_allocn(19, 8, SIZE_MAX, 2, 0));
	assert(exit_status == 19);
	assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));

	assert((ptr = libsimple_ealigned_alloczn(0, 32, 2, 8, 8, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 128);
		assert(info->alignment == 32);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_ealigned_alloczn(1, 8, 2, 4, 4, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 32);
		assert(info->alignment == 8);
		assert(info->zeroed == 32);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_ealigned_allocn(16, 2, 4, 8, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 64);
		assert(info->alignment == 16);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		libsimple_default_failure_exit = 23;
		assert_exit_ptr(libsimple_ealigned_alloczn(0, 8, 16, 0));
		assert(exit_status == 23);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		libsimple_default_failure_exit = 25;
		assert_exit_ptr(libsimple_ealigned_alloczn(1, 8, 32, 0));
		assert(exit_status == 25);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		libsimple_default_failure_exit = 29;
		assert_exit_ptr(libsimple_ealigned_allocn(8, 64, 0));
		assert(exit_status == 29);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	libsimple_default_failure_exit = 33;
	assert_exit_ptr(libsimple_ealigned_alloczn(0, 8, SIZE_MAX, 2, 0));
	assert(exit_status == 33);
	assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));

	libsimple_default_failure_exit = 35;
	assert_exit_ptr(libsimple_ealigned_alloczn(1, 8, SIZE_MAX, 2, 0));
	assert(exit_status == 35);
	assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));

	libsimple_default_failure_exit = 39;
	assert_exit_ptr(libsimple_ealigned_allocn(8, SIZE_MAX, 2, 0));
	assert(exit_status == 39);
	assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));

	return 0;
}

#endif
