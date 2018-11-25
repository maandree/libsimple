/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_wmemdup(const wchar_t *s, size_t n) /* TODO test */
{
	wchar_t *ret;
	size_t size;
	if (LIBSIMPLE_UMUL_OVERFLOW_NONZERO(n + !n, sizeof(wchar_t), &size, SIZE_MAX)) {
		errno = ENOMEM;
		return NULL;
	}
	ret = aligned_alloc(_Alignof(wchar_t), size);
	if (!ret)
		return NULL;
	return wmemcpy(ret, s, n);
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
