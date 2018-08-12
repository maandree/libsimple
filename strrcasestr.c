/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_strrcasestr(const char *h_, const char *n)
{
	char *h = *(char **)(void *)&h_;
	size_t hn = strlen(h);
	size_t nn = strlen(n);
	if (hn < nn)
		return NULL;
	for (h += hn -= nn; hn--; h--)
		if (!strcasecmp(h, n))
			return h;
	return NULL;
}


#ifdef TEST
#include <assert.h>

int
main(void)
{
	assert(!strcmp(libsimple_strrcasestr("", ""), ""));
	assert(!strcmp(libsimple_strrcasestr("test", ""), ""));
	assert(!libsimple_strrcasestr("", ""));
	assert(!libsimple_strrcasestr("t", "t"));
	assert(!strcmp(libsimple_strrcasestr("test", "t"), "t"));
	assert(!strcmp(libsimple_strrcasestr("test", "e"), "est"));
	assert(!strcmp(libsimple_strrcasestr("test", "s"), "st"));
	assert(!libsimple_strrcasestr("test", "x"));
	assert(!strcmp(libsimple_strrcasestr("test", "te"), "test"));
	assert(!strcmp(libsimple_strrcasestr("test", "es"), "est"));
	assert(!strcmp(libsimple_strrcasestr("test", "st"), "st"));
	assert(!libsimple_strrcasestr("test", "xx"));
	assert(!strcmp(libsimple_strrcasestr("abc", "c"), "c"));
	assert(!strcmp(libsimple_strrcasestr("abc", "bc"), "bc"));
	assert(!strcmp(libsimple_strrcasestr("abc", "abc"), "abc"));
	assert(!strcmp(libsimple_strrcasestr("abcabc", "bc"), "bc"));

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
