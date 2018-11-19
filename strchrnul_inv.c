/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strchrnul_inv(const char *s_, int c_) /* TODO man */
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	for (; *s && *s == c; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strchrnul_inv("xxoxx", 'x'), "oxx"));
	assert(!strcmpnul(libsimple_strchrnul_inv("xxXxx", 'x'), "Xxx"));
	assert(!strcmpnul(libsimple_strchrnul_inv("XXoxx", 'x'), "XXoxx"));
	assert(!strcmpnul(libsimple_strchrnul_inv("zzzzz", 'z'), ""));
	assert(!strcmpnul(libsimple_strchrnul_inv("", '\0'), ""));
	return 0;
}

#endif
