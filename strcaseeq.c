/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strcaseeq(const char *, const char *);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strcaseeq("abc", "abc") == 1);
	assert(libsimple_strcaseeq("abc", "ab") == 0);
	assert(libsimple_strcaseeq("ab", "abc") == 0);
	assert(libsimple_strcaseeq("ab", "xy") == 0);
	assert(libsimple_strcaseeq("xy", "ab") == 0);
	assert(libsimple_strcaseeq("", "1") == 0);
	assert(libsimple_strcaseeq("1", "") == 0);
	assert(libsimple_strcaseeq("", "") == 1);
	assert(libsimple_strcaseeq("abc", "ABC") == 1);
	assert(libsimple_strcaseeq("ABC", "abc") == 1);
	return 0;
}

#endif
