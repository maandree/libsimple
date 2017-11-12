/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


extern char *argv0;


void *
enmemdup(int status, const void *s, size_t n)
{
	void *ret = memdup(s, n);
	if (!ret) {
		fprintf(stderr, "%s: memdup: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}
