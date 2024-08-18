/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_memmem(const void *hay_, size_t hayn, const void *sub_, size_t subn)
{
	const char *hay = hay_, *end;
	const char *sub = sub_;

	if (!subn)
		return REMOVE_CONST(hay, char *);
	if (hayn < subn)
		return NULL;
	if (subn == 1)
		return memchr(hay, *sub, hayn);

	for (end = &hay[hayn - subn + 1]; hay != end; hay++)
		if (*hay == *sub && !memcmp(hay, sub, subn))
			return REMOVE_CONST(hay, char *);

	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memmem("test", 4, "test", 4), "test"));
	assert(!strcmpnul(libsimple_memmem("", 0, "", 0), ""));
	assert(!strcmpnul(libsimple_memmem("test", 4, "", 0), "test"));
	assert(!libsimple_memmem("", 0, "test", 4));
	assert(!libsimple_memmem("t", 1, "test", 4));
	assert(!strcmpnul(libsimple_memmem("test", 4, "t", 1), "test"));
	assert(!strcmpnul(libsimple_memmem("test", 4, "e", 1), "est"));
	assert(!strcmpnul(libsimple_memmem("test", 4, "s", 1), "st"));
	assert(!libsimple_memmem("test", 4, "x", 1));
	assert(!strcmpnul(libsimple_memmem("test", 4, "te", 2), "test"));
	assert(!strcmpnul(libsimple_memmem("test", 4, "es", 2), "est"));
	assert(!strcmpnul(libsimple_memmem("test", 4, "st", 2), "st"));
	assert(!strcmpnul(libsimple_memmem("test", 5, "t", 2), "t"));
	assert(!libsimple_memmem("test", 4, "xx", 2));
	assert(!strcmpnul(libsimple_memmem("abc", 3, "c", 1), "c"));
	assert(!strcmpnul(libsimple_memmem("abc", 3, "bc", 2), "bc"));
	assert(!strcmpnul(libsimple_memmem("abc", 3, "abc", 3), "abc"));
	assert(!libsimple_memmem("abc", 3, "abc", 4));
	assert(!strcmpnul(libsimple_memmem("abcabc", 6, "bc", 2), "bcabc"));
	assert(!strcmpnul(libsimple_memmem("ABCABC", 6, "BC", 2), "BCABC"));
	assert(!libsimple_memmem("ABCDEF", 6, "bc", 2));
	assert(!libsimple_memmem("abcdef", 6, "BC", 2));
	return 0;
}

#endif
