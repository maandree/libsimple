/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline size_t libsimple_strrneqlen(const char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	size_t i, j, n;

	for (n = 0; n < 10; n++) {
		char a[] = "abcdefgh", b[] = "abcdefgh";
		size_t I, J;
		assert(libsimple_strrneqlen("", "", n) == 0);
		assert(libsimple_strrneqlen("x", "", n) == 0);
		assert(libsimple_strrneqlen("x", "y", n) == 0);
		assert(libsimple_strrneqlen("", "y", n) == 0);
		for (i = 0; i <= 8; i++) {
			for (j = 0; j <= 8; j++) {
				I = 8 - i;
				J = 8 - j;
				assert(libsimple_strrneqlen(&a[i], &b[j], n) == (I == J ? MIN(I,n) : MIN(I,J) * (n >= MAX(I,J))));
				a[i] = b[j] = '\0';
				assert(libsimple_strrneqlen(a, b, n) == (MIN(i, n) == MIN(j, n) ? MIN(i, n) : 0));
				a[i] = "abcdefgh"[i];
				b[j] = "abcdefgh"[j];
			}
		}
		assert(libsimple_strrneqlen("abc", "ABC", n) == 0);
		assert(libsimple_strrneqlen("123", "123", n) == MIN(3, n));
	}

	return 0;
}

#endif
