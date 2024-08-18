/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline size_t libsimple_strreqlen(const char *, const char *);


#else
#include "test.h"

int
main(void)
{
	size_t i, j;
	char a[] = "abcdefgh", b[] = "abcdefgh";

	assert(libsimple_strreqlen("", "") == 0);
	assert(libsimple_strreqlen("x", "") == 0);
	assert(libsimple_strreqlen("x", "y") == 0);
	assert(libsimple_strreqlen("", "y") == 0);
	for (i = 0; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			assert(libsimple_strreqlen(&a[i], &b[j]) == 8 - (i > j ? i : j));
			a[i] = b[j] = '\0';
			assert(libsimple_strreqlen(a, b) == (i == j ? i : 0));
			a[i] = "abcdefgh"[i];
			b[j] = "abcdefgh"[j];
		}
	}
	assert(libsimple_strreqlen("abc", "ABC") == 0);
	assert(libsimple_strreqlen("123", "123") == 3);

	return 0;
}

#endif
