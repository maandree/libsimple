/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strncasecmpnul(const char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strncasecmpnul(NULL, NULL, 5) == 0);
	assert(libsimple_strncasecmpnul(NULL, "", 5) < 0);
	assert(libsimple_strncasecmpnul("", NULL, 5) > 0);
	assert(libsimple_strncasecmpnul("", "", 5) == 0);
	assert(libsimple_strncasecmpnul(NULL, "x", 5) < 0);
	assert(libsimple_strncasecmpnul("x", NULL, 5) > 0);
	assert(libsimple_strncasecmpnul("x", "x", 5) == 0);
	assert(libsimple_strncasecmpnul("a", "b", 5) < 0);
	assert(libsimple_strncasecmpnul("b", "a", 5) > 0);
	assert(libsimple_strncasecmpnul("aa", "ab", 5) < 0);
	assert(libsimple_strncasecmpnul("ab", "aa", 5) > 0);
	assert(libsimple_strncasecmpnul("aa", "aa", 5) == 0);
	assert(libsimple_strncasecmpnul("A", "a", 5) == 0);
	assert(libsimple_strncasecmpnul("a", "A", 5) == 0);
	assert(libsimple_strncasecmpnul("AA", "Aa", 5) == 0);
	assert(libsimple_strncasecmpnul("Aa", "AA", 5) == 0);
	assert(libsimple_strncasecmpnul("AA", "AA", 5) == 0);
	assert(libsimple_strncasecmpnul("aa", "ab", 1) == 0);
	assert(libsimple_strncasecmpnul("ab", "aa", 1) == 0);
	assert(libsimple_strncasecmpnul("aa", "aa", 1) == 0);
	assert(libsimple_strncasecmpnul("AA", "Aa", 1) == 0);
	assert(libsimple_strncasecmpnul("Aa", "AA", 1) == 0);
	assert(libsimple_strncasecmpnul("AA", "AA", 1) == 0);
	assert(libsimple_strncasecmpnul(NULL, NULL, 0) == 0);
	assert(libsimple_strncasecmpnul(NULL, "", 0) < 0);
	assert(libsimple_strncasecmpnul("", NULL, 0) > 0);
	assert(libsimple_strncasecmpnul("", "", 0) == 0);
	assert(libsimple_strncasecmpnul(NULL, "x", 0) < 0);
	assert(libsimple_strncasecmpnul("x", NULL, 0) > 0);
	assert(libsimple_strncasecmpnul("x", "x", 0) == 0);
	assert(libsimple_strncasecmpnul("a", "b", 0) == 0);
	assert(libsimple_strncasecmpnul("b", "a", 0) == 0);
	assert(libsimple_strncasecmpnul("aa", "ab", 0) == 0);
	assert(libsimple_strncasecmpnul("ab", "aa", 0) == 0);
	assert(libsimple_strncasecmpnul("aa", "aa", 0) == 0);
	assert(libsimple_strncasecmpnul("A", "a", 0) == 0);
	assert(libsimple_strncasecmpnul("a", "A", 0) == 0);
	assert(libsimple_strncasecmpnul("AA", "Aa", 0) == 0);
	assert(libsimple_strncasecmpnul("Aa", "AA", 0) == 0);
	assert(libsimple_strncasecmpnul("AA", "AA", 0) == 0);
	return 0;
}

#endif
