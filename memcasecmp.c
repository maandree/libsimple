/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_memcasecmp(const void *a_, const void *b_, size_t n)
{
	char *a = *(char **)(void *)&a_;
	char *b = *(char **)(void *)&b_;
	size_t i = 0;
	for (; i < n && tolower(a[i]) == tolower(b[i]); i++);
	if (i == n)
		return 0;
	return (tolower(a[i]) & 255) - (tolower(b[i]) & 255);
}


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_memcasecmp("x", "y", 0) == 0);
	assert(libsimple_memcasecmp("x", "x", 1) == 0);
	assert(libsimple_memcasecmp("x", "y", 1) < 0);
	assert(libsimple_memcasecmp("y", "x", 1) > 0);
	assert(libsimple_memcasecmp("x", "X", 1) == 0);
	assert(libsimple_memcasecmp("x", "Y", 1) < 0);
	assert(libsimple_memcasecmp("y", "X", 1) > 0);
	assert(libsimple_memcasecmp("X", "x", 1) == 0);
	assert(libsimple_memcasecmp("X", "y", 1) < 0);
	assert(libsimple_memcasecmp("Y", "x", 1) > 0);
	assert(libsimple_memcasecmp("X", "X", 1) == 0);
	assert(libsimple_memcasecmp("X", "Y", 1) < 0);
	assert(libsimple_memcasecmp("Y", "X", 1) > 0);
	assert(libsimple_memcasecmp("\x00", "\xFF", 1) < 0);
	assert(libsimple_memcasecmp("\xFF", "\x00", 1) > 0);
	assert(libsimple_memcasecmp("\x00", "\x00", 1) == 0);
	assert(libsimple_memcasecmp("\xFF", "\xFF", 1) == 0);
	assert(libsimple_memcasecmp("abc", "abc", 3) == 0);
	assert(libsimple_memcasecmp("abc", "abd", 3) < 0);
	assert(libsimple_memcasecmp("abd", "abc", 3) > 0);
	assert(libsimple_memcasecmp("abc", "ABC", 3) == 0);
	assert(libsimple_memcasecmp("abc", "ABD", 3) < 0);
	assert(libsimple_memcasecmp("abd", "ABC", 3) > 0);
	assert(libsimple_memcasecmp("ABC", "abc", 3) == 0);
	assert(libsimple_memcasecmp("ABC", "abd", 3) < 0);
	assert(libsimple_memcasecmp("ABD", "abc", 3) > 0);
	assert(libsimple_memcasecmp("ABC", "ABC", 3) == 0);
	assert(libsimple_memcasecmp("ABC", "ABD", 3) < 0);
	assert(libsimple_memcasecmp("ABD", "ABC", 3) > 0);
	return 0;
}

#endif
