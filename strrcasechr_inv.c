/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrcasechr_inv(const char *s_, int c) /* TODO test, man */
{
	char *s = *(char **)(void *)&s_, lc = (char)tolower(c), uc = (char)toupper(c), *r = NULL;
	if (lc != uc) {
		for (; *s; s++)
			if (*s != lc && *s != uc)
				r = s;
	} else {
		for (; *s; s++)
			if (*s != lc)
				r = s;
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
