/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemcasechr(const void *s_, int c)
{
	char *s = *(char **)(void *)&s_;
	c = tolower(c);
	for (; tolower(*s) != c; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemcasechr("abcABCabcABC", 'a'), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_rawmemcasechr("abcABCabcABC", 'c'), "cABCabcABC"));
	assert(!strcmpnul(libsimple_rawmemcasechr("abcABCabcABC", 'A'), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_rawmemcasechr("abcABCabcABC", 'C'), "cABCabcABC"));
	assert(!strcmpnul(libsimple_rawmemcasechr("ABCabcABCabc", 'a'), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_rawmemcasechr("ABCabcABCabc", 'c'), "CabcABCabc"));
	assert(!strcmpnul(libsimple_rawmemcasechr("ABCabcABCabc", 'A'), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_rawmemcasechr("ABCabcABCabc", 'C'), "CabcABCabc"));
	return 0;
}

#endif
