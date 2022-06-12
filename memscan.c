/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_memscan(const void *s_, int c_, size_t n)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	size_t i = 0;
	for (; i < n && s[i] != c; i++);
	return &s[i];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memscan("abcABCabcABC", 'a', sizeof("abcABCabcABC") - 1), "abcABCabcABC"));
	assert(!strcmpnul(libsimple_memscan("abcABCabcABC", 'c', sizeof("abcABCabcABC") - 1), "cABCabcABC"));
	assert(!strcmpnul(libsimple_memscan("abcABCabcABC", 'A', sizeof("abcABCabcABC") - 1), "ABCabcABC"));
	assert(!strcmpnul(libsimple_memscan("abcABCabcABC", 'C', sizeof("abcABCabcABC") - 1), "CabcABC"));
	assert(!strcmpnul(libsimple_memscan("ABCabcABCabc", 'a', sizeof("ABCabcABCabc") - 1), "abcABCabc"));
	assert(!strcmpnul(libsimple_memscan("ABCabcABCabc", 'c', sizeof("ABCabcABCabc") - 1), "cABCabc"));
	assert(!strcmpnul(libsimple_memscan("ABCabcABCabc", 'A', sizeof("ABCabcABCabc") - 1), "ABCabcABCabc"));
	assert(!strcmpnul(libsimple_memscan("ABCabcABCabc", 'C', sizeof("ABCabcABCabc") - 1), "CabcABCabc"));
	assert(!strcmpnul(libsimple_memscan("abcABCabcABC", 'x', sizeof("abcABCabcABC") - 1), ""));
	return 0;
}

#endif
