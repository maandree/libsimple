/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strncaseeq(const char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strncaseeq("abc", "abc", 5) == 1);
	assert(libsimple_strncaseeq("abc", "ab", 5) == 0);
	assert(libsimple_strncaseeq("ab", "abc", 5) == 0);
	assert(libsimple_strncaseeq("ab", "xy", 5) == 0);
	assert(libsimple_strncaseeq("xy", "ab", 5) == 0);
	assert(libsimple_strncaseeq("", "1", 5) == 0);
	assert(libsimple_strncaseeq("1", "", 5) == 0);
	assert(libsimple_strncaseeq("", "", 5) == 1);
	assert(libsimple_strncaseeq("abc", "ABC", 5) == 1);
	assert(libsimple_strncaseeq("ABC", "abc", 5) == 1);
	assert(libsimple_strncaseeq("abc", "abc", 1) == 1);
	assert(libsimple_strncaseeq("abc", "ab", 1) == 1);
	assert(libsimple_strncaseeq("ab", "abc", 1) == 1);
	assert(libsimple_strncaseeq("ab", "xy", 1) == 0);
	assert(libsimple_strncaseeq("xy", "ab", 1) == 0);
	assert(libsimple_strncaseeq("", "1", 1) == 0);
	assert(libsimple_strncaseeq("1", "", 1) == 0);
	assert(libsimple_strncaseeq("", "", 1) == 1);
	assert(libsimple_strncaseeq("abc", "ABC", 1) == 1);
	assert(libsimple_strncaseeq("ABC", "abc", 1) == 1);
	assert(libsimple_strncaseeq("abc", "abc", 0) == 1);
	assert(libsimple_strncaseeq("abc", "ab", 0) == 1);
	assert(libsimple_strncaseeq("ab", "abc", 0) == 1);
	assert(libsimple_strncaseeq("ab", "xy", 0) == 1);
	assert(libsimple_strncaseeq("xy", "ab", 0) == 1);
	assert(libsimple_strncaseeq("", "1", 0) == 1);
	assert(libsimple_strncaseeq("1", "", 0) == 1);
	assert(libsimple_strncaseeq("", "", 0) == 1);
	assert(libsimple_strncaseeq("abc", "ABC", 0) == 1);
	assert(libsimple_strncaseeq("ABC", "abc", 0) == 1);
	return 0;
}

#endif
