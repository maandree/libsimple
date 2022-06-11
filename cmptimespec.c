/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline int libsimple_cmptimespec(const struct timespec *, const struct timespec *);


#else
#include "test.h"

int
main(void)
{
	struct timespec ts1, ts2;
	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 0, ts1.tv_nsec = 999999999L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 0, ts1.tv_nsec = 999999999L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 999999999L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 999999999L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 999999999L;
	ts2.tv_sec = 0, ts2.tv_nsec = 999999999L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 1, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 1, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 1, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 1, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 1, ts1.tv_nsec = 0L;
	ts2.tv_sec = 1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 1, ts1.tv_nsec = 1L;
	ts2.tv_sec = 1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 1, ts1.tv_nsec = 0L;
	ts2.tv_sec = 1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 1, ts1.tv_nsec = 1L;
	ts2.tv_sec = 1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec =  0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = -1, ts1.tv_nsec = 1L;
	ts2.tv_sec =  0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec =  0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = -1, ts1.tv_nsec = 1L;
	ts2.tv_sec =  0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec =  0, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec =  0, ts1.tv_nsec = 1L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec =  0, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec =  0, ts1.tv_nsec = 1L;
	ts2.tv_sec = -1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = -1, ts1.tv_nsec = 1L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = -1, ts1.tv_nsec = 1L;
	ts2.tv_sec = -1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 0,        ts1.tv_nsec = 0L;
	ts2.tv_sec = TIME_MAX, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 1,        ts1.tv_nsec = 0L;
	ts2.tv_sec = TIME_MAX, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = TIME_MAX, ts1.tv_nsec = 0L;
	ts2.tv_sec = TIME_MAX, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec =  1, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec =  1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	return 0;
}

#endif
