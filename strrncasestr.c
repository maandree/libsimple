/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strrncasestr(const char *h_, const char *n, size_t len)
{
	char *h = *(char **)(void *)&h_;
	size_t hn = strlen(h);
	size_t nn = strlen(n);
	hn = MIN(hn, len);
	nn = MIN(nn, len);
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
	assert(!strcmpnul(libsimple_strrncasestr("", "", 10), ""));
	assert(!strcmpnul(libsimple_strrncasestr("test", "", 10), ""));
	assert(!libsimple_strrncasestr("", "test", 10));
	assert(!libsimple_strrncasestr("t", "test", 10));
	assert(!strcmpnul(libsimple_strrncasestr("test", "t", 10), "t"));
	assert(!strcmpnul(libsimple_strrncasestr("test", "e", 10), "est"));
	assert(!strcmpnul(libsimple_strrncasestr("test", "s", 10), "st"));
	assert(!libsimple_strrncasestr("test", "x", 10));
	assert(!strcmpnul(libsimple_strrncasestr("test", "te", 10), "test"));
	assert(!strcmpnul(libsimple_strrncasestr("test", "es", 10), "est"));
	assert(!strcmpnul(libsimple_strrncasestr("test", "st", 10), "st"));
	assert(!libsimple_strrncasestr("test", "xx", 10));
	assert(!strcmpnul(libsimple_strrncasestr("abc", "c", 10), "c"));
	assert(!strcmpnul(libsimple_strrncasestr("abc", "bc", 10), "bc"));
	assert(!strcmpnul(libsimple_strrncasestr("abc", "abc", 10), "abc"));
	assert(!strcmpnul(libsimple_strrncasestr("abcabc", "bc", 10), "bc"));

	assert(!strcmpnul(libsimple_strrncasestr("TEST", "", 10), ""));
	assert(!libsimple_strrncasestr("T", "test", 10));
	assert(!strcmpnul(libsimple_strrncasestr("TEST", "t", 10), "T"));
	assert(!strcmpnul(libsimple_strrncasestr("TEST", "e", 10), "EST"));
	assert(!strcmpnul(libsimple_strrncasestr("TEST", "s", 10), "ST"));
	assert(!libsimple_strrncasestr("TEST", "x", 10));
	assert(!strcmpnul(libsimple_strrncasestr("TEST", "te", 10), "TEST"));
	assert(!strcmpnul(libsimple_strrncasestr("TEST", "es", 10), "EST"));
	assert(!strcmpnul(libsimple_strrncasestr("TEST", "st", 10), "ST"));
	assert(!libsimple_strrncasestr("TEST", "xx", 10));
	assert(!strcmpnul(libsimple_strrncasestr("ABC", "c", 10), "C"));
	assert(!strcmpnul(libsimple_strrncasestr("ABC", "bc", 10), "BC"));
	assert(!strcmpnul(libsimple_strrncasestr("ABC", "abc", 10), "ABC"));
	assert(!strcmpnul(libsimple_strrncasestr("ABCABC", "bc", 10), "BC"));

	assert(!libsimple_strrncasestr("", "TEST", 10));
	assert(!libsimple_strrncasestr("t", "TEST", 10));
	assert(!strcmpnul(libsimple_strrncasestr("test", "T", 10), "t"));
	assert(!strcmpnul(libsimple_strrncasestr("test", "E", 10), "est"));
	assert(!strcmpnul(libsimple_strrncasestr("test", "S", 10), "st"));
	assert(!libsimple_strrncasestr("test", "X", 10));
	assert(!strcmpnul(libsimple_strrncasestr("test", "TE", 10), "test"));
	assert(!strcmpnul(libsimple_strrncasestr("test", "ES", 10), "est"));
	assert(!strcmpnul(libsimple_strrncasestr("test", "ST", 10), "st"));
	assert(!libsimple_strrncasestr("test", "XX", 10));
	assert(!strcmpnul(libsimple_strrncasestr("abc", "C", 10), "c"));
	assert(!strcmpnul(libsimple_strrncasestr("abc", "BC", 10), "bc"));
	assert(!strcmpnul(libsimple_strrncasestr("abc", "ABC", 10), "abc"));
	assert(!strcmpnul(libsimple_strrncasestr("abcabc", "BC", 10), "bc"));

	assert(!libsimple_strrncasestr("abcdefgh", "def", 2));
	assert(!libsimple_strrncasestr("abcdefgh", "DEF", 2));
	assert(!libsimple_strrncasestr("ABCDEFGH", "def", 2));

	return 0;
}

#endif
