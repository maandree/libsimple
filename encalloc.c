/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


extern char *argv0;


void *
libsimple_encalloc(int status, size_t n, size_t m) /* TODO test */
{
	void *ret = calloc(n, m);
	if (!ret) {
		fprintf(stderr, "%s: calloc: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}
