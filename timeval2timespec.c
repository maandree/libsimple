/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void libsimple_timeval2timespec(struct timespec *restrict, const struct timeval *restrict);


#else
#include "test.h"

int
main(void)
{
	struct timespec ts;
	libsimple_timeval2timespec(&ts, &(struct timeval){0, 0L});
	assert(ts.tv_sec  == 0);
	assert(ts.tv_nsec == 0L);
	libsimple_timeval2timespec(&ts, &(struct timeval){0, 1L});
	assert(ts.tv_sec  == 0);
	assert(ts.tv_nsec == 1000L);
	libsimple_timeval2timespec(&ts, &(struct timeval){0, 999999L});
	assert(ts.tv_sec  == 0);
	assert(ts.tv_nsec == 999999000L);
	libsimple_timeval2timespec(&ts, &(struct timeval){10, 0L});
	assert(ts.tv_sec  == 10);
	assert(ts.tv_nsec == 0L);
	libsimple_timeval2timespec(&ts, &(struct timeval){10, 1L});
	assert(ts.tv_sec  == 10);
	assert(ts.tv_nsec == 1000L);
	libsimple_timeval2timespec(&ts, &(struct timeval){-10, 0L});
	assert(ts.tv_sec  == -10);
	assert(ts.tv_nsec == 0L);
	libsimple_timeval2timespec(&ts, &(struct timeval){-10, 1L});
	assert(ts.tv_sec  == -10);
	assert(ts.tv_nsec == 1000L);
	return 0;
}

#endif
