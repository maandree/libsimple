/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strcasechr_inv(const char *s_, int c)
{
	char *s = *(char **)(void *)&s_, lc = (char)tolower(c), uc = (char)toupper(c);
	if (lc != uc)
		for (; *s && (*s == lc || *s == uc); s++);
	else
		for (; *s && *s == lc; s++);
	return *s ? s : NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strcasechr_inv("xxoxx", 'x'), "oxx"));
	assert(!strcmpnul(libsimple_strcasechr_inv("xxXxx", 'x'), NULL));
	assert(!strcmpnul(libsimple_strcasechr_inv("XXoxx", 'x'), "oxx"));
	assert(!strcmpnul(libsimple_strcasechr_inv("zzzzz", 'z'), NULL));
	assert(!strcmpnul(libsimple_strcasechr_inv("", '\0'), NULL));
	return 0;
}

#endif
