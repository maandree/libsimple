/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memrcasechr_inv(const void *s_, int c, size_t n_)
{
	char *s = *(char **)(void *)&s_;
	ssize_t n = n_;
	c = tolower(c);
	while (n-- && tolower(s[n]) == c);
	return n < 0 ? NULL : &s[n];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memrcasechr_inv("aabbaabb", 'b', 8), "abb"));
	assert(!strcmpnul(libsimple_memrcasechr_inv("aabbaabb", 'B', 8), "abb"));
	assert(!strcmpnul(libsimple_memrcasechr_inv("AABBAABB", 'b', 8), "ABB"));
	assert(!strcmpnul(libsimple_memrcasechr_inv("AABBAABB", 'B', 8), "ABB"));
	assert(!strcmpnul(libsimple_memrcasechr_inv("aabbaabb", 'a', 8), "b"));
	assert(!strcmpnul(libsimple_memrcasechr_inv("aabbbb\0", '\0', 8), "b"));
	assert(!strcmpnul(libsimple_memrcasechr_inv("--------", '-', 8), NULL));
	return 0;
}

#endif
