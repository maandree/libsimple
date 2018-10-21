/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


size_t
libsimple_strcaseeqlen(const char *a, const char *b)
{
	size_t i = 0;
	for (; tolower(a[i]) == tolower(b[i]) && a[i]; i++);
	return i;
}


#else
#include "test.h"

int
main(void)
{
	char s[] = "abcdefgh", t[] = "ABCDEFGH";
	size_t i, j;
	assert(libsimple_strcaseeqlen("", "") == 0);
	assert(libsimple_strcaseeqlen("x", "") == 0);
	assert(libsimple_strcaseeqlen("x", "y") == 0);
	assert(libsimple_strcaseeqlen("", "y") == 0);
	for (i = 0; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			assert(libsimple_strcaseeqlen(&s[i], &t[j]) == (i == j ? 8 - i : 0));
			assert(libsimple_strcaseeqlen(&t[i], &s[j]) == (i == j ? 8 - i : 0));
			s[i] = t[j] = '\0';
			assert(libsimple_strcaseeqlen(s, t) == (i < j ? i : j));
			assert(libsimple_strcaseeqlen(t, s) == (i < j ? i : j));
			s[i] = "abcdefgh"[i];
			t[j] = "ABCDEFGH"[j];
		}
	}
	assert(libsimple_strcaseeqlen("abc", "abc") == 3);
	assert(libsimple_strcaseeqlen("123", "123") == 3);
	return 0;
}

#endif
