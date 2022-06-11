/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_difftimeval(struct timeval *diff, const struct timeval *minuend, const struct timeval *subtrahend)
{
	time_t s;

	if (LIBSIMPLE_SSUB_OVERFLOW(minuend->tv_sec, subtrahend->tv_sec, &s, TIME_MIN, TIME_MAX)) {
		if (subtrahend->tv_sec < 0)
			goto too_large;
		else
			goto too_small;
	}

	diff->tv_usec = minuend->tv_usec - subtrahend->tv_usec;
	if (diff->tv_usec < 0) {
		if (LIBSIMPLE_SDECR_OVERFLOW(&s, TIME_MIN))
			goto too_small;
		diff->tv_usec += 1000000L;
	}

	diff->tv_sec = s;
	return 0;

too_large:
	diff->tv_sec = TIME_MAX;
	diff->tv_usec = 999999L;
	errno = ERANGE;
	return -1;

too_small:
	diff->tv_sec = TIME_MIN;
	diff->tv_usec = 0;
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
	a.tv_usec = 0L;
	b.tv_sec  = 0;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 0L);

	a.tv_sec  = 10;
	a.tv_usec = 0L;
	b.tv_sec  = 0;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_usec == 0L);

	a.tv_sec  = 10;
	a.tv_usec = 100L;
	b.tv_sec  = 0;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_usec == 100L);

	a.tv_sec  = 10;
	a.tv_usec = 100L;
	b.tv_sec  = 1;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == 9);
	assert(r.tv_usec == 100L);

	a.tv_sec  = 10;
	a.tv_usec = 100L;
	b.tv_sec  = 0;
	b.tv_usec = 1L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == 10);
	assert(r.tv_usec == 99L);

	a.tv_sec  = -10;
	a.tv_usec = 100L;
	b.tv_sec  = 0;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_usec == 100L);

	a.tv_sec  = 10;
	a.tv_usec = 1L;
	b.tv_sec  = 1;
	b.tv_usec = 100L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == 8);
	assert(r.tv_usec == 1000001L - 100L);

	a.tv_sec  = 10;
	a.tv_usec = 0L;
	b.tv_sec  = 20;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_usec == 0L);

	a.tv_sec  = 10;
	a.tv_usec = 10L;
	b.tv_sec  = 20;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == -10);
	assert(r.tv_usec == 10L);

	a.tv_sec  = 10;
	a.tv_usec = 10L;
	b.tv_sec  = 20;
	b.tv_usec = 20L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == -10 - 1);
	assert(r.tv_usec == 1000010L - 20L);

	a.tv_sec  = 10;
	a.tv_usec = 10L;
	b.tv_sec  = -20;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == 30);
	assert(r.tv_usec == 10L);

	a.tv_sec  = 0;
	a.tv_usec = 10L;
	b.tv_sec  = 0;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == 0);
	assert(r.tv_usec == 10L);

	a.tv_sec  = 0;
	a.tv_usec = 0L;
	b.tv_sec  = 0;
	b.tv_usec = 10L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == -1);
	assert(r.tv_usec == 1000000L - 10L);

	a.tv_sec  = TIME_MIN;
	a.tv_usec = 0L;
	b.tv_sec  = 0;
	b.tv_usec = 0L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_usec == 0L);

	a.tv_sec  = TIME_MIN;
	a.tv_usec = 0L;
	b.tv_sec  = 0;
	b.tv_usec = 1L;
	assert(libsimple_difftimeval(&r, &a, &b) == -1 && errno == ERANGE);
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_usec == 0L);

	a.tv_sec  = TIME_MIN;
	a.tv_usec = 0L;
	b.tv_sec  = -1;
	b.tv_usec = 1L;
	assert(!libsimple_difftimeval(&r, &a, &b));
	assert(r.tv_sec  == TIME_MIN);
	assert(r.tv_usec == 999999L);

	a.tv_sec  = TIME_MAX;
	a.tv_usec = 0L;
	b.tv_sec  = -1;
	b.tv_usec = 0L;
	assert(libsimple_difftimeval(&r, &a, &b) == -1 && errno == ERANGE);
	assert(r.tv_sec  == TIME_MAX);
	assert(r.tv_usec == 999999L);

	return 0;
}

#endif
