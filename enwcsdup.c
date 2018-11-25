/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_enwcsdup(int status, const wchar_t *s) /* TODO test */
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
	return 0;
}

#endif
