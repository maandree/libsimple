/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void libsimple_venprintf(int, const char *, va_list);


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested via libsimple_enprintf */
}

#endif
