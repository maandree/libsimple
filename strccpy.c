/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strccpy(char *restrict, const char *restrict, int);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
