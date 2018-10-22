/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_strnend(const char *s_, size_t n)
{
	char *s = *(char **)(void *)&s_;
	char *end = &s[n];
	for (; s != end && *s; s++);
	return s;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_strnend("123456789", 0), "123456789"));
	assert(!strcmpnul(libsimple_strnend("123456789", 1), "23456789"));
	assert(!strcmpnul(libsimple_strnend("123456789", 2), "3456789"));
	assert(!strcmpnul(libsimple_strnend("123456789", 3), "456789"));
	assert(!strcmpnul(libsimple_strnend("123456789", 4), "56789"));
	assert(!strcmpnul(libsimple_strnend("123456789", 5), "6789"));
	assert(!strcmpnul(libsimple_strnend("123456789", 6), "789"));
	assert(!strcmpnul(libsimple_strnend("123456789", 7), "89"));
	assert(!strcmpnul(libsimple_strnend("123456789", 8), "9"));
	assert(!strcmpnul(libsimple_strnend("123456789", 9), ""));
	assert(!strcmpnul(libsimple_strnend("123456789", 10), ""));
	assert(!strcmpnul(libsimple_strnend("123456789", 11), ""));
	assert(!strcmpnul(libsimple_strnend("123456789", 12), ""));
	return 0;
}

#endif
