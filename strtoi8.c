/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 127LL
#define RET_MIN (-RET_MAX - 1LL)


int_least8_t
libsimple_strtoi8(const char *restrict nptr, char **restrict end, int base)
{
	intmax_t r = strtoimax(nptr, end, base);
	if (r < RET_MIN) {
		r = RET_MIN;
		errno = ERANGE;
	} else if (r > RET_MAX) {
		r = RET_MAX;
		errno = ERANGE;
	}
	return (int_least8_t)r;
}


#else
#include "test.h"

int
main(void)
{
	char *e;
	errno = 0;
	assert(strtoi8("0x7F", NULL, 0) == INT8_C(0x7F) && !errno);
	assert(strtoi8("0x7F", NULL, 16) == INT8_C(0x7F) && !errno);
	assert(strtoi8("7F", NULL, 16) == INT8_C(0x7F) && !errno);
	assert(strtoi8("0x7F", NULL, 10) == 0 && !errno);
	assert(strtoi8("0x7F", &e, 0) == INT8_C(0x7F) && !*e && !errno);
	assert(strtoi8("0x7F ", &e, 16) == INT8_C(0x7F) && *e == ' ' && !errno);
	assert(strtoi8("0x7F", &e, 10) == 0 && *e == 'x' && !errno);
	assert(strtoi8("127", &e, 10) == INT8_C(0x7F) && !*e && !errno);
	assert(strtoi8("-127", &e, 10) == INT8_C(-127) && !*e && !errno);
	assert(strtoi8("-128", &e, 10) == INT8_C(-128) && !*e && !errno);
	assert(strtoi8("12", &e, 10) == 12 && !*e && !errno);
	assert(strtoi8("12", &e, 8) == 012 && !*e && !errno);
	assert(strtoi8("012", &e, 0) == 012 && !*e && !errno);
	assert(strtoi8("128", &e, 10) == INT8_C(127) && !*e && errno == ERANGE);
	errno = 0;
	assert(strtoi8("-129", &e, 10) == INT8_C(-128) && !*e && errno == ERANGE);
	errno = 0;
	assert(!strtoi8("1", &e, -10000) && errno == EINVAL);
	errno = 0;
	return 0;
}

#endif
