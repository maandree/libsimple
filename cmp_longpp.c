/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmp_longpp(long int *const *, long int *const *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
