/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strrstr(const char *hay, const char *sub)
{
	return libsimple_memrmem(hay, strlen(hay), sub, strlen(sub));
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strrstr("test", "test"), "test"));
	assert(!strcmpnul(libsimple_strrstr("", ""), ""));
	assert(!strcmpnul(libsimple_strrstr("test", ""), ""));
	assert(!libsimple_strrstr("", "test"));
	assert(!libsimple_strrstr("t", "test"));
	assert(!strcmpnul(libsimple_strrstr("test", "t"), "t"));
	assert(!strcmpnul(libsimple_strrstr("test", "e"), "est"));
	assert(!strcmpnul(libsimple_strrstr("test", "s"), "st"));
	assert(!libsimple_strrstr("test", "x"));
	assert(!strcmpnul(libsimple_strrstr("test", "te"), "test"));
	assert(!strcmpnul(libsimple_strrstr("test", "es"), "est"));
	assert(!strcmpnul(libsimple_strrstr("test", "st"), "st"));
	assert(!libsimple_strrstr("test", "xx"));
	assert(!strcmpnul(libsimple_strrstr("abc", "c"), "c"));
	assert(!strcmpnul(libsimple_strrstr("abc", "bc"), "bc"));
	assert(!strcmpnul(libsimple_strrstr("abc", "abc"), "abc"));
	assert(!strcmpnul(libsimple_strrstr("abcabc", "bc"), "bc"));

	assert(!libsimple_strrstr("TEST", "test"));
	assert(!strcmpnul(libsimple_strrstr("TEST", ""), ""));
	assert(!libsimple_strrstr("T", "test"));
	assert(!libsimple_strrstr("TEST", "t"));
	assert(!libsimple_strrstr("TEST", "e"));
	assert(!libsimple_strrstr("TEST", "s"));
	assert(!libsimple_strrstr("TEST", "x"));
	assert(!libsimple_strrstr("TEST", "te"));
	assert(!libsimple_strrstr("TEST", "es"));
	assert(!libsimple_strrstr("TEST", "st"));
	assert(!libsimple_strrstr("TEST", "xx"));
	assert(!libsimple_strrstr("ABC", "c"));
	assert(!libsimple_strrstr("ABC", "bc"));
	assert(!libsimple_strrstr("ABC", "abc"));
	assert(!libsimple_strrstr("ABCABC", "bc"));

	assert(!libsimple_strrstr("test", "TEST"));
	assert(!libsimple_strrstr("", "TEST"));
	assert(!libsimple_strrstr("t", "TEST"));
	assert(!libsimple_strrstr("test", "T"));
	assert(!libsimple_strrstr("test", "E"));
	assert(!libsimple_strrstr("test", "S"));
	assert(!libsimple_strrstr("test", "X"));
	assert(!libsimple_strrstr("test", "TE"));
	assert(!libsimple_strrstr("test", "ES"));
	assert(!libsimple_strrstr("test", "ST"));
	assert(!libsimple_strrstr("test", "XX"));
	assert(!libsimple_strrstr("abc", "C"));
	assert(!libsimple_strrstr("abc", "BC"));
	assert(!libsimple_strrstr("abc", "ABC"));
	assert(!libsimple_strrstr("abcabc", "BC"));
	return 0;
}

#endif
