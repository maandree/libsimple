/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 65535ULL


uint_least16_t
libsimple_strtou16(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	uintmax_t r = strtoumax(nptr, end, base);
	if(r > RET_MAX) {
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
	return 0;
}

#endif
