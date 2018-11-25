/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_enaligned_wcsdup(int status, const wchar_t *s, size_t alignment) /* TOOD test */
{
	void *ret = aligned_wcsdup(s, alignment);
	if (!ret)
		enprintf(status, "aligned_wcsdup:");
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
