/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


wchar_t *
libsimple_aligned_wcsndup(const wchar_t *s, size_t alignment, size_t n)
{
	size_t size;
	wchar_t *ret;
	n = wcsnlen(s, n);
	size = (n + 1) * sizeof(wchar_t);
	size = size + (alignment - size % alignment) % alignment;
	ret = aligned_alloc(alignment, size);
	if (!ret)
		return NULL;
	wmemcpy(ret, s, n);
	ret[n] = 0;
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
