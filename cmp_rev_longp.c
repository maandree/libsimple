/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmp_rev_longp(const long int *, const long int *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif