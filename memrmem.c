/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memrmem(const void *hay_, size_t hayn, const void *sub_, size_t subn)
{
	char *hay = (void *)hay_, *start;
	const char *sub = sub_;

	if (!subn)
		return &hay[hayn];
	if (hayn < subn)
		return NULL;
	if (subn == 1)
		return libsimple_memrchr(hay, *sub, hayn);

	start = hay;
	hay = &hay[hayn - subn];
	do {
		if (*hay == *sub && !memcmp(hay, sub, subn))
			return hay;
	} while (hay-- != start);

	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmp(libsimple_memrmem("test", 4, "test", 4), "test"));
	assert(!strcmp(libsimple_memrmem("", 0, "", 0), ""));
	assert(!strcmp(libsimple_memrmem("test", 4, "", 0), ""));
	assert(!libsimple_memrmem("", 0, "test", 4));
	assert(!libsimple_memrmem("t", 1, "test", 4));
	assert(!strcmp(libsimple_memrmem("test", 4, "t", 1), "t"));
	assert(!strcmp(libsimple_memrmem("test", 4, "e", 1), "est"));
	assert(!strcmp(libsimple_memrmem("test", 4, "s", 1), "st"));
	assert(!libsimple_memrmem("test", 4, "x", 1));
	assert(!strcmp(libsimple_memrmem("test", 4, "te", 2), "test"));
	assert(!strcmp(libsimple_memrmem("test", 4, "es", 2), "est"));
	assert(!strcmp(libsimple_memrmem("test", 4, "st", 2), "st"));
	assert(!strcmp(libsimple_memrmem("test", 5, "t", 2), "t"));
	assert(!libsimple_memrmem("test", 4, "xx", 2));
	assert(!strcmp(libsimple_memrmem("abc", 3, "c", 1), "c"));
	assert(!strcmp(libsimple_memrmem("abc", 3, "bc", 2), "bc"));
	assert(!strcmp(libsimple_memrmem("abc", 3, "abc", 3), "abc"));
	assert(!libsimple_memrmem("abc", 3, "abc", 4));
	assert(!strcmp(libsimple_memrmem("abcabc", 6, "bc", 2), "bc"));
	return 0;
}

#endif
