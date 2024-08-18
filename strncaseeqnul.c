/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strncaseeqnul(const char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strncaseeqnul("abc", "abc", 5) == 1);
	assert(libsimple_strncaseeqnul("abc", "ab", 5) == 0);
	assert(libsimple_strncaseeqnul("ab", "abc", 5) == 0);
	assert(libsimple_strncaseeqnul("ab", "xy", 5) == 0);
	assert(libsimple_strncaseeqnul("xy", "ab", 5) == 0);
	assert(libsimple_strncaseeqnul("", "1", 5) == 0);
	assert(libsimple_strncaseeqnul("1", "", 5) == 0);
	assert(libsimple_strncaseeqnul("", "", 5) == 1);
	assert(libsimple_strncaseeqnul("abc", "ABC", 5) == 1);
	assert(libsimple_strncaseeqnul("ABC", "abc", 5) == 1);
	assert(libsimple_strncaseeqnul("", NULL, 5) == 0);
	assert(libsimple_strncaseeqnul("1", NULL, 5) == 0);
	assert(libsimple_strncaseeqnul(NULL, "", 5) == 0);
	assert(libsimple_strncaseeqnul(NULL, "1", 5) == 0);
	assert(libsimple_strncaseeqnul(NULL, NULL, 5) == 1);
	assert(libsimple_strncaseeqnul("abc", "abc", 1) == 1);
	assert(libsimple_strncaseeqnul("abc", "ab", 1) == 1);
	assert(libsimple_strncaseeqnul("ab", "abc", 1) == 1);
	assert(libsimple_strncaseeqnul("ab", "xy", 1) == 0);
	assert(libsimple_strncaseeqnul("xy", "ab", 1) == 0);
	assert(libsimple_strncaseeqnul("", "1", 1) == 0);
	assert(libsimple_strncaseeqnul("1", "", 1) == 0);
	assert(libsimple_strncaseeqnul("", "", 1) == 1);
	assert(libsimple_strncaseeqnul("abc", "ABC", 1) == 1);
	assert(libsimple_strncaseeqnul("ABC", "abc", 1) == 1);
	assert(libsimple_strncaseeqnul("", NULL, 1) == 0);
	assert(libsimple_strncaseeqnul("1", NULL, 1) == 0);
	assert(libsimple_strncaseeqnul(NULL, "", 1) == 0);
	assert(libsimple_strncaseeqnul(NULL, "1", 1) == 0);
	assert(libsimple_strncaseeqnul(NULL, NULL, 1) == 1);
	assert(libsimple_strncaseeqnul("abc", "abc", 0) == 1);
	assert(libsimple_strncaseeqnul("abc", "ab", 0) == 1);
	assert(libsimple_strncaseeqnul("ab", "abc", 0) == 1);
	assert(libsimple_strncaseeqnul("ab", "xy", 0) == 1);
	assert(libsimple_strncaseeqnul("xy", "ab", 0) == 1);
	assert(libsimple_strncaseeqnul("", "1", 0) == 1);
	assert(libsimple_strncaseeqnul("1", "", 0) == 1);
	assert(libsimple_strncaseeqnul("", "", 0) == 1);
	assert(libsimple_strncaseeqnul("abc", "ABC", 0) == 1);
	assert(libsimple_strncaseeqnul("ABC", "abc", 0) == 1);
	assert(libsimple_strncaseeqnul("", NULL, 0) == 0);
	assert(libsimple_strncaseeqnul("1", NULL, 0) == 0);
	assert(libsimple_strncaseeqnul(NULL, "", 0) == 0);
	assert(libsimple_strncaseeqnul(NULL, "1", 0) == 0);
	assert(libsimple_strncaseeqnul(NULL, NULL, 0) == 1);
	return 0;
}

#endif
