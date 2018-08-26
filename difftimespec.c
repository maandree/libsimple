/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


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


#else
#include "test.h"

int
main(void)
{
	struct timespec r, a, b;

	a.tv_sec = 0, a.tv_nsec = 0L;
	b.tv_sec = 0, b.tv_nsec = 0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_nsec == 0L);

	a.tv_sec = 10, a.tv_nsec = 0L;
	b.tv_sec =  0, b.tv_nsec = 0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_nsec == 0L);

	a.tv_sec = 10, a.tv_nsec = 100L;
	b.tv_sec =  0, b.tv_nsec =   0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_nsec == 100L);

	a.tv_sec = 10, a.tv_nsec = 100L;
	b.tv_sec =  1, b.tv_nsec =   0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == 9);
	assert(r.tv_nsec == 100L);

	a.tv_sec = 10, a.tv_nsec = 100L;
	b.tv_sec =  0, b.tv_nsec =   1L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_nsec == 99L);

	a.tv_sec = -10, a.tv_nsec = 100L;
	b.tv_sec =   0, b.tv_nsec =   0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_nsec == 100L);

	a.tv_sec = 10, a.tv_nsec =   1L;
	b.tv_sec =  1, b.tv_nsec = 100L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == 8);
	assert(r.tv_nsec == 1000000001L - 100L);

	a.tv_sec = 10, a.tv_nsec = 0L;
	b.tv_sec = 20, b.tv_nsec = 0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_nsec == 0L);

	a.tv_sec = 10, a.tv_nsec = 10L;
	b.tv_sec = 20, b.tv_nsec =  0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_nsec == 10L);

	a.tv_sec = 10, a.tv_nsec = 10L;
	b.tv_sec = 20, b.tv_nsec = 20L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == -10 - 1);
	assert(r.tv_nsec == 1000000010L - 20L);

	a.tv_sec =  10, a.tv_nsec = 10L;
	b.tv_sec = -20, b.tv_nsec =  0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == 30);
	assert(r.tv_nsec == 10L);

	a.tv_sec = 0, a.tv_nsec = 10L;
	b.tv_sec = 0, b.tv_nsec =  0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_nsec == 10L);

	a.tv_sec = 0, a.tv_nsec =  0L;
	b.tv_sec = 0, b.tv_nsec = 10L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == -1);
	assert(r.tv_nsec == 1000000000L - 10L);

	a.tv_sec = TIME_MIN, a.tv_nsec = 0L;
	b.tv_sec = 0,        b.tv_nsec = 0L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_nsec == 0L);

	a.tv_sec = TIME_MIN, a.tv_nsec = 0L;
	b.tv_sec = 0,        b.tv_nsec = 1L;
	assert(libsimple_difftimespec(&r, &a, &b) == -1 && errno == ERANGE);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_nsec == 0L);

	a.tv_sec = TIME_MIN, a.tv_nsec = 0L;
	b.tv_sec = -1,       b.tv_nsec = 1L;
	assert(!libsimple_difftimespec(&r, &a, &b));
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_nsec == 999999999L);

	a.tv_sec = TIME_MAX, a.tv_nsec = 0L;
	b.tv_sec = -1,       b.tv_nsec = 0L;
	assert(libsimple_difftimespec(&r, &a, &b) == -1 && errno == ERANGE);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_nsec == 999999999L);

	return 0;
}

#endif
