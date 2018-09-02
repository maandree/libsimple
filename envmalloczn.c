/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_envmalloczn(int status, int clear, size_t n, va_list ap)
{
	void *ret = libsimple_vmalloczn(clear, n, ap);
	if (!ret)
		enprintf(status, "%s:", clear ? "calloc" : "malloc");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr;

	assert((ptr = libsimple_enmalloczn(1, 0, 5, 3, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 15);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_enmalloczn(1, 1, 5, 4, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 20);
		assert(info->zeroed == 20);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_enmallocn(1, 4, 3, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 12);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_encallocn(1, 4, 4, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 16);
		assert(info->zeroed == 16);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enmalloczn(3, 0, 4, 0));
		assert(exit_status == 3);
		stderr_buf[stderr_n] = 0;
		assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enmalloczn(5, 1, 2, 0));
		assert(exit_status == 5);
		assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enmallocn(9, 1, 0));
		assert(exit_status == 9);
		assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_encallocn(7, 5, 0));
		assert(exit_status == 7);
		assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	assert_exit_ptr(libsimple_enmalloczn(13, 0, SIZE_MAX, 2, 0));
	assert(exit_status == 13);
	assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));

	assert_exit_ptr(libsimple_enmalloczn(15, 1, SIZE_MAX, 2, 0));
	assert(exit_status == 15);
	assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));

	assert_exit_ptr(libsimple_enmallocn(19, SIZE_MAX, 2, 0));
	assert(exit_status == 19);
	assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));

	assert_exit_ptr(libsimple_encallocn(17, SIZE_MAX, 2, 0));
	assert(exit_status == 17);
	assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));

	assert((ptr = libsimple_emalloczn(0, 2, 5, 3, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 30);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_emalloczn(1, 2, 5, 4, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 40);
		assert(info->zeroed == 40);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_emallocn(2, 4, 3, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 24);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_ecallocn(2, 4, 4, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 32);
		assert(info->zeroed == 32);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		libsimple_default_failure_exit = 23;
		assert_exit_ptr(libsimple_emalloczn(0, 4, 0));
		assert(exit_status == 23);
		assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		libsimple_default_failure_exit = 25;
		assert_exit_ptr(libsimple_emalloczn(1, 2, 0));
		assert(exit_status == 25);
		assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		libsimple_default_failure_exit = 29;
		assert_exit_ptr(libsimple_emallocn(1, 0));
		assert(exit_status == 29);
		assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		libsimple_default_failure_exit = 27;
		assert_exit_ptr(libsimple_ecallocn(5, 0));
		assert(exit_status == 27);
		assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	libsimple_default_failure_exit = 33;
	assert_exit_ptr(libsimple_emalloczn(0, SIZE_MAX, 2, 0));
	assert(exit_status == 33);
	assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));

	libsimple_default_failure_exit = 35;
	assert_exit_ptr(libsimple_emalloczn(1, SIZE_MAX, 2, 0));
	assert(exit_status == 35);
	assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));

	libsimple_default_failure_exit = 39;
	assert_exit_ptr(libsimple_emallocn(SIZE_MAX, 2, 0));
	assert(exit_status == 39);
	assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));

	libsimple_default_failure_exit = 37;
	assert_exit_ptr(libsimple_ecallocn(SIZE_MAX, 2, 0));
	assert(exit_status == 37);
	assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));

	return 0;
}

#endif
