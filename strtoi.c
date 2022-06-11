/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


signed int
libsimple_strtoi(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	signed long int r = strtol(nptr, end, base);
	if(r < INT_MIN) {
		r = INT_MIN;
		errno = ERANGE;
	} else if(r > INT_MAX) {
		r = INT_MAX;
		errno = ERANGE;
	}
	return (signed int)r;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
