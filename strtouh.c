/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


unsigned short int
libsimple_strtouh(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	unsigned long int r = strtoul(nptr, end, base);
	if(r > USHRT_MAX) {
		r = USHRT_MAX;
		errno = ERANGE;
	}
	return (unsigned short int)r;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
