/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strncasechr(const char *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	char *end = &s[n];
	c = tolower(c);
	for (; s != end && *s && tolower(*s) != c; s++);
	return s == end ? NULL : tolower(*s) == c ? s : NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strncasechr("abcABCabcABC", 'a', 13), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_strncasechr("abcABCabcABC", 'c', 13), "cABCabcABC"));
	assert(!strcmpnul(libsimple_strncasechr("abcABCabcABC", 'A', 13), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_strncasechr("abcABCabcABC", 'C', 13), "cABCabcABC"));
	assert(!strcmpnul(libsimple_strncasechr("ABCabcABCabc", 'a', 13), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_strncasechr("ABCabcABCabc", 'c', 13), "CabcABCabc"));
	assert(!strcmpnul(libsimple_strncasechr("ABCabcABCabc", 'A', 13), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_strncasechr("ABCabcABCabc", 'C', 13), "CabcABCabc"));
	assert(!libsimple_strncasechr("abcABCabcABC", 'x', 13));
	assert(!libsimple_strncasechr("abcABCabcABC", 'x', 20));
	assert(!strcmpnul(libsimple_strncasechr("abcABCabcABC", '\0', 13), ""));
	assert(!strcmpnul(libsimple_strncasechr("abcABCabcABC", '\0', 20), ""));
	assert(!libsimple_strncasechr("abcABCabcABC", '\0', 3));
	assert(!libsimple_strncasechr("abcdef", 'd', 3));
	assert(!libsimple_strncasechr("abcdef", 'e', 3));
	assert(!strcmpnul(libsimple_strncasechr("123123", '1', 7), "123123"));
	assert(!strcmpnul(libsimple_strncasechr("123123", '3', 7), "3123"));
	return 0;
}

#endif
