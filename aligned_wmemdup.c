/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_aligned_wmemdup(const wchar_t *s, size_t alignment, size_t n)
{
	size_t size;
	void *ret;
	if (LIBSIMPLE_UMUL_OVERFLOW_NONZERO(n, sizeof(wchar_t), &size, SIZE_MAX)) {
		errno = ENOMEM;
		enprintf(status, "wcsdup:");
	}
	size = size + (alignment - size % alignment) % alignment;
	ret = aligned_alloc(alignment, size ? size : alignment);
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
