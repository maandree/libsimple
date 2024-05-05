/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmp_int32pp(int32_t *const *, int32_t *const *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
