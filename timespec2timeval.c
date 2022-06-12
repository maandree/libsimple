/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_timespec2timeval(struct timeval *restrict tv, const struct timespec *restrict ts)
{
	tv->tv_sec = ts->tv_sec;
	tv->tv_usec = ts->tv_nsec / 1000L;
	if ((ts->tv_nsec % 1000L) >= 500L) {
		if (++(tv->tv_usec) == 1000000L) {
			if (LIBSIMPLE_SINCR_OVERFLOW(&tv->tv_sec, TIME_MAX)) {
				tv->tv_sec = TIME_MAX;
				tv->tv_usec = 999999L;
				errno = EOVERFLOW;
				return -1;
			}
			tv->tv_usec = 0;
		}
	}
	return 0;
}


#else
#include "test.h"

int
main(void)
{
	struct timeval tv;

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){0, 0}));
	assert(tv.tv_sec  == 0);
	assert(tv.tv_usec == 0);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){100, 0}));
	assert(tv.tv_sec  == 100);
	assert(tv.tv_usec == 0);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){100, 100000000L}));
	assert(tv.tv_sec  == 100);
	assert(tv.tv_usec == 100000L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){100, 100000400L}));
	assert(tv.tv_sec  == 100);
	assert(tv.tv_usec == 100000L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){100, 100000500L}));
	assert(tv.tv_sec  == 100);
	assert(tv.tv_usec == 100001L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){100, 999999999L}));
	assert(tv.tv_sec  == 101);
	assert(tv.tv_usec == 0L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){-100, 0}));
	assert(tv.tv_sec  == -100);
	assert(tv.tv_usec == 0);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){-100, 100000000L}));
	assert(tv.tv_sec  == -100);
	assert(tv.tv_usec == 100000L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){-100, 100000400L}));
	assert(tv.tv_sec  == -100);
	assert(tv.tv_usec == 100000L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){-100, 100000500L}));
	assert(tv.tv_sec  == -100);
	assert(tv.tv_usec == 100001L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){-100, 999999999L}));
	assert(tv.tv_sec  == -99);
	assert(tv.tv_usec == 0L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){TIME_MAX, 100000500L}));
	assert(tv.tv_sec  == TIME_MAX);
	assert(tv.tv_usec == 100001L);

	assert(libsimple_timespec2timeval(&tv, &(struct timespec){TIME_MAX, 999999500L}) == -1 && errno == EOVERFLOW);
	assert(tv.tv_sec  == TIME_MAX);
	assert(tv.tv_usec == 999999L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){TIME_MIN, 100000500L}));
	assert(tv.tv_sec  == TIME_MIN);
	assert(tv.tv_usec == 100001L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){TIME_MIN, 0L}));
	assert(tv.tv_sec  == TIME_MIN);
	assert(tv.tv_usec == 0L);

	assert(!libsimple_timespec2timeval(&tv, &(struct timespec){TIME_MIN, 500L}));
	assert(tv.tv_sec  == TIME_MIN);
	assert(tv.tv_usec == 1L);

	return 0;
}

#endif
