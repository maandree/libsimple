/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void * libsimple_memreplace(void *, int, int, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_memreplace(buf, 'o', 'x', 46) == &buf[46]);
	assert(!memcmp(buf, "hellx wxrld\0gxxdbye wxrld", 26));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_memreplace(buf, 'o', 'x', 12) == &buf[12]);
	assert(!memcmp(buf, "hellx wxrld\0goodbye world", 26));

	return 0;
}

#endif
