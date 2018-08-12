/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_strstarts(const char *s, const char *t)
{
	for (; *t && *s == *t; s++, t++);
	return !*t;
}


#ifdef TEST
#include <assert.h>

int
main(void)
{
	assert(libsimple_strstarts("", "") == 1);
	assert(libsimple_strstarts("test", "") == 1);
	assert(libsimple_strstarts("", "test") == 0);
	assert(libsimple_strstarts("test", "test") == 1);
	assert(libsimple_strstarts("test", "testx") == 0);
	assert(libsimple_strstarts("test", "tes") == 1);
	assert(libsimple_strstarts("test", "te") == 1);
	assert(libsimple_strstarts("test", "t") == 1);
	assert(libsimple_strstarts("test", "x") == 0);
	assert(libsimple_strstarts("test", "xx") == 0);

	assert(libsimple_strstarts("TEST", "") == 1);
	assert(libsimple_strstarts("TEST", "test") == 0);
	assert(libsimple_strstarts("TEST", "testx") == 0);
	assert(libsimple_strstarts("TEST", "tes") == 0);
	assert(libsimple_strstarts("TEST", "te") == 0);
	assert(libsimple_strstarts("TEST", "t") == 0);
	assert(libsimple_strstarts("TEST", "x") == 0);
	assert(libsimple_strstarts("TEST", "xx") == 0);

	assert(libsimple_strstarts("", "TEST") == 0);
	assert(libsimple_strstarts("test", "TEST") == 0);
	assert(libsimple_strstarts("test", "TESTX") == 0);
	assert(libsimple_strstarts("test", "TES") == 0);
	assert(libsimple_strstarts("test", "TE") == 0);
	assert(libsimple_strstarts("test", "T") == 0);
	assert(libsimple_strstarts("test", "X") == 0);
	assert(libsimple_strstarts("test", "XX") == 0);
	return 0;
}

#endif
