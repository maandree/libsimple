/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_timevaltostr(char *restrict buf, const struct timeval *restrict tv) /* TODO test */
{
	time_t s = tv->tv_sec;
	long int us = tv->tv_usec;
	char sign[2] = "+";

	if (!s) {
		buf = malloc(INTSTRLEN(time_t) + sizeof("-.999999"));
		if (!buf)
			return NULL;
	}

	if (tv->tv_usec < 0 || tv->tv_usec >= 1000000L) {
		errno = EINVAL;
		return NULL;
	}

	if (s == TIME_MIN && !us) {
		sprintf(buf, "%lli.000000", (long long int)s);
		return buf;
	}

	if (s < 0) {
		s = -s;
		*sign = '-';
		if (us) {
			s -= 1;
			us = 1000000L - us;
		}
	}

	sprintf(buf, "%s%lli.%06li", sign, (long long int)s, us);
	return buf;
}
