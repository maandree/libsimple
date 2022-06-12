/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strset(char *, int);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strset(buf, 'x') == buf);
	assert(!strcmp(buf, "xxxxxxxxxxx"));
	assert(!strcmp(&buf[12], "goodbye world"));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_strset(buf, '\0') == buf);
	assert(!memcmp(buf, "\0\0\0\0\0\0\0\0\0\0\0\0goodbye world", 26));

	return 0;
}

#endif
