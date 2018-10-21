/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrchr(const void *s_, int c_, size_t n)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	while (s[--n] != c);
	return &s[n];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemrchr("abcABCabcABC", 'a', sizeof("abcABCabcABC") - 1), "abcABC"));
	assert(!strcmpnul(libsimple_rawmemrchr("abcABCabcABC", 'c', sizeof("abcABCabcABC") - 1), "cABC"));
	assert(!strcmpnul(libsimple_rawmemrchr("abcABCabcABC", 'A', sizeof("abcABCabcABC") - 1), "ABC"));
	assert(!strcmpnul(libsimple_rawmemrchr("abcABCabcABC", 'C', sizeof("abcABCabcABC") - 1), "C"));
	assert(!strcmpnul(libsimple_rawmemrchr("ABCabcABCabc", 'a', sizeof("ABCabcABCabc") - 1), "abc"));
	assert(!strcmpnul(libsimple_rawmemrchr("ABCabcABCabc", 'c', sizeof("ABCabcABCabc") - 1), "c"));
	assert(!strcmpnul(libsimple_rawmemrchr("ABCabcABCabc", 'A', sizeof("ABCabcABCabc") - 1), "ABCabc"));
	assert(!strcmpnul(libsimple_rawmemrchr("ABCabcABCabc", 'C', sizeof("ABCabcABCabc") - 1), "Cabc"));
	return 0;
}

#endif
