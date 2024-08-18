/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmp_intptrp(const intptr_t *, const intptr_t *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
