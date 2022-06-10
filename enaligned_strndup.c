/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_enaligned_strndup(int status, const char *s, size_t alignment, size_t n)
{
	void *ret = aligned_strndup(s, alignment, n);
	if (!ret)
		enprintf(status, "aligned_strndup:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *s;

	assert((s = libsimple_enaligned_strndup(1, "hello", 2, SIZE_MAX)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_enaligned_strndup(1, "hello", 2, 100)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_enaligned_strndup(1, "hello", 2, 6)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_enaligned_strndup(1, "hello", 2, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_enaligned_strndup(1, "hello", 2, 4)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hell", 5));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_strndup(44, "hello", 2, 10));
		assert(exit_status == 44);
		assert_stderr("%s: aligned_strndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
