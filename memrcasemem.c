/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memrcasemem(const void *hay_, size_t hayn, const void *sub_, size_t subn)
{
	const char *hay = hay_;
	const char *sub = sub_;
	const char *start;

	if (!subn)
		return &REMOVE_CONST(hay, char *)[hayn];
	if (hayn < subn)
		return NULL;
	if (subn == 1)
		return libsimple_memrcasechr(hay, *sub, hayn);

	start = hay;
	hay = &hay[hayn - subn];
	do {
		if (tolower(*hay) == tolower(*sub) && !libsimple_memcasecmp(hay, sub, subn))
			return REMOVE_CONST(hay, char *);
	} while (hay-- != start);

	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memrcasemem("test", 4, "test", 4), "test"));
	assert(!strcmpnul(libsimple_memrcasemem("", 0, "", 0), ""));
	assert(!strcmpnul(libsimple_memrcasemem("test", 4, "", 0), ""));
	assert(!libsimple_memrcasemem("", 0, "test", 4));
	assert(!libsimple_memrcasemem("t", 1, "test", 4));
	assert(!strcmpnul(libsimple_memrcasemem("test", 4, "t", 1), "t"));
	assert(!strcmpnul(libsimple_memrcasemem("test", 4, "e", 1), "est"));
	assert(!strcmpnul(libsimple_memrcasemem("test", 4, "s", 1), "st"));
	assert(!libsimple_memrcasemem("test", 4, "x", 1));
	assert(!strcmpnul(libsimple_memrcasemem("test", 4, "te", 2), "test"));
	assert(!strcmpnul(libsimple_memrcasemem("test", 4, "es", 2), "est"));
	assert(!strcmpnul(libsimple_memrcasemem("test", 4, "st", 2), "st"));
	assert(!strcmpnul(libsimple_memrcasemem("test", 5, "t", 2), "t"));
	assert(!libsimple_memrcasemem("test", 4, "xx", 2));
	assert(!strcmpnul(libsimple_memrcasemem("abc", 3, "c", 1), "c"));
	assert(!strcmpnul(libsimple_memrcasemem("abc", 3, "bc", 2), "bc"));
	assert(!strcmpnul(libsimple_memrcasemem("abc", 3, "abc", 3), "abc"));
	assert(!libsimple_memrcasemem("abc", 3, "abc", 4));
	assert(!strcmpnul(libsimple_memrcasemem("abcabc", 6, "bc", 2), "bc"));
	assert(!strcmpnul(libsimple_memrcasemem("abcabc", 6, "BC", 2), "bc"));
	assert(!strcmpnul(libsimple_memrcasemem("ABCABC", 6, "bc", 2), "BC"));
	assert(!strcmpnul(libsimple_memrcasemem("ABCABC", 6, "BC", 2), "BC"));
	return 0;
}

#endif
