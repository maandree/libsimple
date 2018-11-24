/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrchr_inv(const void *s_, int c_, size_t n)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	while (s[--n] == c);
	return &s[n];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemrchr_inv("aabbaabb", 'b', 8), "abb"));
	assert(!strcmpnul(libsimple_rawmemrchr_inv("aabbaabb", 'B', 8), "b"));
	assert(!strcmpnul(libsimple_rawmemrchr_inv("AABBAABB", 'b', 8), "B"));
	assert(!strcmpnul(libsimple_rawmemrchr_inv("AABBAABB", 'B', 8), "ABB"));
	assert(!strcmpnul(libsimple_rawmemrchr_inv("aabbaabb", 'a', 8), "b"));
	assert(!strcmpnul(libsimple_rawmemrchr_inv("aabbbb\0", '\0', 8), "b"));
	return 0;
}

#endif
