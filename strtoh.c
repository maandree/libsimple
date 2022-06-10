/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


signed short int
libsimple_strtoh(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	signed long int r = strtol(nptr, end, base);
	if(r < SHRT_MIN) {
		r = SHRT_MIN;
		errno = ERANGE;
	} else if(r > SHRT_MAX) {
		r = SHRT_MAX;
		errno = ERANGE;
	}
	return (signed short int)r;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
