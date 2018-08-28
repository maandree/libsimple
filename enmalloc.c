/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_enmalloc(int status, size_t n) /* TODO test */
{
	void *ret = malloc(n);
	if (!ret)
		enprintf(status, "malloc:");
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
