/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strrncasechr_inv(const char *s_, int c, size_t n) /* TODO man */
{
	char *s = *(char **)(void *)&s_;
	char *end = &s[n], *r = NULL;
	c = tolower(c);
	for (; *s && s != end; s++)
		if (tolower(*s) != c)
			r = s;
	return r;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'b', SIZE_MAX), "abb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'B', SIZE_MAX), "abb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'b', SIZE_MAX), "ABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'B', SIZE_MAX), "ABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'a', SIZE_MAX), "b"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", '\0', SIZE_MAX), "b"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("--------", '-', SIZE_MAX), NULL));

	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'b', 9), "abb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'B', 9), "abb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'b', 9), "ABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'B', 9), "ABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'a', 9), "b"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", '\0', 9), "b"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("--------", '-', 9), NULL));

	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'b', 8), "abb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'B', 8), "abb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'b', 8), "ABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'B', 8), "ABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'a', 8), "b"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", '\0', 8), "b"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("--------", '-', 8), NULL));

	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'b', 7), "abb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'B', 7), "abb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'b', 7), "ABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'B', 7), "ABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'a', 7), "bb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", '\0', 7), "bb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("--------", '-', 7), NULL));

	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'b', 4), "abbaabb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'B', 4), "abbaabb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'b', 4), "ABBAABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'B', 4), "ABBAABB"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'a', 4), "baabb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", '\0', 4), "baabb"));
	assert(!strcmpnul(libsimple_strrncasechr_inv("--------", '-', 4), NULL));

	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'b', 0), NULL));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'B', 0), NULL));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'b', 0), NULL));
	assert(!strcmpnul(libsimple_strrncasechr_inv("AABBAABB", 'B', 0), NULL));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", 'a', 0), NULL));
	assert(!strcmpnul(libsimple_strrncasechr_inv("aabbaabb", '\0', 0), NULL));
	assert(!strcmpnul(libsimple_strrncasechr_inv("--------", '-', 0), NULL));

	return 0;
}

#endif
