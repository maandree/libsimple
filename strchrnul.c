/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_strchrnul(const char *s_, int c)
{
	char *s = *(char **)(void *)&s_;
	for (; *s && (int)*s != c; s++);
	return s;
}


#ifdef TEST
#include <assert.h>

int
main(void)
{
	assert(!strcmp(libsimple_strchrnul("1234512345", '3'), "34512345"));
	assert(!strcmp(libsimple_strchrnul("1234512345", '1'), "1234512345"));
	assert(!strcmp(libsimple_strchrnul("1234512345", 'x'), ""));
	return 0;
}

#endif
