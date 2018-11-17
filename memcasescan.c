/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memcasescan(const void *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	size_t i = 0;
	c = tolower(c);
	for (; i < n && tolower(s[i]) != c; i++);
	return &s[i];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memcasescan("abcABCabcABC", 'a', sizeof("abcABCabcABC") - 1), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_memcasescan("abcABCabcABC", 'c', sizeof("abcABCabcABC") - 1), "cABCabcABC"));
	assert(!strcmpnul(libsimple_memcasescan("abcABCabcABC", 'A', sizeof("abcABCabcABC") - 1), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_memcasescan("abcABCabcABC", 'C', sizeof("abcABCabcABC") - 1), "cABCabcABC"));
	assert(!strcmpnul(libsimple_memcasescan("ABCabcABCabc", 'a', sizeof("ABCabcABCabc") - 1), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_memcasescan("ABCabcABCabc", 'c', sizeof("ABCabcABCabc") - 1), "CabcABCabc"));
	assert(!strcmpnul(libsimple_memcasescan("ABCabcABCabc", 'A', sizeof("ABCabcABCabc") - 1), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_memcasescan("ABCabcABCabc", 'C', sizeof("ABCabcABCabc") - 1), "CabcABCabc"));
	assert(!strcmpnul(libsimple_memcasescan("abcABCabcABC", 'x', sizeof("abcABCabcABC") - 1), ""));
	return 0;
}

#endif
