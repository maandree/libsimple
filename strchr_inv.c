/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strchr_inv(const char *s_, int c_) /* TODO man */
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	for (; *s && *s == c; s++);
	return *s ? s : NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strchr_inv("xxoxx", 'x'), "oxx"));
	assert(!strcmpnul(libsimple_strchr_inv("xxXxx", 'x'), "Xxx"));
	assert(!strcmpnul(libsimple_strchr_inv("XXoxx", 'x'), "XXoxx"));
	assert(!strcmpnul(libsimple_strchr_inv("zzzzz", 'z'), NULL));
	assert(!strcmpnul(libsimple_strchr_inv("", '\0'), NULL));
	return 0;
}

#endif
