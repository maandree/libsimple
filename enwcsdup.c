/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_enwcsdup(int status, const wchar_t *s)
{
	size_t n = wcslen(s) + 1, size;
	wchar_t *ret;
	if (LIBSIMPLE_UMUL_OVERFLOW_NONZERO(n, sizeof(wchar_t), &size, SIZE_MAX)) {
		errno = ENOMEM;
		enprintf(status, "wcsdup:");
	}
	ret = aligned_alloc(_Alignof(wchar_t), size);
	if (!ret)
		enprintf(status, "wcsdup:");
	wmemcpy(ret, s, n);
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	wchar_t *s;

	assert((s = libsimple_enwcsdup(1, L"hello")));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6 * sizeof(wchar_t));
		assert(info->alignment == _Alignof(wchar_t));
		assert(!info->zeroed);
	}
	assert(!wcscmp(s, L"hello"));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enwcsdup(18, L"hello"));
		assert(exit_status == 18);
		assert_stderr("%s: wcsdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
