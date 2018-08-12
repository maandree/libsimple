/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_sumtimespec(struct timespec *sum, const struct timespec *augend, const struct timespec *addend) /* TODO test */
{
	long int ns = augend->tv_nsec + addend->tv_nsec;
	time_t s;
	int ret = 0;

	s = augend->tv_sec + addend->tv_sec;
	if ((augend->tv_sec < 0) == (addend->tv_sec < 0)) {
		if (augend->tv_sec >= 0 && augend->tv_sec > TIME_MAX - addend->tv_sec) {
			s = TIME_MAX;
			ns = 999999999L;
			errno = ERANGE;
			ret = -1;
		} else if (augend->tv_sec < 0 && augend->tv_sec + addend->tv_sec < TIME_MIN) {
			s = TIME_MIN;
			ns = 0;
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

	sum->tv_sec = s;
	sum->tv_nsec = ns;
	return ret;
}
