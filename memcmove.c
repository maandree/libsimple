/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memcmove(void *d_, const void *s_, int c_, size_t n) /* TODO test, man */
{
	char *d = d_, c = (char)c_, *p;
	const char *s = s_;
	if (d < s) {
		for (; n; n--, s++)
			if ((*d++ = *s) == c)
				return d;
	} else {
		for (p = *(char **)(void *)&s; n; n--, p++) {
			if (*p == c) {
				n = (size_t)(p - s);
				p = &d[n + 1];
				do { d[n] = s[n]; } while (n--);
				return p;
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
