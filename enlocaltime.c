/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void
libsimple_enlocaltime(int status, struct tm *tm, struct timespec *ts)
{
	if (libsimple_localtime(tm, ts))
		enprintf(status, "libsimple_localtime:");
}


#else
#include "test.h"

int
main(void)
{
	/* TODO test */
	return 0;
}

#endif
