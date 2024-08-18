/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 32767LL
#define RET_MIN (-RET_MAX - 1LL)


int_least16_t
libsimple_strtoi16(const char *restrict nptr, char **restrict end, int base)
{
	intmax_t r = strtoimax(nptr, end, base);
	if (r < RET_MIN) {
		r = RET_MIN;
		errno = ERANGE;
	} else if (r > RET_MAX) {
		r = RET_MAX;
		errno = ERANGE;
	}
	return (int_least16_t)r;
}


#else
#include "test.h"

int
main(void)
{
	char *e;
	errno = 0;
	assert(strtoi16("0x7FFF", NULL, 0) == INT16_C(0x7FFF) && !errno);
	assert(strtoi16("0x7FFF", NULL, 16) == INT16_C(0x7FFF) && !errno);
	assert(strtoi16("7FFF", NULL, 16) == INT16_C(0x7FFF) && !errno);
	assert(strtoi16("0x7FFF", NULL, 10) == 0 && !errno);
	assert(strtoi16("0x7FFF", &e, 0) == INT16_C(0x7FFF) && !*e && !errno);
	assert(strtoi16("0x7FFF ", &e, 16) == INT16_C(0x7FFF) && *e == ' ' && !errno);
	assert(strtoi16("0x7FFF", &e, 10) == 0 && *e == 'x' && !errno);
	assert(strtoi16("32767", &e, 10) == INT16_C(0x7FFF) && !*e && !errno);
	assert(strtoi16("-32767", &e, 10) == INT16_C(-32767) && !*e && !errno);
	assert(strtoi16("-32768", &e, 10) == INT16_C(-32768) && !*e && !errno);
	assert(strtoi16("1234", &e, 10) == 1234 && !*e && !errno);
	assert(strtoi16("1234", &e, 8) == 01234 && !*e && !errno);
	assert(strtoi16("01234", &e, 0) == 01234 && !*e && !errno);
	assert(strtoi16("32768", &e, 10) == INT16_C(32767) && !*e && errno == ERANGE);
	errno = 0;
	assert(strtoi16("-32769", &e, 10) == INT16_C(-32768) && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtoi16("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
