/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_streqnul(const char *, const char *);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_streqnul("abc", "abc") == 1);
	assert(libsimple_streqnul("abc", "ab") == 0);
	assert(libsimple_streqnul("ab", "abc") == 0);
	assert(libsimple_streqnul("ab", "xy") == 0);
	assert(libsimple_streqnul("xy", "ab") == 0);
	assert(libsimple_streqnul("", "1") == 0);
	assert(libsimple_streqnul("1", "") == 0);
	assert(libsimple_streqnul("", "") == 1);
	assert(libsimple_streqnul("abc", "ABC") == 0);
	assert(libsimple_streqnul("ABC", "abc") == 0);
	assert(libsimple_streqnul("", NULL) == 0);
	assert(libsimple_streqnul("1", NULL) == 0);
	assert(libsimple_streqnul(NULL, "") == 0);
	assert(libsimple_streqnul(NULL, "1") == 0);
	assert(libsimple_streqnul(NULL, NULL) == 1);
	return 0;
}

#endif
