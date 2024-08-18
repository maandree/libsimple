/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 255ULL


uint_least8_t
libsimple_strtou8(const char *restrict nptr, char **restrict end, int base)
{
	uintmax_t r = strtoumax(nptr, end, base);
	if (r > RET_MAX) {
		r = RET_MAX;
		errno = ERANGE;
	}
	return (uint_least8_t)r;
}


#else
#include "test.h"

int
main(void)
{
	char *e;
	errno = 0;
	assert(strtou8("0xFF", NULL, 0) == UINT8_C(0xFF) && !errno);
	assert(strtou8("0xFF", NULL, 16) == UINT8_C(0xFF) && !errno);
	assert(strtou8("FF", NULL, 16) == UINT8_C(0xFF) && !errno);
	assert(strtou8("0xFF", NULL, 10) == 0 && !errno);
	assert(strtou8("0xFF", &e, 0) == UINT8_C(0xFF) && !*e && !errno);
	assert(strtou8("0xFF ", &e, 16) == UINT8_C(0xFF) && *e == ' ' && !errno);
	assert(strtou8("0xFF", &e, 10) == 0 && *e == 'x' && !errno);
	assert(strtou8("255", &e, 10) == UINT8_C(0xFF) && !*e && !errno);
	assert(strtou8("12", &e, 10) == 12 && !*e && !errno);
	assert(strtou8("12", &e, 8) == 012 && !*e && !errno);
	assert(strtou8("012", &e, 0) == 012 && !*e && !errno);
	assert(strtou8("256", &e, 10) == UINT8_C(255) && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtou8("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
