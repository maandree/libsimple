/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmp_int_least8pp(int_least8_t *const *, int_least8_t *const *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif