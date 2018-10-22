/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrncasechr(const char *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	char *end = &s[n], *r = NULL;
	c = tolower(c);
	for (; s != end; s++) {
		if (tolower(*s) == c)
			r = s;
		if (!*s)
			break;
	}
	return r;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strrncasechr("abcABCabcABC", 'a', 13), "ABC"));
	assert(!strcmpnul(libsimple_strrncasechr("abcABCabcABC", 'c', 13), "C"));
	assert(!strcmpnul(libsimple_strrncasechr("abcABCabcABC", 'A', 13), "ABC"));
	assert(!strcmpnul(libsimple_strrncasechr("abcABCabcABC", 'C', 13), "C"));
	assert(!strcmpnul(libsimple_strrncasechr("ABCabcABCabc", 'a', 13), "abc"));
	assert(!strcmpnul(libsimple_strrncasechr("ABCabcABCabc", 'c', 13), "c"));
	assert(!strcmpnul(libsimple_strrncasechr("ABCabcABCabc", 'A', 13), "abc"));
	assert(!strcmpnul(libsimple_strrncasechr("ABCabcABCabc", 'C', 13), "c"));
	assert(!libsimple_strrncasechr("abcABCabcABC", 'x', 13));
	assert(!libsimple_strrncasechr("abcABCabcABC", 'x', 20));
	assert(!strcmpnul(libsimple_strrncasechr("abcABCabcABC", '\0', 13), ""));
	assert(!strcmpnul(libsimple_strrncasechr("abcABCabcABC", '\0', 20), ""));
	assert(!libsimple_strrncasechr("abcABCabcABC", '\0', 3));
	assert(!libsimple_strrncasechr("abcdef", 'd', 3));
	assert(!libsimple_strrncasechr("abcdef", 'e', 3));
	assert(!strcmpnul(libsimple_strrncasechr("123123", '1', 7), "123"));
	assert(!strcmpnul(libsimple_strrncasechr("123123", '3', 7), "3"));
	return 0;
}

#endif
