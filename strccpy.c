/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strccpy(char *restrict, const char *restrict, int);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strccpy(buf, "hello", '\0') == &buf[6]);
	assert(!strcmp(buf, "hello"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strccpy(buf, "hello", 'o') == &buf[5]);
	assert(!strcmp(buf, "hello"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strccpy(buf, "hello", 'l') == &buf[3]);
	assert(!strcmp(buf, "hel"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strccpy(buf, "hello", 'x') == NULL);
	assert(!strcmp(buf, "hello"));

	return 0;
}

#endif
