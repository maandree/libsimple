/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strreplace(char *, int, int);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strreplace(buf, 'o', 'x') == &buf[11]);
	assert(!memcmp(buf, "hellx wxrld\0goodbye world", 26));

	return 0;
}

#endif
