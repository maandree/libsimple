/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strnreplace(char *, int, int, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnreplace(buf, 'o', 'x', SIZE_MAX) == &buf[11]);
	assert(!memcmp(buf, "hellx wxrld\0goodbye world", 26));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnreplace(buf, 'o', 'x', 12) == &buf[11]);
	assert(!memcmp(buf, "hellx wxrld\0goodbye world", 26));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnreplace(buf, 'o', 'x', 11) == &buf[11]);
	assert(!memcmp(buf, "hellx wxrld\0goodbye world", 26));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnreplace(buf, 'o', 'x', 6) == &buf[6]);
	assert(!memcmp(buf, "hellx world\0goodbye world", 26));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnreplace(buf, 'o', 'x', 5) == &buf[5]);
	assert(!memcmp(buf, "hellx world\0goodbye world", 26));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnreplace(buf, 'o', 'x', 4) == &buf[4]);
	assert(!memcmp(buf, "hello world\0goodbye world", 26));

	return 0;
}

#endif
