/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_inchrset(int, const char *);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_inchrset('a', "xyz") == 0);
	assert(libsimple_inchrset('b', "xyz") == 0);
	assert(libsimple_inchrset('c', "xyz") == 0);
	assert(libsimple_inchrset('x', "xyz") == 1);
	assert(libsimple_inchrset('y', "xyz") == 1);
	assert(libsimple_inchrset('z', "xyz") == 1);
	assert(libsimple_inchrset('\0', "xyz") == 0);
	return 0;
}

#endif
