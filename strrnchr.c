/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strrnchr(const char *s_, int c_, size_t n)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	char *end = &s[n], *r = NULL;
	for (; s != end; s++) {
		if (*s == c)
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
	assert(!strcmpnul(libsimple_strrnchr("abcABCabcABC", 'a', 13), "abcABC"));
	assert(!strcmpnul(libsimple_strrnchr("abcABCabcABC", 'c', 13), "cABC"));
	assert(!strcmpnul(libsimple_strrnchr("abcABCabcABC", 'A', 13), "ABC"));
	assert(!strcmpnul(libsimple_strrnchr("abcABCabcABC", 'C', 13), "C"));
	assert(!strcmpnul(libsimple_strrnchr("ABCabcABCabc", 'a', 13), "abc"));
	assert(!strcmpnul(libsimple_strrnchr("ABCabcABCabc", 'c', 13), "c"));
	assert(!strcmpnul(libsimple_strrnchr("ABCabcABCabc", 'A', 13), "ABCabc"));
	assert(!strcmpnul(libsimple_strrnchr("ABCabcABCabc", 'C', 13), "Cabc"));
	assert(!libsimple_strrnchr("abcABCabcABC", 'x', 13));
	assert(!libsimple_strrnchr("abcABCabcABC", 'x', 20));
	assert(!strcmpnul(libsimple_strrnchr("abcABCabcABC", '\0', 13), ""));
	assert(!strcmpnul(libsimple_strrnchr("abcABCabcABC", '\0', 20), ""));
	assert(!libsimple_strrnchr("abcABCabcABC", '\0', 3));
	assert(!libsimple_strrnchr("abcdef", 'd', 3));
	assert(!libsimple_strrnchr("abcdef", 'e', 3));
	assert(!strcmpnul(libsimple_strrnchr("123123", '1', 7), "123"));
	assert(!strcmpnul(libsimple_strrnchr("123123", '3', 7), "3"));
	return 0;
}

#endif
