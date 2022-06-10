/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST

#define RET_MAX 2147483647LL
#define RET_MIN (-RET_MAX - 1LL)


int_least32_t
libsimple_strtoi32(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	intmax_t r = strtoimax(nptr, end, base);
	if(r < RET_MIN) {
		r = RET_MIN;
		errno = ERANGE;
	} else if(r > RET_MAX) {
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
	return 0;
}

#endif
