/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memrcasechr(const void *s_, int c, size_t n_)
{
	char *s = *(char **)(void *)&s_;
	ssize_t n = (ssize_t)n_;
	c = tolower(c);
	while (n-- && tolower(s[n]) != c);
	return n < 0 ? NULL : &s[n];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memrcasechr("abcABCabcABC", 'a', sizeof("abcABCabcABC") - 1), "ABC"));
	assert(!strcmpnul(libsimple_memrcasechr("abcABCabcABC", 'c', sizeof("abcABCabcABC") - 1), "C"));
	assert(!strcmpnul(libsimple_memrcasechr("abcABCabcABC", 'A', sizeof("abcABCabcABC") - 1), "ABC"));
	assert(!strcmpnul(libsimple_memrcasechr("abcABCabcABC", 'C', sizeof("abcABCabcABC") - 1), "C"));
	assert(!strcmpnul(libsimple_memrcasechr("ABCabcABCabc", 'a', sizeof("ABCabcABCabc") - 1), "abc"));
	assert(!strcmpnul(libsimple_memrcasechr("ABCabcABCabc", 'c', sizeof("ABCabcABCabc") - 1), "c"));
	assert(!strcmpnul(libsimple_memrcasechr("ABCabcABCabc", 'A', sizeof("ABCabcABCabc") - 1), "abc"));
	assert(!strcmpnul(libsimple_memrcasechr("ABCabcABCabc", 'C', sizeof("ABCabcABCabc") - 1), "c"));
	assert(!libsimple_memrcasechr("abcABCabcABC", 'x', sizeof("abcABCabcABC") - 1));
	return 0;
}

#endif
