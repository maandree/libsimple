/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_stptoupper(char *d, const char *s)
{
	size_t n;
	char *ret;
	if (d == s) {
		for (; *d; d++)
			*d = (char)toupper(*d);
		return d;
	} else if (d < s) {
		for (; *s; d++, s++)
			*d = (char)toupper(*s);
		*d = '\0';
		return d;
	} else {
		for (n = 0; s[n]; n++);
		ret = &d[n];
		do {
			d[n] = (char)toupper(s[n]);
		} while (n--);
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
	assert(!strcmpnul(libsimple_stptoupper(&buf[3], &buf[0]), ""));
	assert(!strcmp(buf, "abcABCDEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_stptoupper(&buf[0], &buf[3]), ""));
	assert(!strcmp(buf, "DEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(!strcmpnul(libsimple_stptoupper(&buf[0], &buf[0]), ""));
	assert(!strcmp(buf, "ABCDEABCDE12345"));

	return 0;
}

#endif
