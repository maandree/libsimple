/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


size_t
libsimple_streqlen(const char *a, const char *b)
{
	size_t i = 0;
	for (; a[i] == b[i] && a[i]; i++);
	return i;
}


#else
#include "test.h"

int
main(void)
{
	char s[] = "abcdefgh", t[] = "abcdefgh";
	size_t i, j;
	assert(libsimple_streqlen("", "") == 0);
	assert(libsimple_streqlen("x", "") == 0);
	assert(libsimple_streqlen("x", "y") == 0);
	assert(libsimple_streqlen("", "y") == 0);
	for (i = 0; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			assert(libsimple_streqlen(&s[i], &t[j]) == (i == j ? 8 - i : 0));
			s[i] = t[j] = '\0';
			assert(libsimple_streqlen(s, t) == (i < j ? i : j));
			s[i] = "abcdefgh"[i];
			t[j] = "abcdefgh"[j];
		}
	}
	assert(libsimple_streqlen("abc", "ABC") == 0);
	assert(libsimple_streqlen("123", "123") == 3);
	return 0;
}

#endif
