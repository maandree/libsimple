/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
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
	assert(!strcmp(libsimple_strcasestr("", ""), ""));
	assert(!strcmp(libsimple_strcasestr("test", ""), "test"));
	assert(!libsimple_strcasestr("", "test"));
	assert(!libsimple_strcasestr("t", "test"));
	assert(!strcmp(libsimple_strcasestr("test", "t"), "test"));
	assert(!strcmp(libsimple_strcasestr("test", "e"), "est"));
	assert(!strcmp(libsimple_strcasestr("test", "s"), "st"));
	assert(!libsimple_strcasestr("test", "x"));
	assert(!strcmp(libsimple_strcasestr("test", "te"), "test"));
	assert(!strcmp(libsimple_strcasestr("test", "es"), "est"));
	assert(!strcmp(libsimple_strcasestr("test", "st"), "st"));
	assert(!libsimple_strcasestr("test", "xx"));
	assert(!strcmp(libsimple_strcasestr("abc", "c"), "c"));
	assert(!strcmp(libsimple_strcasestr("abc", "bc"), "bc"));
	assert(!strcmp(libsimple_strcasestr("abc", "abc"), "abc"));
	assert(!strcmp(libsimple_strcasestr("abcabc", "bc"), "bcabc"));

	assert(!strcmp(libsimple_strcasestr("TEST", ""), "TEST"));
	assert(!libsimple_strcasestr("T", "test"));
	assert(!strcmp(libsimple_strcasestr("TEST", "t"), "TEST"));
	assert(!strcmp(libsimple_strcasestr("TEST", "e"), "EST"));
	assert(!strcmp(libsimple_strcasestr("TEST", "s"), "ST"));
	assert(!libsimple_strcasestr("TEST", "x"));
	assert(!strcmp(libsimple_strcasestr("TEST", "te"), "TEST"));
	assert(!strcmp(libsimple_strcasestr("TEST", "es"), "EST"));
	assert(!strcmp(libsimple_strcasestr("TEST", "st"), "ST"));
	assert(!libsimple_strcasestr("TEST", "xx"));
	assert(!strcmp(libsimple_strcasestr("ABC", "c"), "C"));
	assert(!strcmp(libsimple_strcasestr("ABC", "bc"), "BC"));
	assert(!strcmp(libsimple_strcasestr("ABC", "abc"), "ABC"));
	assert(!strcmp(libsimple_strcasestr("ABCABC", "bc"), "BCABC"));

	assert(!libsimple_strcasestr("", "TEST"));
	assert(!libsimple_strcasestr("t", "TEST"));
	assert(!strcmp(libsimple_strcasestr("test", "T"), "test"));
	assert(!strcmp(libsimple_strcasestr("test", "E"), "est"));
	assert(!strcmp(libsimple_strcasestr("test", "S"), "st"));
	assert(!libsimple_strcasestr("test", "X"));
	assert(!strcmp(libsimple_strcasestr("test", "TE"), "test"));
	assert(!strcmp(libsimple_strcasestr("test", "ES"), "est"));
	assert(!strcmp(libsimple_strcasestr("test", "ST"), "st"));
	assert(!libsimple_strcasestr("test", "XX"));
	assert(!strcmp(libsimple_strcasestr("abc", "C"), "c"));
	assert(!strcmp(libsimple_strcasestr("abc", "BC"), "bc"));
	assert(!strcmp(libsimple_strcasestr("abc", "ABC"), "abc"));
	assert(!strcmp(libsimple_strcasestr("abcabc", "BC"), "bcabc"));
	return 0;
}

#endif
