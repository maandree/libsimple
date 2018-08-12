/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_multimeval(struct timeval *prod, const struct timeval *multiplicand, int multiplier) /* TODO test */
{
	struct timespec a, p;
	int r;
	libsimple_timeval2timespec(&a, multiplicand);
	r = libsimple_multimespec(&p, &a, multiplier);
	if (r && errno != ERANGE)
		return r;
	return r | libsimple_timespec2timeval(prod, &p);
}
