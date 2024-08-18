/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_enwmemdup(int status, const wchar_t *s, size_t n)
{
	wchar_t *ret = libsimple_wmemdup(s, n);
	if (!ret)
		enprintf(status, "wmemdup:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	wchar_t *s;

	assert((s = libsimple_enwmemdup(1, L"hello", 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 5 * sizeof(wchar_t));
		assert(!info->zeroed);
	}
	assert(!wmemcmp(s, L"hello", 5));
	free(s);

	assert((s = libsimple_ewmemdup(L"test", 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 5 * sizeof(wchar_t));
		assert(!info->zeroed);
	}
	assert(!wmemcmp(s, L"test", 5));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enwmemdup(44, L"hello", 2));
		assert(exit_status == 44);
		assert_stderr("%s: wmemdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 55;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ewmemdup(L"test", 2));
		assert(exit_status == 55);
		assert_stderr("%s: wmemdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		assert_exit_ptr(libsimple_enwmemdup(41, NULL, SSIZE_MAX));
		assert(exit_status == 41);
		assert_stderr("%s: wmemdup: %s\n", argv0, strerror(ENOMEM));

		libsimple_default_failure_exit = 51;
		assert_exit_ptr(libsimple_ewmemdup(NULL, SSIZE_MAX));
		assert(exit_status == 51);
		assert_stderr("%s: wmemdup: %s\n", argv0, strerror(ENOMEM));
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
