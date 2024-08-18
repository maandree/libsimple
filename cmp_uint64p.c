/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmp_uint64p(const uint64_t *, const uint64_t *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
