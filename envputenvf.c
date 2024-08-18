/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void
libsimple_envputenvf(int status, const char *fmt, va_list ap)
{
	if (libsimple_vputenvf(fmt, ap))
		enprintf(status, "putenvf:");
}


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested via libsimple_enputenvf */
}

#endif
