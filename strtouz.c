/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline size_t libsimple_strtouz(const char *restrict nptr, char **restrict end, int base); /* TODO test, man */


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
