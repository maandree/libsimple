/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void *libsimple_memtolower(void *, const void *, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_memtolower(&buf[3], &buf[0], 16), "abcdeabcde12345"));
	assert(!strcmp(buf, "ABCabcdeabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_memtolower(&buf[0], &buf[3], 13), "deabcde12345"));
	assert(!strcmp(buf, "deabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_memtolower(&buf[0], &buf[0], 16), "abcdeabcde12345"));
	assert(!strcmp(buf, "abcdeabcde12345"));

	return 0;
}

#endif
