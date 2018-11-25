/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_stptolower(char *d, const char *s)
{
	size_t n;
	char *ret;
	if (d == s) {
		for (; *d; d++)
			*d = tolower(*d);
		return d;
	} else if (d < s) {
		for (; *s; d++, s++)
			*d = tolower(*s);
		*d = '\0';
		return d;
	} else {
		for (n = 0; s[n]; n++);
		ret = &d[n];
		do {
			d[n] = tolower(s[n]);
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

	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stptolower(&buf[3], &buf[0]), ""));
	assert(!strcmp(buf, "ABCabcdeabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stptolower(&buf[0], &buf[3]), ""));
	assert(!strcmp(buf, "deabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_stptolower(&buf[0], &buf[0]), ""));
	assert(!strcmp(buf, "abcdeabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strtolower(&buf[3], &buf[0]), "abcdeabcde12345"));
	assert(!strcmp(buf, "ABCabcdeabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strtolower(&buf[0], &buf[3]), "deabcde12345"));
	assert(!strcmp(buf, "deabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(!strcmpnul(libsimple_strtolower(&buf[0], &buf[0]), "abcdeabcde12345"));
	assert(!strcmp(buf, "abcdeabcde12345"));

	return 0;
}

#endif
