/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strcasechrnul(const char *s_, int c)
{
	char *s = *(char **)(void *)&s_, lc = (char)tolower(c), uc = (char)toupper(c);
	if (lc != uc)
		for (; *s && *s != lc && *s != uc; s++);
	else
		for (; *s && *s != lc; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strcasechrnul("abcABCabcABCx123123", 'c'), "cABCabcABCx123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("abcABCabcABCx123123", 'a'), "abcABCabcABCx123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("abcABCabcABCx123123", 'x'), "x123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("abcABCabcABCx123123", 'C'), "cABCabcABCx123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("abcABCabcABCx123123", 'A'), "abcABCabcABCx123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("abcABCabcABCx123123", 'X'), "x123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("ABCabcABCabcX123123", 'c'), "CabcABCabcX123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("ABCabcABCabcX123123", 'a'), "ABCabcABCabcX123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("ABCabcABCabcX123123", 'x'), "X123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("ABCabcABCabcX123123", 'C'), "CabcABCabcX123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("ABCabcABCabcX123123", 'A'), "ABCabcABCabcX123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("ABCabcABCabcX123123", 'X'), "X123123"));
	assert(!strcmpnul(libsimple_strcasechrnul("ABCabcABCabcX123123", '0'), ""));
	assert(!strcmpnul(libsimple_strcasechrnul("ABCabcABCabcX123123", '1'), "123123"));
	return 0;
}

#endif
