/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_evcallocn(size_t, va_list);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
