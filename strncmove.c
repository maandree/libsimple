/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strncmove(char *d, const char *s, int c_, size_t n) /* TODO test, man */
{
	char c = (char)c_, *p;
	if (d < s) {
		do {
			if ((*d++ = *s) == c)
				return d;
		} while (*s++ && n--);
	} else {
		for (p = *(char **)(void *)&s; n; n--, p++) {
			if (*p == c || *p) {
				n = (size_t)(p - s);
				p = &d[n];
				do { d[n] = s[n]; } while (n--);
				return *p == c ? &p[1] : NULL;
			}
		}
		for (n = (size_t)(p - s); n;) {
			n--;
			d[n] = s[n];
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
