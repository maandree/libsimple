/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_stpntolower(char *d, const char *s, size_t n)
{
	size_t i;
	char *ret;
	if (d == s) {
		for (; n && *d; d++, n--)
			*d = (char)tolower(*d);
		return d;
	} else if (d < s) {
		for (; n && *s; d++, s++, n--)
			*d = (char)tolower(*s);
		if (n)
			*d = '\0';
		return d;
	} else {
		for (i = 0; i < n && s[i]; i++);
		ret = &d[i];
		if (i != n)
			d[i] = (char)tolower(s[i]);
		while (i--)
			d[i] = (char)tolower(s[i]);
		return ret;
	}
}


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stpntolower(&buf[3], &buf[0], SIZE_MAX), ""));
	assert(!strcmp(buf, "ABCabcdeabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stpntolower(&buf[0], &buf[3], SIZE_MAX), ""));
	assert(!strcmp(buf, "deabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stpntolower(&buf[0], &buf[0], SIZE_MAX), ""));
	assert(!strcmp(buf, "abcdeabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strntolower(&buf[3], &buf[0], SIZE_MAX), "abcdeabcde12345"));
	assert(!strcmp(buf, "ABCabcdeabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strntolower(&buf[0], &buf[3], SIZE_MAX), "deabcde12345"));
	assert(!strcmp(buf, "deabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strntolower(&buf[0], &buf[0], SIZE_MAX), "abcdeabcde12345"));
	assert(!strcmp(buf, "abcdeabcde12345"));

	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	buf[18] = 'X';
	assert(!strcmpnul(libsimple_stpntolower(&buf[3], &buf[0], 15), "X"));
	assert(!strcmp(buf, "ABCabcdeabcde12345X"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stpntolower(&buf[0], &buf[3], 12), "345"));
	assert(!strcmp(buf, "deabcde12345345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345X");
	assert(!strcmpnul(libsimple_stpntolower(&buf[0], &buf[0], 15), "X"));
	assert(!strcmp(buf, "abcdeabcde12345X"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	buf[18] = 'X';
	assert(!strcmpnul(libsimple_strntolower(&buf[3], &buf[0], 15), "abcdeabcde12345X"));
	assert(!strcmp(buf, "ABCabcdeabcde12345X"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strntolower(&buf[0], &buf[3], 12), "deabcde12345345"));
	assert(!strcmp(buf, "deabcde12345345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345X");
	assert(!strcmpnul(libsimple_strntolower(&buf[0], &buf[0], 15), "abcdeabcde12345X"));
	assert(!strcmp(buf, "abcdeabcde12345X"));

	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stpntolower(&buf[3], &buf[0], 0), "DEabcde12345"));
	assert(!strcmp(buf, "ABCDEabcde12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stpntolower(&buf[0], &buf[3], 0), "ABCDEabcde12345"));
	assert(!strcmp(buf, "ABCDEabcde12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stpntolower(&buf[0], &buf[0], 0), "ABCDEabcde12345"));
	assert(!strcmp(buf, "ABCDEabcde12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strntolower(&buf[3], &buf[0], 0), "DEabcde12345"));
	assert(!strcmp(buf, "ABCDEabcde12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strntolower(&buf[0], &buf[3], 0), "ABCDEabcde12345"));
	assert(!strcmp(buf, "ABCDEabcde12345"));
	memset(buf, 0, sizeof(buf));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strntolower(&buf[0], &buf[0], 0), "ABCDEabcde12345"));
	assert(!strcmp(buf, "ABCDEabcde12345"));

	return 0;
}

#endif
