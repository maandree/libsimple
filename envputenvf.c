/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void
libsimple_envputenvf(int status, const char *fmt, va_list ap) /* TODO test */
{
	if (libsimple_vputenvf(fmt, ap))
		enprintf(status, "putenvf:");
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
