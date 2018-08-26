/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_multimeval(struct timeval *prod, const struct timeval *multiplicand, int multiplier)
{
	struct timespec a, p;
	int r;
	libsimple_timeval2timespec(&a, multiplicand);
	r = libsimple_multimespec(&p, &a, multiplier);
	if (r && errno != ERANGE)
		return r;
	if (libsimple_timespec2timeval(prod, &p) && r)
		errno = ERANGE;
	return r;
}


#else
#include "test.h"

int
main(void)
{
	struct timeval r, a;

	a.tv_sec = 0, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, 0));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0L);

	a.tv_sec = 10, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, 0));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0L);

	a.tv_sec = 0, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, 0));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0L);

	a.tv_sec = 10, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, 0));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0L);

	a.tv_sec = 0, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, 1));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0L);

	a.tv_sec = 10, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, 1));
	assert(r.tv_sec  == 10);
	assert(r.tv_usec == 0L);

	a.tv_sec = 0, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, 1));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 10L);

	a.tv_sec = 10, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, 1));
	assert(r.tv_sec  == 10);
	assert(r.tv_usec == 10L);

	a.tv_sec = 0, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, 10));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0L);

	a.tv_sec = 10, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, 10));
	assert(r.tv_sec  == 100);
	assert(r.tv_usec == 0L);

	a.tv_sec = 0, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, 10));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 100L);

	a.tv_sec = 10, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, 10));
	assert(r.tv_sec  == 100);
	assert(r.tv_usec == 100L);

	a.tv_sec = 0, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, -1));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0L);

	a.tv_sec = 10, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, -1));
	assert(r.tv_sec  == -10);
	assert(r.tv_usec == 0L);

	a.tv_sec = 0, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, -1));
	assert(r.tv_sec  == -1);
	assert(r.tv_usec == 1000000L - 10L);

	a.tv_sec = 10, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, -1));
	assert(r.tv_sec  == -11);
	assert(r.tv_usec == 1000000L - 10L);

	a.tv_sec = 0, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, -10));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0L);

	a.tv_sec = 10, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, -10));
	assert(r.tv_sec  == -100);
	assert(r.tv_usec == 0L);

	a.tv_sec = 0, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, -10));
	assert(r.tv_sec  == -1);
	assert(r.tv_usec == 1000000L - 100L);

	a.tv_sec = 10, a.tv_usec = 10L;
	assert(!libsimple_multimeval(&r, &a, -10));
	assert(r.tv_sec  == -101);
	assert(r.tv_usec == 1000000L - 100L);

	a.tv_sec = TIME_MAX, a.tv_usec = 999999L;
	assert(!libsimple_multimeval(&r, &a, 0));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0);

	a.tv_sec = TIME_MAX, a.tv_usec = 999999L;
	assert(!libsimple_multimeval(&r, &a, 1));
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_usec == 999999L);

	a.tv_sec = TIME_MAX, a.tv_usec = 0L;
	assert(libsimple_multimeval(&r, &a, 2) == -1 && errno == ERANGE);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_usec == 999999L);

	a.tv_sec = TIME_MAX, a.tv_usec = 0L;
	assert(libsimple_multimeval(&r, &a, -2) == -1 && errno == ERANGE);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_usec == 0L);

	a.tv_sec = TIME_MAX, a.tv_usec = 0L;
	assert(!libsimple_multimeval(&r, &a, -1));
	assert(r.tv_sec  == -TIME_MAX);
	assert(r.tv_usec == 0L);

	if (-TIME_MAX > TIME_MIN) {
		a.tv_sec = TIME_MAX, a.tv_usec = 999999L;
		assert(!libsimple_multimeval(&r, &a, -1));
		assert(r.tv_sec  == -TIME_MAX - (time_t)1);
		assert(r.tv_usec == 1L);
	}

	a.tv_sec = 10, a.tv_usec = 100001L;
	assert(!libsimple_multimeval(&r, &a, 10));
	assert(r.tv_sec  == 101);
	assert(r.tv_usec == 10L);

	return 0;
}

#endif
