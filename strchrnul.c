/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strchrnul(const char *s_, char c_)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	for (; *s && *s != c; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strchrnul("1234512345", '3'), "34512345"));
	assert(!strcmpnul(libsimple_strchrnul("1234512345", '1'), "1234512345"));
	assert(!strcmpnul(libsimple_strchrnul("1234512345", 'x'), ""));
	return 0;
}

#endif
