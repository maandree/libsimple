/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_encalloc(int status, size_t n, size_t m)
{
	void *ret = calloc(n, m);
	if (!ret)
		enprintf(status, "calloc:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr;

	assert((ptr = libsimple_encalloc(1, 2, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 10);
		assert(info->zeroed == 10);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_ecalloc(3, 4)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 12);
		assert(info->zeroed == 12);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_encalloc(5, 1, 1));
		assert(exit_status == 5);
		assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 103;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ecalloc(1, 1));
		assert(exit_status == 103);
		assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
