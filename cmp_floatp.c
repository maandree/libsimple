/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmp_floatp(const float *, const float *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif