/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strncmpnul(const char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strncmpnul(NULL, NULL, 5) == 0);
	assert(libsimple_strncmpnul(NULL, "", 5) < 0);
	assert(libsimple_strncmpnul("", NULL, 5) > 0);
	assert(libsimple_strncmpnul("", "", 5) == 0);
	assert(libsimple_strncmpnul(NULL, "x", 5) < 0);
	assert(libsimple_strncmpnul("x", NULL, 5) > 0);
	assert(libsimple_strncmpnul("x", "x", 5) == 0);
	assert(libsimple_strncmpnul("a", "b", 5) < 0);
	assert(libsimple_strncmpnul("b", "a", 5) > 0);
	assert(libsimple_strncmpnul("aa", "ab", 5) < 0);
	assert(libsimple_strncmpnul("ab", "aa", 5) > 0);
	assert(libsimple_strncmpnul("aa", "aa", 5) == 0);
	assert(libsimple_strncmpnul("A", "a", 5) < 0);
	assert(libsimple_strncmpnul("a", "A", 5) > 0);
	assert(libsimple_strncmpnul("AA", "Aa", 5) < 0);
	assert(libsimple_strncmpnul("Aa", "AA", 5) > 0);
	assert(libsimple_strncmpnul("AA", "AA", 5) == 0);
	assert(libsimple_strncmpnul("aa", "ab", 1) == 0);
	assert(libsimple_strncmpnul("ab", "aa", 1) == 0);
	assert(libsimple_strncmpnul("aa", "aa", 1) == 0);
	assert(libsimple_strncmpnul("AA", "Aa", 1) == 0);
	assert(libsimple_strncmpnul("Aa", "AA", 1) == 0);
	assert(libsimple_strncmpnul("AA", "AA", 1) == 0);
	assert(libsimple_strncmpnul(NULL, NULL, 0) == 0);
	assert(libsimple_strncmpnul(NULL, "", 0) < 0);
	assert(libsimple_strncmpnul("", NULL, 0) > 0);
	assert(libsimple_strncmpnul("", "", 0) == 0);
	assert(libsimple_strncmpnul(NULL, "x", 0) < 0);
	assert(libsimple_strncmpnul("x", NULL, 0) > 0);
	assert(libsimple_strncmpnul("x", "x", 0) == 0);
	assert(libsimple_strncmpnul("a", "b", 0) == 0);
	assert(libsimple_strncmpnul("b", "a", 0) == 0);
	assert(libsimple_strncmpnul("aa", "ab", 0) == 0);
	assert(libsimple_strncmpnul("ab", "aa", 0) == 0);
	assert(libsimple_strncmpnul("aa", "aa", 0) == 0);
	assert(libsimple_strncmpnul("A", "a", 0) == 0);
	assert(libsimple_strncmpnul("a", "A", 0) == 0);
	assert(libsimple_strncmpnul("AA", "Aa", 0) == 0);
	assert(libsimple_strncmpnul("Aa", "AA", 0) == 0);
	assert(libsimple_strncmpnul("AA", "AA", 0) == 0);
	return 0;
}

#endif
