/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


size_t
libsimple_strncaseeqlen(const char *a, const char *b, size_t n)
{
	size_t i = 0;
	for (; i < n && a[i] && tolower(a[i]) == tolower(b[i]); i++);
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
		assert(libsimple_strncaseeqlen("", "", n) == 0);
		assert(libsimple_strncaseeqlen("x", "", n) == 0);
		assert(libsimple_strncaseeqlen("x", "y", n) == 0);
		assert(libsimple_strncaseeqlen("", "y", n) == 0);
		assert(libsimple_strncaseeqlen("abc", "ABC", n) == MIN(n, 3));
		assert(libsimple_strncaseeqlen("ABC", "abc", n) == MIN(n, 3));
		assert(libsimple_strncaseeqlen("ABC", "ABC", n) == MIN(n, 3));
		assert(libsimple_strncaseeqlen("123", "123", n) == MIN(n, 3));
		for (i = 0; i <= 8; i++) {
			for (j = 0; j <= 8; j++) {
				assert(libsimple_strncaseeqlen(&s[i], &t[j], n) == MIN(i == j ? 8 - i : 0, n));
				s[i] = t[j] = '\0';
				assert(libsimple_strncaseeqlen(s, t, n) == MIN(i < j ? i : j, n));
				s[i] = "abcdefgh"[i];
				t[j] = "abcdefgh"[j];
			}
		}
	}
	return 0;
}

#endif
