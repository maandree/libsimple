/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memrchr(const void *s_, int c_, size_t n_)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	ssize_t n = (ssize_t)n_;
	while (n-- && s[n] != c);
	return n < 0 ? NULL : &s[n];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memrchr("abcABCabcABC", 'a', sizeof("abcABCabcABC") - 1), "abcABC"));
	assert(!strcmpnul(libsimple_memrchr("abcABCabcABC", 'c', sizeof("abcABCabcABC") - 1), "cABC"));
	assert(!strcmpnul(libsimple_memrchr("abcABCabcABC", 'A', sizeof("abcABCabcABC") - 1), "ABC"));
	assert(!strcmpnul(libsimple_memrchr("abcABCabcABC", 'C', sizeof("abcABCabcABC") - 1), "C"));
	assert(!strcmpnul(libsimple_memrchr("ABCabcABCabc", 'a', sizeof("ABCabcABCabc") - 1), "abc"));
	assert(!strcmpnul(libsimple_memrchr("ABCabcABCabc", 'c', sizeof("ABCabcABCabc") - 1), "c"));
	assert(!strcmpnul(libsimple_memrchr("ABCabcABCabc", 'A', sizeof("ABCabcABCabc") - 1), "ABCabc"));
	assert(!strcmpnul(libsimple_memrchr("ABCabcABCabc", 'C', sizeof("ABCabcABCabc") - 1), "Cabc"));
	assert(!libsimple_memrchr("abcABCabcABC", 'x', sizeof("abcABCabcABC") - 1));
	return 0;
}

#endif
