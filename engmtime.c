/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void
libsimple_engmtime(int status, struct tm *tm, struct timespec *ts) /* TODO test (also libsimple_egmtime) */
{
	if (libsimple_gmtime(tm, ts))
		enprintf(status, "libsimple_gmtime:");
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
