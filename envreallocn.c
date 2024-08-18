/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_envreallocn(int status, void *ptr, size_t n, va_list ap)
{
	void *ret = libsimple_vreallocn(ptr, n, ap);
	if (!ret)
		enprintf(status, "realloc:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested via libsimple_enreallocn */
}

#endif
