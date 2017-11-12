/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_multimespec(struct timespec *prod, const struct timespec *multiplicand, int multiplier)
{
	time_t s = multiplicand->tv_sec;
	long long int ns = (long long int)(multiplicand->tv_nsec);
	long long int xs;
	int neg = (s < 0) ^ (multiplier < 0);

	if (multiplier == 0 || multiplier == 1) {
		prod->tv_sec = multiplier * multiplicand->tv_sec;
		prod->tv_nsec = multiplier * multiplicand->tv_nsec;
		return 0;
	}

	if (s < 0) {
		if (TIME_MIN != -TIME_MAX && s == TIME_MIN)
			goto overflow;
		s = -s;
		if (ns)
			ns = 1000000000L - ns;
	}
	if (multiplier < 0)
		multiplier = -multiplier;

	ns *= multiplier;
	xs = ns / 1000000000L;
	ns %= 1000000000L;

	if (s > TIME_MAX / multiplier)
		goto overflow;
	s *= multiplier;

	if (s > TIME_MAX - (time_t)xs)
		goto overflow;
	s += (time_t)xs;

	if (neg) {
		s = -s;
		if (ns) {
			if (s == TIME_MIN)
				goto overflow;
			ns = 1000000000L - ns;
			s -= 1;
		}
	}

	prod->tv_sec = s;
	prod->tv_nsec = ns;
	return 0;

overflow:
	if (neg) {
		prod->tv_sec = TIME_MIN;
		prod->tv_nsec = 0;
	} else {
		prod->tv_sec = TIME_MAX;
		prod->tv_nsec = 999999999L;
	}
	errno = ERANGE;
	return -1;
}
