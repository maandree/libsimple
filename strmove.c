/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strmove(char *, const char *);


#else
#include "test.h"

int
main(void)
{
	char buf[1024];

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_strmove(&buf[3], buf) == &buf[3]);
	assert(!strcmp(buf, "helhello world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_strmove(buf, &buf[3]) == buf);
	assert(!strcmp(buf, "lo world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_strmove(buf, buf) == buf);
	assert(!strcmp(buf, "hello world"));

	return 0;
}

#endif
