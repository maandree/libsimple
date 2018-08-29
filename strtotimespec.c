/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


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

	if (*s == '-') {
		neg = 1;
		s++;
	} else if (*s == '+') {
		s++;
	}

	if (!isdigit(*s) && *s != '.') {
		errno = EINVAL;
		return -1;
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
			goto overflow_integer;
		sec *= 10;
		if (sec < TIME_MIN + (*s & 15))
			goto overflow_integer;
		sec -= *s & 15;
	}

	if (!neg) {
		if (TIME_MIN != -TIME_MAX && sec == TIME_MIN)
			goto overflow_integer;
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
					goto overflow_periodic;
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
						goto overflow_fraction;
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

	ts->tv_sec = sec;
	ts->tv_nsec = nsec;
	return 0;

overflow_integer:
	while (isdigit(*s)) s++;
	if (*s != '.')
		goto overflow;
	s++;

overflow_fraction:
	while (isdigit(*s)) s++;
	if (*s == '(')
		bracket = 1;
	else if (*s != '.')
		goto overflow;
	s++;
	if (!isdigit(*s)) {
		errno = EINVAL;
		return -1;
	}

overflow_periodic:
	if (bracket) {
		while (isdigit(*s)) s++;
		if (*s != ')') {
			errno = EINVAL;
			return -1;
		}
		s++;
	} else {
		while (isdigit(*s)) s++;
	}

overflow:
	if (end)
		*end = (void *)s;
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


#else
#include "test.h"

#define MS(N) N##000000L

#define INVAL(S)\
	do {\
		errno = 0;\
		assert(libsimple_strtotimespec(&t, (S), &end) == -1 && errno == EINVAL);\
		errno = 0;\
	} while (0)

int
main(void)
{
	char s[1024];
	struct timespec t;
	char *end;

	INVAL("");     INVAL("x");    INVAL(".");    INVAL("(");      INVAL(")");       INVAL(" ");      INVAL(" x");
	INVAL(" .");   INVAL(" (");   INVAL(" )");   INVAL("1.(1");   INVAL("1...1");   INVAL("1.()");   INVAL("1..");
	INVAL("+");    INVAL("+x");   INVAL("+.");   INVAL("+(");     INVAL("+)");      INVAL("+ ");     INVAL("+ x");
	INVAL("+ .");  INVAL("+ (");  INVAL("+ )");  INVAL("+1.(1");  INVAL("+1...1");  INVAL("+1.()");  INVAL("+1..");
	INVAL("-");    INVAL("-x");   INVAL("-.");   INVAL("-(");     INVAL("-)");      INVAL("- ");     INVAL("- x");
	INVAL("- .");  INVAL("- (");  INVAL("- )");  INVAL("-1.(1");  INVAL("-1...1");  INVAL("-1.()");  INVAL("-1..");
	INVAL("++");   INVAL("++x");  INVAL("++.");  INVAL("++(");    INVAL("++)");     INVAL("++ ");    INVAL("++ x");
	INVAL("++ ."); INVAL("++ ("); INVAL("++ )"); INVAL("++1.(1"); INVAL("++1...1"); INVAL("++1.()"); INVAL("++1..");
	INVAL("+-");   INVAL("+-x");  INVAL("+-.");  INVAL("+-(");    INVAL("+-)");     INVAL("+- ");    INVAL("+- x");
	INVAL("+- ."); INVAL("+- ("); INVAL("+- )"); INVAL("+-1.(1"); INVAL("+-1...1"); INVAL("+-1.()"); INVAL("+-1..");
	INVAL("-+");   INVAL("-+x");  INVAL("-+.");  INVAL("-+(");    INVAL("-+)");     INVAL("-+ ");    INVAL("-+ x");
	INVAL("-+ ."); INVAL("-+ ("); INVAL("-+ )"); INVAL("-+1.(1"); INVAL("-+1...1"); INVAL("-+1.()"); INVAL("-+1..");
	INVAL("--");   INVAL("--x");  INVAL("--.");  INVAL("--(");    INVAL("--)");     INVAL("-- ");    INVAL("-- x");
	INVAL("-- ."); INVAL("-- ("); INVAL("-- )"); INVAL("--1.(1"); INVAL("--1...1"); INVAL("--1.()"); INVAL("--1..");

	assert(!libsimple_strtotimespec(&t, "0xyz", &end));
	assert(t.tv_sec  == 0);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, "xyz"));

	assert(!libsimple_strtotimespec(&t, "1 xyz", &end));
	assert(t.tv_sec  == 1);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, " xyz"));

	assert(!libsimple_strtotimespec(&t, "  0.1-", &end));
	assert(t.tv_sec  == 0);
	assert(t.tv_nsec == MS(100));
	assert(!strcmp(end, "-"));

	assert(!libsimple_strtotimespec(&t, ".100", &end));
	assert(t.tv_sec  == 0);
	assert(t.tv_nsec == MS(100));
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "0010.", &end));
	assert(t.tv_sec  == 10);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "0020.300", NULL));
	assert(t.tv_sec  == 20);
	assert(t.tv_nsec == MS(300));

	assert(!libsimple_strtotimespec(&t, "98.1002003004", &end));
	assert(t.tv_sec  == 98);
	assert(t.tv_nsec == 100200300L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "99.1002003005", &end));
	assert(t.tv_sec  == 99);
	assert(t.tv_nsec == 100200301L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "100.9999999991", &end));
	assert(t.tv_sec  == 100);
	assert(t.tv_nsec == 999999999L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "101.9999999995x", &end));
	assert(t.tv_sec  == 102);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, "x"));

	assert(!libsimple_strtotimespec(&t, "9..1", &end));
	assert(t.tv_sec  == 9);
	assert(t.tv_nsec == 111111111L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "8..2", &end));
	assert(t.tv_sec  == 8);
	assert(t.tv_nsec == 222222222L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "7.(3)", &end));
	assert(t.tv_sec  == 7);
	assert(t.tv_nsec == 333333333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "6.(5)", &end));
	assert(t.tv_sec  == 6);
	assert(t.tv_nsec == 555555556L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "4.(9)", &end));
	assert(t.tv_sec  == 5);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "3..9", &end));
	assert(t.tv_sec  == 4);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "2..0", &end));
	assert(t.tv_sec  == 2);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "2.(0)", &end));
	assert(t.tv_sec  == 2);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "11.22.33", &end));
	assert(t.tv_sec  == 11);
	assert(t.tv_nsec == 223333333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "22.333333333(4)", &end));
	assert(t.tv_sec  == 22);
	assert(t.tv_nsec == 333333333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "22.333333333(5)", &end));
	assert(t.tv_sec  == 22);
	assert(t.tv_nsec == 333333334L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "22.333333333.4", &end));
	assert(t.tv_sec  == 22);
	assert(t.tv_nsec == 333333333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "22.333333333.5", &end));
	assert(t.tv_sec  == 22);
	assert(t.tv_nsec == 333333334L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "+11.22.33", &end));
	assert(t.tv_sec  == 11);
	assert(t.tv_nsec == 223333333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "-11.22.33", &end));
	assert(t.tv_sec  == -12);
	assert(t.tv_nsec == 1000000000L - 223333333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimespec(&t, "-11", &end));
	assert(t.tv_sec  == -11);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, ""));

	sprintf(s, "%ji", (intmax_t)TIME_MIN);
	errno = 0;
	assert(!libsimple_strtotimespec(&t, s, &end));
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, ""));

	sprintf(s, "%ji.5", (intmax_t)TIME_MIN + (intmax_t)1);
	errno = 0;
	assert(!libsimple_strtotimespec(&t, s, &end));
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_nsec == MS(500));
	assert(!strcmp(end, ""));

	sprintf(s, "%ji", (intmax_t)TIME_MAX);
	assert(!libsimple_strtotimespec(&t, s, &end));
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_nsec == 0L);
	assert(!strcmp(end, ""));

	sprintf(s, "%ji.999999999", (intmax_t)TIME_MAX);
	assert(!libsimple_strtotimespec(&t, s, &end));
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_nsec == 999999999L);
	assert(!strcmp(end, ""));

	sprintf(s, "%ji.5w", (intmax_t)TIME_MIN);
	errno = 0;
	assert(libsimple_strtotimespec(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_nsec == 0);
	assert(!strcmp(end, "w"));

	sprintf(s, "%ji0y", (intmax_t)TIME_MAX);
	errno = 0;
	assert(libsimple_strtotimespec(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_nsec == 999999999L);
	assert(!strcmp(end, "y"));

	sprintf(s, "%ji.9999999999999z", (intmax_t)TIME_MAX);
	errno = 0;
	assert(libsimple_strtotimespec(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_nsec == 999999999L);
	assert(!strcmp(end, "z"));

	sprintf(s, "%ji.9999999999999.999e", (intmax_t)TIME_MAX);
	errno = 0;
	assert(libsimple_strtotimespec(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_nsec == 999999999L);
	assert(!strcmp(end, "e"));

	sprintf(s, "%ji.9999999999999(999)r", (intmax_t)TIME_MAX);
	errno = 0;
	assert(libsimple_strtotimespec(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_nsec == 999999999L);
	assert(!strcmp(end, "r"));

	sprintf(s, "%ji0.(0)t", (intmax_t)TIME_MIN);
	errno = 0;
	assert(libsimple_strtotimespec(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_nsec == 0);
	assert(!strcmp(end, "t"));

	sprintf(s, "%ji0.()", (intmax_t)TIME_MIN);
	INVAL(s);

	sprintf(s, "%ji0.(s)", (intmax_t)TIME_MIN);
	INVAL(s);

	sprintf(s, "%ji0.0t", (intmax_t)TIME_MIN);
	errno = 0;
	assert(libsimple_strtotimespec(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_nsec == 0);
	assert(!strcmp(end, "t"));

	sprintf(s, "%ji0..", (intmax_t)TIME_MIN);
	INVAL(s);

	return 0;
}

#endif
