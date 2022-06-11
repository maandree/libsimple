/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline char *libsimple_strnccpy(char *restrict, const char *restrict, int, size_t);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
