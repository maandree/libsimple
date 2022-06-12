/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strtoupper(char *, const char *);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strtoupper(&buf[3], &buf[0]), "ABCDEABCDE12345"));
	assert(!strcmp(buf, "abcABCDEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strtoupper(&buf[0], &buf[3]), "DEABCDE12345"));
	assert(!strcmp(buf, "DEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strtoupper(&buf[0], &buf[0]), "ABCDEABCDE12345"));
	assert(!strcmp(buf, "ABCDEABCDE12345"));

	return 0;
}

#endif
