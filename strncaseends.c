/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_strncaseends(const char *s_, const char *t, size_t n)
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
		assert(libsimple_strncaseends("abcABC", "", n) == 1);
		assert(libsimple_strncaseends("ABCabc", "", n) == 1);
		assert(libsimple_strncaseends("123456", "", n) == 1);
		for (i = 0; i < 7; i++) {
			for (j = 1; j < 8 - i; j++) {
				strcpy(buf, &"abcABCx"[i])[j] = '\0';
				assert(libsimple_strncaseends("abcABC", buf, n) == ((!i || i == 3) && j <= MIN(n, 6 - i)));
				assert(libsimple_strncaseends("ABCabc", buf, n) == ((!i || i == 3) && j <= MIN(n, 6 - i)));
				strcpy(buf, &"ABCabcx"[i])[j] = '\0';
				assert(libsimple_strncaseends("abcABC", buf, n) == ((!i || i == 3) && j <= MIN(n, 6 - i)));
				assert(libsimple_strncaseends("ABCabc", buf, n) == ((!i || i == 3) && j <= MIN(n, 6 - i)));
				strcpy(buf, &"1234567"[i])[j] = '\0';
				assert(libsimple_strncaseends("123456", buf, n) == (!i && j >= 1 && j <= MIN(n, 6)));
				assert(libsimple_strncaseends("zzzzzz", buf, n) == 0);
				strcpy(buf, &"aaaaaaa"[i])[j] = '\0';
				assert(libsimple_strncaseends("zzzzzz", buf, n) == 0);
			}
		}
	}
	return 0;
}

#endif
