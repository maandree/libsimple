/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


extern char *argv0;


char *
enstrdup(int status, const char *s)
{
	char *ret = strdup(s);
	if (!ret) {
		fprintf(stderr, "%s: strdup: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}
