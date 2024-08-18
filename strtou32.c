/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 4294967295ULL


uint_least32_t
libsimple_strtou32(const char *restrict nptr, char **restrict end, int base)
{
	uintmax_t r = strtoumax(nptr, end, base);
	if (r > RET_MAX) {
		r = RET_MAX;
		errno = ERANGE;
	}
	return (uint_least32_t)r;
}


#else
#include "test.h"

int
main(void)
{
	char *e;
	errno = 0;
	assert(strtou32("0xFFFFFFFF", NULL, 0) == UINT32_C(0xFFFFFFFF) && !errno);
	assert(strtou32("0xFFFFFFFF", NULL, 16) == UINT32_C(0xFFFFFFFF) && !errno);
	assert(strtou32("FFFFFFFF", NULL, 16) == UINT32_C(0xFFFFFFFF) && !errno);
	assert(strtou32("0xFFFFFFFF", NULL, 10) == 0 && !errno);
	assert(strtou32("0xFFFFFFFF", &e, 0) == UINT32_C(0xFFFFFFFF) && !*e && !errno);
	assert(strtou32("0xFFFFFFFF ", &e, 16) == UINT32_C(0xFFFFFFFF) && *e == ' ' && !errno);
	assert(strtou32("0xFFFFFFFF", &e, 10) == 0 && *e == 'x' && !errno);
	assert(strtou32("4294967295", &e, 10) == UINT32_C(0xFFFFFFFF) && !*e && !errno);
	assert(strtou32("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtou32("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtou32("01234", &e, 0) == 01234 && !*e && !errno);
	assert(strtou32("4294967296", &e, 10) == UINT32_C(4294967295) && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtou32("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
