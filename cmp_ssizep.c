/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_cmp_ssizep(const ssize_t *, const ssize_t *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
