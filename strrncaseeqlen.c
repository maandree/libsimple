/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline size_t libsimple_strrncaseeqlen(const char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	size_t i, j, n;

	for (n = 0; n < 10; n++) {
		char a[] = "abcdefgh", b[] = "ABCDEFGH";
		size_t I, J;
		assert(libsimple_strrncaseeqlen("", "", n) == 0);
		assert(libsimple_strrncaseeqlen("x", "", n) == 0);
		assert(libsimple_strrncaseeqlen("x", "y", n) == 0);
		assert(libsimple_strrncaseeqlen("", "y", n) == 0);
		for (i = 0; i <= 8; i++) {
			for (j = 0; j <= 8; j++) {
				I = 8 - i;
				J = 8 - j;
				assert(libsimple_strrncaseeqlen(&a[i], &b[j], n) == (I == J ? MIN(I,n) : MIN(I,J) * (n >= MAX(I,J))));
				assert(libsimple_strrncaseeqlen(&b[i], &a[j], n) == (I == J ? MIN(I,n) : MIN(I,J) * (n >= MAX(I,J))));
				a[i] = b[j] = '\0';
				assert(libsimple_strrncaseeqlen(a, b, n) == (MIN(i, n) == MIN(j, n) ? MIN(i, n) : 0));
				assert(libsimple_strrncaseeqlen(b, a, n) == (MIN(i, n) == MIN(j, n) ? MIN(i, n) : 0));
				a[i] = "abcdefgh"[i];
				b[j] = "ABCDEFGH"[j];
			}
		}
		assert(libsimple_strrncaseeqlen("abc", "abc", n) == MIN(3, n));
		assert(libsimple_strrncaseeqlen("123", "123", n) == MIN(3, n));
	}

	return 0;
}

#endif
