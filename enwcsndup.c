/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


wchar_t *
libsimple_enwcsndup(int status, const wchar_t *s, size_t n)
{
	wchar_t *ret = libsimple_wcsndup(s, n);
	if (!ret)
		enprintf(status, "wcsndup:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	wchar_t *s;

	assert((s = libsimple_enwcsndup(1, L"hello", 10)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6 * sizeof(wchar_t));
		assert(info->alignment == _Alignof(wchar_t));
		assert(!info->zeroed);
	}
	assert(!wcscmp(s, L"hello"));
	free(s);

	assert((s = libsimple_enwcsndup(1, L"hello", 2)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 3 * sizeof(wchar_t));
		assert(info->alignment == _Alignof(wchar_t));
		assert(!info->zeroed);
	}
	assert(!wcscmp(s, L"he"));
	free(s);

	assert((s = libsimple_enwcsndup(1, L"hello", 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 1 * sizeof(wchar_t));
		assert(info->alignment == _Alignof(wchar_t));
		assert(!info->zeroed);
	}
	assert(!wcscmp(s, L""));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enwcsndup(24, L"hello", 10));
		assert(exit_status == 24);
		assert_stderr("%s: wcsndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enwcsndup(26, L"hello", 1));
		assert(exit_status == 26);
		assert_stderr("%s: wcsndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enwcsndup(28, L"hello", 0));
		assert(exit_status == 28);
		assert_stderr("%s: wcsndup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
