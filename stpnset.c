/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_stpnset(char *, int, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_stpnset(buf, 'x', SIZE_MAX) == &buf[11]);
	assert(!strcmp(buf, "xxxxxxxxxxx"));
	assert(!strcmp(&buf[12], "goodbye world"));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_stpnset(buf, '\0', SIZE_MAX) == &buf[11]);
	assert(!memcmp(buf, "\0\0\0\0\0\0\0\0\0\0\0\0goodbye world", 26));


	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_stpnset(buf, 'x', 5) == &buf[5]);
	assert(!strcmp(buf, "xxxxx world"));
	assert(!strcmp(&buf[12], "goodbye world"));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_stpnset(buf, '\0', 5) == &buf[5]);
	assert(!memcmp(buf, "\0\0\0\0\0 world\0goodbye world", 26));

	return 0;
}

#endif
