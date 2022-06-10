/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST

#define RET_MAX 255ULL


uint_least8_t
libsimple_strtou8(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	uintmax_t r = strtoumax(nptr, end, base);
	if(r > RET_MAX) {
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
	return 0;
}

#endif
