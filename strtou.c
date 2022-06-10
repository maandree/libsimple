/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


unsigned int
libsimple_strtou(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	signed long int r = strtoul(nptr, end, base);
	if(r > UINT_MAX) {
		r = UINT_MAX;
		errno = ERANGE;
	}
	return (unsigned int)r;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
