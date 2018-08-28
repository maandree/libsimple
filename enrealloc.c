/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_enrealloc(int status, void *ptr, size_t n) /* TODO test */
{
	char *ret = realloc(ptr, n);
	if (!ret)
		enprintf(status, "realloc:");
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
