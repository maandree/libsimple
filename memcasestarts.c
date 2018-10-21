/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_memcasestarts(const void *s_, size_t n, const void *t_, size_t m)
{
	const char *s = s_, *t = t_;
	size_t i = 0;
	if (n < m)
		return 0;
	while (i < m && tolower(s[i]) == tolower(t[i])) i++;
	return i == m;
}


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_memcasestarts("", 0, "", 0) == 1);
	assert(libsimple_memcasestarts("test", 4, "", 0) == 1);
	assert(libsimple_memcasestarts("", 0, "test", 4) == 0);
	assert(libsimple_memcasestarts("test", 4, "test", 4) == 1);
	assert(libsimple_memcasestarts("test", 4, "test", 5) == 0);
	assert(libsimple_memcasestarts("test", 4, "testx", 5) == 0);
	assert(libsimple_memcasestarts("test", 4, "tes", 3) == 1);
	assert(libsimple_memcasestarts("test", 4, "te", 2) == 1);
	assert(libsimple_memcasestarts("test", 4, "t", 1) == 1);
	assert(libsimple_memcasestarts("test", 4, "x", 1) == 0);
	assert(libsimple_memcasestarts("test", 4, "xx", 2) == 0);

	assert(libsimple_memcasestarts("TEST", 4, "", 0) == 1);
	assert(libsimple_memcasestarts("TEST", 4, "test", 4) == 1);
	assert(libsimple_memcasestarts("TEST", 4, "test", 5) == 0);
	assert(libsimple_memcasestarts("TEST", 4, "testx", 5) == 0);
	assert(libsimple_memcasestarts("TEST", 4, "tes", 3) == 1);
	assert(libsimple_memcasestarts("TEST", 4, "te", 2) == 1);
	assert(libsimple_memcasestarts("TEST", 4, "t", 1) == 1);
	assert(libsimple_memcasestarts("TEST", 4, "x", 1) == 0);
	assert(libsimple_memcasestarts("TEST", 4, "xx", 2) == 0);

	assert(libsimple_memcasestarts("", 0, "TEST", 4) == 0);
	assert(libsimple_memcasestarts("test", 4, "TEST", 4) == 1);
	assert(libsimple_memcasestarts("test", 4, "TEST", 5) == 0);
	assert(libsimple_memcasestarts("test", 4, "TESTX", 5) == 0);
	assert(libsimple_memcasestarts("test", 4, "TES", 3) == 1);
	assert(libsimple_memcasestarts("test", 4, "TE", 2) == 1);
	assert(libsimple_memcasestarts("test", 4, "T", 1) == 1);
	assert(libsimple_memcasestarts("test", 4, "X", 1) == 0);
	assert(libsimple_memcasestarts("test", 4, "XX", 2) == 0);
	return 0;
}

#endif
