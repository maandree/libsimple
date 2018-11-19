/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemchr_inv(const void *s_, int c_) /* TODO man */
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	while (*s++ == c);
	return &s[-1];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemchr_inv("xxoxx", 'x'), "oxx"));
	assert(!strcmpnul(libsimple_rawmemchr_inv("xxXxx", 'x'), "Xxx"));
	assert(!strcmpnul(libsimple_rawmemchr_inv("XXoxx", 'x'), "XXoxx"));
	return 0;
}

#endif
