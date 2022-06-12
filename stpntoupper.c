/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_stpntoupper(char *d, const char *s, size_t n)
{
	size_t i;
	char *ret;
	if (d == s) {
		for (; n && *d; d++, n--)
			*d = (char)toupper(*d);
		return d;
	} else if (d < s) {
		for (; n && *s; d++, s++, n--)
			*d = (char)toupper(*s);
		if (n)
			*d = '\0';
		return d;
	} else {
		for (i = 0; i < n && s[i]; i++);
		ret = &d[i];
		if (i != n)
			d[i] = (char)toupper(s[i]);
		while (i--)
			d[i] = (char)toupper(s[i]);
		return ret;
	}
}


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_stpntoupper(&buf[3], &buf[0], SIZE_MAX), ""));
	assert(!strcmp(buf, "abcABCDEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_stpntoupper(&buf[0], &buf[3], SIZE_MAX), ""));
	assert(!strcmp(buf, "DEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_stpntoupper(&buf[0], &buf[0], SIZE_MAX), ""));
	assert(!strcmp(buf, "ABCDEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strntoupper(&buf[3], &buf[0], SIZE_MAX), "ABCDEABCDE12345"));
	assert(!strcmp(buf, "abcABCDEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strntoupper(&buf[0], &buf[3], SIZE_MAX), "DEABCDE12345"));
	assert(!strcmp(buf, "DEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strntoupper(&buf[0], &buf[0], SIZE_MAX), "ABCDEABCDE12345"));
	assert(!strcmp(buf, "ABCDEABCDE12345"));

	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	buf[18] = 'x';
	assert(!strcmpnul(libsimple_stpntoupper(&buf[3], &buf[0], 15), "x"));
	assert(!strcmp(buf, "abcABCDEABCDE12345x"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_stpntoupper(&buf[0], &buf[3], 12), "345"));
	assert(!strcmp(buf, "DEABCDE12345345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345x");
	assert(!strcmpnul(libsimple_stpntoupper(&buf[0], &buf[0], 15), "x"));
	assert(!strcmp(buf, "ABCDEABCDE12345x"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	buf[18] = 'x';
	assert(!strcmpnul(libsimple_strntoupper(&buf[3], &buf[0], 15), "ABCDEABCDE12345x"));
	assert(!strcmp(buf, "abcABCDEABCDE12345x"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strntoupper(&buf[0], &buf[3], 12), "DEABCDE12345345"));
	assert(!strcmp(buf, "DEABCDE12345345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345x");
	assert(!strcmpnul(libsimple_strntoupper(&buf[0], &buf[0], 15), "ABCDEABCDE12345x"));
	assert(!strcmp(buf, "ABCDEABCDE12345x"));

	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_stpntoupper(&buf[3], &buf[0], 0), "deABCDE12345"));
	assert(!strcmp(buf, "abcdeABCDE12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_stpntoupper(&buf[0], &buf[3], 0), "abcdeABCDE12345"));
	assert(!strcmp(buf, "abcdeABCDE12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_stpntoupper(&buf[0], &buf[0], 0), "abcdeABCDE12345"));
	assert(!strcmp(buf, "abcdeABCDE12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strntoupper(&buf[3], &buf[0], 0), "deABCDE12345"));
	assert(!strcmp(buf, "abcdeABCDE12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strntoupper(&buf[0], &buf[3], 0), "abcdeABCDE12345"));
	assert(!strcmp(buf, "abcdeABCDE12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_strntoupper(&buf[0], &buf[0], 0), "abcdeABCDE12345"));
	assert(!strcmp(buf, "abcdeABCDE12345"));

	return 0;
}

#endif
