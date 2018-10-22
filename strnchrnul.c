/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strnchrnul(const char *s_, int c_, size_t n)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	char *end = &s[n];
	for (; s != end && *s && *s != c; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strnchrnul("abcABCabcABC", 'a', 13), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_strnchrnul("abcABCabcABC", 'c', 13), "cABCabcABC"));
	assert(!strcmpnul(libsimple_strnchrnul("abcABCabcABC", 'A', 13), "ABCabcABC"));
	assert(!strcmpnul(libsimple_strnchrnul("abcABCabcABC", 'C', 13), "CabcABC"));
	assert(!strcmpnul(libsimple_strnchrnul("ABCabcABCabc", 'a', 13), "abcABCabc"));
	assert(!strcmpnul(libsimple_strnchrnul("ABCabcABCabc", 'c', 13), "cABCabc"));
	assert(!strcmpnul(libsimple_strnchrnul("ABCabcABCabc", 'A', 13), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_strnchrnul("ABCabcABCabc", 'C', 13), "CabcABCabc"));
	assert(!strcmpnul(libsimple_strnchrnul("abcABCabcABC", 'x', 13), ""));
	assert(!strcmpnul(libsimple_strnchrnul("abcABCabcABC", 'x', 20), ""));
	assert(!strcmpnul(libsimple_strnchrnul("abcABCabcABC", '\0', 13), ""));
	assert(!strcmpnul(libsimple_strnchrnul("abcABCabcABC", '\0', 20), ""));
	assert(!strcmpnul(libsimple_strnchrnul("abcABCabcABC", '\0', 3), "ABCabcABC"));
	assert(!strcmpnul(libsimple_strnchrnul("abcdef", 'd', 3), "def"));
	assert(!strcmpnul(libsimple_strnchrnul("abcdef", 'e', 3), "def"));
	assert(!strcmpnul(libsimple_strnchrnul("123123", '1', 7), "123123"));
	assert(!strcmpnul(libsimple_strnchrnul("123123", '3', 7), "3123"));
	return 0;
}

#endif
