/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void *libsimple_vcallocn(size_t, va_list);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
