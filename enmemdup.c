/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


extern char *argv0;


void *
libsimple_enmemdup(int status, const void *s, size_t n) /* TODO test */
{
	void *ret = memdup(s, n);
	if (!ret) {
		fprintf(stderr, "%s: memdup: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}
