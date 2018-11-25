/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_wcsndup(const wchar_t *s, size_t n) /* TODO test */
{
	size_t n = wcsnlen(s, n), size;
	wchar_t *ret;
	if (LIBSIMPLE_UMUL_OVERFLOW_NONZERO(n + 1, sizeof(wchar_t), &size, SIZE_MAX)) {
		errno = ENOMEM;
		enprintf(status, "wcsdup:");
	}
	ret = aligned_alloc(_Alignof(wchar_t), size);
	if (!ret)
		enprintf(status, "wcsdup:");
	wmemcpy(ret, s, n);
	ret[n] = '\0';
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
