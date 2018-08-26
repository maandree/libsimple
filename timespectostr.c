/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_timespectostr(char *restrict buf, const struct timespec *restrict ts)
{
	time_t s = ts->tv_sec;
	long int ns = ts->tv_nsec;
	char sign[2] = "+";

	if (!buf) {
		buf = malloc(INTSTRLEN(time_t) + sizeof("-.999999999"));
		if (!buf)
			return NULL;
	}

	if (ts->tv_nsec < 0 || ts->tv_nsec >= 1000000000L) {
		errno = EINVAL;
		return NULL;
	}

	if (s == TIME_MIN && !ns) {
		sprintf(buf, "%lli.000000000", (long long int)s);
		return buf;
	}

	if (s < 0) {
		s = -s;
		*sign = '-';
		if (ns) {
			s -= 1;
			ns = 1000000000L - ns;
		}
	}

	sprintf(buf, "%s%lli.%09li", sign, (long long int)s, ns);
	return buf;
}
