/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


void *
libsimple_rawmemrchr(const void *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	while ((int)s[--n] != c);
	return &s[n];
}


#ifdef TEST
#include <assert.h>

int
main(void)
{
	assert(!strcmp(libsimple_rawmemrchr("1234512345", '3', sizeof("1234512345") - 1), "345"));
	assert(!strcmp(libsimple_rawmemrchr("1234512345", '5', sizeof("1234512345") - 1), "5"));
	return 0;
}

#endif
