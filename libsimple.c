/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


#else
#include "test.h"

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
LIBSIMPLE_GCC_ONLY__(__attribute__((__format__(__printf__, 2, 3))))
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
	void *ptr, *old;
	const char *cs;
	const wchar_t *cws;
	char *s;
	wchar_t *ws;
	size_t i, n;
	DEFINE_PAGESIZE;
	DEFINE_CACHELINE;

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

#define X1 0
#define X2 0, 0
#define X3 0, 0, 0
	assert(ELEMSOF((char []){X1}) == 1);
	assert(ELEMSOF((char []){X2}) == 2);
	assert(ELEMSOF((char []){X3}) == 3);
	assert(ELEMSOF((short int []){X3}) == 3);
	assert(ELEMSOF((int []){X3}) == 3);
	assert(ELEMSOF((long int []){X3}) == 3);
	assert(ELEMSOF((float []){X3}) == 3);
	assert(ELEMSOF((double []){X3}) == 3);
#undef X1
#undef X2
#undef X3

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
		assert(!((uintptr_t)s % _Alignof(max_align_t)));
		assert(!memcmp(s, cs, n));
	}
#else
	fprintf(stderr, "warning: libsimple_memdupa missing\n");
#endif

#ifdef libsimple_aligned_memdupa
	cs = "xyz";
	for (n = 1; n < 4; n++) {
		for (i = 1; i < 5; i++) {
			s = libsimple_aligned_memdupa(cs, i, n);
			assert(s);
			assert(s != cs);
			assert(!((uintptr_t)s % i));
			assert(!memcmp(s, cs, n));
		}
	}
#else
	fprintf(stderr, "warning: libsimple_aligned_memdupa missing\n");
#endif

#ifdef libsimple_aligned_strdupa
	for (i = 1; i < 5; i++) {
		cs = "";
		s = libsimple_aligned_strdupa(cs, i);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % i));
		assert(!strcmp(s, cs));

		cs = "xyz";
		s = libsimple_aligned_strdupa(cs, i);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % i));
		assert(!strcmp(s, cs));
	}
#else
	fprintf(stderr, "warning: libsimple_aligned_strdupa missing\n");
#endif

#ifdef libsimple_aligned_strndupa
	for (i = 1; i < 5; i++) {
		cs = "";
		s = libsimple_aligned_strndupa(cs, i, 5);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % i));
		assert(!strcmp(s, ""));

		cs = "xyz";

		s = libsimple_aligned_strndupa(cs, i, 5);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % i));
		assert(!strcmp(s, "xyz"));

		s = libsimple_aligned_strndupa(cs, i, 4);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % i));
		assert(!strcmp(s, "xyz"));

		s = libsimple_aligned_strndupa(cs, i, 3);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % i));
		assert(!strcmp(s, "xyz"));

		s = libsimple_aligned_strndupa(cs, i, 2);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % i));
		assert(!strcmp(s, "xy"));

		s = libsimple_aligned_strndupa(cs, i, 1);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % i));
		assert(!strcmp(s, "x"));

		s = libsimple_aligned_strndupa(cs, i, 0);
		assert(s);
		assert(s != cs);
		assert(!((uintptr_t)s % i));
		assert(!strcmp(s, ""));
	}
#else
	fprintf(stderr, "warning: libsimple_aligned_strndupa missing\n");
#endif

#ifdef libsimple_wcsdupa
	cws = L"";
	ws = libsimple_wcsdupa(cws);
	assert(ws);
	assert(ws != cws);
	assert(!((uintptr_t)ws % _Alignof(wchar_t)));
	assert(!wcscmp(ws, cws));

	cws = L"xyz";
	ws = libsimple_wcsdupa(cws);
	assert(ws);
	assert(ws != cws);
	assert(!((uintptr_t)ws % _Alignof(wchar_t)));
	assert(!wcscmp(ws, cws));
#else
	fprintf(stderr, "warning: libsimple_wcsdupa missing\n");
#endif

#ifdef libsimple_wcsndupa
	cws = L"";
	ws = libsimple_wcsndupa(cws, 5);
	assert(ws);
	assert(ws != cws);
	assert(!((uintptr_t)ws % _Alignof(wchar_t)));
	assert(!wcscmp(ws, L""));

	cws = L"xyz";

	ws = libsimple_wcsndupa(cws, 5);
	assert(ws);
	assert(ws != cws);
	assert(!((uintptr_t)ws % _Alignof(wchar_t)));
	assert(!wcscmp(ws, L"xyz"));

	ws = libsimple_wcsndupa(cws, 4);
	assert(ws);
	assert(ws != cws);
	assert(!((uintptr_t)ws % _Alignof(wchar_t)));
	assert(!wcscmp(ws, L"xyz"));

	ws = libsimple_wcsndupa(cws, 3);
	assert(ws);
	assert(ws != cws);
	assert(!((uintptr_t)ws % _Alignof(wchar_t)));
	assert(!wcscmp(ws, L"xyz"));

	ws = libsimple_wcsndupa(cws, 2);
	assert(ws);
	assert(ws != cws);
	assert(!((uintptr_t)ws % _Alignof(wchar_t)));
	assert(!wcscmp(ws, L"xy"));

	ws = libsimple_wcsndupa(cws, 1);
	assert(ws);
	assert(ws != cws);
	assert(!((uintptr_t)ws % _Alignof(wchar_t)));
	assert(!wcscmp(ws, L"x"));

	ws = libsimple_wcsndupa(cws, 0);
	assert(ws);
	assert(ws != cws);
	assert(!((uintptr_t)ws % _Alignof(wchar_t)));
	assert(!wcscmp(ws, L""));
#else
	fprintf(stderr, "warning: libsimple_wcsndupa missing\n");
#endif

#ifdef libsimple_wmemdupa
	cws = L"xyz";
	for (n = 1; n < 4; n++) {
		ws = libsimple_wmemdupa(cws, n);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % _Alignof(wchar_t)));
		assert(!wmemcmp(ws, cws, n));
	}
#else
	fprintf(stderr, "warning: libsimple_wmemdupa missing\n");
#endif

#ifdef libsimple_aligned_wmemdupa
	cws = L"xyz";
	for (n = 1; n < 4; n++) {
		for (i = 1; i < 5; i++) {
			ws = libsimple_aligned_wmemdupa(cws, i, n);
			assert(ws);
			assert(ws != cws);
			assert(!((uintptr_t)ws % i));
			assert(!wmemcmp(ws, cws, n));
		}
	}
#else
	fprintf(stderr, "warning: libsimple_aligned_wmemdupa missing\n");
#endif

#ifdef libsimple_aligned_wcsdupa
	for (i = 1; i < 5; i++) {
		cws = L"";
		ws = libsimple_aligned_wcsdupa(cws, i);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % i));
		assert(!wcscmp(ws, cws));

		cws = L"xyz";
		ws = libsimple_aligned_wcsdupa(cws, i);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % i));
		assert(!wcscmp(ws, cws));
	}
#else
	fprintf(stderr, "warning: libsimple_aligned_wcsdupa missing\n");
#endif

#ifdef libsimple_aligned_wcsndupa
	for (i = 1; i < 5; i++) {
		cws = L"";
		ws = libsimple_aligned_wcsndupa(cws, i, 5);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % i));
		assert(!wcscmp(ws, L""));

		cws = L"xyz";

		ws = libsimple_aligned_wcsndupa(cws, i, 5);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % i));
		assert(!wcscmp(ws, L"xyz"));

		ws = libsimple_aligned_wcsndupa(cws, i, 4);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % i));
		assert(!wcscmp(ws, L"xyz"));

		ws = libsimple_aligned_wcsndupa(cws, i, 3);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % i));
		assert(!wcscmp(ws, L"xyz"));

		ws = libsimple_aligned_wcsndupa(cws, i, 2);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % i));
		assert(!wcscmp(ws, L"xy"));

		ws = libsimple_aligned_wcsndupa(cws, i, 1);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % i));
		assert(!wcscmp(ws, L"x"));

		ws = libsimple_aligned_wcsndupa(cws, i, 0);
		assert(ws);
		assert(ws != cws);
		assert(!((uintptr_t)ws % i));
		assert(!wcscmp(ws, L""));
	}
#else
	fprintf(stderr, "warning: libsimple_aligned_wcsndupa missing\n");
#endif

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

	assert(!libsimple_vallocn(0) && errno == EINVAL);
	errno = 0;

	assert(!libsimple_vallocn(SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;

	assert((ptr = libsimple_vallocn(9, (pagesize - 1), 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 9 * (pagesize - 1));
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

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

#ifdef LIBSIMPLE_HAVE_ALIGNED_REALLOC
	assert((ptr = libsimple_aligned_realloc(NULL, 16, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 || info->size == info->alignment);
		assert(!info->zeroed);
		ASSERT_ALIGNMENT(info, 16);
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_aligned_realloc(old = ptr, 32, 10)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 10 || info->size == info->alignment);
		assert(!info->zeroed);
		ASSERT_ALIGNMENT(info, 32);
		assert(ptr != old);
		free(old);
	}
	free(ptr);
	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert(!libsimple_aligned_realloc(NULL, 8, 1) && errno == ENOMEM);
		assert(!alloc_fail_in);
	}
#else
	assert(libsimple_aligned_realloc(NULL, 8, 1) && errno == ENOSYS);
#endif

#ifdef LIBSIMPLE_HAVE_ALIGNED_REALLOC
	assert((ptr = libsimple_aligned_reallocarray(NULL, 16, 5, 3)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 15 || info->size == info->alignment);
		assert(!info->zeroed);
		ASSERT_ALIGNMENT(info, 16);
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_aligned_reallocarray(old = ptr, 32, 10, 2)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 20 || info->size == info->alignment);
		assert(!info->zeroed);
		ASSERT_ALIGNMENT(info, 32);
		assert(ptr != old);
		free(old);
	}
	free(ptr);
	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert(!libsimple_aligned_reallocarray(NULL, 8, 1, 1) && errno == ENOMEM);
		assert(!alloc_fail_in);
	}
#else
	assert(libsimple_aligned_reallocarray(NULL, 8, 1, 1) && errno == ENOSYS);
#endif

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


	if (!have_custom_malloc()) {
		stderr_real = 1;
		fprintf(stderr, "\nSome tests have not been ran because malloc(3) was not "
		                "replaced, this is normal if running under valgrind(1).\n\n");
	}
	return 0;
}

#endif
