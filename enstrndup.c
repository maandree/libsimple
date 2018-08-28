/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_enstrndup(int status, const char *s, size_t n) /* TODO test (libsimple_estrndup) */
{
	void *ret = strndup(s, n);
	if (!ret)
		enprintf(status, "strndup:");
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
