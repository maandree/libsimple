/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_strtotimeval(struct timeval *restrict tv, const char *restrict s, char **restrict end)
{
	struct timespec ts;
	int r = libsimple_strtotimespec(&ts, s, end);
	if (r && errno != ERANGE)
		return r;
	if (libsimple_timespec2timeval(tv, &ts) && r)
		errno = ERANGE;
	return r;
}


#else
#include "test.h"

#define MS(N) N##000L

#define INVAL(S)\
	do {\
		errno = 0;\
		assert(libsimple_strtotimeval(&t, (S), &end) == -1 && errno == EINVAL);\
		errno = 0;\
	} while (0)

int
main(void)
{
	char s[1024];
	struct timeval t;
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

	assert(!libsimple_strtotimeval(&t, "0xyz", &end));
	assert(t.tv_sec  == 0);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, "xyz"));

	assert(!libsimple_strtotimeval(&t, "1 xyz", &end));
	assert(t.tv_sec  == 1);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, " xyz"));

	assert(!libsimple_strtotimeval(&t, "  0.1-", &end));
	assert(t.tv_sec  == 0);
	assert(t.tv_usec == MS(100));
	assert(!strcmp(end, "-"));

	assert(!libsimple_strtotimeval(&t, ".100", &end));
	assert(t.tv_sec  == 0);
	assert(t.tv_usec == MS(100));
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "0010.", &end));
	assert(t.tv_sec  == 10);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "0020.300", NULL));
	assert(t.tv_sec  == 20);
	assert(t.tv_usec == MS(300));

	assert(!libsimple_strtotimeval(&t, "98.1002004", &end));
	assert(t.tv_sec  == 98);
	assert(t.tv_usec == 100200L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "99.1002005", &end));
	assert(t.tv_sec  == 99);
	assert(t.tv_usec == 100201L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "100.9999991", &end));
	assert(t.tv_sec  == 100);
	assert(t.tv_usec == 999999L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "101.9999995x", &end));
	assert(t.tv_sec  == 102);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, "x"));

	assert(!libsimple_strtotimeval(&t, "9..1", &end));
	assert(t.tv_sec  == 9);
	assert(t.tv_usec == 111111L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "8..2", &end));
	assert(t.tv_sec  == 8);
	assert(t.tv_usec == 222222L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "7.(3)", &end));
	assert(t.tv_sec  == 7);
	assert(t.tv_usec == 333333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "6.(5)", &end));
	assert(t.tv_sec  == 6);
	assert(t.tv_usec == 555556L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "4.(9)", &end));
	assert(t.tv_sec  == 5);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "3..9", &end));
	assert(t.tv_sec  == 4);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "2..0", &end));
	assert(t.tv_sec  == 2);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "2.(0)", &end));
	assert(t.tv_sec  == 2);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "11.22.33", &end));
	assert(t.tv_sec  == 11);
	assert(t.tv_usec == 223333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "22.333333(4)", &end));
	assert(t.tv_sec  == 22);
	assert(t.tv_usec == 333333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "22.333333(5)", &end));
	assert(t.tv_sec  == 22);
	assert(t.tv_usec == 333334L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "22.333333.4", &end));
	assert(t.tv_sec  == 22);
	assert(t.tv_usec == 333333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "22.333333.5", &end));
	assert(t.tv_sec  == 22);
	assert(t.tv_usec == 333334L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "+11.22.33", &end));
	assert(t.tv_sec  == 11);
	assert(t.tv_usec == 223333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "-11.22.33", &end));
	assert(t.tv_sec  == -12);
	assert(t.tv_usec == 1000000L - 223333L);
	assert(!strcmp(end, ""));

	assert(!libsimple_strtotimeval(&t, "-11", &end));
	assert(t.tv_sec  == -11);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, ""));

	sprintf(s, "%ji", (intmax_t)TIME_MIN);
	errno = 0;
	assert(!libsimple_strtotimeval(&t, s, &end));
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, ""));

	sprintf(s, "%ji.5", (intmax_t)TIME_MIN + (intmax_t)1);
	errno = 0;
	assert(!libsimple_strtotimeval(&t, s, &end));
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_usec == MS(500));
	assert(!strcmp(end, ""));

	sprintf(s, "%ji", (intmax_t)TIME_MAX);
	assert(!libsimple_strtotimeval(&t, s, &end));
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_usec == 0L);
	assert(!strcmp(end, ""));

	sprintf(s, "%ji.999999999", (intmax_t)TIME_MAX);
	assert(!libsimple_strtotimeval(&t, s, &end));
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_usec == 999999L);
	assert(!strcmp(end, ""));

	sprintf(s, "%ji.5w", (intmax_t)TIME_MIN);
	errno = 0;
	assert(libsimple_strtotimeval(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_usec == 0);
	assert(!strcmp(end, "w"));

	sprintf(s, "%ji0y", (intmax_t)TIME_MAX);
	errno = 0;
	assert(libsimple_strtotimeval(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_usec == 999999L);
	assert(!strcmp(end, "y"));

	sprintf(s, "%ji.9999999999z", (intmax_t)TIME_MAX);
	errno = 0;
	assert(libsimple_strtotimeval(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_usec == 999999L);
	assert(!strcmp(end, "z"));

	sprintf(s, "%ji.9999999999.999e", (intmax_t)TIME_MAX);
	errno = 0;
	assert(libsimple_strtotimeval(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_usec == 999999L);
	assert(!strcmp(end, "e"));

	sprintf(s, "%ji.9999999999(999)r", (intmax_t)TIME_MAX);
	errno = 0;
	assert(libsimple_strtotimeval(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MAX);
	assert(t.tv_usec == 999999L);
	assert(!strcmp(end, "r"));

	sprintf(s, "%ji0.(0)t", (intmax_t)TIME_MIN);
	errno = 0;
	assert(libsimple_strtotimeval(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_usec == 0);
	assert(!strcmp(end, "t"));

	sprintf(s, "%ji0.()", (intmax_t)TIME_MIN);
	INVAL(s);

	sprintf(s, "%ji0.(s)", (intmax_t)TIME_MIN);
	INVAL(s);

	sprintf(s, "%ji0.0t", (intmax_t)TIME_MIN);
	errno = 0;
	assert(libsimple_strtotimeval(&t, s, &end) == -1 && errno == ERANGE);
	errno = 0;
	assert(t.tv_sec  == TIME_MIN);
	assert(t.tv_usec == 0);
	assert(!strcmp(end, "t"));

	sprintf(s, "%ji0..", (intmax_t)TIME_MIN);
	INVAL(s);

	return 0;
}

#endif
