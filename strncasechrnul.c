/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strncasechrnul(const char *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	char *end = &s[n];
	c = tolower(c);
	for (; s != end && *s && tolower(*s) != c; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strncasechrnul("abcABCabcABC", 'a', 13), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_strncasechrnul("abcABCabcABC", 'c', 13), "cABCabcABC"));
	assert(!strcmpnul(libsimple_strncasechrnul("abcABCabcABC", 'A', 13), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_strncasechrnul("abcABCabcABC", 'C', 13), "cABCabcABC"));
	assert(!strcmpnul(libsimple_strncasechrnul("ABCabcABCabc", 'a', 13), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_strncasechrnul("ABCabcABCabc", 'c', 13), "CabcABCabc"));
	assert(!strcmpnul(libsimple_strncasechrnul("ABCabcABCabc", 'A', 13), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_strncasechrnul("ABCabcABCabc", 'C', 13), "CabcABCabc"));
	assert(!strcmpnul(libsimple_strncasechrnul("abcABCabcABC", 'x', 13), ""));
	assert(!strcmpnul(libsimple_strncasechrnul("abcABCabcABC", 'x', 20), ""));
	assert(!strcmpnul(libsimple_strncasechrnul("abcABCabcABC", '\0', 13), ""));
	assert(!strcmpnul(libsimple_strncasechrnul("abcABCabcABC", '\0', 20), ""));
	assert(!strcmpnul(libsimple_strncasechrnul("abcABCabcABC", '\0', 3), "ABCabcABC"));
	assert(!strcmpnul(libsimple_strncasechrnul("abcdef", 'd', 3), "def"));
	assert(!strcmpnul(libsimple_strncasechrnul("abcdef", 'e', 3), "def"));
	assert(!strcmpnul(libsimple_strncasechrnul("123123", '1', 7), "123123"));
	assert(!strcmpnul(libsimple_strncasechrnul("123123", '3', 7), "3123"));
	return 0;
}

#endif
