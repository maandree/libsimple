/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_timevaltostr(char *restrict buf, const struct timeval *restrict tv)
{
	time_t s = tv->tv_sec;
	long int us = tv->tv_usec;
	char sign[2] = "+";

	if (!buf) {
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


#else
#include "test.h"

int
main(void)
{
	char buf[1000];

	/* Mostly tested in libsimple.c */

	errno = 0;
	assert(!libsimple_timevaltostr(buf, &(struct timeval){.tv_sec = 0, .tv_usec = -1}) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_timevaltostr(buf, &(struct timeval){.tv_sec = 0, .tv_usec = -2}) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_timevaltostr(buf, &(struct timeval){.tv_sec = 0, .tv_usec = 1000000L}) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_timevaltostr(buf, &(struct timeval){.tv_sec = 0, .tv_usec = 1000001L}) && errno == EINVAL);

	return 0;
}

#endif
