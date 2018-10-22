/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_strncasestarts(const char *s_, const char *t, size_t n)
{
	char *s = *(char **)(void *)&s_;
	size_t len = strlen(t);
	n = strnlen(s, n);
	if (n < len)
		return 0;
	return !strncasecmp(s, t, len);
}


#else
#include "test.h"

int
main(void)
{
	size_t n, i, j;
	char buf[10];
	for (n = 0; n <= 8; n++) {
		assert(libsimple_strncasestarts("abcABC", "", n) == 1);
		assert(libsimple_strncasestarts("ABCabc", "", n) == 1);
		assert(libsimple_strncasestarts("123456", "", n) == 1);
		for (i = 0; i < 7; i++) {
			for (j = 1; j < 8 - i; j++) {
				strcpy(buf, &"abcABCx"[i])[j] = '\0';
				assert(libsimple_strncasestarts("abcABC", buf, n) == ((i == 0 || i == 3) && i + j < 7 && n >= j));
				assert(libsimple_strncasestarts("ABCabc", buf, n) == ((i == 0 || i == 3) && i + j < 7 && n >= j));
				strcpy(buf, &"ABCabcx"[i])[j] = '\0';
				assert(libsimple_strncasestarts("abcABC", buf, n) == ((i == 0 || i == 3) && i + j < 7 && n >= j));
				assert(libsimple_strncasestarts("ABCabc", buf, n) == ((i == 0 || i == 3) && i + j < 7 && n >= j));
				strcpy(buf, &"1234567"[i])[j] = '\0';
				assert(libsimple_strncasestarts("123456", buf, n) == (i == 0 && j < 7 && n >= j));
				assert(libsimple_strncasestarts("zzzzzz", buf, n) == 0);
				strcpy(buf, &"aaaaaaa"[i])[j] = '\0';
				assert(libsimple_strncasestarts("zzzzzz", buf, n) == 0);
			}
		}
	}
	return 0;
}

#endif
