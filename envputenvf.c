/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


extern char *argv0;


void
libsimple_envputenvf(int status, const char *fmt, va_list ap) /* TODO test */
{
	if (vputenvf(fmt, ap)) {
		fprintf(stderr, "%s: putenvf: %s\n", argv0, strerror(errno));
		exit(status);
	}
}
