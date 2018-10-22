/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strnchr(const char *s_, int c_, size_t n)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	char *end = &s[n];
	for (; s != end && *s && *s != c; s++);
	return s == end ? NULL : *s == c ? s : NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strnchr("abcABCabcABC", 'a', 13), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_strnchr("abcABCabcABC", 'c', 13), "cABCabcABC"));
	assert(!strcmpnul(libsimple_strnchr("abcABCabcABC", 'A', 13), "ABCabcABC"));
	assert(!strcmpnul(libsimple_strnchr("abcABCabcABC", 'C', 13), "CabcABC"));
	assert(!strcmpnul(libsimple_strnchr("ABCabcABCabc", 'a', 13), "abcABCabc"));
	assert(!strcmpnul(libsimple_strnchr("ABCabcABCabc", 'c', 13), "cABCabc"));
	assert(!strcmpnul(libsimple_strnchr("ABCabcABCabc", 'A', 13), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_strnchr("ABCabcABCabc", 'C', 13), "CabcABCabc"));
	assert(!libsimple_strnchr("abcABCabcABC", 'x', 13));
	assert(!libsimple_strnchr("abcABCabcABC", 'x', 20));
	assert(!strcmpnul(libsimple_strnchr("abcABCabcABC", '\0', 13), ""));
	assert(!strcmpnul(libsimple_strnchr("abcABCabcABC", '\0', 20), ""));
	assert(!libsimple_strnchr("abcABCabcABC", '\0', 3));
	assert(!libsimple_strnchr("abcdef", 'd', 3));
	assert(!libsimple_strnchr("abcdef", 'e', 3));
	assert(!strcmpnul(libsimple_strnchr("123123", '1', 7), "123123"));
	assert(!strcmpnul(libsimple_strnchr("123123", '3', 7), "3123"));
	return 0;
}

#endif
