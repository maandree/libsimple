/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_enstrndup(int status, const char *s, size_t n)
{
	void *ret = strndup(s, n);
	if (!ret)
		enprintf(status, "strndup:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	char *s;

	assert((s = libsimple_enstrndup(1, "hello", 10)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 1);
		assert(!info->zeroed);
	}
	assert(!strcmp(s, "hello"));
	free(s);

	assert((s = libsimple_enstrndup(1, "hello", 2)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 3);
		assert(info->alignment == 1);
		assert(!info->zeroed);
	}
	assert(!strcmp(s, "he"));
	free(s);

	assert((s = libsimple_enstrndup(1, "hello", 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 1);
		assert(info->alignment == 1);
		assert(!info->zeroed);
	}
	assert(!strcmp(s, ""));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enstrndup(14, "hello", 10));
		assert(exit_status == 14);
		assert_stderr("%s: strndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enstrndup(16, "hello", 1));
		assert(exit_status == 16);
		assert_stderr("%s: strndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enstrndup(18, "hello", 0));
		assert(exit_status == 18);
		assert_stderr("%s: strndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
