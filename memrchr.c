/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


void *
libsimple_memrchr(const void *s_, int c, size_t n_)
{
	char *s = *(char **)(void *)&s_;
	ssize_t n = n_;
	while (n-- && (int)s[n] != c);
	return n < 0 ? NULL : &s[n];
}


#ifdef TEST
#include <assert.h>

int
main(void)
{
	assert(!strcmp(libsimple_memrchr("1234512345", '3', sizeof("1234512345") - 1), "345"));
	assert(!strcmp(libsimple_memrchr("1234512345", '5', sizeof("1234512345") - 1), "5"));
	assert(!libsimple_memrchr("1234512345", 'x', sizeof("1234512345") - 1));
	return 0;
}

#endif
