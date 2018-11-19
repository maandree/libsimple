/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrnchr_inv(const char *s_, int c_, size_t n) /* TODO test, man */
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	char *end = &s[n], *r = NULL;
	for (; s != end; s++) {
		if (*s != c)
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
