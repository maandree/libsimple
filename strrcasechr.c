/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrcasechr(const char *s_, int c)
{
	char *s = *(char **)(void *)&s_, lc = (char)tolower(c), uc = (char)toupper(c), *r = NULL;
	if (lc != uc) {
		for (; *s; s++)
			if (*s == lc || *s == uc)
				r = s;
	} else {
		for (; *s; s++)
			if (*s == lc)
				r = s;
	}
	return r;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strrcasechr("abcABCabcABCx123123", 'c'), "Cx123123"));
	assert(!strcmpnul(libsimple_strrcasechr("abcABCabcABCx123123", 'a'), "ABCx123123"));
	assert(!strcmpnul(libsimple_strrcasechr("abcABCabcABCx123123", 'x'), "x123123"));
	assert(!strcmpnul(libsimple_strrcasechr("abcABCabcABCx123123", 'C'), "Cx123123"));
	assert(!strcmpnul(libsimple_strrcasechr("abcABCabcABCx123123", 'A'), "ABCx123123"));
	assert(!strcmpnul(libsimple_strrcasechr("abcABCabcABCx123123", 'X'), "x123123"));
	assert(!strcmpnul(libsimple_strrcasechr("ABCabcABCabcX123123", 'c'), "cX123123"));
	assert(!strcmpnul(libsimple_strrcasechr("ABCabcABCabcX123123", 'a'), "abcX123123"));
	assert(!strcmpnul(libsimple_strrcasechr("ABCabcABCabcX123123", 'x'), "X123123"));
	assert(!strcmpnul(libsimple_strrcasechr("ABCabcABCabcX123123", 'C'), "cX123123"));
	assert(!strcmpnul(libsimple_strrcasechr("ABCabcABCabcX123123", 'A'), "abcX123123"));
	assert(!strcmpnul(libsimple_strrcasechr("ABCabcABCabcX123123", 'X'), "X123123"));
	assert(!libsimple_strrcasechr("ABCabcABCabcX123123", '0'));
	assert(!strcmpnul(libsimple_strrcasechr("ABCabcABCabcX123123", '1'), "123"));
	return 0;
}

#endif
