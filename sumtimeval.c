/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_sumtimeval(struct timeval *sum, const struct timeval *augend, const struct timeval *addend) /* TODO test */
{
	struct timespec a, b, s;
	int r;
	libsimple_timeval2timespec(&a, augend);
	libsimple_timeval2timespec(&b, addend);
	r = libsimple_sumtimespec(&s, &a, &b);
	if (r && errno != ERANGE)
		return r;
	return r | libsimple_timespec2timeval(sum, &s);
}
