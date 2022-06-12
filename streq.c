/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_streq(const char *, const char *);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_streq("abc", "abc") == 1);
	assert(libsimple_streq("abc", "ab") == 0);
	assert(libsimple_streq("ab", "abc") == 0);
	assert(libsimple_streq("ab", "xy") == 0);
	assert(libsimple_streq("xy", "ab") == 0);
	assert(libsimple_streq("", "1") == 0);
	assert(libsimple_streq("1", "") == 0);
	assert(libsimple_streq("", "") == 1);
	assert(libsimple_streq("abc", "ABC") == 0);
	assert(libsimple_streq("ABC", "abc") == 0);
	return 0;
}

#endif
