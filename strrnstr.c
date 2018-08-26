/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrnstr(const char *h_, const char *n, size_t len)
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
		if (!strncmp(h, n, nn))
			return h;
	if (!strncmp(h, n, nn))
		return h;
	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strrnstr("", "", 10), ""));
	assert(!strcmpnul(libsimple_strrnstr("test", "", 10), ""));
	assert(!libsimple_strrnstr("", "test", 10));
	assert(!libsimple_strrnstr("t", "test", 10));
	assert(!strcmpnul(libsimple_strrnstr("test", "t", 10), "t"));
	assert(!strcmpnul(libsimple_strrnstr("test", "e", 10), "est"));
	assert(!strcmpnul(libsimple_strrnstr("test", "s", 10), "st"));
	assert(!libsimple_strrnstr("test", "x", 10));
	assert(!strcmpnul(libsimple_strrnstr("test", "te", 10), "test"));
	assert(!strcmpnul(libsimple_strrnstr("test", "es", 10), "est"));
	assert(!strcmpnul(libsimple_strrnstr("test", "st", 10), "st"));
	assert(!libsimple_strrnstr("test", "xx", 10));
	assert(!strcmpnul(libsimple_strrnstr("abc", "c", 10), "c"));
	assert(!strcmpnul(libsimple_strrnstr("abc", "bc", 10), "bc"));
	assert(!strcmpnul(libsimple_strrnstr("abc", "abc", 10), "abc"));
	assert(!strcmpnul(libsimple_strrnstr("abcabc", "bc", 10), "bc"));

	assert(!strcmpnul(libsimple_strrnstr("TEST", "", 10), ""));
	assert(!libsimple_strrnstr("T", "test", 10));
	assert(!libsimple_strrnstr("TEST", "t", 10));
	assert(!libsimple_strrnstr("TEST", "e", 10));
	assert(!libsimple_strrnstr("TEST", "s", 10));
	assert(!libsimple_strrnstr("TEST", "x", 10));
	assert(!libsimple_strrnstr("TEST", "te", 10));
	assert(!libsimple_strrnstr("TEST", "es", 10));
	assert(!libsimple_strrnstr("TEST", "st", 10));
	assert(!libsimple_strrnstr("TEST", "xx", 10));
	assert(!libsimple_strrnstr("ABC", "c", 10));
	assert(!libsimple_strrnstr("ABC", "bc", 10));
	assert(!libsimple_strrnstr("ABC", "abc", 10));
	assert(!libsimple_strrnstr("ABCABC", "bc", 10));

	assert(!libsimple_strrnstr("", "TEST", 10));
	assert(!libsimple_strrnstr("t", "TEST", 10));
	assert(!libsimple_strrnstr("test", "T", 10));
	assert(!libsimple_strrnstr("test", "E", 10));
	assert(!libsimple_strrnstr("test", "S", 10));
	assert(!libsimple_strrnstr("test", "X", 10));
	assert(!libsimple_strrnstr("test", "TE", 10));
	assert(!libsimple_strrnstr("test", "ES", 10));
	assert(!libsimple_strrnstr("test", "ST", 10));
	assert(!libsimple_strrnstr("test", "XX", 10));
	assert(!libsimple_strrnstr("abc", "C", 10));
	assert(!libsimple_strrnstr("abc", "BC", 10));
	assert(!libsimple_strrnstr("abc", "ABC", 10));
	assert(!libsimple_strrnstr("abcabc", "BC", 10));

	assert(!libsimple_strncasestr("abcdefgh", "def", 2));
	assert(!libsimple_strncasestr("abcdefgh", "DEF", 2));
	assert(!libsimple_strncasestr("ABCDEFGH", "def", 2));

	return 0;
}

#endif
