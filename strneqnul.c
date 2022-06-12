/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strneqnul(const char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strneqnul("abc", "abc", 5) == 1);
	assert(libsimple_strneqnul("abc", "ab", 5) == 0);
	assert(libsimple_strneqnul("ab", "abc", 5) == 0);
	assert(libsimple_strneqnul("ab", "xy", 5) == 0);
	assert(libsimple_strneqnul("xy", "ab", 5) == 0);
	assert(libsimple_strneqnul("", "1", 5) == 0);
	assert(libsimple_strneqnul("1", "", 5) == 0);
	assert(libsimple_strneqnul("", "", 5) == 1);
	assert(libsimple_strneqnul("abc", "ABC", 5) == 0);
	assert(libsimple_strneqnul("ABC", "abc", 5) == 0);
	assert(libsimple_strneqnul("", NULL, 5) == 0);
	assert(libsimple_strneqnul("1", NULL, 5) == 0);
	assert(libsimple_strneqnul(NULL, "", 5) == 0);
	assert(libsimple_strneqnul(NULL, "1", 5) == 0);
	assert(libsimple_strneqnul(NULL, NULL, 5) == 1);
	assert(libsimple_strneqnul("abc", "abc", 1) == 1);
	assert(libsimple_strneqnul("abc", "ab", 1) == 1);
	assert(libsimple_strneqnul("ab", "abc", 1) == 1);
	assert(libsimple_strneqnul("ab", "xy", 1) == 0);
	assert(libsimple_strneqnul("xy", "ab", 1) == 0);
	assert(libsimple_strneqnul("", "1", 1) == 0);
	assert(libsimple_strneqnul("1", "", 1) == 0);
	assert(libsimple_strneqnul("", "", 1) == 1);
	assert(libsimple_strneqnul("abc", "ABC", 1) == 0);
	assert(libsimple_strneqnul("ABC", "abc", 1) == 0);
	assert(libsimple_strneqnul("", NULL, 1) == 0);
	assert(libsimple_strneqnul("1", NULL, 1) == 0);
	assert(libsimple_strneqnul(NULL, "", 1) == 0);
	assert(libsimple_strneqnul(NULL, "1", 1) == 0);
	assert(libsimple_strneqnul(NULL, NULL, 1) == 1);
	assert(libsimple_strneqnul("abc", "abc", 0) == 1);
	assert(libsimple_strneqnul("abc", "ab", 0) == 1);
	assert(libsimple_strneqnul("ab", "abc", 0) == 1);
	assert(libsimple_strneqnul("ab", "xy", 0) == 1);
	assert(libsimple_strneqnul("xy", "ab", 0) == 1);
	assert(libsimple_strneqnul("", "1", 0) == 1);
	assert(libsimple_strneqnul("1", "", 0) == 1);
	assert(libsimple_strneqnul("", "", 0) == 1);
	assert(libsimple_strneqnul("abc", "ABC", 0) == 1);
	assert(libsimple_strneqnul("ABC", "abc", 0) == 1);
	assert(libsimple_strneqnul("", NULL, 0) == 0);
	assert(libsimple_strneqnul("1", NULL, 0) == 0);
	assert(libsimple_strneqnul(NULL, "", 0) == 0);
	assert(libsimple_strneqnul(NULL, "1", 0) == 0);
	assert(libsimple_strneqnul(NULL, NULL, 0) == 1);
	return 0;
}

#endif
