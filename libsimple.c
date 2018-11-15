/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


#else
#include "test.h"

static size_t
gcd(size_t u, size_t v)
{
	size_t t;
	int shift = 0;
	/* Not needed because u>0, v>0: if (!(u | v)) return u + v; */
	while (!((u | v) & 1)) u >>= 1, v >>= 1, shift++;
	while (!(u & 1))       u >>= 1;
	do {
		while (!(v & 1)) v >>= 1;
		if (u > v)       t = u, u = v, v = t;
	} while (v -= u);
	return u << shift;
}

static size_t
lcm(size_t u, size_t v)
{
	return u / gcd(u, v) * v;
}

static int
test_timespec(double d, time_t sec, long int nsec, double rd, const char *s, const char *ss)
{
	char buf[1000], *str;
	struct timespec t;
	double dt;

	libsimple_doubletotimespec(&t, d);
	subassert(t.tv_sec == sec);
	subassert(t.tv_nsec == nsec);

	dt = libsimple_timespectodouble(&t);
	subassert(dt >= rd - 0.0000000001);
	subassert(dt <= rd + 0.0000000001);

	str = libsimple_timespectostr(buf, &t);
	subassert(str == buf);
	subassert(!strcmp(str, s));

	subassert((str = libsimple_timespectostr(NULL, &t)));
	subassert(!strcmp(str, s));

	strcpy(buf, str);
	free(str);
	str = libsimple_minimise_number_string(buf);
	subassert(str == buf);
	subassert(!strcmp(str, ss));

	return 1;
}

static int
test_timeval(double d, time_t sec, long int usec, double rd, const char *s, const char *ss)
{
	char buf[1000], *str;
	struct timeval t;
	double dt;

	libsimple_doubletotimeval(&t, d);
	subassert(t.tv_sec == sec);
	subassert(t.tv_usec == usec);

	dt = libsimple_timevaltodouble(&t);
	subassert(dt >= rd - 0.0000001);
	subassert(dt <= rd + 0.0000001);

	str = libsimple_timevaltostr(buf, &t);
	subassert(str == buf);
	subassert(!strcmp(str, s));

	str = libsimple_timevaltostr(NULL, &t);
	subassert(str);
	subassert(!strcmp(str, s));

	strcpy(buf, str);
	free(str);
	str = libsimple_minimise_number_string(buf);
	subassert(str == buf);
	subassert(!strcmp(str, ss));

	return 1;
}

#ifdef libsimple_vasprintfa
static int
test_vasprintfa(const char *expected, const char *format, ...)
{
	char *s;
	va_list ap;
	va_start(ap, format);
	s = libsimple_vasprintfa(format, ap);
	subassert(s);
	subassert(!strcmp(s, expected));
	va_end(ap);
	return 1;
}
#endif

int
main(void)
{
	struct allocinfo *volatile info;
	void *ptr;
	struct timespec ts, ts1, ts2;
	struct timeval tv1, tv2;
	const char *cs;
	char buf[1024], *s;
	int intarray[10];
	size_t i, j, n;
	size_t pagesize, cacheline;

	pagesize = (size_t)sysconf(_SC_PAGESIZE);
	cacheline = (size_t)sysconf(_SC_LEVEL1_DCACHE_LINESIZE);

	assert(libsimple_default_failure_exit == 1);

	assert(MIN(1, 3) == 1);
	assert(MIN(1, 1) == 1);
	assert(MIN(3, 1) == 1);
	assert(MIN(1, -3) == -3);
	assert(MIN(1, -1) == -1);
	assert(MIN(3, -1) == -1);
	assert(MIN(-1, 3) == -1);
	assert(MIN(-1, 1) == -1);
	assert(MIN(-3, 1) == -3);
	assert(MIN(-1, -3) == -3);
	assert(MIN(-1, -1) == -1);
	assert(MIN(-3, -1) == -3);

	assert(MAX(1, 3) == 3);
	assert(MAX(1, 1) == 1);
	assert(MAX(3, 1) == 3);
	assert(MAX(1, -3) == 1);
	assert(MAX(1, -1) == 1);
	assert(MAX(3, -1) == 3);
	assert(MAX(-1, 3) == 3);
	assert(MAX(-1, 1) == 1);
	assert(MAX(-3, 1) == 1);
	assert(MAX(-1, -3) == -1);
	assert(MAX(-1, -1) == -1);
	assert(MAX(-3, -1) == -1);

	assert(MIN3(1, 2, 3) == 1);
	assert(MIN3(1, 3, 2) == 1);
	assert(MIN3(2, 1, 3) == 1);
	assert(MIN3(2, 3, 1) == 1);
	assert(MIN3(3, 1, 2) == 1);
	assert(MIN3(3, 2, 1) == 1);
	assert(MIN3(1, 2, -3) == -3);
	assert(MIN3(1, 3, -2) == -2);
	assert(MIN3(2, 1, -3) == -3);
	assert(MIN3(2, 3, -1) == -1);
	assert(MIN3(3, 1, -2) == -2);
	assert(MIN3(3, 2, -1) == -1);
	assert(MIN3(1, -2, 3) == -2);
	assert(MIN3(1, -3, 2) == -3);
	assert(MIN3(2, -1, 3) == -1);
	assert(MIN3(2, -3, 1) == -3);
	assert(MIN3(3, -1, 2) == -1);
	assert(MIN3(3, -2, 1) == -2);
	assert(MIN3(1, -2, -3) == -3);
	assert(MIN3(1, -3, -2) == -3);
	assert(MIN3(2, -1, -3) == -3);
	assert(MIN3(2, -3, -1) == -3);
	assert(MIN3(3, -1, -2) == -2);
	assert(MIN3(3, -2, -1) == -2);
	assert(MIN3(-1, 2, 3) == -1);
	assert(MIN3(-1, 3, 2) == -1);
	assert(MIN3(-2, 1, 3) == -2);
	assert(MIN3(-2, 3, 1) == -2);
	assert(MIN3(-3, 1, 2) == -3);
	assert(MIN3(-3, 2, 1) == -3);
	assert(MIN3(-1, 2, -3) == -3);
	assert(MIN3(-1, 3, -2) == -2);
	assert(MIN3(-2, 1, -3) == -3);
	assert(MIN3(-2, 3, -1) == -2);
	assert(MIN3(-3, 1, -2) == -3);
	assert(MIN3(-3, 2, -1) == -3);
	assert(MIN3(-1, -2, 3) == -2);
	assert(MIN3(-1, -3, 2) == -3);
	assert(MIN3(-2, -1, 3) == -2);
	assert(MIN3(-2, -3, 1) == -3);
	assert(MIN3(-3, -1, 2) == -3);
	assert(MIN3(-3, -2, 1) == -3);
	assert(MIN3(-1, -2, -3) == -3);
	assert(MIN3(-1, -3, -2) == -3);
	assert(MIN3(-2, -1, -3) == -3);
	assert(MIN3(-2, -3, -1) == -3);
	assert(MIN3(-3, -1, -2) == -3);
	assert(MIN3(-3, -2, -1) == -3);

	assert(MAX3(1, 2, 3) == 3);
	assert(MAX3(1, 3, 2) == 3);
	assert(MAX3(2, 1, 3) == 3);
	assert(MAX3(2, 3, 1) == 3);
	assert(MAX3(3, 1, 2) == 3);
	assert(MAX3(3, 2, 1) == 3);
	assert(MAX3(1, 2, -3) == 2);
	assert(MAX3(1, 3, -2) == 3);
	assert(MAX3(2, 1, -3) == 2);
	assert(MAX3(2, 3, -1) == 3);
	assert(MAX3(3, 1, -2) == 3);
	assert(MAX3(3, 2, -1) == 3);
	assert(MAX3(1, -2, 3) == 3);
	assert(MAX3(1, -3, 2) == 2);
	assert(MAX3(2, -1, 3) == 3);
	assert(MAX3(2, -3, 1) == 2);
	assert(MAX3(3, -1, 2) == 3);
	assert(MAX3(3, -2, 1) == 3);
	assert(MAX3(1, -2, -3) == 1);
	assert(MAX3(1, -3, -2) == 1);
	assert(MAX3(2, -1, -3) == 2);
	assert(MAX3(2, -3, -1) == 2);
	assert(MAX3(3, -1, -2) == 3);
	assert(MAX3(3, -2, -1) == 3);
	assert(MAX3(-1, 2, 3) == 3);
	assert(MAX3(-1, 3, 2) == 3);
	assert(MAX3(-2, 1, 3) == 3);
	assert(MAX3(-2, 3, 1) == 3);
	assert(MAX3(-3, 1, 2) == 2);
	assert(MAX3(-3, 2, 1) == 2);
	assert(MAX3(-1, 2, -3) == 2);
	assert(MAX3(-1, 3, -2) == 3);
	assert(MAX3(-2, 1, -3) == 1);
	assert(MAX3(-2, 3, -1) == 3);
	assert(MAX3(-3, 1, -2) == 1);
	assert(MAX3(-3, 2, -1) == 2);
	assert(MAX3(-1, -2, 3) == 3);
	assert(MAX3(-1, -3, 2) == 2);
	assert(MAX3(-2, -1, 3) == 3);
	assert(MAX3(-2, -3, 1) == 1);
	assert(MAX3(-3, -1, 2) == 2);
	assert(MAX3(-3, -2, 1) == 1);
	assert(MAX3(-1, -2, -3) == -1);
	assert(MAX3(-1, -3, -2) == -1);
	assert(MAX3(-2, -1, -3) == -1);
	assert(MAX3(-2, -3, -1) == -1);
	assert(MAX3(-3, -1, -2) == -1);
	assert(MAX3(-3, -2, -1) == -1);

	assert(ELEMSOF((char [1]){}) == 1);
	assert(ELEMSOF((char [2]){}) == 2);
	assert(ELEMSOF((char [3]){}) == 3);
	assert(ELEMSOF((short int [3]){}) == 3);
	assert(ELEMSOF((int [3]){}) == 3);
	assert(ELEMSOF((long int [3]){}) == 3);
	assert(ELEMSOF((float [3]){}) == 3);
	assert(ELEMSOF((double [3]){}) == 3);

	assert(STRLEN("") == 0);
	assert(STRLEN("a") == 1);
	assert(STRLEN("aa") == 2);
	assert(STRLEN("abc") == 3);
	assert(STRLEN("a\0bc") == 4);
	assert(STRLEN("\0\0\0\0\0") == 5);

#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wtype-limits"
#endif
	assert(INTSTRLEN(int8_t)   == 4);
	assert(INTSTRLEN(uint8_t)  == 3);
	assert(INTSTRLEN(int16_t)  == 6);
	assert(INTSTRLEN(uint16_t) == 5);
	assert(INTSTRLEN(int32_t)  == 11);
	assert(INTSTRLEN(uint32_t) == 10);
	assert(INTSTRLEN(int64_t)  == 20 || INTSTRLEN(int64_t) == 21);
	assert(INTSTRLEN(uint64_t) == 20);
#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic pop
#endif

	assert(TYPE_MAX(int8_t)   == INT8_MAX);
	assert(TYPE_MAX(uint8_t)  == UINT8_MAX);
	assert(TYPE_MAX(int16_t)  == INT16_MAX);
	assert(TYPE_MAX(uint16_t) == UINT16_MAX);
	assert(TYPE_MAX(int32_t)  == INT32_MAX);
	assert(TYPE_MAX(uint32_t) == UINT32_MAX);
	assert(TYPE_MAX(int64_t)  == INT64_MAX);
	assert(TYPE_MAX(uint64_t) == UINT64_MAX);

	assert(TYPE_MIN(int8_t)   == INT8_MIN);
	assert(TYPE_MIN(uint8_t)  == 0);
	assert(TYPE_MIN(int16_t)  == INT16_MIN);
	assert(TYPE_MIN(uint16_t) == 0);
	assert(TYPE_MIN(int32_t)  == INT32_MIN);
	assert(TYPE_MIN(uint32_t) == 0);
	assert(TYPE_MIN(int64_t)  == INT64_MIN);
	assert(TYPE_MIN(uint64_t) == 0);

	assert(strcmpnul(libsimple_strend("abc\0xyz"), "xyz"));

	assert(libsimple_inchrset('a', "xyz") == 0);
	assert(libsimple_inchrset('b', "xyz") == 0);
	assert(libsimple_inchrset('c', "xyz") == 0);
	assert(libsimple_inchrset('x', "xyz") == 1);
	assert(libsimple_inchrset('y', "xyz") == 1);
	assert(libsimple_inchrset('z', "xyz") == 1);
	assert(libsimple_inchrset('\0', "xyz") == 0);

	stpcpy(buf, "abcxyz");
	assert(libsimple_mempcpy(buf, "123", 3) == &buf[3]);
	assert(!strcmpnul(buf, "123xyz"));

	assert(libsimple_streq("abc", "abc") == 1);
	assert(libsimple_streq("abc", "ab") == 0);
	assert(libsimple_streq("ab", "abc") == 0);
	assert(libsimple_streq("ab", "xy") == 0);
	assert(libsimple_streq("xy", "ab") == 0);
	assert(libsimple_streq("", "1") == 0);
	assert(libsimple_streq("1", "") == 0);
	assert(libsimple_streq("", "") == 1);
	assert(libsimple_streq("abc", "ABC") == 0);
	assert(libsimple_streq("ABC", "abc") == 0);

	assert(libsimple_strneq("abc", "abc", 5) == 1);
	assert(libsimple_strneq("abc", "ab", 5) == 0);
	assert(libsimple_strneq("ab", "abc", 5) == 0);
	assert(libsimple_strneq("ab", "xy", 5) == 0);
	assert(libsimple_strneq("xy", "ab", 5) == 0);
	assert(libsimple_strneq("", "1", 5) == 0);
	assert(libsimple_strneq("1", "", 5) == 0);
	assert(libsimple_strneq("", "", 5) == 1);
	assert(libsimple_strneq("abc", "ABC", 5) == 0);
	assert(libsimple_strneq("ABC", "abc", 5) == 0);
	assert(libsimple_strneq("abc", "abc", 1) == 1);
	assert(libsimple_strneq("abc", "ab", 1) == 1);
	assert(libsimple_strneq("ab", "abc", 1) == 1);
	assert(libsimple_strneq("ab", "xy", 1) == 0);
	assert(libsimple_strneq("xy", "ab", 1) == 0);
	assert(libsimple_strneq("", "1", 1) == 0);
	assert(libsimple_strneq("1", "", 1) == 0);
	assert(libsimple_strneq("", "", 1) == 1);
	assert(libsimple_strneq("abc", "ABC", 1) == 0);
	assert(libsimple_strneq("ABC", "abc", 1) == 0);
	assert(libsimple_strneq("abc", "abc", 0) == 1);
	assert(libsimple_strneq("abc", "ab", 0) == 1);
	assert(libsimple_strneq("ab", "abc", 0) == 1);
	assert(libsimple_strneq("ab", "xy", 0) == 1);
	assert(libsimple_strneq("xy", "ab", 0) == 1);
	assert(libsimple_strneq("", "1", 0) == 1);
	assert(libsimple_strneq("1", "", 0) == 1);
	assert(libsimple_strneq("", "", 0) == 1);
	assert(libsimple_strneq("abc", "ABC", 0) == 1);
	assert(libsimple_strneq("ABC", "abc", 0) == 1);

	assert(libsimple_streqnul("abc", "abc") == 1);
	assert(libsimple_streqnul("abc", "ab") == 0);
	assert(libsimple_streqnul("ab", "abc") == 0);
	assert(libsimple_streqnul("ab", "xy") == 0);
	assert(libsimple_streqnul("xy", "ab") == 0);
	assert(libsimple_streqnul("", "1") == 0);
	assert(libsimple_streqnul("1", "") == 0);
	assert(libsimple_streqnul("", "") == 1);
	assert(libsimple_streqnul("abc", "ABC") == 0);
	assert(libsimple_streqnul("ABC", "abc") == 0);
	assert(libsimple_streqnul("", NULL) == 0);
	assert(libsimple_streqnul("1", NULL) == 0);
	assert(libsimple_streqnul(NULL, "") == 0);
	assert(libsimple_streqnul(NULL, "1") == 0);
	assert(libsimple_streqnul(NULL, NULL) == 1);

	assert(libsimple_strneqnul("abc", "abc", 5) == 1);
	assert(libsimple_strneqnul("abc", "ab", 5) == 0);
	assert(libsimple_strneqnul("ab", "abc", 5) == 0);
	assert(libsimple_strneqnul("ab", "xy", 5) == 0);
	assert(libsimple_strneqnul("xy", "ab", 5) == 0);
	assert(libsimple_strneqnul("", "1", 5) == 0);
	assert(libsimple_strneqnul("1", "", 5) == 0);
	assert(libsimple_strneqnul("", "", 5) == 1);
	assert(libsimple_strneqnul("abc", "ABC", 5) == 0);
	assert(libsimple_strneqnul("ABC", "abc", 5) == 0);
	assert(libsimple_strneqnul("", NULL, 5) == 0);
	assert(libsimple_strneqnul("1", NULL, 5) == 0);
	assert(libsimple_strneqnul(NULL, "", 5) == 0);
	assert(libsimple_strneqnul(NULL, "1", 5) == 0);
	assert(libsimple_strneqnul(NULL, NULL, 5) == 1);
	assert(libsimple_strneqnul("abc", "abc", 1) == 1);
	assert(libsimple_strneqnul("abc", "ab", 1) == 1);
	assert(libsimple_strneqnul("ab", "abc", 1) == 1);
	assert(libsimple_strneqnul("ab", "xy", 1) == 0);
	assert(libsimple_strneqnul("xy", "ab", 1) == 0);
	assert(libsimple_strneqnul("", "1", 1) == 0);
	assert(libsimple_strneqnul("1", "", 1) == 0);
	assert(libsimple_strneqnul("", "", 1) == 1);
	assert(libsimple_strneqnul("abc", "ABC", 1) == 0);
	assert(libsimple_strneqnul("ABC", "abc", 1) == 0);
	assert(libsimple_strneqnul("", NULL, 1) == 0);
	assert(libsimple_strneqnul("1", NULL, 1) == 0);
	assert(libsimple_strneqnul(NULL, "", 1) == 0);
	assert(libsimple_strneqnul(NULL, "1", 1) == 0);
	assert(libsimple_strneqnul(NULL, NULL, 1) == 1);
	assert(libsimple_strneqnul("abc", "abc", 0) == 1);
	assert(libsimple_strneqnul("abc", "ab", 0) == 1);
	assert(libsimple_strneqnul("ab", "abc", 0) == 1);
	assert(libsimple_strneqnul("ab", "xy", 0) == 1);
	assert(libsimple_strneqnul("xy", "ab", 0) == 1);
	assert(libsimple_strneqnul("", "1", 0) == 1);
	assert(libsimple_strneqnul("1", "", 0) == 1);
	assert(libsimple_strneqnul("", "", 0) == 1);
	assert(libsimple_strneqnul("abc", "ABC", 0) == 1);
	assert(libsimple_strneqnul("ABC", "abc", 0) == 1);
	assert(libsimple_strneqnul("", NULL, 0) == 0);
	assert(libsimple_strneqnul("1", NULL, 0) == 0);
	assert(libsimple_strneqnul(NULL, "", 0) == 0);
	assert(libsimple_strneqnul(NULL, "1", 0) == 0);
	assert(libsimple_strneqnul(NULL, NULL, 0) == 1);

	assert(libsimple_strcaseeq("abc", "abc") == 1);
	assert(libsimple_strcaseeq("abc", "ab") == 0);
	assert(libsimple_strcaseeq("ab", "abc") == 0);
	assert(libsimple_strcaseeq("ab", "xy") == 0);
	assert(libsimple_strcaseeq("xy", "ab") == 0);
	assert(libsimple_strcaseeq("", "1") == 0);
	assert(libsimple_strcaseeq("1", "") == 0);
	assert(libsimple_strcaseeq("", "") == 1);
	assert(libsimple_strcaseeq("abc", "ABC") == 1);
	assert(libsimple_strcaseeq("ABC", "abc") == 1);

	assert(libsimple_strncaseeq("abc", "abc", 5) == 1);
	assert(libsimple_strncaseeq("abc", "ab", 5) == 0);
	assert(libsimple_strncaseeq("ab", "abc", 5) == 0);
	assert(libsimple_strncaseeq("ab", "xy", 5) == 0);
	assert(libsimple_strncaseeq("xy", "ab", 5) == 0);
	assert(libsimple_strncaseeq("", "1", 5) == 0);
	assert(libsimple_strncaseeq("1", "", 5) == 0);
	assert(libsimple_strncaseeq("", "", 5) == 1);
	assert(libsimple_strncaseeq("abc", "ABC", 5) == 1);
	assert(libsimple_strncaseeq("ABC", "abc", 5) == 1);
	assert(libsimple_strncaseeq("abc", "abc", 1) == 1);
	assert(libsimple_strncaseeq("abc", "ab", 1) == 1);
	assert(libsimple_strncaseeq("ab", "abc", 1) == 1);
	assert(libsimple_strncaseeq("ab", "xy", 1) == 0);
	assert(libsimple_strncaseeq("xy", "ab", 1) == 0);
	assert(libsimple_strncaseeq("", "1", 1) == 0);
	assert(libsimple_strncaseeq("1", "", 1) == 0);
	assert(libsimple_strncaseeq("", "", 1) == 1);
	assert(libsimple_strncaseeq("abc", "ABC", 1) == 1);
	assert(libsimple_strncaseeq("ABC", "abc", 1) == 1);
	assert(libsimple_strncaseeq("abc", "abc", 0) == 1);
	assert(libsimple_strncaseeq("abc", "ab", 0) == 1);
	assert(libsimple_strncaseeq("ab", "abc", 0) == 1);
	assert(libsimple_strncaseeq("ab", "xy", 0) == 1);
	assert(libsimple_strncaseeq("xy", "ab", 0) == 1);
	assert(libsimple_strncaseeq("", "1", 0) == 1);
	assert(libsimple_strncaseeq("1", "", 0) == 1);
	assert(libsimple_strncaseeq("", "", 0) == 1);
	assert(libsimple_strncaseeq("abc", "ABC", 0) == 1);
	assert(libsimple_strncaseeq("ABC", "abc", 0) == 1);

	assert(libsimple_strcaseeqnul("abc", "abc") == 1);
	assert(libsimple_strcaseeqnul("abc", "ab") == 0);
	assert(libsimple_strcaseeqnul("ab", "abc") == 0);
	assert(libsimple_strcaseeqnul("ab", "xy") == 0);
	assert(libsimple_strcaseeqnul("xy", "ab") == 0);
	assert(libsimple_strcaseeqnul("", "1") == 0);
	assert(libsimple_strcaseeqnul("1", "") == 0);
	assert(libsimple_strcaseeqnul("", "") == 1);
	assert(libsimple_strcaseeqnul("abc", "ABC") == 1);
	assert(libsimple_strcaseeqnul("ABC", "abc") == 1);
	assert(libsimple_strcaseeqnul("", NULL) == 0);
	assert(libsimple_strcaseeqnul("1", NULL) == 0);
	assert(libsimple_strcaseeqnul(NULL, "") == 0);
	assert(libsimple_strcaseeqnul(NULL, "1") == 0);
	assert(libsimple_strcaseeqnul(NULL, NULL) == 1);

	assert(libsimple_strncaseeqnul("abc", "abc", 5) == 1);
	assert(libsimple_strncaseeqnul("abc", "ab", 5) == 0);
	assert(libsimple_strncaseeqnul("ab", "abc", 5) == 0);
	assert(libsimple_strncaseeqnul("ab", "xy", 5) == 0);
	assert(libsimple_strncaseeqnul("xy", "ab", 5) == 0);
	assert(libsimple_strncaseeqnul("", "1", 5) == 0);
	assert(libsimple_strncaseeqnul("1", "", 5) == 0);
	assert(libsimple_strncaseeqnul("", "", 5) == 1);
	assert(libsimple_strncaseeqnul("abc", "ABC", 5) == 1);
	assert(libsimple_strncaseeqnul("ABC", "abc", 5) == 1);
	assert(libsimple_strncaseeqnul("", NULL, 5) == 0);
	assert(libsimple_strncaseeqnul("1", NULL, 5) == 0);
	assert(libsimple_strncaseeqnul(NULL, "", 5) == 0);
	assert(libsimple_strncaseeqnul(NULL, "1", 5) == 0);
	assert(libsimple_strncaseeqnul(NULL, NULL, 5) == 1);
	assert(libsimple_strncaseeqnul("abc", "abc", 1) == 1);
	assert(libsimple_strncaseeqnul("abc", "ab", 1) == 1);
	assert(libsimple_strncaseeqnul("ab", "abc", 1) == 1);
	assert(libsimple_strncaseeqnul("ab", "xy", 1) == 0);
	assert(libsimple_strncaseeqnul("xy", "ab", 1) == 0);
	assert(libsimple_strncaseeqnul("", "1", 1) == 0);
	assert(libsimple_strncaseeqnul("1", "", 1) == 0);
	assert(libsimple_strncaseeqnul("", "", 1) == 1);
	assert(libsimple_strncaseeqnul("abc", "ABC", 1) == 1);
	assert(libsimple_strncaseeqnul("ABC", "abc", 1) == 1);
	assert(libsimple_strncaseeqnul("", NULL, 1) == 0);
	assert(libsimple_strncaseeqnul("1", NULL, 1) == 0);
	assert(libsimple_strncaseeqnul(NULL, "", 1) == 0);
	assert(libsimple_strncaseeqnul(NULL, "1", 1) == 0);
	assert(libsimple_strncaseeqnul(NULL, NULL, 1) == 1);
	assert(libsimple_strncaseeqnul("abc", "abc", 0) == 1);
	assert(libsimple_strncaseeqnul("abc", "ab", 0) == 1);
	assert(libsimple_strncaseeqnul("ab", "abc", 0) == 1);
	assert(libsimple_strncaseeqnul("ab", "xy", 0) == 1);
	assert(libsimple_strncaseeqnul("xy", "ab", 0) == 1);
	assert(libsimple_strncaseeqnul("", "1", 0) == 1);
	assert(libsimple_strncaseeqnul("1", "", 0) == 1);
	assert(libsimple_strncaseeqnul("", "", 0) == 1);
	assert(libsimple_strncaseeqnul("abc", "ABC", 0) == 1);
	assert(libsimple_strncaseeqnul("ABC", "abc", 0) == 1);
	assert(libsimple_strncaseeqnul("", NULL, 0) == 0);
	assert(libsimple_strncaseeqnul("1", NULL, 0) == 0);
	assert(libsimple_strncaseeqnul(NULL, "", 0) == 0);
	assert(libsimple_strncaseeqnul(NULL, "1", 0) == 0);
	assert(libsimple_strncaseeqnul(NULL, NULL, 0) == 1);

	for (i = 0, n = 10; i < n; i++)
		buf[i] = i;
	LIBSIMPLE_UNLIST(buf, 4, &n);
	LIBSIMPLE_UNLIST(buf, 9 - 1, &n);
	LIBSIMPLE_UNLIST(buf, 6 - 1, &n);
	assert(n == 7);
	assert(buf[0] == 0);
	assert(buf[1] == 1);
	assert(buf[2] == 2);
	assert(buf[3] == 3);
	assert(buf[4] == 5);
	assert(buf[5] == 7);
	assert(buf[6] == 8);

	for (i = 0, n = 10; i < n; i++)
		intarray[i] = i;
	LIBSIMPLE_UNLIST(intarray, 4, &n);
	LIBSIMPLE_UNLIST(intarray, 9 - 1, &n);
	LIBSIMPLE_UNLIST(intarray, 6 - 1, &n);
	assert(n == 7);
	assert(intarray[0] == 0);
	assert(intarray[1] == 1);
	assert(intarray[2] == 2);
	assert(intarray[3] == 3);
	assert(intarray[4] == 5);
	assert(intarray[5] == 7);
	assert(intarray[6] == 8);

	assert(libsimple_strcmpnul(NULL, NULL) == 0);
	assert(libsimple_strcmpnul(NULL, "") < 0);
	assert(libsimple_strcmpnul("", NULL) > 0);
	assert(libsimple_strcmpnul("", "") == 0);
	assert(libsimple_strcmpnul(NULL, "x") < 0);
	assert(libsimple_strcmpnul("x", NULL) > 0);
	assert(libsimple_strcmpnul("x", "x") == 0);
	assert(libsimple_strcmpnul("a", "b") < 0);
	assert(libsimple_strcmpnul("b", "a") > 0);
	assert(libsimple_strcmpnul("aa", "ab") < 0);
	assert(libsimple_strcmpnul("ab", "aa") > 0);
	assert(libsimple_strcmpnul("aa", "aa") == 0);
	assert(libsimple_strcmpnul("A", "a") < 0);
	assert(libsimple_strcmpnul("a", "A") > 0);
	assert(libsimple_strcmpnul("AA", "Aa") < 0);
	assert(libsimple_strcmpnul("Aa", "AA") > 0);
	assert(libsimple_strcmpnul("AA", "AA") == 0);

	assert(libsimple_strcasecmpnul(NULL, NULL) == 0);
	assert(libsimple_strcasecmpnul(NULL, "") < 0);
	assert(libsimple_strcasecmpnul("", NULL) > 0);
	assert(libsimple_strcasecmpnul("", "") == 0);
	assert(libsimple_strcasecmpnul(NULL, "x") < 0);
	assert(libsimple_strcasecmpnul("x", NULL) > 0);
	assert(libsimple_strcasecmpnul("x", "x") == 0);
	assert(libsimple_strcasecmpnul("a", "b") < 0);
	assert(libsimple_strcasecmpnul("b", "a") > 0);
	assert(libsimple_strcasecmpnul("aa", "ab") < 0);
	assert(libsimple_strcasecmpnul("ab", "aa") > 0);
	assert(libsimple_strcasecmpnul("aa", "aa") == 0);
	assert(libsimple_strcasecmpnul("A", "a") == 0);
	assert(libsimple_strcasecmpnul("a", "A") == 0);
	assert(libsimple_strcasecmpnul("AA", "Aa") == 0);
	assert(libsimple_strcasecmpnul("Aa", "AA") == 0);
	assert(libsimple_strcasecmpnul("AA", "AA") == 0);

	assert(libsimple_strncmpnul(NULL, NULL, 5) == 0);
	assert(libsimple_strncmpnul(NULL, "", 5) < 0);
	assert(libsimple_strncmpnul("", NULL, 5) > 0);
	assert(libsimple_strncmpnul("", "", 5) == 0);
	assert(libsimple_strncmpnul(NULL, "x", 5) < 0);
	assert(libsimple_strncmpnul("x", NULL, 5) > 0);
	assert(libsimple_strncmpnul("x", "x", 5) == 0);
	assert(libsimple_strncmpnul("a", "b", 5) < 0);
	assert(libsimple_strncmpnul("b", "a", 5) > 0);
	assert(libsimple_strncmpnul("aa", "ab", 5) < 0);
	assert(libsimple_strncmpnul("ab", "aa", 5) > 0);
	assert(libsimple_strncmpnul("aa", "aa", 5) == 0);
	assert(libsimple_strncmpnul("A", "a", 5) < 0);
	assert(libsimple_strncmpnul("a", "A", 5) > 0);
	assert(libsimple_strncmpnul("AA", "Aa", 5) < 0);
	assert(libsimple_strncmpnul("Aa", "AA", 5) > 0);
	assert(libsimple_strncmpnul("AA", "AA", 5) == 0);
	assert(libsimple_strncmpnul("aa", "ab", 1) == 0);
	assert(libsimple_strncmpnul("ab", "aa", 1) == 0);
	assert(libsimple_strncmpnul("aa", "aa", 1) == 0);
	assert(libsimple_strncmpnul("AA", "Aa", 1) == 0);
	assert(libsimple_strncmpnul("Aa", "AA", 1) == 0);
	assert(libsimple_strncmpnul("AA", "AA", 1) == 0);
	assert(libsimple_strncmpnul(NULL, NULL, 0) == 0);
	assert(libsimple_strncmpnul(NULL, "", 0) < 0);
	assert(libsimple_strncmpnul("", NULL, 0) > 0);
	assert(libsimple_strncmpnul("", "", 0) == 0);
	assert(libsimple_strncmpnul(NULL, "x", 0) < 0);
	assert(libsimple_strncmpnul("x", NULL, 0) > 0);
	assert(libsimple_strncmpnul("x", "x", 0) == 0);
	assert(libsimple_strncmpnul("a", "b", 0) == 0);
	assert(libsimple_strncmpnul("b", "a", 0) == 0);
	assert(libsimple_strncmpnul("aa", "ab", 0) == 0);
	assert(libsimple_strncmpnul("ab", "aa", 0) == 0);
	assert(libsimple_strncmpnul("aa", "aa", 0) == 0);
	assert(libsimple_strncmpnul("A", "a", 0) == 0);
	assert(libsimple_strncmpnul("a", "A", 0) == 0);
	assert(libsimple_strncmpnul("AA", "Aa", 0) == 0);
	assert(libsimple_strncmpnul("Aa", "AA", 0) == 0);
	assert(libsimple_strncmpnul("AA", "AA", 0) == 0);

	assert(libsimple_strncasecmpnul(NULL, NULL, 5) == 0);
	assert(libsimple_strncasecmpnul(NULL, "", 5) < 0);
	assert(libsimple_strncasecmpnul("", NULL, 5) > 0);
	assert(libsimple_strncasecmpnul("", "", 5) == 0);
	assert(libsimple_strncasecmpnul(NULL, "x", 5) < 0);
	assert(libsimple_strncasecmpnul("x", NULL, 5) > 0);
	assert(libsimple_strncasecmpnul("x", "x", 5) == 0);
	assert(libsimple_strncasecmpnul("a", "b", 5) < 0);
	assert(libsimple_strncasecmpnul("b", "a", 5) > 0);
	assert(libsimple_strncasecmpnul("aa", "ab", 5) < 0);
	assert(libsimple_strncasecmpnul("ab", "aa", 5) > 0);
	assert(libsimple_strncasecmpnul("aa", "aa", 5) == 0);
	assert(libsimple_strncasecmpnul("A", "a", 5) == 0);
	assert(libsimple_strncasecmpnul("a", "A", 5) == 0);
	assert(libsimple_strncasecmpnul("AA", "Aa", 5) == 0);
	assert(libsimple_strncasecmpnul("Aa", "AA", 5) == 0);
	assert(libsimple_strncasecmpnul("AA", "AA", 5) == 0);
	assert(libsimple_strncasecmpnul("aa", "ab", 1) == 0);
	assert(libsimple_strncasecmpnul("ab", "aa", 1) == 0);
	assert(libsimple_strncasecmpnul("aa", "aa", 1) == 0);
	assert(libsimple_strncasecmpnul("AA", "Aa", 1) == 0);
	assert(libsimple_strncasecmpnul("Aa", "AA", 1) == 0);
	assert(libsimple_strncasecmpnul("AA", "AA", 1) == 0);
	assert(libsimple_strncasecmpnul(NULL, NULL, 0) == 0);
	assert(libsimple_strncasecmpnul(NULL, "", 0) < 0);
	assert(libsimple_strncasecmpnul("", NULL, 0) > 0);
	assert(libsimple_strncasecmpnul("", "", 0) == 0);
	assert(libsimple_strncasecmpnul(NULL, "x", 0) < 0);
	assert(libsimple_strncasecmpnul("x", NULL, 0) > 0);
	assert(libsimple_strncasecmpnul("x", "x", 0) == 0);
	assert(libsimple_strncasecmpnul("a", "b", 0) == 0);
	assert(libsimple_strncasecmpnul("b", "a", 0) == 0);
	assert(libsimple_strncasecmpnul("aa", "ab", 0) == 0);
	assert(libsimple_strncasecmpnul("ab", "aa", 0) == 0);
	assert(libsimple_strncasecmpnul("aa", "aa", 0) == 0);
	assert(libsimple_strncasecmpnul("A", "a", 0) == 0);
	assert(libsimple_strncasecmpnul("a", "A", 0) == 0);
	assert(libsimple_strncasecmpnul("AA", "Aa", 0) == 0);
	assert(libsimple_strncasecmpnul("Aa", "AA", 0) == 0);
	assert(libsimple_strncasecmpnul("AA", "AA", 0) == 0);

#ifdef libsimple_strdupa
	cs = "";
	s = libsimple_strdupa(cs);
	assert(s);
	assert(s != cs);
	assert(!strcmp(s, cs));

	cs = "xyz";
	s = libsimple_strdupa(cs);
	assert(s);
	assert(s != cs);
	assert(!strcmp(s, cs));
#else
	fprintf(stderr, "warning: libsimple_strdupa missing\n");
#endif

#ifdef libsimple_strndupa
	cs = "";
	s = libsimple_strndupa(cs, 5);
	assert(s);
	assert(s != cs);
	assert(!strcmp(s, ""));

	cs = "xyz";

	s = libsimple_strndupa(cs, 5);
	assert(s);
	assert(s != cs);
	assert(!strcmp(s, "xyz"));

	s = libsimple_strndupa(cs, 4);
	assert(s);
	assert(s != cs);
	assert(!strcmp(s, "xyz"));

	s = libsimple_strndupa(cs, 3);
	assert(s);
	assert(s != cs);
	assert(!strcmp(s, "xyz"));

	s = libsimple_strndupa(cs, 2);
	assert(s);
	assert(s != cs);
	assert(!strcmp(s, "xy"));

	s = libsimple_strndupa(cs, 1);
	assert(s);
	assert(s != cs);
	assert(!strcmp(s, "x"));

	s = libsimple_strndupa(cs, 0);
	assert(s);
	assert(s != cs);
	assert(!strcmp(s, ""));
#else
	fprintf(stderr, "warning: libsimple_strndupa missing\n");
#endif

#ifdef libsimple_memdupa
	cs = "xyz";
	for (n = 1; n < 4; n++) {
		s = libsimple_memdupa(cs, n);
		assert(s);
		assert(s != cs);
		assert(!memcmp(s, cs, n));
	}
#else
	fprintf(stderr, "warning: libsimple_memdupa missing\n");
#endif

#ifdef libsimple_aligned_memdupa
	cs = "xyz";
	for (n = 1; n < 4; n++) {
		s = libsimple_aligned_memdupa(cs, 4 + i, n);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % (4 + i)));
		assert(!memcmp(s, cs, n));
	}
#else
	fprintf(stderr, "warning: libsimple_aligned_memdupa missing\n");
#endif

	unsetenv("X");
	assert(!getenv("X"));
	assert(!libsimple_getenv_ne("X"));
	putenv("X=xyz");
	assert(!strcmpnul(getenv("X"), "xyz"));
	assert(!strcmpnul(libsimple_getenv_ne("X"), "xyz"));
	putenv("X=");
	assert(!strcmpnul(getenv("X"), ""));
	assert(!libsimple_getenv_ne("X"));

	unsetenv("X");
	assert(!getenv("X"));
	assert(!strcmpnul(libsimple_getenv_e("X"), ""));
	putenv("X=xyz");
	assert(!strcmpnul(getenv("X"), "xyz"));
	assert(!strcmpnul(libsimple_getenv_e("X"), "xyz"));
	putenv("X=");
	assert(!strcmpnul(getenv("X"), ""));
	assert(!strcmpnul(libsimple_getenv_e("X"), ""));

	assert(test_timespec(10.3000200010, 10, 300020001L, 10.300020001, "+10.300020001", "10.300020001"));
	assert(test_timespec(10.3000200014, 10, 300020001L, 10.300020001, "+10.300020001", "10.300020001"));
	assert(test_timespec(10.3000200015, 10, 300020002L, 10.300020002, "+10.300020002", "10.300020002"));
	assert(test_timespec(10.9999999999, 11, 0, 11, "+11.000000000", "11"));
	assert(test_timespec(-10.3000200010, -11, 699979999L, -10.300020001, "-10.300020001", "-10.300020001"));
	assert(test_timespec(-10.3000200014, -11, 699979999L, -10.300020001, "-10.300020001", "-10.300020001"));
	assert(test_timespec(-10.3000200015, -11, 699979998L, -10.300020002, "-10.300020002", "-10.300020002"));
	assert(test_timespec(-10.9999999999, -11, 0, -11, "-11.000000000", "-11"));
	assert(test_timespec(10, 10, 0, 10, "+10.000000000", "10"));
	assert(test_timespec(0, 0, 0, 0, "+0.000000000", "0"));
	assert(test_timespec(-10, -10, 0, -10, "-10.000000000", "-10"));

	assert(test_timeval(10.3000201000, 10, 300020L, 10.300020, "+10.300020", "10.30002"));
	assert(test_timeval(10.3000204000, 10, 300020L, 10.300020, "+10.300020", "10.30002"));
	assert(test_timeval(10.3000205000, 10, 300021L, 10.300021, "+10.300021", "10.300021"));
	assert(test_timeval(10.9999999000, 11, 0, 11, "+11.000000", "11"));
	assert(test_timeval(-10.3000201000, -11, 699980L, -10.300020, "-10.300020", "-10.30002"));
	assert(test_timeval(-10.3000204000, -11, 699980L, -10.300020, "-10.300020", "-10.30002"));
	assert(test_timeval(-10.3000205000, -11, 699979L, -10.300021, "-10.300021", "-10.300021"));
	assert(test_timeval(-10.9999999000, -11, 0, -11, "-11.000000", "-11"));
	assert(test_timeval(10, 10, 0, 10, "+10.000000", "10"));
	assert(test_timeval(0, 0, 0, 0, "+0.000000", "0"));
	assert(test_timeval(-10, -10, 0, -10, "-10.000000", "-10"));

	libsimple_timeval2timespec(&ts, &(struct timeval){0, 0L});
	assert(ts.tv_sec  == 0);
	assert(ts.tv_nsec == 0L);
	libsimple_timeval2timespec(&ts, &(struct timeval){0, 1L});
	assert(ts.tv_sec  == 0);
	assert(ts.tv_nsec == 1000L);
	libsimple_timeval2timespec(&ts, &(struct timeval){0, 999999L});
	assert(ts.tv_sec  == 0);
	assert(ts.tv_nsec == 999999000L);
	libsimple_timeval2timespec(&ts, &(struct timeval){10, 0L});
	assert(ts.tv_sec  == 10);
	assert(ts.tv_nsec == 0L);
	libsimple_timeval2timespec(&ts, &(struct timeval){10, 1L});
	assert(ts.tv_sec  == 10);
	assert(ts.tv_nsec == 1000L);
	libsimple_timeval2timespec(&ts, &(struct timeval){-10, 0L});
	assert(ts.tv_sec  == -10);
	assert(ts.tv_nsec == 0L);
	libsimple_timeval2timespec(&ts, &(struct timeval){-10, 1L});
	assert(ts.tv_sec  == -10);
	assert(ts.tv_nsec == 1000L);

	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 0, ts1.tv_nsec = 999999999L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 0, ts1.tv_nsec = 999999999L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 999999999L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 999999999L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 999999999L;
	ts2.tv_sec = 0, ts2.tv_nsec = 999999999L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 1, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 1, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 1, ts1.tv_nsec = 0L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 1, ts1.tv_nsec = 1L;
	ts2.tv_sec = 0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 0L;
	ts2.tv_sec = 1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 0, ts1.tv_nsec = 1L;
	ts2.tv_sec = 1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 1, ts1.tv_nsec = 0L;
	ts2.tv_sec = 1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 1, ts1.tv_nsec = 1L;
	ts2.tv_sec = 1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = 1, ts1.tv_nsec = 0L;
	ts2.tv_sec = 1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 1, ts1.tv_nsec = 1L;
	ts2.tv_sec = 1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec =  0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = -1, ts1.tv_nsec = 1L;
	ts2.tv_sec =  0, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec =  0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = -1, ts1.tv_nsec = 1L;
	ts2.tv_sec =  0, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec =  0, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec =  0, ts1.tv_nsec = 1L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec =  0, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec =  0, ts1.tv_nsec = 1L;
	ts2.tv_sec = -1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = -1, ts1.tv_nsec = 1L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = -1, ts1.tv_nsec = 1L;
	ts2.tv_sec = -1, ts2.tv_nsec = 1L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec = 0,        ts1.tv_nsec = 0L;
	ts2.tv_sec = TIME_MAX, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = 1,        ts1.tv_nsec = 0L;
	ts2.tv_sec = TIME_MAX, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);
	ts1.tv_sec = TIME_MAX, ts1.tv_nsec = 0L;
	ts2.tv_sec = TIME_MAX, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 0);
	ts1.tv_sec =  1, ts1.tv_nsec = 0L;
	ts2.tv_sec = -1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == 1);
	ts1.tv_sec = -1, ts1.tv_nsec = 0L;
	ts2.tv_sec =  1, ts2.tv_nsec = 0L;
	assert(libsimple_cmptimespec(&ts1, &ts2) == -1);

	tv1.tv_sec = 0, tv1.tv_usec = 0L;
	tv2.tv_sec = 0, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);
	tv1.tv_sec = 0, tv1.tv_usec = 1L;
	tv2.tv_sec = 0, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = 0, tv1.tv_usec = 999999L;
	tv2.tv_sec = 0, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = 0, tv1.tv_usec = 0L;
	tv2.tv_sec = 0, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = 0, tv1.tv_usec = 1L;
	tv2.tv_sec = 0, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);
	tv1.tv_sec = 0, tv1.tv_usec = 999999L;
	tv2.tv_sec = 0, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = 0, tv1.tv_usec = 0L;
	tv2.tv_sec = 0, tv2.tv_usec = 999999L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = 0, tv1.tv_usec = 1L;
	tv2.tv_sec = 0, tv2.tv_usec = 999999L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = 0, tv1.tv_usec = 999999L;
	tv2.tv_sec = 0, tv2.tv_usec = 999999L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);
	tv1.tv_sec = 1, tv1.tv_usec = 0L;
	tv2.tv_sec = 0, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = 1, tv1.tv_usec = 1L;
	tv2.tv_sec = 0, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = 1, tv1.tv_usec = 0L;
	tv2.tv_sec = 0, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = 1, tv1.tv_usec = 1L;
	tv2.tv_sec = 0, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = 0, tv1.tv_usec = 0L;
	tv2.tv_sec = 1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = 0, tv1.tv_usec = 1L;
	tv2.tv_sec = 1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = 0, tv1.tv_usec = 0L;
	tv2.tv_sec = 1, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = 0, tv1.tv_usec = 1L;
	tv2.tv_sec = 1, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = 1, tv1.tv_usec = 0L;
	tv2.tv_sec = 1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);
	tv1.tv_sec = 1, tv1.tv_usec = 1L;
	tv2.tv_sec = 1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = 1, tv1.tv_usec = 0L;
	tv2.tv_sec = 1, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = 1, tv1.tv_usec = 1L;
	tv2.tv_sec = 1, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);
	tv1.tv_sec = -1, tv1.tv_usec = 0L;
	tv2.tv_sec =  0, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = -1, tv1.tv_usec = 1L;
	tv2.tv_sec =  0, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = -1, tv1.tv_usec = 0L;
	tv2.tv_sec =  0, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = -1, tv1.tv_usec = 1L;
	tv2.tv_sec =  0, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec =  0, tv1.tv_usec = 0L;
	tv2.tv_sec = -1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec =  0, tv1.tv_usec = 1L;
	tv2.tv_sec = -1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec =  0, tv1.tv_usec = 0L;
	tv2.tv_sec = -1, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec =  0, tv1.tv_usec = 1L;
	tv2.tv_sec = -1, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = -1, tv1.tv_usec = 0L;
	tv2.tv_sec = -1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);
	tv1.tv_sec = -1, tv1.tv_usec = 1L;
	tv2.tv_sec = -1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = -1, tv1.tv_usec = 0L;
	tv2.tv_sec = -1, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = -1, tv1.tv_usec = 1L;
	tv2.tv_sec = -1, tv2.tv_usec = 1L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);
	tv1.tv_sec = 0,        tv1.tv_usec = 0L;
	tv2.tv_sec = TIME_MAX, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = 1,        tv1.tv_usec = 0L;
	tv2.tv_sec = TIME_MAX, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);
	tv1.tv_sec = TIME_MAX, tv1.tv_usec = 0L;
	tv2.tv_sec = TIME_MAX, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 0);
	tv1.tv_sec =  1, tv1.tv_usec = 0L;
	tv2.tv_sec = -1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == 1);
	tv1.tv_sec = -1, tv1.tv_usec = 0L;
	tv2.tv_sec =  1, tv2.tv_usec = 0L;
	assert(libsimple_cmptimeval(&tv1, &tv2) == -1);

#define ASSERT_ALIGNMENT(INFO, ALIGN)\
	do {\
		assert((INFO)->alignment <= lcm(cacheline, ALIGN));\
		assert(!((INFO)->alignment % (ALIGN)));\
		if ((cacheline - (ALIGN) % cacheline) % cacheline + (INFO)->size % (ALIGN) > cacheline)\
			assert(!((INFO)->alignment % cacheline));\
	} while (0)

	assert((ptr = libsimple_mallocz(0, 11)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 11);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);

	assert((ptr = libsimple_mallocz(1, 12)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 12);
		assert(info->zeroed == 12);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);

	assert((ptr = libsimple_emallocz(0, 13)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 13);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);

	assert((ptr = libsimple_emallocz(1, 14)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 14);
		assert(info->zeroed == 14);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);

	assert((ptr = libsimple_enmallocz(10, 0, 15)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 15);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);

	assert((ptr = libsimple_enmallocz(10, 1, 16)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 16);
		assert(info->zeroed == 16);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);

	assert((ptr = libsimple_aligned_allocz(0, 8, 8)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		ASSERT_ALIGNMENT(info, 8);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);

	assert((ptr = libsimple_aligned_allocz(1, 8, 16)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 16);
		ASSERT_ALIGNMENT(info, 8);
		assert(info->zeroed == 16);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert(!libsimple_posix_memalignz(&ptr, 0, 8 * sizeof(void *), 8));
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		ASSERT_ALIGNMENT(info, 8 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert(!libsimple_posix_memalignz(&ptr, 1, 4 * sizeof(void *), 16));
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 16);
		ASSERT_ALIGNMENT(info, 4 * sizeof(void *));
		assert(info->zeroed == 16);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_memalignz(0, 4, 9)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 9 || info->size == 12);
		ASSERT_ALIGNMENT(info, 4);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_memalignz(1, 2, 7)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 7 || info->size == 8);
		ASSERT_ALIGNMENT(info, 2);
		assert(info->zeroed == 7 || info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_memalign(2, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 || info->size == 6);
		ASSERT_ALIGNMENT(info, 2);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert(!libsimple_memalignzn(0, 128, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalignzn(1, 128, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalignn(128, 0) && errno == EINVAL);
	errno = 0;

	assert(!libsimple_memalignzn(0, 1024, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_memalignzn(1, 1024, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_memalignn(1024, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;

	assert(!libsimple_memalignz(0, 65, 100) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalignz(1, 65, 100) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalign(65, 100) && errno == EINVAL);
	errno = 0;

	assert(!libsimple_memalignzn(0, 65, 100, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalignzn(1, 65, 100, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalignn(65, 100, 0) && errno == EINVAL);
	errno = 0;

	assert(!libsimple_memalignz(0, 0, 100) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalignz(1, 0, 100) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalign(0, 100) && errno == EINVAL);
	errno = 0;

	assert(!libsimple_memalignzn(0, 0, 100, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalignzn(1, 0, 100, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_memalignn(0, 100, 0) && errno == EINVAL);
	errno = 0;

	assert((ptr = libsimple_memalignzn(0, 1, 9, 9, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 81);
		ASSERT_ALIGNMENT(info, 1);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_memalignzn(1, 2, 9, 9, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 162);
		ASSERT_ALIGNMENT(info, 2);
		assert(info->zeroed == 162);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_memalignn(4, 9, 9, 3, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 243 || info->size == 244);
		ASSERT_ALIGNMENT(info, 4);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_enmemalignz(1, 1, 2, 9)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 9 || info->size == 10);
		ASSERT_ALIGNMENT(info, 2);
		assert(info->zeroed == 9 || info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_ememalignz(1, 2, 7)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 7 || info->size == 8);
		ASSERT_ALIGNMENT(info, 2);
		assert(info->zeroed == 7 || info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_enmemalignz(1, 0, 2, 8)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		ASSERT_ALIGNMENT(info, 2);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_ememalignz(0, 4, 4)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4);
		ASSERT_ALIGNMENT(info, 4);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_enmemalign(1, 4, 8)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		ASSERT_ALIGNMENT(info, 4);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_ememalign(8, 3)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 3 || info->size == 8);
		ASSERT_ALIGNMENT(info, 8);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_vallocz(0, 9)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 9 || info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_vallocz(1, 7)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 7 || info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == 7 || info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_valloc(5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 || info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_vallocz(1, 3 * pagesize)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 3 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == 3 * pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_vallocz(0, 4 * pagesize)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_valloc(5 * pagesize)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_valloczn(1, 3 * pagesize, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 6 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == 6 * pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_valloczn(0, 4 * pagesize, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_vallocn(5 * pagesize, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 10 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert(!libsimple_valloczn(0, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_valloczn(1, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_vallocn(0) && errno == EINVAL);
	errno = 0;

	assert(!libsimple_valloczn(0, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_valloczn(1, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_vallocn(SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;

	assert((ptr = libsimple_pvallocz(0, 9)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvallocz(1, 7)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvalloc(5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 || info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvallocz(1, pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvallocz(1, pagesize)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvallocz(1, pagesize + 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 2 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == 2 * pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvallocz(1, 3 * pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 3 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == 3 * pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvallocz(0, 4 * pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvalloc(5 * pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvalloczn(1, 3 * pagesize - 1, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 6 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == 6 * pagesize);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvalloczn(0, 4 * pagesize - 1, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvallocn(5 * pagesize - 1, 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 10 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)info->alignment));
	}
	free(ptr);
	ptr = NULL;

	assert(!libsimple_pvalloczn(0, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_pvalloczn(1, 0) && errno == EINVAL);
	errno = 0;
	assert(!libsimple_pvallocn(0) && errno == EINVAL);
	errno = 0;

	assert(!libsimple_pvalloczn(0, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_pvalloczn(1, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;
	assert(!libsimple_pvallocn(SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;

	assert((ptr = libsimple_valloczn(0, 9, 9, pagesize - 1, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 81 * (pagesize - 1));
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_valloczn(1, 9, 8, pagesize - 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 72 * (pagesize - 2));
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_vallocn(9, (pagesize - 1), 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 9 * (pagesize - 1));
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_envallocz(1, 1, 5 * pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 * pagesize - 1);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_evallocz(1, 3 * pagesize + 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 3 * pagesize + 1);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_envallocz(1, 0, pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == pagesize - 1);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_evallocz(0, pagesize + 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == pagesize + 1);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_envalloc(1, 127)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 127);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_evalloc(3 * pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 3 * pagesize - 1);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_pvalloczn(0, 9, 9, pagesize - 1, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 81 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_pvalloczn(1, 9, 8, pagesize - 2, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 72 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_pvallocn(9, (pagesize - 1), 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 9 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert((ptr = libsimple_enpvallocz(1, 1, 5 * pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_epvallocz(1, 3 * pagesize + 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_enpvallocz(1, 0, pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_epvallocz(0, pagesize + 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 2 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_enpvalloc(1, 127)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_epvalloc(3 * pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 3 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enmallocz(5, 0, 20));
		assert(exit_status == 5);
		assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enmallocz(6, 1, 20));
		assert(exit_status == 6);
		assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 7;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_emallocz(0, 20));
		assert(exit_status == 7);
		assert_stderr("%s: malloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 8;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_emallocz(1, 20));
		assert(exit_status == 8);
		assert_stderr("%s: calloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(!(ptr = libsimple_mallocz(0, 20)) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(!(ptr = libsimple_mallocz(1, 20)) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(!(ptr = libsimple_aligned_allocz(0, 8, 8)) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(!(ptr = libsimple_aligned_allocz(1, 8, 16)) && errno == ENOMEM);
		assert(!alloc_fail_in);

		errno = 0;

		alloc_fail_in = 1;
		assert(libsimple_posix_memalignz(&ptr, 0, 4 * sizeof(void *), 8) == ENOMEM && !errno);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(libsimple_posix_memalignz(&ptr, 1, 16 * sizeof(void *), 16) == ENOMEM && !errno);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(!libsimple_memalignz(0, 4 * sizeof(void *), 8) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(!libsimple_memalignz(1, 16 * sizeof(void *), 16) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enmemalignz(3, 1, sizeof(void *), 4));
		assert(exit_status == 3);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 102;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ememalignz(1, sizeof(void *), 4));
		assert(exit_status == 102);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enmemalignz(5, 0, sizeof(void *), 4));
		assert(exit_status == 5);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 103;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ememalignz(0, sizeof(void *), 4));
		assert(exit_status == 103);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enmemalign(7, sizeof(void *), 4));
		assert(exit_status == 7);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 104;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ememalign(sizeof(void *), 4));
		assert(exit_status == 104);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert(!libsimple_vallocz(0, 8) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(!libsimple_vallocz(1, 16) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_envallocz(3, 1, 4));
		assert(exit_status == 3);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 102;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_evallocz(1, 4));
		assert(exit_status == 102);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_envallocz(5, 0, 4));
		assert(exit_status == 5);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 103;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_evallocz(0, 4));
		assert(exit_status == 103);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_envalloc(7, 4));
		assert(exit_status == 7);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 104;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_evalloc(4));
		assert(exit_status == 104);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert(!libsimple_pvallocz(0, 8) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert(!libsimple_pvallocz(1, 16) && errno == ENOMEM);
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enpvallocz(3, 1, 4));
		assert(exit_status == 3);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 102;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_epvallocz(1, 4));
		assert(exit_status == 102);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enpvallocz(5, 0, 4));
		assert(exit_status == 5);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 103;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_epvallocz(0, 4));
		assert(exit_status == 103);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enpvalloc(7, 4));
		assert(exit_status == 7);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 104;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_epvalloc(4));
		assert(exit_status == 104);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	assert_exit_ptr(libsimple_enmemalignz(3, 1, 0, 4));
	assert(exit_status == 3);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));

	libsimple_default_failure_exit = 102;
	assert_exit_ptr(libsimple_ememalignz(1, 0, 4));
	assert(exit_status == 102);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));
	assert(!alloc_fail_in);

	assert_exit_ptr(libsimple_enmemalignz(5, 0, 0, 4));
	assert(exit_status == 5);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));

	libsimple_default_failure_exit = 103;
	assert_exit_ptr(libsimple_ememalignz(0, 0, 4));
	assert(exit_status == 103);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));
	assert(!alloc_fail_in);

	assert_exit_ptr(libsimple_enmemalign(7, 0, 4));
	assert(exit_status == 7);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));

	libsimple_default_failure_exit = 104;
	assert_exit_ptr(libsimple_ememalign(0, 4));
	assert(exit_status == 104);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));
	libsimple_default_failure_exit = 1;

	assert_exit_ptr(libsimple_enmemalignz(3, 1, 3, 4));
	assert(exit_status == 3);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));

	libsimple_default_failure_exit = 102;
	assert_exit_ptr(libsimple_ememalignz(1, 3, 4));
	assert(exit_status == 102);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));
	assert(!alloc_fail_in);

	assert_exit_ptr(libsimple_enmemalignz(5, 0, 3, 4));
	assert(exit_status == 5);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));

	libsimple_default_failure_exit = 103;
	assert_exit_ptr(libsimple_ememalignz(0, 3, 4));
	assert(exit_status == 103);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));
	assert(!alloc_fail_in);

	assert_exit_ptr(libsimple_enmemalign(7, 3, 4));
	assert(exit_status == 7);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));

	libsimple_default_failure_exit = 104;
	assert_exit_ptr(libsimple_ememalign(3, 4));
	assert(exit_status == 104);
	assert_stderr("%s: libsimple_vmemalignz: %s\n", argv0, strerror(EINVAL));
	libsimple_default_failure_exit = 1;

	assert(libsimple_memeq("abcxyz", "abc123", 3));
	assert(!libsimple_memeq("abcxyz", "abc123", 4));
	assert(libsimple_memeq("abcxyz", "abcx23", 4));
	assert(libsimple_memeq("1", "2", 0));
	assert(!libsimple_memeq("1", "2", 1));
	assert(!libsimple_memeq("abc", "ABC", 3));
	assert(!libsimple_memeq("ABC", "abc", 3));
	assert(libsimple_memeq("ABC", "ABC", 3));

	assert(libsimple_memcaseeq("abcxyz", "abc123", 3));
	assert(!libsimple_memcaseeq("abcxyz", "abc123", 4));
	assert(libsimple_memcaseeq("abcxyz", "abcx23", 4));
	assert(libsimple_memcaseeq("1", "2", 0));
	assert(!libsimple_memcaseeq("1", "2", 1));
	assert(libsimple_memcaseeq("abc", "ABC", 3));
	assert(libsimple_memcaseeq("ABC", "abc", 3));
	assert(libsimple_memcaseeq("ABC", "ABC", 3));

	stpcpy(buf, "abc123");
	assert(!strcmpnul(libsimple_mempset(buf, '.', 3), "123"));
	assert(!strcmp(buf, "...123"));

#ifdef libsimple_asprintfa
	s = libsimple_asprintfa("%sxyz%s", "abc", "123");
	assert(s);
	assert(!strcmp(s, "abcxyz123"));
#else
	fprintf(stderr, "warning: libsimple_asprintfa missing\n");
#endif

#ifdef libsimple_vasprintfa
	assert(test_vasprintfa("abcxyz123", "%sxyz%s", "abc", "123"));
#else
	fprintf(stderr, "warning: libsimple_vasprintfa missing\n");
#endif

	{
		char a[] = "abcdefgh", b[] = "abcdefgh";
		assert(libsimple_strreqlen("", "") == 0);
		assert(libsimple_strreqlen("x", "") == 0);
		assert(libsimple_strreqlen("x", "y") == 0);
		assert(libsimple_strreqlen("", "y") == 0);
		for (i = 0; i <= 8; i++) {
			for (j = 0; j <= 8; j++) {
				assert(libsimple_strreqlen(&a[i], &b[j]) == 8 - (i > j ? i : j));
				a[i] = b[j] = '\0';
				assert(libsimple_strreqlen(a, b) == (i == j ? i : 0));
				a[i] = "abcdefgh"[i];
				b[j] = "abcdefgh"[j];
			}
		}
		assert(libsimple_strreqlen("abc", "ABC") == 0);
		assert(libsimple_strreqlen("123", "123") == 3);
	}

	{
		char a[] = "abcdefgh", b[] = "ABCDEFGH";
		assert(libsimple_strrcaseeqlen("", "") == 0);
		assert(libsimple_strrcaseeqlen("x", "") == 0);
		assert(libsimple_strrcaseeqlen("x", "y") == 0);
		assert(libsimple_strrcaseeqlen("", "y") == 0);
		for (i = 0; i <= 8; i++) {
			for (j = 0; j <= 8; j++) {
				assert(libsimple_strrcaseeqlen(&a[i], &b[j]) == 8 - (i > j ? i : j));
				assert(libsimple_strrcaseeqlen(&b[i], &a[j]) == 8 - (i > j ? i : j));
				a[i] = b[j] = '\0';
				assert(libsimple_strrcaseeqlen(a, b) == (i == j ? i : 0));
				assert(libsimple_strrcaseeqlen(b, a) == (i == j ? i : 0));
				a[i] = "abcdefgh"[i];
				b[j] = "ABCDEFGH"[j];
			}
		}
		assert(libsimple_strrcaseeqlen("abc", "abc") == 3);
		assert(libsimple_strrcaseeqlen("123", "123") == 3);
	}

	for (n = 0; n < 10; n++) {
		char a[] = "abcdefgh", b[] = "abcdefgh";
		size_t I, J;
		assert(libsimple_strrneqlen("", "", n) == 0);
		assert(libsimple_strrneqlen("x", "", n) == 0);
		assert(libsimple_strrneqlen("x", "y", n) == 0);
		assert(libsimple_strrneqlen("", "y", n) == 0);
		for (i = 0; i <= 8; i++) {
			for (j = 0; j <= 8; j++) {
				I = 8 - i;
				J = 8 - j;
				assert(libsimple_strrneqlen(&a[i], &b[j], n) == (I == J ? MIN(I,n) : MIN(I,J) * (n >= MAX(I,J))));
				a[i] = b[j] = '\0';
				assert(libsimple_strrneqlen(a, b, n) == (MIN(i, n) == MIN(j, n) ? MIN(i, n) : 0));
				a[i] = "abcdefgh"[i];
				b[j] = "abcdefgh"[j];
			}
		}
		assert(libsimple_strrneqlen("abc", "ABC", n) == 0);
		assert(libsimple_strrneqlen("123", "123", n) == MIN(3, n));
	}

	for (n = 0; n < 10; n++) {
		char a[] = "abcdefgh", b[] = "ABCDEFGH";
		size_t I, J;
		assert(libsimple_strrncaseeqlen("", "", n) == 0);
		assert(libsimple_strrncaseeqlen("x", "", n) == 0);
		assert(libsimple_strrncaseeqlen("x", "y", n) == 0);
		assert(libsimple_strrncaseeqlen("", "y", n) == 0);
		for (i = 0; i <= 8; i++) {
			for (j = 0; j <= 8; j++) {
				I = 8 - i;
				J = 8 - j;
				assert(libsimple_strrncaseeqlen(&a[i], &b[j], n) == (I == J ? MIN(I,n) : MIN(I,J) * (n >= MAX(I,J))));
				assert(libsimple_strrncaseeqlen(&b[i], &a[j], n) == (I == J ? MIN(I,n) : MIN(I,J) * (n >= MAX(I,J))));
				a[i] = b[j] = '\0';
				assert(libsimple_strrncaseeqlen(a, b, n) == (MIN(i, n) == MIN(j, n) ? MIN(i, n) : 0));
				assert(libsimple_strrncaseeqlen(b, a, n) == (MIN(i, n) == MIN(j, n) ? MIN(i, n) : 0));
				a[i] = "abcdefgh"[i];
				b[j] = "ABCDEFGH"[j];
			}
		}
		assert(libsimple_strrncaseeqlen("abc", "abc", n) == MIN(3, n));
		assert(libsimple_strrncaseeqlen("123", "123", n) == MIN(3, n));
	}

	{
		char p_[4096];
		char *p = p_;

		memset(p, 0, sizeof(p_));
		assert(libsimple_memsetelem(p, &(uint64_t){~0}, 0, 0) == p);
		assert(libsimple_memsetelem(p, &(uint64_t){~0}, 0, 10) == p);
		assert(libsimple_memsetelem(p, &(uint64_t){~0}, 1, 0) == p);
		assert(libsimple_memsetelem(p, &(uint64_t){~0}, 2, 0) == p);
		assert(libsimple_memsetelem(p, &(uint64_t){~0}, 4, 0) == p);
		assert(libsimple_memsetelem(p, &(uint64_t){~0}, 8, 0) == p);
		assert(libsimple_memsetelem(p, &(uint64_t){~0}, 16, 0) == p);
		assert(libsimple_memsetelem(p, &(uint64_t){~0}, 3, 0) == p);
		assert(libsimple_memsetelem(p, &(uint8_t){0x09}, 1, 3000) == p);
		assert(libsimple_memsetelem(p, &(uint16_t){0x0807}, 2, 1000) == p);
		assert(libsimple_memsetelem(p, &(uint32_t){0x10203040UL}, 4, 300) == p);
		assert(libsimple_memsetelem(p, &(uint64_t){0x0102030450607080ULL}, 8, 100) == p);
		assert(libsimple_memsetelem(p, (char []){0xA0, 0xB0, 0xC0}, 3, 16) == p);

		for (i = 0; i < 48; i++)
			assert(p[i] == ((char []){0xA0, 0xB0, 0xC0})[i % 3]);
		for (; i < 800; i += 8)
			assert(*(uint64_t *)&p[i] == 0x0102030450607080ULL);
		for (; i < 1200; i += 4)
			assert(*(uint32_t *)&p[i] == 0x10203040UL);
		for (; i < 2000; i += 2)
			assert(*(uint16_t *)&p[i] == 0x0807);
		for (; i < 3000; i++)
			assert(p[i] == 0x09);
		for (; i < sizeof(p_); i++)
			assert(p[i] == 0);
	}

	if (!have_custom_malloc()) {
		stderr_real = 1;
		fprintf(stderr, "\nSome tests have not been ran because malloc(3) was not "
		                "replaced, this is normal if running under valgrind(1).\n\n");
	}
	return 0;
}

#endif
