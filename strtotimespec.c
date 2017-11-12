/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_strtotimespec(struct timespec *restrict ts, const char *restrict s, char **restrict end)
{
	int neg = 0, bracket = 0;
	time_t sec = 0;
	long int nsec = 0;
	long int mul = 100000000L;
	const char *p;

	if (end)
		*end = (void *)s;

	while (isspace(*s))
		s++;

	if (!isdigit(s) && *s != '+' && *s != '-' && *s != '.') {
		errno = EINVAL;
		return -1;
	}

	if (*s == '-') {
		neg = 1;
		s++;
	} else if (*s == '+') {
		s++;
	}

	if (*s == '.') {
		if (s[1] == '.' || s[1] == '(') {
			if (!isdigit(s[2])) {
				errno = EINVAL;
				return -1;
			}
		} else if (!isdigit(s[1])) {
			errno = EINVAL;
			return -1;
		}
	}

	for (; isdigit(*s); s++) {
		if (sec < TIME_MIN / 10)
			goto overflow;
		sec *= 10;
		if (sec < TIME_MIN + (*s & 15))
			goto overflow;
		sec -= *s & 15;
	}

	if (!neg) {
		if (TIME_MIN != -TIME_MAX && sec == TIME_MIN)
			goto overflow;
		sec = -sec;
	}

	if (*s != '.') {
		ts->tv_sec = sec;
		ts->tv_nsec = 0;
		if (end)
			*end = (void *)s;
		return 0;
	}

	for (s++; mul && isdigit(*s); s++) {
		nsec += (*s & 15) * mul;
		mul /= 10;
	}

	if (*s == '.' || *s == '(') {
		bracket = *s++ == '(';
		p = s;
		if (!isdigit(*s)) {
			errno = EINVAL;
			return -1;
		}
		for (p = s; isdigit(*p); p++);
		if (bracket) {
			if (*p == ')') {
				p++;
			} else {
				errno = EINVAL;
				return -1;
			}
		}
		if (end)
			*end = (void *)p;
		p = s;
		while (mul) {
			for (s = p; mul && isdigit(*s); s++) {
				nsec += (*s & 15) * mul;
				mul /= 10;
			}
		}
		if (!isdigit(*s))
			s = p;
		if (*s >= '5') {
			nsec += 1;
			if (nsec == 1000000000L) {
				if (sec == TIME_MAX)
					goto overflow;
				sec += 1;
				nsec = 0;
			}
		}
	} else {
		if (isdigit(*s)) {
			if (*s >= '5') {
				nsec += 1;
				if (nsec == 1000000000L) {
					if (sec == TIME_MAX)
						goto overflow;
					sec += 1;
					nsec = 0;
				}
			}
			while (isdigit(*s))
				s++;
		}
		if (end)
			*end = (void *)s;
	}

	if (neg && nsec) {
		if (sec == TIME_MIN)
			goto overflow;
		nsec = 1000000000L - nsec;
		sec -= 1;
	}

	return 0;
overflow:
	if (neg) {
		ts->tv_sec = TIME_MIN;
		ts->tv_nsec = 0;
	} else {
		ts->tv_sec = TIME_MAX;
		ts->tv_nsec = 999999999L;
	}
	errno = ERANGE;
	return -1;
}
