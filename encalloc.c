/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_encalloc(int status, size_t n, size_t m) /* TODO test */
{
	void *ret = calloc(n, m);
	if (!ret)
		enprintf(status, "calloc:");
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
