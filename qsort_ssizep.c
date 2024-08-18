/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void libsimple_qsort_ssizep(ssize_t *[], size_t);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
