/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void libsimple__enprintf(int, const char *, ...); /* TODO test */


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
