/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_envreallocn(int status, void *ptr, size_t n, va_list ap) /* TODO test */
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
	return 0;
}

#endif
