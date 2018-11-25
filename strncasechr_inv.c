/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strncasechr_inv(const char *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	char *end = &s[n];
	c = tolower(c);
	for (; s != end && *s && tolower(*s) == c; s++);
	return (s == end || !*s || tolower(*s) == c) ? NULL : s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strncasechr_inv("xxoxx", 'x', SIZE_MAX), "oxx"));
	assert(!strcmpnul(libsimple_strncasechr_inv("xxXxx", 'x', SIZE_MAX), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("XXoxx", 'x', SIZE_MAX), "oxx"));
	assert(!strcmpnul(libsimple_strncasechr_inv("zzzzz", 'z', SIZE_MAX), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("", '\0', SIZE_MAX), NULL));

	assert(!strcmpnul(libsimple_strncasechr_inv("xxoxx", 'x', 6), "oxx"));
	assert(!strcmpnul(libsimple_strncasechr_inv("xxXxx", 'x', 6), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("XXoxx", 'x', 6), "oxx"));
	assert(!strcmpnul(libsimple_strncasechr_inv("zzzzz", 'z', 6), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("", '\0', 6), NULL));

	assert(!strcmpnul(libsimple_strncasechr_inv("xxoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_strncasechr_inv("xxXxx", 'x', 5), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("XXoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_strncasechr_inv("zzzzz", 'z', 5), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("", '\0', 5), NULL));

	assert(!strcmpnul(libsimple_strncasechr_inv("xxoxx", 'x', 3), "oxx"));
	assert(!strcmpnul(libsimple_strncasechr_inv("xxXxx", 'x', 3), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("XXoxx", 'x', 3), "oxx"));
	assert(!strcmpnul(libsimple_strncasechr_inv("zzzzz", 'z', 3), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("", '\0', 3), NULL));

	assert(!strcmpnul(libsimple_strncasechr_inv("xxoxx", 'x', 2), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("xxXxx", 'x', 2), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("XXoxx", 'x', 2), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("zzzzz", 'z', 2), NULL));
	assert(!strcmpnul(libsimple_strncasechr_inv("", '\0', 2), NULL));
	return 0;
}

#endif
