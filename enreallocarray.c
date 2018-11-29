/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_enreallocarray(int status, void *ptr, size_t n, size_t m) /* TODO test */
{
	void *ret = reallocarray(ptr, n, m);
	if (!ret)
		enprintf(status, "reallocarray:");
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
