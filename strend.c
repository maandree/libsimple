/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strend(const char *);


#else
#include "test.h"

int
main(void)
{
	assert(strcmpnul(libsimple_strend("abc\0xyz"), "xyz"));
	return 0;
}

#endif
