/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 2147483647LL
#define RET_MIN (-RET_MAX - 1LL)


int_least32_t
libsimple_strtoi32(const char *restrict nptr, char **restrict end, int base)
{
	intmax_t r = strtoimax(nptr, end, base);
	if (r < RET_MIN) {
		r = RET_MIN;
		errno = ERANGE;
	} else if (r > RET_MAX) {
		r = RET_MAX;
		errno = ERANGE;
	}
	return (int_least32_t)r;
}


#else
#include "test.h"

int
main(void)
{
	char *e;
	errno = 0;
	assert(strtoi32("0x7FFFFFFF", NULL, 0) == INT32_C(0x7FFFFFFF) && !errno);
	assert(strtoi32("0x7FFFFFFF", NULL, 16) == INT32_C(0x7FFFFFFF) && !errno);
	assert(strtoi32("7FFFFFFF", NULL, 16) == INT32_C(0x7FFFFFFF) && !errno);
	assert(strtoi32("0x7FFFFFFF", NULL, 10) == 0 && !errno);
	assert(strtoi32("0x7FFFFFFF", &e, 0) == INT32_C(0x7FFFFFFF) && !*e && !errno);
	assert(strtoi32("0x7FFFFFFF ", &e, 16) == INT32_C(0x7FFFFFFF) && *e == ' ' && !errno);
	assert(strtoi32("0x7FFFFFFF", &e, 10) == 0 && *e == 'x' && !errno);
	assert(strtoi32("2147483647", &e, 10) == INT32_C(0x7FFFFFFF) && !*e && !errno);
	assert(strtoi32("-2147483647", &e, 10) == INT32_C(-2147483647) && !*e && !errno);
	assert(strtoi32("-2147483648", &e, 10) == INT32_C(-2147483648) && !*e && !errno);
	assert(strtoi32("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtoi32("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtoi32("01234", &e, 0) == 01234 && !*e && !errno);
	assert(strtoi32("2147483648", &e, 10) == INT32_C(2147483647) && !*e && errno == ERANGE);
	errno = 0;
	assert(strtoi32("-2147483649", &e, 10) == INT32_C(-2147483648) && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtoi32("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
