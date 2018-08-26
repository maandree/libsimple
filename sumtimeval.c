/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_sumtimeval(struct timeval *sum, const struct timeval *augend, const struct timeval *addend)
{
	struct timespec a, b, s;
	int r;
	libsimple_timeval2timespec(&a, augend);
	libsimple_timeval2timespec(&b, addend);
	r = libsimple_sumtimespec(&s, &a, &b);
	if (r && errno != ERANGE)
		return r;
	if (libsimple_timespec2timeval(sum, &s) && r)
		errno = ERANGE;
	return r;
}


#else
#include "test.h"

int
main(void)
{
	struct timeval r, a, b;

	a.tv_sec = 0, a.tv_usec = 0;
	b.tv_sec = 0, b.tv_usec = 0;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0);

	a.tv_sec = 10, a.tv_usec = 10000L;
	b.tv_sec =  0, b.tv_usec =     0L;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_usec == 10000L);

	a.tv_sec =  10, a.tv_usec = 10000L;
	b.tv_sec = -10, b.tv_usec =     0L;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 10000L);

	a.tv_sec =  10, a.tv_usec = 10000L;
	b.tv_sec = -20, b.tv_usec = 20000L;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_usec == 30000L);

	a.tv_sec = 1, a.tv_usec = 999999L;
	b.tv_sec = 1, b.tv_usec =      1L;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == 3);
	assert(r.tv_usec == 0L);

	a.tv_sec = TIME_MAX, a.tv_usec = 0L;
	b.tv_sec = TIME_MAX, b.tv_usec = 0L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_usec == 999999L);

	a.tv_sec = TIME_MAX, a.tv_usec = 999999L;
	b.tv_sec =        0, b.tv_usec =      1L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_usec == 999999L);

	a.tv_sec = TIME_MAX, a.tv_usec =      1L;
	b.tv_sec =        0, b.tv_usec = 999999L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_usec == 999999L);

	a.tv_sec = TIME_MIN, a.tv_usec = 0L;
	b.tv_sec = TIME_MIN, b.tv_usec = 0L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_usec == 0L);

	a.tv_sec = TIME_MIN, a.tv_usec = 100L;
	b.tv_sec = TIME_MIN, b.tv_usec = 100L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_usec == 0L);

	return 0;
}

#endif
