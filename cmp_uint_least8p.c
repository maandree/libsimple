/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmp_uint_least8p(const uint_least8_t *, const uint_least8_t *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif