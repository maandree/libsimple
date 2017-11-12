/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


extern char *argv0;


void
envputenvf(int status, const char *fmt, va_list ap)
{
	if (vputenvf(fmt, ap)) {
		fprintf(stderr, "%s: putenvf: %s\n", argv0, strerror(errno));
		exit(status);
	}
}
