/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


unsigned char
libsimple_strtouhh(const char *restrict nptr, char **restrict end, int base) /* TODO test, man */
{
	unsigned long int r = strtoul(nptr, end, base);
	if(r > UCHAR_MAX) {
		r = UCHAR_MAX;
		errno = ERANGE;
	}
	return (unsigned char)r;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
