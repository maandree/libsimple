/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline size_t libsimple_strrcaseeqlen(const char *, const char *);


#else
#include "test.h"

int
main(void)
{
	size_t i, j;
	char a[] = "abcdefgh", b[] = "ABCDEFGH";

	assert(libsimple_strrcaseeqlen("", "") == 0);
	assert(libsimple_strrcaseeqlen("x", "") == 0);
	assert(libsimple_strrcaseeqlen("x", "y") == 0);
	assert(libsimple_strrcaseeqlen("", "y") == 0);
	for (i = 0; i <= 8; i++) {
		for (j = 0; j <= 8; j++) {
			assert(libsimple_strrcaseeqlen(&a[i], &b[j]) == 8 - (i > j ? i : j));
			assert(libsimple_strrcaseeqlen(&b[i], &a[j]) == 8 - (i > j ? i : j));
			a[i] = b[j] = '\0';
			assert(libsimple_strrcaseeqlen(a, b) == (i == j ? i : 0));
			assert(libsimple_strrcaseeqlen(b, a) == (i == j ? i : 0));
			a[i] = "abcdefgh"[i];
			b[j] = "ABCDEFGH"[j];
		}
	}
	assert(libsimple_strrcaseeqlen("abc", "abc") == 3);
	assert(libsimple_strrcaseeqlen("123", "123") == 3);

	return 0;
}

#endif
