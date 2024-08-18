/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 65535ULL


uint_least16_t
libsimple_strtou16(const char *restrict nptr, char **restrict end, int base)
{
	uintmax_t r = strtoumax(nptr, end, base);
	if (r > RET_MAX) {
		r = RET_MAX;
		errno = ERANGE;
	}
	return (uint_least16_t)r;
}


#else
#include "test.h"

int
main(void)
{
	char *e;
	errno = 0;
	assert(strtou16("0xFFFF", NULL, 0) == UINT16_C(0xFFFF) && !errno);
	assert(strtou16("0xFFFF", NULL, 16) == UINT16_C(0xFFFF) && !errno);
	assert(strtou16("FFFF", NULL, 16) == UINT16_C(0xFFFF) && !errno);
	assert(strtou16("0xFFFF", NULL, 10) == 0 && !errno);
	assert(strtou16("0xFFFF", &e, 0) == UINT16_C(0xFFFF) && !*e && !errno);
	assert(strtou16("0xFFFF ", &e, 16) == UINT16_C(0xFFFF) && *e == ' ' && !errno);
	assert(strtou16("0xFFFF", &e, 10) == 0 && *e == 'x' && !errno);
	assert(strtou16("65535", &e, 10) == UINT16_C(0xFFFF) && !*e && !errno);
	assert(strtou16("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtou16("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtou16("01234", &e, 0) == 01234 && !*e && !errno);
	assert(strtou16("65536", &e, 10) == UINT16_C(65535) && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtou16("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
