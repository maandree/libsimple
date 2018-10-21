/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


size_t
libsimple_memcaseeqlen(const void *a_, size_t n, const void *b_, size_t m)
{
	const char *a = a_, *b = b_;
	size_t i = 0;
	n = n < m ? n : m;
	for (; i < n && tolower(a[i]) == tolower(b[i]); i++);
	return i;
}


#else
#include "test.h"

int
main(void)
{
	char s[] = "abcdefgh", t[] = "ABCDEFGH";
	size_t i, j;
	assert(libsimple_memcaseeqlen("x", 0, "x", 0) == 0);
	assert(libsimple_memcaseeqlen("x", 1, "x", 0) == 0);
	assert(libsimple_memcaseeqlen("x", 1, "y", 1) == 0);
	assert(libsimple_memcaseeqlen("y", 0, "y", 1) == 0);
	for (i = 0; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			assert(libsimple_memcaseeqlen(&s[i], 8 - i, &t[j], 8 - j) == (i == j ? 8 - i : 0));
			assert(libsimple_memcaseeqlen(s, i, t, j) == (i < j ? i : j));
			assert(libsimple_memcaseeqlen(&t[i], 8 - i, &s[j], 8 - j) == (i == j ? 8 - i : 0));
			assert(libsimple_memcaseeqlen(t, i, s, j) == (i < j ? i : j));
		}
	}
	assert(libsimple_memcaseeqlen("abc", 3, "abc", 3) == 3);
	assert(libsimple_memcaseeqlen("123", 3, "123", 3) == 3);
	return 0;
}

#endif
