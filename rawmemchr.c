/* See LICENSE file for copyright and license details. */
#include "common.h"
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
	assert(!strcmpnul(libsimple_rawmemchr("abcABCabcABC", 'a'), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_rawmemchr("abcABCabcABC", 'c'), "cABCabcABC"));
	assert(!strcmpnul(libsimple_rawmemchr("abcABCabcABC", 'A'), "ABCabcABC"));
	assert(!strcmpnul(libsimple_rawmemchr("abcABCabcABC", 'C'), "CabcABC"));
	assert(!strcmpnul(libsimple_rawmemchr("ABCabcABCabc", 'a'), "abcABCabc"));
	assert(!strcmpnul(libsimple_rawmemchr("ABCabcABCabc", 'c'), "cABCabc"));
	assert(!strcmpnul(libsimple_rawmemchr("ABCabcABCabc", 'A'), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_rawmemchr("ABCabcABCabc", 'C'), "CabcABCabc"));
	return 0;
}

#endif
