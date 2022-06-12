/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strcmpnul(const char *, const char *);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strcmpnul(NULL, NULL) == 0);
	assert(libsimple_strcmpnul(NULL, "") < 0);
	assert(libsimple_strcmpnul("", NULL) > 0);
	assert(libsimple_strcmpnul("", "") == 0);
	assert(libsimple_strcmpnul(NULL, "x") < 0);
	assert(libsimple_strcmpnul("x", NULL) > 0);
	assert(libsimple_strcmpnul("x", "x") == 0);
	assert(libsimple_strcmpnul("a", "b") < 0);
	assert(libsimple_strcmpnul("b", "a") > 0);
	assert(libsimple_strcmpnul("aa", "ab") < 0);
	assert(libsimple_strcmpnul("ab", "aa") > 0);
	assert(libsimple_strcmpnul("aa", "aa") == 0);
	assert(libsimple_strcmpnul("A", "a") < 0);
	assert(libsimple_strcmpnul("a", "A") > 0);
	assert(libsimple_strcmpnul("AA", "Aa") < 0);
	assert(libsimple_strcmpnul("Aa", "AA") > 0);
	assert(libsimple_strcmpnul("AA", "AA") == 0);
	return 0;
}

#endif
