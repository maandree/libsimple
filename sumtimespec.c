/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_sumtimespec(struct timespec *sum, const struct timespec *augend, const struct timespec *addend)
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
		} else if (augend->tv_sec < 0 && augend->tv_sec < TIME_MIN - addend->tv_sec) {
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


#else
#include "test.h"

int
main(void)
{
	struct timespec r, a, b;

	a.tv_sec = 0, a.tv_nsec = 0;
	b.tv_sec = 0, b.tv_nsec = 0;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_nsec == 0);

	a.tv_sec = 10, a.tv_nsec = 10000L;
	b.tv_sec =  0, b.tv_nsec =     0L;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_nsec == 10000L);

	a.tv_sec =  10, a.tv_nsec = 10000L;
	b.tv_sec = -10, b.tv_nsec =     0L;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_nsec == 10000L);

	a.tv_sec =  10, a.tv_nsec = 10000L;
	b.tv_sec = -20, b.tv_nsec = 20000L;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_nsec == 30000L);

	a.tv_sec = 1, a.tv_nsec = 999999999L;
	b.tv_sec = 1, b.tv_nsec =         1L;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == 3);
	assert(r.tv_nsec == 0L);

	a.tv_sec = TIME_MAX, a.tv_nsec = 0L;
	b.tv_sec = TIME_MAX, b.tv_nsec = 0L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_nsec == 999999999L);

	a.tv_sec = TIME_MAX, a.tv_nsec = 999999999L;
	b.tv_sec =        0, b.tv_nsec =         1L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_nsec == 999999999L);

	a.tv_sec = TIME_MAX, a.tv_nsec =         1L;
	b.tv_sec =        0, b.tv_nsec = 999999999L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_nsec == 999999999L);

	a.tv_sec = TIME_MIN, a.tv_nsec = 0L;
	b.tv_sec = TIME_MIN, b.tv_nsec = 0L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_nsec == 0L);

	a.tv_sec = TIME_MIN, a.tv_nsec = 100L;
	b.tv_sec = TIME_MIN, b.tv_nsec = 100L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_nsec == 0L);

	return 0;
}

#endif
