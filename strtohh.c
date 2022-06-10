/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


signed char
libsimple_strtohh(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	signed long int r = strtol(nptr, end, base);
	if(r < SCHAR_MIN) {
		r = SCHAR_MIN;
		errno = ERANGE;
	} else if(r > SCHAR_MAX) {
		r = SCHAR_MAX;
		errno = ERANGE;
	}
	return (signed char)r;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
