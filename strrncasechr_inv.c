/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrncasechr_inv(const char *s_, int c, size_t n) /* TODO test, man */
{
	char *s = *(char **)(void *)&s_;
	char *end = &s[n], *r = NULL;
	c = tolower(c);
	for (; s != end; s++) {
		if (tolower(*s) != c)
			r = s;
		if (!*s)
			break;
	}
	return r;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
