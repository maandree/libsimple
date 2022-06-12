/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_strnstarts(const char *s_, const char *t, size_t n)
{
	char *s = *(char **)(void *)&s_;
	size_t len = strlen(t);
	n = strnlen(s, n);
	if (n < len)
		return 0;
	return !strncmp(s, t, len);
}


#else
#include "test.h"

int
main(void)
{
	size_t n, i, j;
	char buf[10];
	for (n = 0; n <= 8; n++) {
		assert(libsimple_strnstarts("abcABC", "", n) == 1);
		assert(libsimple_strnstarts("ABCabc", "", n) == 1);
		assert(libsimple_strnstarts("123456", "", n) == 1);
		for (i = 0; i < 7; i++) {
			for (j = 1; j < 8 - i; j++) {
				strcpy(buf, &"abcABCx"[i])[j] = '\0';
				assert(libsimple_strnstarts("abcABC", buf, n) == (i == 0 && j < 7 && n >= j));
				assert(libsimple_strnstarts("ABCabc", buf, n) == (i == 3 && j < 4 && n >= j));
				strcpy(buf, &"ABCabcx"[i])[j] = '\0';
				assert(libsimple_strnstarts("abcABC", buf, n) == (i == 3 && j < 4 && n >= j));
				assert(libsimple_strnstarts("ABCabc", buf, n) == (i == 0 && j < 7 && n >= j));
				strcpy(buf, &"1234567"[i])[j] = '\0';
				assert(libsimple_strnstarts("123456", buf, n) == (i == 0 && j < 7 && n >= j));
				assert(libsimple_strnstarts("zzzzzz", buf, n) == 0);
				strcpy(buf, &"aaaaaaa"[i])[j] = '\0';
				assert(libsimple_strnstarts("zzzzzz", buf, n) == 0);
			}
		}
	}
	return 0;
}

#endif
