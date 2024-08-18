/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strncasestr(const char *h_, const char *n, size_t len)
{
	char *h = *(char **)(void *)&h_;
	size_t nn = strlen(n);
	nn = MIN(nn, len);
	if (!nn)
		return h;
	for (; *h && len--; h++)
		if (!strncasecmp(h, n, nn))
			return h;
	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strncasestr("", "", 10), ""));
	assert(!strcmpnul(libsimple_strncasestr("test", "", 10), "test"));
	assert(!libsimple_strncasestr("", "test", 10));
	assert(!libsimple_strncasestr("t", "test", 10));
	assert(!strcmpnul(libsimple_strncasestr("test", "t", 10), "test"));
	assert(!strcmpnul(libsimple_strncasestr("test", "e", 10), "est"));
	assert(!strcmpnul(libsimple_strncasestr("test", "s", 10), "st"));
	assert(!libsimple_strncasestr("test", "x", 10));
	assert(!strcmpnul(libsimple_strncasestr("test", "te", 10), "test"));
	assert(!strcmpnul(libsimple_strncasestr("test", "es", 10), "est"));
	assert(!strcmpnul(libsimple_strncasestr("test", "st", 10), "st"));
	assert(!libsimple_strncasestr("test", "xx", 10));
	assert(!strcmpnul(libsimple_strncasestr("abc", "c", 10), "c"));
	assert(!strcmpnul(libsimple_strncasestr("abc", "bc", 10), "bc"));
	assert(!strcmpnul(libsimple_strncasestr("abc", "abc", 10), "abc"));
	assert(!strcmpnul(libsimple_strncasestr("abcabc", "bc", 10), "bcabc"));

	assert(!strcmpnul(libsimple_strncasestr("TEST", "", 10), "TEST"));
	assert(!libsimple_strncasestr("T", "test", 10));
	assert(!strcmpnul(libsimple_strncasestr("TEST", "t", 10), "TEST"));
	assert(!strcmpnul(libsimple_strncasestr("TEST", "e", 10), "EST"));
	assert(!strcmpnul(libsimple_strncasestr("TEST", "s", 10), "ST"));
	assert(!libsimple_strncasestr("TEST", "x", 10));
	assert(!strcmpnul(libsimple_strncasestr("TEST", "te", 10), "TEST"));
	assert(!strcmpnul(libsimple_strncasestr("TEST", "es", 10), "EST"));
	assert(!strcmpnul(libsimple_strncasestr("TEST", "st", 10), "ST"));
	assert(!libsimple_strncasestr("TEST", "xx", 10));
	assert(!strcmpnul(libsimple_strncasestr("ABC", "c", 10), "C"));
	assert(!strcmpnul(libsimple_strncasestr("ABC", "bc", 10), "BC"));
	assert(!strcmpnul(libsimple_strncasestr("ABC", "abc", 10), "ABC"));
	assert(!strcmpnul(libsimple_strncasestr("ABCABC", "bc", 10), "BCABC"));

	assert(!libsimple_strncasestr("", "TEST", 10));
	assert(!libsimple_strncasestr("t", "TEST", 10));
	assert(!strcmpnul(libsimple_strncasestr("test", "T", 10), "test"));
	assert(!strcmpnul(libsimple_strncasestr("test", "E", 10), "est"));
	assert(!strcmpnul(libsimple_strncasestr("test", "S", 10), "st"));
	assert(!libsimple_strncasestr("test", "X", 10));
	assert(!strcmpnul(libsimple_strncasestr("test", "TE", 10), "test"));
	assert(!strcmpnul(libsimple_strncasestr("test", "ES", 10), "est"));
	assert(!strcmpnul(libsimple_strncasestr("test", "ST", 10), "st"));
	assert(!libsimple_strncasestr("test", "XX", 10));
	assert(!strcmpnul(libsimple_strncasestr("abc", "C", 10), "c"));
	assert(!strcmpnul(libsimple_strncasestr("abc", "BC", 10), "bc"));
	assert(!strcmpnul(libsimple_strncasestr("abc", "ABC", 10), "abc"));
	assert(!strcmpnul(libsimple_strncasestr("abcabc", "BC", 10), "bcabc"));

	assert(!libsimple_strncasestr("abcdefgh", "def", 2));
	assert(!libsimple_strncasestr("abcdefgh", "DEF", 2));
	assert(!libsimple_strncasestr("ABCDEFGH", "def", 2));

	return 0;
}

#endif
