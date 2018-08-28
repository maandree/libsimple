/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern char *argv0;


void *
libsimple_envmalloczn(int status, int clear, size_t n, va_list ap) /* TODO test */
{
	void *ret = libsimple_vmalloczn(clear, n, ap);
	if (!ret) {
		fprintf(stderr, "%s: %s: %s\n", argv0, clear ? "calloc" : "malloc", strerror(errno));
		exit(status);
	}
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
