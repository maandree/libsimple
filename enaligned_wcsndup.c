/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_enaligned_wcsndup(int status, const wchar_t *s, size_t alignment, size_t n) /* TOOD test */
{
	void *ret = aligned_wcsndup(s, alignment, n);
	if (!ret)
		enprintf(status, "aligned_wcsndup:");
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
