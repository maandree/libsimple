/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrchr_inv(const char *s_, int c_) /* TODO test, man */
{
	char *s = *(char **)(void *)&s_, c = (char)c_, *r = NULL;
	for (; *s; s++)
		if (*s != c)
			r = s;
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
