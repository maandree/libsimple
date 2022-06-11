/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memptolower(void *d_, const void *s_, size_t n)
{
	char *ret, *d = d_;
	const char *s = s_;
	if (d == s) {
		for (; n; d++, n--)
			*d = (char)tolower(*d);
		return d;
	} else if (d < s) {
		for (; n; d++, s++, n--)
			*d = (char)tolower(*s);
		return d;
	} else {
		ret = &d[n];
		while (n) {
			n--;
			d[n] = (char)tolower(s[n]);
		}
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
	assert(libsimple_memptolower(&buf[3], &buf[0], 16) == &buf[19]);
	assert(!strcmp(buf, "ABCabcdeabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(libsimple_memptolower(&buf[0], &buf[3], 13) == &buf[13]);
	assert(!strcmp(buf, "deabcde12345"));
	stpcpy(buf, "ABCDEabcde12345");
	assert(libsimple_memptolower(&buf[0], &buf[0], 16) == &buf[16]);
	assert(!strcmp(buf, "abcdeabcde12345"));

	return 0;
}

#endif
