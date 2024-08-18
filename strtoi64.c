/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 9223372036854775807LL
#define RET_MIN (-RET_MAX - 1LL)


int_least64_t
libsimple_strtoi64(const char *restrict nptr, char **restrict end, int base)
{
	intmax_t r = strtoimax(nptr, end, base);
	if (r < RET_MIN) {
		r = RET_MIN;
		errno = ERANGE;
	} else if (r > RET_MAX) {
		r = RET_MAX;
		errno = ERANGE;
	}
	return (int_least64_t)r;
}


#else
#include "test.h"

int
main(void)
{
	char *e;
	errno = 0;
	assert(strtoi64("0x7FFFFFFFFFFFFFFF", NULL, 0) == INT64_C(0x7FFFFFFFFFFFFFFF) && !errno);
	assert(strtoi64("0x7FFFFFFFFFFFFFFF", NULL, 16) == INT64_C(0x7FFFFFFFFFFFFFFF) && !errno);
	assert(strtoi64("7FFFFFFFFFFFFFFF", NULL, 16) == INT64_C(0x7FFFFFFFFFFFFFFF) && !errno);
	assert(strtoi64("0x7FFFFFFFFFFFFFFF", NULL, 10) == 0 && !errno);
	assert(strtoi64("0x7FFFFFFFFFFFFFFF", &e, 0) == INT64_C(0x7FFFFFFFFFFFFFFF) && !*e && !errno);
	assert(strtoi64("0x7FFFFFFFFFFFFFFF ", &e, 16) == INT64_C(0x7FFFFFFFFFFFFFFF) && *e == ' ' && !errno);
	assert(strtoi64("0x7FFFFFFFFFFFFFFF", &e, 10) == 0 && *e == 'x' && !errno);
	assert(strtoi64("9223372036854775807", &e, 10) == INT64_C(0x7FFFFFFFFFFFFFFF) && !*e && !errno);
	assert(strtoi64("-9223372036854775807", &e, 10) == INT64_C(-9223372036854775807) && !*e && !errno);
	assert(strtoi64("-9223372036854775808", &e, 10) == INT64_C(-9223372036854775808) && !*e && !errno);
	assert(strtoi64("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtoi64("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtoi64("01234", &e, 0) == 01234 && !*e && !errno);
	assert(strtoi64("9223372036854775808", &e, 10) == INT64_C(9223372036854775807) && !*e && errno == ERANGE);
	errno = 0;
	assert(strtoi64("-9223372036854775809", &e, 10) == INT64_C(-9223372036854775808) && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtoi64("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
