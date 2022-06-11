/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_mempcpy(void *restrict, const void *restrict, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(buf, "abcxyz");
	assert(libsimple_mempcpy(buf, "123", 3) == &buf[3]);
	assert(!strcmpnul(buf, "123xyz"));

	return 0;
}

#endif
