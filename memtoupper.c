/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_memtoupper(void *, const void *, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_memtoupper(&buf[3], &buf[0], 16), "ABCDEABCDE12345"));
	assert(!strcmp(buf, "abcABCDEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_memtoupper(&buf[0], &buf[3], 13), "DEABCDE12345"));
	assert(!strcmp(buf, "DEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_memtoupper(&buf[0], &buf[0], 16), "ABCDEABCDE12345"));
	assert(!strcmp(buf, "ABCDEABCDE12345"));

	return 0;
}

#endif
