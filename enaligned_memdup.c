/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_enaligned_memdup(int status, const void *s, size_t alignment, size_t n)
{
	void *ret = aligned_memdup(s, alignment, n);
	if (!ret)
		enprintf(status, "aligned_memdup:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *s;

	assert((s = libsimple_enaligned_memdup(1, "hello", 2, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 5));
	free(s);

	assert((s = libsimple_ealigned_memdup("test", 8, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 8);
		assert(info->alignment == 8);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "test", 5));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_memdup(44, "hello", 2, 2));
		assert(exit_status == 44);
		assert_stderr("%s: aligned_memdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 55;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ealigned_memdup("test", 8, 2));
		assert(exit_status == 55);
		assert_stderr("%s: aligned_memdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
