/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_strends(const char *s, const char *t)
{
	return memends(s, strlen(s), t, strlen(t));
}


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strends("", "") == 1);
	assert(libsimple_strends("test", "") == 1);
	assert(libsimple_strends("", "test") == 0);
	assert(libsimple_strends("test", "test") == 1);
	assert(libsimple_strends("test", "testx") == 0);
	assert(libsimple_strends("test", "est") == 1);
	assert(libsimple_strends("test", "st") == 1);
	assert(libsimple_strends("test", "t") == 1);
	assert(libsimple_strends("test", "x") == 0);
	assert(libsimple_strends("test", "xx") == 0);

	assert(libsimple_strends("TEST", "") == 1);
	assert(libsimple_strends("TEST", "test") == 0);
	assert(libsimple_strends("TEST", "testx") == 0);
	assert(libsimple_strends("TEST", "est") == 0);
	assert(libsimple_strends("TEST", "st") == 0);
	assert(libsimple_strends("TEST", "t") == 0);
	assert(libsimple_strends("TEST", "x") == 0);
	assert(libsimple_strends("TEST", "xx") == 0);

	assert(libsimple_strends("", "TEST") == 0);
	assert(libsimple_strends("test", "TEST") == 0);
	assert(libsimple_strends("test", "TESTX") == 0);
	assert(libsimple_strends("test", "EST") == 0);
	assert(libsimple_strends("test", "ST") == 0);
	assert(libsimple_strends("test", "T") == 0);
	assert(libsimple_strends("test", "X") == 0);
	assert(libsimple_strends("test", "XX") == 0);
	return 0;
}

#endif
