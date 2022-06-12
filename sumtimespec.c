/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_sumtimespec(struct timespec *sum, const struct timespec *augend, const struct timespec *addend)
{
	time_t s;

	if (LIBSIMPLE_SADD_OVERFLOW(augend->tv_sec, addend->tv_sec, &s, TIME_MIN, TIME_MAX)) {
		if (addend->tv_sec > 0)
			goto too_large;
		else
			goto too_small;
	}

	sum->tv_nsec = augend->tv_nsec + addend->tv_nsec;
	if (sum->tv_nsec >= 1000000000L) {
		if (LIBSIMPLE_SINCR_OVERFLOW(&s, TIME_MAX))
			goto too_large;
		sum->tv_nsec -= 1000000000L;
	}

	sum->tv_sec = s;
	return 0;

too_large:
	sum->tv_sec = TIME_MAX;
	sum->tv_nsec = 999999999L;
	errno = ERANGE;
	return -1;

too_small:
	sum->tv_sec = TIME_MIN;
	sum->tv_nsec = 0;
	errno = ERANGE;
	return -1;
}


#else
#include "test.h"

int
main(void)
{
	struct timespec r, a, b;

	a.tv_sec  = 0;
	a.tv_nsec = 0;
	b.tv_sec  = 0;
	b.tv_nsec = 0;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_nsec == 0);

	a.tv_sec  = 10;
	a.tv_nsec = 10000L;
	b.tv_sec  = 0;
	b.tv_nsec = 0L;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_nsec == 10000L);

	a.tv_sec  = 10;
	a.tv_nsec = 10000L;
	b.tv_sec  = -10;
	b.tv_nsec = 0L;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_nsec == 10000L);

	a.tv_sec  = 10;
	a.tv_nsec = 10000L;
	b.tv_sec  = -20;
	b.tv_nsec = 20000L;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_nsec == 30000L);

	a.tv_sec  = 1;
	a.tv_nsec = 999999999L;
	b.tv_sec  = 1;
	b.tv_nsec = 1L;
	assert(!libsimple_sumtimespec(&r, &a, &b));
	assert(r.tv_sec  == 3);
	assert(r.tv_nsec == 0L);

	a.tv_sec  = TIME_MAX;
	a.tv_nsec = 0L;
	b.tv_sec  = TIME_MAX;
	b.tv_nsec = 0L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_nsec == 999999999L);

	a.tv_sec  = TIME_MAX;
	a.tv_nsec = 999999999L;
	b.tv_sec  = 0;
	b.tv_nsec = 1L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_nsec == 999999999L);

	a.tv_sec  = TIME_MAX;
	a.tv_nsec = 1L;
	b.tv_sec  = 0;
	b.tv_nsec = 999999999L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_nsec == 999999999L);

	a.tv_sec  = TIME_MIN;
	a.tv_nsec = 0L;
	b.tv_sec  = TIME_MIN;
	b.tv_nsec = 0L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_nsec == 0L);

	a.tv_sec  = TIME_MIN;
	a.tv_nsec = 100L;
	b.tv_sec  = TIME_MIN;
	b.tv_nsec = 100L;
	assert(libsimple_sumtimespec(&r, &a, &b) == -1);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_nsec == 0L);

	return 0;
}

#endif
