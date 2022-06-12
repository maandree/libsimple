/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strcasecmpnul(const char *, const char *);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strcasecmpnul(NULL, NULL) == 0);
	assert(libsimple_strcasecmpnul(NULL, "") < 0);
	assert(libsimple_strcasecmpnul("", NULL) > 0);
	assert(libsimple_strcasecmpnul("", "") == 0);
	assert(libsimple_strcasecmpnul(NULL, "x") < 0);
	assert(libsimple_strcasecmpnul("x", NULL) > 0);
	assert(libsimple_strcasecmpnul("x", "x") == 0);
	assert(libsimple_strcasecmpnul("a", "b") < 0);
	assert(libsimple_strcasecmpnul("b", "a") > 0);
	assert(libsimple_strcasecmpnul("aa", "ab") < 0);
	assert(libsimple_strcasecmpnul("ab", "aa") > 0);
	assert(libsimple_strcasecmpnul("aa", "aa") == 0);
	assert(libsimple_strcasecmpnul("A", "a") == 0);
	assert(libsimple_strcasecmpnul("a", "A") == 0);
	assert(libsimple_strcasecmpnul("AA", "Aa") == 0);
	assert(libsimple_strcasecmpnul("Aa", "AA") == 0);
	assert(libsimple_strcasecmpnul("AA", "AA") == 0);
	return 0;
}

#endif
