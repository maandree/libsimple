/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemcasechr_inv(const void *s_, int c)
{
	char *s = *(char **)(void *)&s_;
	c = tolower(c);
	for (; tolower(*s) == c; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemcasechr_inv("xxoxx", 'x'), "oxx"));
	assert(!strcmpnul(libsimple_rawmemcasechr_inv("XXoxx", 'x'), "oxx"));
	return 0;
}

#endif
