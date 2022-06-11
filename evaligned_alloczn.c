/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_evaligned_alloczn(int, size_t, size_t, va_list);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
