/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrcasechr_inv(const void *s_, int c, size_t n) /* TODO man */
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
	assert(!strcmpnul(libsimple_rawmemrcasechr_inv("aabbaabb", 'b', 8), "abb"));
	assert(!strcmpnul(libsimple_rawmemrcasechr_inv("aabbaabb", 'B', 8), "abb"));
	assert(!strcmpnul(libsimple_rawmemrcasechr_inv("AABBAABB", 'b', 8), "ABB"));
	assert(!strcmpnul(libsimple_rawmemrcasechr_inv("AABBAABB", 'B', 8), "ABB"));
	assert(!strcmpnul(libsimple_rawmemrcasechr_inv("aabbaabb", 'a', 8), "b"));
	assert(!strcmpnul(libsimple_rawmemrcasechr_inv("aabbbb\0", '\0', 8), "b"));
	return 0;
}

#endif
