/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrcasestr(const char *h_, const char *n)
{
	char *h = *(char **)(void *)&h_;
	size_t hn = strlen(h);
	size_t nn = strlen(n);
	if (!nn)
		return &h[hn];
	if (hn < nn)
		return NULL;
	for (h += hn -= nn; hn--; h--)
		if (!strncasecmp(h, n, nn))
			return h;
	if (!strncasecmp(h, n, nn))
		return h;
	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strrcasestr("", ""), ""));
	assert(!strcmpnul(libsimple_strrcasestr("test", ""), ""));
	assert(!strcmpnul(libsimple_strrcasestr("t", "t"), "t"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "t"), "t"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "e"), "est"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "s"), "st"));
	assert(!libsimple_strrcasestr("test", "x"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "te"), "test"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "es"), "est"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "st"), "st"));
	assert(!libsimple_strrcasestr("test", "xx"));
	assert(!strcmpnul(libsimple_strrcasestr("abc", "c"), "c"));
	assert(!strcmpnul(libsimple_strrcasestr("abc", "bc"), "bc"));
	assert(!strcmpnul(libsimple_strrcasestr("abc", "abc"), "abc"));
	assert(!strcmpnul(libsimple_strrcasestr("abcabc", "bc"), "bc"));

	assert(!strcmpnul(libsimple_strrcasestr("TEST", ""), ""));
	assert(!libsimple_strrcasestr("T", "test"));
	assert(!strcmpnul(libsimple_strrcasestr("TEST", "t"), "T"));
	assert(!strcmpnul(libsimple_strrcasestr("TEST", "e"), "EST"));
	assert(!strcmpnul(libsimple_strrcasestr("TEST", "s"), "ST"));
	assert(!libsimple_strrcasestr("TEST", "x"));
	assert(!strcmpnul(libsimple_strrcasestr("TEST", "te"), "TEST"));
	assert(!strcmpnul(libsimple_strrcasestr("TEST", "es"), "EST"));
	assert(!strcmpnul(libsimple_strrcasestr("TEST", "st"), "ST"));
	assert(!libsimple_strrcasestr("TEST", "xx"));
	assert(!strcmpnul(libsimple_strrcasestr("ABC", "c"), "C"));
	assert(!strcmpnul(libsimple_strrcasestr("ABC", "bc"), "BC"));
	assert(!strcmpnul(libsimple_strrcasestr("ABC", "abc"), "ABC"));
	assert(!strcmpnul(libsimple_strrcasestr("ABCABC", "bc"), "BC"));

	assert(!libsimple_strrcasestr("", "TEST"));
	assert(!libsimple_strrcasestr("t", "TEST"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "T"), "t"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "E"), "est"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "S"), "st"));
	assert(!libsimple_strrcasestr("test", "X"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "TE"), "test"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "ES"), "est"));
	assert(!strcmpnul(libsimple_strrcasestr("test", "ST"), "st"));
	assert(!libsimple_strrcasestr("test", "XX"));
	assert(!strcmpnul(libsimple_strrcasestr("abc", "C"), "c"));
	assert(!strcmpnul(libsimple_strrcasestr("abc", "BC"), "bc"));
	assert(!strcmpnul(libsimple_strrcasestr("abc", "ABC"), "abc"));
	assert(!strcmpnul(libsimple_strrcasestr("abcabc", "BC"), "bc"));
	return 0;
}

#endif
