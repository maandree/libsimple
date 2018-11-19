/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strcmove(char *d, const char *s, int c_) /* TODO test, man */
{
	char c = (char)c_, *p;
	size_t n;
	if (d < s) {
		do {
			if ((*d++ = *s) == c)
				return d;
		} while (*s++);
	} else {
		for (p = *(char **)(void *)&s;; p++) {
			if (*p == c || *p) {
				n = (size_t)(p - s);
				p = &d[n];
				do { d[n] = s[n]; } while (n--);
				return *p == c ? &p[1] : NULL;
			}
		}
	}
	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
