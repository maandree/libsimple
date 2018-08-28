/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_envmalloczn(int status, int clear, size_t n, va_list ap) /* TODO test */
{
	void *ret = libsimple_vmalloczn(clear, n, ap);
	if (!ret)
		enprintf(status, "%s:", clear ? "calloc" : "malloc");
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
