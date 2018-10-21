/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


size_t
libsimple_memreqlen(const void *a_, size_t n, const void *b_, size_t m)
{
	const char *a = &((char *)a_)[n], *b = &((char *)b_)[m];
	size_t i = 0, len = n < m ? n : m;
	for (; i < len && *--a == *--b; i++);
	return i;
}


#else
#include "test.h"

int
main(void)
{
	char s[] = "abcdefgh", t[] = "abcdefgh";
	size_t i, j;
	assert(libsimple_memreqlen("x", 0, "x", 0) == 0);
	assert(libsimple_memreqlen("x", 1, "x", 0) == 0);
	assert(libsimple_memreqlen("x", 1, "y", 1) == 0);
	assert(libsimple_memreqlen("y", 0, "y", 1) == 0);
	for (i = 0; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			assert(libsimple_memreqlen(&s[i], 8 - i, &t[j], 8 - j) == 8 - (i > j ? i : j));
			assert(libsimple_memreqlen(s, i, t, j) == (i == j ? i : 0));
		}
	}
	assert(libsimple_memreqlen("abc", 3, "ABC", 3) == 0);
	assert(libsimple_memreqlen("123", 3, "123", 3) == 3);
	return 0;
}

#endif
