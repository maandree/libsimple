/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_memptoupper(void *d_, const void *s_, size_t n)
{
	char *ret, *d = d_;
	const char *s = s_;
	if (d == s) {
		for (; n; d++, n--)
			*d = (char)toupper(*d);
		return d;
	} else if (d < s) {
		for (; n; d++, s++, n--)
			*d = (char)toupper(*s);
		return d;
	} else {
		ret = &d[n];
		while (n) {
			n--;
			d[n] = (char)toupper(s[n]);
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

	stpcpy(buf, "abcdeABCDE12345");
	assert(libsimple_memptoupper(&buf[3], &buf[0], 16) == &buf[19]);
	assert(!strcmp(buf, "abcABCDEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(libsimple_memptoupper(&buf[0], &buf[3], 13) == &buf[13]);
	assert(!strcmp(buf, "DEABCDE12345"));
	stpcpy(buf, "abcdeABCDE12345");
	assert(libsimple_memptoupper(&buf[0], &buf[0], 16) == &buf[16]);
	assert(!strcmp(buf, "ABCDEABCDE12345"));

	return 0;
}

#endif
