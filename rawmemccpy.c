/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void *libsimple_rawmemccpy(void *restrict, const void *restrict, int);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemccpy(buf, "hello", 'o') == &buf[5]);
	assert(!strncmp(buf, "hellox", 6));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemccpy(buf, "hello", 'l') == &buf[3]);
	assert(!strncmp(buf, "helx", 4));

	return 0;
}

#endif
