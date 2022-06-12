/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strnstr(const char *h_, const char *n, size_t len)
{
	char *h = *(char **)(void *)&h_;
	size_t nn = strlen(n);
	nn = MIN(nn, len);
	if (!nn)
		return h;
	for (; *h && len--; h++)
		if (!strncmp(h, n, nn))
			return h;
	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strnstr("", "", 10), ""));
	assert(!strcmpnul(libsimple_strnstr("test", "", 10), "test"));
	assert(!libsimple_strnstr("", "test", 10));
	assert(!libsimple_strnstr("t", "test", 10));
	assert(!strcmpnul(libsimple_strnstr("test", "t", 10), "test"));
	assert(!strcmpnul(libsimple_strnstr("test", "e", 10), "est"));
	assert(!strcmpnul(libsimple_strnstr("test", "s", 10), "st"));
	assert(!libsimple_strnstr("test", "x", 10));
	assert(!strcmpnul(libsimple_strnstr("test", "te", 10), "test"));
	assert(!strcmpnul(libsimple_strnstr("test", "es", 10), "est"));
	assert(!strcmpnul(libsimple_strnstr("test", "st", 10), "st"));
	assert(!libsimple_strnstr("test", "xx", 10));
	assert(!strcmpnul(libsimple_strnstr("abc", "c", 10), "c"));
	assert(!strcmpnul(libsimple_strnstr("abc", "bc", 10), "bc"));
	assert(!strcmpnul(libsimple_strnstr("abc", "abc", 10), "abc"));
	assert(!strcmpnul(libsimple_strnstr("abcabc", "bc", 10), "bcabc"));

	assert(!strcmpnul(libsimple_strnstr("TEST", "", 10), "TEST"));
	assert(!libsimple_strnstr("T", "test", 10));
	assert(!libsimple_strnstr("TEST", "t", 10));
	assert(!libsimple_strnstr("TEST", "e", 10));
	assert(!libsimple_strnstr("TEST", "s", 10));
	assert(!libsimple_strnstr("TEST", "x", 10));
	assert(!libsimple_strnstr("TEST", "te", 10));
	assert(!libsimple_strnstr("TEST", "es", 10));
	assert(!libsimple_strnstr("TEST", "st", 10));
	assert(!libsimple_strnstr("TEST", "xx", 10));
	assert(!libsimple_strnstr("ABC", "c", 10));
	assert(!libsimple_strnstr("ABC", "bc", 10));
	assert(!libsimple_strnstr("ABC", "abc", 10));
	assert(!libsimple_strnstr("ABCABC", "bc", 10));

	assert(!libsimple_strnstr("", "TEST", 10));
	assert(!libsimple_strnstr("t", "TEST", 10));
	assert(!libsimple_strnstr("test", "T", 10));
	assert(!libsimple_strnstr("test", "E", 10));
	assert(!libsimple_strnstr("test", "S", 10));
	assert(!libsimple_strnstr("test", "X", 10));
	assert(!libsimple_strnstr("test", "TE", 10));
	assert(!libsimple_strnstr("test", "ES", 10));
	assert(!libsimple_strnstr("test", "ST", 10));
	assert(!libsimple_strnstr("test", "XX", 10));
	assert(!libsimple_strnstr("abc", "C", 10));
	assert(!libsimple_strnstr("abc", "BC", 10));
	assert(!libsimple_strnstr("abc", "ABC", 10));
	assert(!libsimple_strnstr("abcabc", "BC", 10));

	assert(!libsimple_strncasestr("abcdefgh", "def", 2));
	assert(!libsimple_strncasestr("abcdefgh", "DEF", 2));
	assert(!libsimple_strncasestr("ABCDEFGH", "def", 2));

	return 0;
}

#endif
