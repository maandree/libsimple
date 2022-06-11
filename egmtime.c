/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void libsimple_egmtime(struct tm *, struct timespec *);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
