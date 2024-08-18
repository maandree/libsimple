/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strcasechrnul_inv(const char *s_, int c)
{
	char *s = *(char **)(void *)&s_, lc = (char)tolower(c), uc = (char)toupper(c);
	if (lc != uc)
		for (; *s && (*s == lc || *s == uc); s++);
	else
		for (; *s && *s == lc; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strcasechrnul_inv("xxoxx", 'x'), "oxx"));
	assert(!strcmpnul(libsimple_strcasechrnul_inv("xxXxx", 'x'), ""));
	assert(!strcmpnul(libsimple_strcasechrnul_inv("XXoxx", 'x'), "oxx"));
	assert(!strcmpnul(libsimple_strcasechrnul_inv("zzzzz", 'z'), ""));
	assert(!strcmpnul(libsimple_strcasechrnul_inv("", '\0'), ""));
	return 0;
}

#endif
