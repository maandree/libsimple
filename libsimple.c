/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int libsimple_default_failure_exit = 1;


#else
#include "test.h"

int
main(void)
{
	const char *cs;
	char buf[1024], *s;
	int intarray[10];
	size_t i, n;

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

	return 0;
}

#endif
