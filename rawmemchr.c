/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


void *
libsimple_rawmemchr(const void *s_, int c)
{
	char *s = *(char **)(void *)&s_;
	while ((int)*s++ != c);
	return &s[-1];
}


#ifdef TEST
#include <assert.h>

int
main(void)
{
	assert(!strcmp(libsimple_rawmemchr("1234512345", '3'), "34512345"));
	assert(!strcmp(libsimple_rawmemchr("1234512345", '1'), "1234512345"));
	return 0;
}

#endif
