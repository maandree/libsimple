/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern char *argv0;


void *
libsimple_enmalloc(int status, size_t n) /* TODO test */
{
	void *ret = malloc(n);
	if (!ret) {
		fprintf(stderr, "%s: malloc: %s\n", argv0, strerror(errno));
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
