/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_timespec2timeval(struct timeval *restrict tv, const struct timespec *restrict ts) /* TODO test */
{
        tv->tv_sec = ts->tv_sec;
        tv->tv_usec = ts->tv_nsec / 1000L;
        if ((ts->tv_nsec % 1000L) >= 500L) {
                if (++(tv->tv_usec) == 1000000L) {
                        tv->tv_usec = 0;
                        if (tv->tv_sec == TIME_MAX) {
                                tv->tv_usec = 999999L;
                                errno = EOVERFLOW;
                                return -1;
                        } else {
                                tv->tv_sec += 1;
                        }
                }
        }
        return 0;
}
