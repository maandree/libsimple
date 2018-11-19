/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strncasechrnul_inv(const char *s_, int c, size_t n) /* TODO man */
{
	char *s = *(char **)(void *)&s_;
	char *end = &s[n];
	c = tolower(c);
	for (; s != end && *s && tolower(*s) == c; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxoxx", 'x', SIZE_MAX), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxXxx", 'x', SIZE_MAX), ""));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("XXoxx", 'x', SIZE_MAX), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("zzzzz", 'z', SIZE_MAX), ""));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("", '\0', SIZE_MAX), ""));

	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxoxx", 'x', 6), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxXxx", 'x', 6), ""));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("XXoxx", 'x', 6), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("zzzzz", 'z', 6), ""));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("", '\0', 6), ""));

	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxXxx", 'x', 5), ""));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("XXoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("zzzzz", 'z', 5), ""));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("", '\0', 5), ""));

	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxoxx", 'x', 3), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxXxx", 'x', 3), "xx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("XXoxx", 'x', 3), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("zzzzz", 'z', 3), "zz"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("", '\0', 3), ""));

	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxoxx", 'x', 2), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("xxXxx", 'x', 2), "Xxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("XXoxx", 'x', 2), "oxx"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("zzzzz", 'z', 2), "zzz"));
	assert(!strcmpnul(libsimple_strncasechrnul_inv("", '\0', 2), ""));
	return 0;
}

#endif
