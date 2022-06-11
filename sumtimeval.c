/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_sumtimeval(struct timeval *sum, const struct timeval *augend, const struct timeval *addend)
{
	time_t s;

	if (LIBSIMPLE_SADD_OVERFLOW(augend->tv_sec, addend->tv_sec, &s, TIME_MIN, TIME_MAX)) {
		if (addend->tv_sec > 0)
			goto too_large;
		else
			goto too_small;
	}

	sum->tv_usec = augend->tv_usec + addend->tv_usec;
	if (sum->tv_usec >= 1000000L) {
		if (LIBSIMPLE_SINCR_OVERFLOW(&s, TIME_MAX))
			goto too_large;
		sum->tv_usec -= 1000000L;
	}

	sum->tv_sec = s;
	return 0;

too_large:
	sum->tv_sec = TIME_MAX;
	sum->tv_usec = 999999L;
	errno = ERANGE;
	return -1;

too_small:
	sum->tv_sec = TIME_MIN;
	sum->tv_usec = 0;
	errno = ERANGE;
	return -1;
}


#else
#include "test.h"

int
main(void)
{
	struct timeval r, a, b;

	a.tv_sec  = 0;
	a.tv_usec = 0;
	b.tv_sec  = 0;
	b.tv_usec = 0;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0);

	a.tv_sec  = 10;
	a.tv_usec = 10000L;
	b.tv_sec  = 0;
	b.tv_usec = 0L;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_usec == 10000L);

	a.tv_sec  = 10;
	a.tv_usec = 10000L;
	b.tv_sec  = -10;
	b.tv_usec = 0L;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 10000L);

	a.tv_sec  = 10;
	a.tv_usec = 10000L;
	b.tv_sec  = -20;
	b.tv_usec = 20000L;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_usec == 30000L);

	a.tv_sec  = 1;
	a.tv_usec = 999999L;
	b.tv_sec  = 1;
	b.tv_usec = 1L;
	assert(!libsimple_sumtimeval(&r, &a, &b));
	assert(r.tv_sec  == 3);
	assert(r.tv_usec == 0L);

	a.tv_sec  = TIME_MAX;
	a.tv_usec = 0L;
	b.tv_sec  = TIME_MAX;
	b.tv_usec = 0L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_usec == 999999L);

	a.tv_sec  = TIME_MAX;
	a.tv_usec = 999999L;
	b.tv_sec  = 0;
	b.tv_usec = 1L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_usec == 999999L);

	a.tv_sec  = TIME_MAX;
	a.tv_usec = 1L;
	b.tv_sec  = 0;
	b.tv_usec = 999999L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_usec == 999999L);

	a.tv_sec  = TIME_MIN;
	a.tv_usec = 0L;
	b.tv_sec  = TIME_MIN;
	b.tv_usec = 0L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_usec == 0L);

	a.tv_sec  = TIME_MIN;
	a.tv_usec = 100L;
	b.tv_sec  = TIME_MIN;
	b.tv_usec = 100L;
	assert(libsimple_sumtimeval(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_usec == 0L);

	return 0;
}

#endif
