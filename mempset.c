/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_mempset(void *, int, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(buf, "abc123");
	assert(!strcmpnul(libsimple_mempset(buf, '.', 3), "123"));
	assert(!strcmp(buf, "...123"));

	return 0;
}

#endif
