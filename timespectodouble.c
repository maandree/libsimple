/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline double libsimple_timespectodouble(const struct timespec *); /* TODO tested in libsimple.c */


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
