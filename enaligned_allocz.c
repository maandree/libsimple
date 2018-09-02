/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_enaligned_allocz(int status, int clear, size_t alignment, size_t n)
{
	void *ret = libsimple_aligned_allocz(clear, alignment, n);
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

	assert((ptr = libsimple_enaligned_allocz(1, 1, 8, 8)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		assert(info->alignment == 8);
		assert(info->zeroed == 8);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_ealigned_allocz(1, 4, 8)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		assert(info->alignment == 4);
		assert(info->zeroed == 8);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_enaligned_allocz(1, 0, 4, 8)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		assert(info->alignment == 4);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_ealigned_allocz(0, 2, 4)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4);
		assert(info->alignment == 2);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_enaligned_alloc(1, 4, 8)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		assert(info->alignment == 4);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_ealigned_alloc(2, 4)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4);
		assert(info->alignment == 2);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_allocz(3, 1, 2, 4));
		assert(exit_status == 3);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 102;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ealigned_allocz(1, 1, 4));
		assert(exit_status == 102);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_allocz(5, 0, 2, 4));
		assert(exit_status == 5);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 103;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ealigned_allocz(0, 1, 4));
		assert(exit_status == 103);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_alloc(7, 2, 4));
		assert(exit_status == 7);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 104;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ealigned_alloc(1, 4));
		assert(exit_status == 104);
		assert_stderr("%s: aligned_alloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
