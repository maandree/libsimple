/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrcasechr_inv(const void *s_, int c, size_t n) /* TODO test, man */
{
	char *s = *(char **)(void *)&s_;
	c = tolower(c);
	while (--n, tolower(s[n]) == c);
	return &s[n];
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
