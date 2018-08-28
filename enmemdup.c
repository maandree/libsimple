/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_enmemdup(int status, const void *s, size_t n) /* TODO test (libsimple_ememdup) */
{
	void *ret = memdup(s, n);
	if (!ret)
		enprintf(status, "memdup:");
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
