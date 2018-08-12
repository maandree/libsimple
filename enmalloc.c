/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


extern char *argv0;


void *
enmalloc(int status, size_t n) /* TODO test */
{
	void *ret = malloc(n);
	if (!ret) {
		fprintf(stderr, "%s: malloc: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}
