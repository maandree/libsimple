/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrchr_inv(const char *s_, int c_) /* TODO man */
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
	assert(!strcmpnul(libsimple_strrchr_inv("aabbaabb", 'b'), "abb"));
	assert(!strcmpnul(libsimple_strrchr_inv("aabbaabb", 'B'), "b"));
	assert(!strcmpnul(libsimple_strrchr_inv("AABBAABB", 'b'), "B"));
	assert(!strcmpnul(libsimple_strrchr_inv("AABBAABB", 'B'), "ABB"));
	assert(!strcmpnul(libsimple_strrchr_inv("aabbaabb", 'a'), "b"));
	assert(!strcmpnul(libsimple_strrchr_inv("aabbaabb", '\0'), "b"));
	assert(!strcmpnul(libsimple_strrchr_inv("--------", '-'), NULL));
	return 0;
}

#endif
