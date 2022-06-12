/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strchrnul(const char *s_, int c_)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	for (; *s && *s != c; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strchrnul("abcABCabcABCx", 'c'), "cABCabcABCx"));
	assert(!strcmpnul(libsimple_strchrnul("abcABCabcABCx", 'a'), "abcABCabcABCx"));
	assert(!strcmpnul(libsimple_strchrnul("abcABCabcABCx", 'x'), "x"));
	assert(!strcmpnul(libsimple_strchrnul("abcABCabcABCx", 'C'), "CabcABCx"));
	assert(!strcmpnul(libsimple_strchrnul("abcABCabcABCx", 'A'), "ABCabcABCx"));
	assert(!strcmpnul(libsimple_strchrnul("abcABCabcABCx", 'X'), ""));
	assert(!strcmpnul(libsimple_strchrnul("abcABCabcABCx", '0'), ""));
	assert(!strcmpnul(libsimple_strchrnul("ABCabcABCabcX", 'c'), "cABCabcX"));
	assert(!strcmpnul(libsimple_strchrnul("ABCabcABCabcX", 'a'), "abcABCabcX"));
	assert(!strcmpnul(libsimple_strchrnul("ABCabcABCabcX", 'x'), ""));
	assert(!strcmpnul(libsimple_strchrnul("ABCabcABCabcX", 'C'), "CabcABCabcX"));
	assert(!strcmpnul(libsimple_strchrnul("ABCabcABCabcX", 'A'), "ABCabcABCabcX"));
	assert(!strcmpnul(libsimple_strchrnul("ABCabcABCabcX", 'X'), "X"));
	assert(!strcmpnul(libsimple_strchrnul("ABCabcABCabcX", '0'), ""));
	return 0;
}

#endif
