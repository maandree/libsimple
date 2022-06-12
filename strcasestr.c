/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strcasestr(const char *h_, const char *n)
{
	char *h = *(char **)(void *)&h_;
	size_t nn = strlen(n);
	if (!nn)
		return h;
	for (; *h; h++)
		if (!strncasecmp(h, n, nn))
			return h;
	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strcasestr("", ""), ""));
	assert(!strcmpnul(libsimple_strcasestr("test", ""), "test"));
	assert(!libsimple_strcasestr("", "test"));
	assert(!libsimple_strcasestr("t", "test"));
	assert(!strcmpnul(libsimple_strcasestr("test", "t"), "test"));
	assert(!strcmpnul(libsimple_strcasestr("test", "e"), "est"));
	assert(!strcmpnul(libsimple_strcasestr("test", "s"), "st"));
	assert(!libsimple_strcasestr("test", "x"));
	assert(!strcmpnul(libsimple_strcasestr("test", "te"), "test"));
	assert(!strcmpnul(libsimple_strcasestr("test", "es"), "est"));
	assert(!strcmpnul(libsimple_strcasestr("test", "st"), "st"));
	assert(!libsimple_strcasestr("test", "xx"));
	assert(!strcmpnul(libsimple_strcasestr("abc", "c"), "c"));
	assert(!strcmpnul(libsimple_strcasestr("abc", "bc"), "bc"));
	assert(!strcmpnul(libsimple_strcasestr("abc", "abc"), "abc"));
	assert(!strcmpnul(libsimple_strcasestr("abcabc", "bc"), "bcabc"));

	assert(!strcmpnul(libsimple_strcasestr("TEST", ""), "TEST"));
	assert(!libsimple_strcasestr("T", "test"));
	assert(!strcmpnul(libsimple_strcasestr("TEST", "t"), "TEST"));
	assert(!strcmpnul(libsimple_strcasestr("TEST", "e"), "EST"));
	assert(!strcmpnul(libsimple_strcasestr("TEST", "s"), "ST"));
	assert(!libsimple_strcasestr("TEST", "x"));
	assert(!strcmpnul(libsimple_strcasestr("TEST", "te"), "TEST"));
	assert(!strcmpnul(libsimple_strcasestr("TEST", "es"), "EST"));
	assert(!strcmpnul(libsimple_strcasestr("TEST", "st"), "ST"));
	assert(!libsimple_strcasestr("TEST", "xx"));
	assert(!strcmpnul(libsimple_strcasestr("ABC", "c"), "C"));
	assert(!strcmpnul(libsimple_strcasestr("ABC", "bc"), "BC"));
	assert(!strcmpnul(libsimple_strcasestr("ABC", "abc"), "ABC"));
	assert(!strcmpnul(libsimple_strcasestr("ABCABC", "bc"), "BCABC"));

	assert(!libsimple_strcasestr("", "TEST"));
	assert(!libsimple_strcasestr("t", "TEST"));
	assert(!strcmpnul(libsimple_strcasestr("test", "T"), "test"));
	assert(!strcmpnul(libsimple_strcasestr("test", "E"), "est"));
	assert(!strcmpnul(libsimple_strcasestr("test", "S"), "st"));
	assert(!libsimple_strcasestr("test", "X"));
	assert(!strcmpnul(libsimple_strcasestr("test", "TE"), "test"));
	assert(!strcmpnul(libsimple_strcasestr("test", "ES"), "est"));
	assert(!strcmpnul(libsimple_strcasestr("test", "ST"), "st"));
	assert(!libsimple_strcasestr("test", "XX"));
	assert(!strcmpnul(libsimple_strcasestr("abc", "C"), "c"));
	assert(!strcmpnul(libsimple_strcasestr("abc", "BC"), "bc"));
	assert(!strcmpnul(libsimple_strcasestr("abc", "ABC"), "abc"));
	assert(!strcmpnul(libsimple_strcasestr("abcabc", "BC"), "bcabc"));
	return 0;
}

#endif
