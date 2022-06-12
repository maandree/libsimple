/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


size_t
libsimple_strneqlen(const char *a, const char *b, size_t n)
{
	size_t i = 0;
	for (; i < n && a[i] && a[i] == b[i]; i++);
	return i;
}


#else
#include "test.h"

int
main(void)
{
	char s[] = "abcdefgh", t[] = "abcdefgh";
	size_t i, j, n;
	for (n = 0; n < 10; n++) {
		assert(libsimple_strneqlen("", "", n) == 0);
		assert(libsimple_strneqlen("x", "", n) == 0);
		assert(libsimple_strneqlen("x", "y", n) == 0);
		assert(libsimple_strneqlen("", "y", n) == 0);
		assert(libsimple_strneqlen("abc", "ABC", n) == 0);
		assert(libsimple_strneqlen("ABC", "abc", n) == 0);
		assert(libsimple_strneqlen("ABC", "ABC", n) == MIN(n, 3));
		assert(libsimple_strneqlen("123", "123", n) == MIN(n, 3));
		for (i = 0; i <= 8; i++) {
			for (j = 0; j <= 8; j++) {
				assert(libsimple_strneqlen(&s[i], &t[j], n) == MIN(i == j ? 8 - i : 0, n));
				s[i] = t[j] = '\0';
				assert(libsimple_strneqlen(s, t, n) == MIN(i < j ? i : j, n));
				s[i] = "abcdefgh"[i];
				t[j] = "abcdefgh"[j];
			}
		}
	}
	return 0;
}

#endif
