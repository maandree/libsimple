/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_difftimeval(struct timeval *diff, const struct timeval *minuend, const struct timeval *subtrahend) /* TODO test */
{
	struct timespec a, b, d;
	int r;
	libsimple_timeval2timespec(&a, minuend);
	libsimple_timeval2timespec(&b, subtrahend);
	r = libsimple_difftimespec(&d, &a, &b);
	if (r && errno != ERANGE)
		return r;
	return r | libsimple_timespec2timeval(diff, &d);
}
