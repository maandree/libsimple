/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_enwcsndup(int status, const wchar_t *s, size_t n) /* TODO test */
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
	return 0;
}

#endif
