/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemchr(const void *s_, int c_)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	while (*s++ != c);
	return &s[-1];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemchr("1234512345", '3'), "34512345"));
	assert(!strcmpnul(libsimple_rawmemchr("1234512345", '1'), "1234512345"));
	return 0;
}

#endif
