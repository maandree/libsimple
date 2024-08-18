/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#include <sys/timex.h>
#ifndef TEST


int
libsimple_gmtime(struct tm *tm, struct timespec *ts)
{
	struct timex timex;
	int r;

	memset(&timex, 0, sizeof(timex));
	timex.status = ADJ_NANO;
	r = adjtimex(&timex);
	if (r == -1)
		return -1;
	if (ts) {
		ts->tv_sec = timex.time.tv_sec;
		ts->tv_nsec = timex.time.tv_usec;
	}

	if (timex.time.tv_sec % (24 * 60 * 60) == 0) {
		if (r == TIME_INS) {
			timex.time.tv_sec -= 1;
			if (!gmtime_r(&timex.time.tv_sec, tm))
				return -1;
			tm->tm_sec += 1;
			return 1;
		} else if (r == TIME_DEL) {
			timex.time.tv_sec += 1;
			if (!gmtime_r(&timex.time.tv_sec, tm))
				return -1;
		} else {
			if (!gmtime_r(&timex.time.tv_sec, tm))
				return -1;
		}
	} else if (r == TIME_OOP) {
		if (!gmtime_r(&timex.time.tv_sec, tm))
			return -1;
		tm->tm_sec += 1;
	} else {
		if (!gmtime_r(&timex.time.tv_sec, tm))
			return -1;
	}

	return 0;
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
