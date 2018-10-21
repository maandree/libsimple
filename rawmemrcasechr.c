/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrcasechr(const void *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	c = tolower(c);
	while (--n, tolower(s[n]) != c);
	return &s[n];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemrcasechr("abcABCabcABC", 'a', sizeof("abcABCabcABC") - 1), "ABC"));
	assert(!strcmpnul(libsimple_rawmemrcasechr("abcABCabcABC", 'c', sizeof("abcABCabcABC") - 1), "C"));
	assert(!strcmpnul(libsimple_rawmemrcasechr("abcABCabcABC", 'A', sizeof("abcABCabcABC") - 1), "ABC"));
	assert(!strcmpnul(libsimple_rawmemrcasechr("abcABCabcABC", 'C', sizeof("abcABCabcABC") - 1), "C"));
	assert(!strcmpnul(libsimple_rawmemrcasechr("ABCabcABCabc", 'a', sizeof("ABCabcABCabc") - 1), "abc"));
	assert(!strcmpnul(libsimple_rawmemrcasechr("ABCabcABCabc", 'c', sizeof("ABCabcABCabc") - 1), "c"));
	assert(!strcmpnul(libsimple_rawmemrcasechr("ABCabcABCabc", 'A', sizeof("ABCabcABCabc") - 1), "abc"));
	assert(!strcmpnul(libsimple_rawmemrcasechr("ABCabcABCabc", 'C', sizeof("ABCabcABCabc") - 1), "c"));
	return 0;
}

#endif
