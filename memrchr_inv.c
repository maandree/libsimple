/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memrchr_inv(const void *s_, int c_, size_t n_) /* TODO man */
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	ssize_t n = n_;
	while (n-- && s[n] == c);
	return n < 0 ? NULL : &s[n];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memrchr_inv("aabbaabb", 'b', 8), "abb"));
	assert(!strcmpnul(libsimple_memrchr_inv("aabbaabb", 'B', 8), "b"));
	assert(!strcmpnul(libsimple_memrchr_inv("AABBAABB", 'b', 8), "B"));
	assert(!strcmpnul(libsimple_memrchr_inv("AABBAABB", 'B', 8), "ABB"));
	assert(!strcmpnul(libsimple_memrchr_inv("aabbaabb", 'a', 8), "b"));
	assert(!strcmpnul(libsimple_memrchr_inv("aabbbb\0", '\0', 8), "b"));
	assert(!strcmpnul(libsimple_memrchr_inv("--------", '-', 8), NULL));
	return 0;
}

#endif
