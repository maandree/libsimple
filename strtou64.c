/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 18446744073709551615ULL


uint_least64_t
libsimple_strtou64(const char *restrict nptr, char **restrict end, int base)
{
	uintmax_t r = strtoumax(nptr, end, base);
#if UINTMAX_MAX > RET_MAX
	if (r > RET_MAX) {
		r = RET_MAX;
		errno = ERANGE;
	}
#endif
	return (uint_least64_t)r;
}


#else
#include "test.h"

int
main(void)
{
	char *e;
	errno = 0;
	assert(strtou64("0xFFFFFFFFFFFFFFFF", NULL, 0) == UINT64_C(0xFFFFFFFFFFFFFFFF) && !errno);
	assert(strtou64("0xFFFFFFFFFFFFFFFF", NULL, 16) == UINT64_C(0xFFFFFFFFFFFFFFFF) && !errno);
	assert(strtou64("FFFFFFFFFFFFFFFF", NULL, 16) == UINT64_C(0xFFFFFFFFFFFFFFFF) && !errno);
	assert(strtou64("0xFFFFFFFFFFFFFFFF", NULL, 10) == 0 && !errno);
	assert(strtou64("0xFFFFFFFFFFFFFFFF", &e, 0) == UINT64_C(0xFFFFFFFFFFFFFFFF) && !*e && !errno);
	assert(strtou64("0xFFFFFFFFFFFFFFFF ", &e, 16) == UINT64_C(0xFFFFFFFFFFFFFFFF) && *e == ' ' && !errno);
	assert(strtou64("0xFFFFFFFFFFFFFFFF", &e, 10) == 0 && *e == 'x' && !errno);
	assert(strtou64("18446744073709551615", &e, 10) == UINT64_C(0xFFFFFFFFFFFFFFFF) && !*e && !errno);
	assert(strtou64("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtou64("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtou64("01234", &e, 0) == 01234 && !*e && !errno);
	assert(strtou64("18446744073709551616", &e, 10) == UINT64_C(18446744073709551615) && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtou64("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
