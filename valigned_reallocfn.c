/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_valigned_reallocfn(void *, size_t, size_t, va_list); /* TODO test (aligned_reallocfn) */


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
