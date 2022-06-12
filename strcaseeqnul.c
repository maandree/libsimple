/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strcaseeqnul(const char *, const char *);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strcaseeqnul("abc", "abc") == 1);
	assert(libsimple_strcaseeqnul("abc", "ab") == 0);
	assert(libsimple_strcaseeqnul("ab", "abc") == 0);
	assert(libsimple_strcaseeqnul("ab", "xy") == 0);
	assert(libsimple_strcaseeqnul("xy", "ab") == 0);
	assert(libsimple_strcaseeqnul("", "1") == 0);
	assert(libsimple_strcaseeqnul("1", "") == 0);
	assert(libsimple_strcaseeqnul("", "") == 1);
	assert(libsimple_strcaseeqnul("abc", "ABC") == 1);
	assert(libsimple_strcaseeqnul("ABC", "abc") == 1);
	assert(libsimple_strcaseeqnul("", NULL) == 0);
	assert(libsimple_strcaseeqnul("1", NULL) == 0);
	assert(libsimple_strcaseeqnul(NULL, "") == 0);
	assert(libsimple_strcaseeqnul(NULL, "1") == 0);
	assert(libsimple_strcaseeqnul(NULL, NULL) == 1);
	return 0;
}

#endif
