/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void
libsimple_enlocaltime(int status, struct tm *tm, struct timespec *ts) /* TODO test (also libsimple_elocaltime) */
{
	if (libsimple_localtime(tm, ts))
		enprintf(status, "libsimple_localtime:");
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
