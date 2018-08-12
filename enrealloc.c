/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


extern char *argv0;


void *
enrealloc(int status, void *ptr, size_t n) /* TODO test */
{
	char *ret = realloc(ptr, n);
	if (!ret) {
		fprintf(stderr, "%s: realloc: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}
