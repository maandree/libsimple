/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_strrstr(const char *hay, const char *sub)
{
	return libsimple_memrmem(hay, strlen(hay), sub, strlen(sub));
}


#ifdef TEST
#include <assert.h>

int
main(void)
{
	assert(!strcmp(libsimple_strrstr("test", "test"), "test"));
	assert(!strcmp(libsimple_strrstr("", ""), ""));
	assert(!strcmp(libsimple_strrstr("test", ""), ""));
	assert(!libsimple_strrstr("", "test"));
	assert(!libsimple_strrstr("t", "test"));
	assert(!strcmp(libsimple_strrstr("test", "t"), "t"));
	assert(!strcmp(libsimple_strrstr("test", "e"), "est"));
	assert(!strcmp(libsimple_strrstr("test", "s"), "st"));
	assert(!libsimple_strrstr("test", "x"));
	assert(!strcmp(libsimple_strrstr("test", "te"), "test"));
	assert(!strcmp(libsimple_strrstr("test", "es"), "est"));
	assert(!strcmp(libsimple_strrstr("test", "st"), "st"));
	assert(!libsimple_strrstr("test", "xx"));
	assert(!strcmp(libsimple_strrstr("abc", "c"), "c"));
	assert(!strcmp(libsimple_strrstr("abc", "bc"), "bc"));
	assert(!strcmp(libsimple_strrstr("abc", "abc"), "abc"));
	assert(!strcmp(libsimple_strrstr("abcabc", "bc"), "bc"));

	assert(!strcmp(libsimple_strrcasestr("TEST", "test"), "TEST"));
	assert(!strcmp(libsimple_strrcasestr("TEST", ""), ""));
	assert(!libsimple_strrcasestr("T", "test"));
	assert(!strcmp(libsimple_strrcasestr("TEST", "t"), "T"));
	assert(!strcmp(libsimple_strrcasestr("TEST", "e"), "EST"));
	assert(!strcmp(libsimple_strrcasestr("TEST", "s"), "ST"));
	assert(!libsimple_strrcasestr("TEST", "x"));
	assert(!strcmp(libsimple_strrcasestr("TEST", "te"), "TEST"));
	assert(!strcmp(libsimple_strrcasestr("TEST", "es"), "EST"));
	assert(!strcmp(libsimple_strrcasestr("TEST", "st"), "ST"));
	assert(!libsimple_strrcasestr("TEST", "xx"));
	assert(!strcmp(libsimple_strrcasestr("ABC", "c"), "C"));
	assert(!strcmp(libsimple_strrcasestr("ABC", "bc"), "BC"));
	assert(!strcmp(libsimple_strrcasestr("ABC", "abc"), "ABC"));
	assert(!strcmp(libsimple_strrcasestr("ABCABC", "bc"), "BC"));

	assert(!strcmp(libsimple_strrcasestr("test", "TEST"), "test"));
	assert(!libsimple_strrcasestr("", "TEST"));
	assert(!libsimple_strrcasestr("t", "TEST"));
	assert(!strcmp(libsimple_strrcasestr("test", "T"), "t"));
	assert(!strcmp(libsimple_strrcasestr("test", "E"), "est"));
	assert(!strcmp(libsimple_strrcasestr("test", "S"), "st"));
	assert(!libsimple_strrcasestr("test", "X"));
	assert(!strcmp(libsimple_strrcasestr("test", "TE"), "test"));
	assert(!strcmp(libsimple_strrcasestr("test", "ES"), "est"));
	assert(!strcmp(libsimple_strrcasestr("test", "ST"), "st"));
	assert(!libsimple_strrcasestr("test", "XX"));
	assert(!strcmp(libsimple_strrcasestr("abc", "C"), "c"));
	assert(!strcmp(libsimple_strrcasestr("abc", "BC"), "bc"));
	assert(!strcmp(libsimple_strrcasestr("abc", "ABC"), "abc"));
	assert(!strcmp(libsimple_strrcasestr("abcabc", "BC"), "bc"));
	return 0;
}

#endif
