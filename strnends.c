/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_strnends(const char *s_, const char *t, size_t n)
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
		assert(libsimple_strnends("abcABC", "", n) == 1);
		assert(libsimple_strnends("ABCabc", "", n) == 1);
		assert(libsimple_strnends("123456", "", n) == 1);
		for (i = 0; i < 7; i++) {
			for (j = 1; j < 8 - i; j++) {
				strcpy(buf, &"abcABCx"[i])[j] = '\0';
				assert(libsimple_strnends("abcABC", buf, n) == (!i && j >= 1 && j <= MIN(n, 6)));
				assert(libsimple_strnends("ABCabc", buf, n) == (i == 3 && n >= 1 && j <= MIN(n, 3)));
				strcpy(buf, &"ABCabcx"[i])[j] = '\0';
				assert(libsimple_strnends("abcABC", buf, n) == (i == 3 && n >= 1 && j <= MIN(n, 3)));
				assert(libsimple_strnends("ABCabc", buf, n) == (!i && j >= 1 && j <= MIN(n, 6)));
				strcpy(buf, &"1234567"[i])[j] = '\0';
				assert(libsimple_strnends("123456", buf, n) == (!i && j >= 1 && j <= MIN(n, 6)));
				assert(libsimple_strnends("zzzzzz", buf, n) == 0);
				strcpy(buf, &"aaaaaaa"[i])[j] = '\0';
				assert(libsimple_strnends("zzzzzz", buf, n) == 0);
			}
		}
	}
	return 0;
}

#endif
