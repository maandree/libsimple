/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
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

	assert((s = libsimple_estrndup("test", 10)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 5);
		assert(info->alignment == 1);
		assert(!info->zeroed);
	}
	assert(!strcmp(s, "test"));
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

	assert((s = libsimple_estrndup("test", 3)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 4);
		assert(info->alignment == 1);
		assert(!info->zeroed);
	}
	assert(!strcmp(s, "tes"));
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

	assert((s = libsimple_estrndup("test", 0)));
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

		libsimple_default_failure_exit = 15;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_estrndup("test", 10));
		assert(exit_status == 15);
		assert_stderr("%s: strndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enstrndup(16, "hello", 1));
		assert(exit_status == 16);
		assert_stderr("%s: strndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 17;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_estrndup("test", 2));
		assert(exit_status == 17);
		assert_stderr("%s: strndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enstrndup(18, "hello", 0));
		assert(exit_status == 18);
		assert_stderr("%s: strndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 19;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_estrndup("test", 0));
		assert(exit_status == 19);
		assert_stderr("%s: strndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
