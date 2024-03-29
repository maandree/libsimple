/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_memcaseends(const void *s_, size_t n, const void *t_, size_t m)
{
	const char *s = s_, *t = t_;
	if (n < m)
		return 0;
	while (m) {
		n--;
		m--;
		if (tolower(s[n]) != tolower(t[m]))
			return 0;
	}
	return 1;
}


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_memcaseends("", 0, "", 0) == 1);
	assert(libsimple_memcaseends("test", 4, "", 0) == 1);
	assert(libsimple_memcaseends("", 0, "test", 4) == 0);
	assert(libsimple_memcaseends("test", 4, "test", 4) == 1);
	assert(libsimple_memcaseends("test", 4, "test", 5) == 0);
	assert(libsimple_memcaseends("test", 4, "testx", 5) == 0);
	assert(libsimple_memcaseends("test", 4, "est", 3) == 1);
	assert(libsimple_memcaseends("test", 4, "st", 2) == 1);
	assert(libsimple_memcaseends("test", 4, "t", 1) == 1);
	assert(libsimple_memcaseends("test", 4, "x", 1) == 0);
	assert(libsimple_memcaseends("test", 4, "xx", 2) == 0);

	assert(libsimple_memcaseends("TEST", 4, "", 0) == 1);
	assert(libsimple_memcaseends("TEST", 4, "test", 4) == 1);
	assert(libsimple_memcaseends("TEST", 4, "test", 5) == 0);
	assert(libsimple_memcaseends("TEST", 4, "testx", 5) == 0);
	assert(libsimple_memcaseends("TEST", 4, "est", 3) == 1);
	assert(libsimple_memcaseends("TEST", 4, "st", 2) == 1);
	assert(libsimple_memcaseends("TEST", 4, "t", 1) == 1);
	assert(libsimple_memcaseends("TEST", 4, "x", 1) == 0);
	assert(libsimple_memcaseends("TEST", 4, "xx", 2) == 0);

	assert(libsimple_memcaseends("", 0, "TEST", 4) == 0);
	assert(libsimple_memcaseends("test", 4, "TEST", 4) == 1);
	assert(libsimple_memcaseends("test", 4, "TEST", 5) == 0);
	assert(libsimple_memcaseends("test", 4, "TESTX", 5) == 0);
	assert(libsimple_memcaseends("test", 4, "EST", 3) == 1);
	assert(libsimple_memcaseends("test", 4, "ST", 2) == 1);
	assert(libsimple_memcaseends("test", 4, "T", 1) == 1);
	assert(libsimple_memcaseends("test", 4, "X", 1) == 0);
	assert(libsimple_memcaseends("test", 4, "XX", 2) == 0);
	return 0;
}

#endif
