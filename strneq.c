/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strneq(const char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strneq("abc", "abc", 5) == 1);
	assert(libsimple_strneq("abc", "ab", 5) == 0);
	assert(libsimple_strneq("ab", "abc", 5) == 0);
	assert(libsimple_strneq("ab", "xy", 5) == 0);
	assert(libsimple_strneq("xy", "ab", 5) == 0);
	assert(libsimple_strneq("", "1", 5) == 0);
	assert(libsimple_strneq("1", "", 5) == 0);
	assert(libsimple_strneq("", "", 5) == 1);
	assert(libsimple_strneq("abc", "ABC", 5) == 0);
	assert(libsimple_strneq("ABC", "abc", 5) == 0);
	assert(libsimple_strneq("abc", "abc", 1) == 1);
	assert(libsimple_strneq("abc", "ab", 1) == 1);
	assert(libsimple_strneq("ab", "abc", 1) == 1);
	assert(libsimple_strneq("ab", "xy", 1) == 0);
	assert(libsimple_strneq("xy", "ab", 1) == 0);
	assert(libsimple_strneq("", "1", 1) == 0);
	assert(libsimple_strneq("1", "", 1) == 0);
	assert(libsimple_strneq("", "", 1) == 1);
	assert(libsimple_strneq("abc", "ABC", 1) == 0);
	assert(libsimple_strneq("ABC", "abc", 1) == 0);
	assert(libsimple_strneq("abc", "abc", 0) == 1);
	assert(libsimple_strneq("abc", "ab", 0) == 1);
	assert(libsimple_strneq("ab", "abc", 0) == 1);
	assert(libsimple_strneq("ab", "xy", 0) == 1);
	assert(libsimple_strneq("xy", "ab", 0) == 1);
	assert(libsimple_strneq("", "1", 0) == 1);
	assert(libsimple_strneq("1", "", 0) == 1);
	assert(libsimple_strneq("", "", 0) == 1);
	assert(libsimple_strneq("abc", "ABC", 0) == 1);
	assert(libsimple_strneq("ABC", "abc", 0) == 1);
	return 0;
}

#endif
