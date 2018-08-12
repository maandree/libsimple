/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_strtotimeval(struct timeval *restrict tv, const char *restrict s, char **restrict end) /* TODO test */
{
	struct timespec ts;
	int r = libsimple_strtotimespec(&ts, s, end);
	if (r && errno != ERANGE)
		return r;
	return r | libsimple_timespec2timeval(tv, &ts);
}
