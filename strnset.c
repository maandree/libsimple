/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strnset(char *, int, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnset(buf, 'x', SIZE_MAX) == buf);
	assert(!strcmp(buf, "xxxxxxxxxxx"));
	assert(!strcmp(&buf[12], "goodbye world"));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnset(buf, '\0', SIZE_MAX) == buf);
	assert(!memcmp(buf, "\0\0\0\0\0\0\0\0\0\0\0\0goodbye world", 26));


	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnset(buf, 'x', 5) == buf);
	assert(!strcmp(buf, "xxxxx world"));
	assert(!strcmp(&buf[12], "goodbye world"));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strnset(buf, '\0', 5) == buf);
	assert(!memcmp(buf, "\0\0\0\0\0 world\0goodbye world", 26));

	return 0;
}

#endif
