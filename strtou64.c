/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#define RET_MAX 18446744073709551615ULL


uint_least64_t
libsimple_strtou64(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	uintmax_t r = strtoumax(nptr, end, base);
#if UINTMAX_MAX > RET_MAX
	if(r > RET_MAX) {
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
	return 0;
}

#endif
