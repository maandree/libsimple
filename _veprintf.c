/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void libsimple__veprintf(const char *, va_list);


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested via libsimple__eprintf */
}

#endif
