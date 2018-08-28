/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern char *argv0;


void
libsimple_envputenvf(int status, const char *fmt, va_list ap) /* TODO test */
{
	if (vputenvf(fmt, ap)) {
		fprintf(stderr, "%s: putenvf: %s\n", argv0, strerror(errno));
		exit(status);
	}
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
