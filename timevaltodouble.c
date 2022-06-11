/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline double libsimple_timevaltodouble(const struct timeval *); /* TODO tested in libsimple.c */


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
