/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


size_t
libsimple_memrcaseeqlen(const void *a_, size_t n, const void *b_, size_t m)
{
	const char *a = &((const char *)a_)[n];
	const char *b = &((const char *)b_)[m];
	size_t i = 0, len = n < m ? n : m;
	for (; i < len; i++) {
		a--;
		b--;
		if (tolower(*a) != tolower(*b))
			break;
	}
	return i;
}


#else
#include "test.h"

int
main(void)
{
	char s[] = "abcdefgh", t[] = "ABCDEFGH";
	size_t i, j;
	assert(libsimple_memrcaseeqlen("x", 0, "x", 0) == 0);
	assert(libsimple_memrcaseeqlen("x", 1, "x", 0) == 0);
	assert(libsimple_memrcaseeqlen("x", 1, "y", 1) == 0);
	assert(libsimple_memrcaseeqlen("y", 0, "y", 1) == 0);
	for (i = 0; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			assert(libsimple_memrcaseeqlen(&s[i], 8 - i, &t[j], 8 - j) == 8 - (i > j ? i : j));
			assert(libsimple_memrcaseeqlen(s, i, t, j) == (i == j ? i : 0));
			assert(libsimple_memrcaseeqlen(&t[i], 8 - i, &s[j], 8 - j) == 8 - (i > j ? i : j));
			assert(libsimple_memrcaseeqlen(t, i, s, j) == (i == j ? i : 0));
		}
	}
	assert(libsimple_memrcaseeqlen("abc", 3, "abc", 3) == 3);
	assert(libsimple_memrcaseeqlen("123", 3, "123", 3) == 3);
	return 0;
}

#endif
