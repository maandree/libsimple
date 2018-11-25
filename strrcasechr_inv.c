/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrcasechr_inv(const char *s_, int c)
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
	assert(!strcmpnul(libsimple_strrcasechr_inv("aabbaabb", 'b'), "abb"));
	assert(!strcmpnul(libsimple_strrcasechr_inv("aabbaabb", 'B'), "abb"));
	assert(!strcmpnul(libsimple_strrcasechr_inv("AABBAABB", 'b'), "ABB"));
	assert(!strcmpnul(libsimple_strrcasechr_inv("AABBAABB", 'B'), "ABB"));
	assert(!strcmpnul(libsimple_strrcasechr_inv("aabbaabb", 'a'), "b"));
	assert(!strcmpnul(libsimple_strrcasechr_inv("aabbaabb", '\0'), "b"));
	assert(!strcmpnul(libsimple_strrcasechr_inv("--------", '-'), NULL));
	return 0;
}

#endif
