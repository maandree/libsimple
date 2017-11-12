/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_difftimespec(struct timespec *diff, const struct timespec *minuend, const struct timespec *subtrahend)
{
	long int ns = minuend->tv_nsec - subtrahend->tv_nsec;
	time_t s;
	int ret = 0;

	s = minuend->tv_sec - subtrahend->tv_sec;
	if ((minuend->tv_sec <= 0) != (subtrahend->tv_sec <= 0)) {
		if (minuend->tv_sec < 0 && minuend->tv_sec < TIME_MIN + subtrahend->tv_sec) {
			s = TIME_MIN;
			ns = 0;
			errno = ERANGE;
			ret = -1;
		} else if (minuend->tv_sec >= 0 && minuend->tv_sec > TIME_MAX + subtrahend->tv_sec) {
			s = TIME_MAX;
			ns = 999999999L;
			errno = ERANGE;
			ret = -1;
		}
	}

	if (ns < 0) {
		if (s == TIME_MIN) {
			ns = 0L;
			errno = ERANGE;
			ret = -1;
		} else {
			s -= 1;
			ns += 1000000000L;
		}
	} else if (ns >= 1000000000L) {
		if (s == TIME_MAX) {
			ns = 999999999L;
			errno = ERANGE;
			ret = -1;
		} else {
			s += 1;
			ns -= 1000000000L;
		}
	}

	diff->tv_sec = s;
	diff->tv_nsec = ns;
	return ret;
}
