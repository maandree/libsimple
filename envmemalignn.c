/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void *libsimple_envmemalignn(int, size_t, size_t, va_list);


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested via libsimple_enmemalignn */
}

#endif