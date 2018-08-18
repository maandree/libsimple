/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_strcaseends(const char *s, const char *t)
{
	size_t sn = strlen(s);
	size_t tn = strlen(t);
	if (tn > sn)
		return 0;
	return !strcasecmp(&s[sn - tn], t);
}


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_strcaseends("", "") == 1);
	assert(libsimple_strcaseends("test", "") == 1);
	assert(libsimple_strcaseends("", "test") == 0);
	assert(libsimple_strcaseends("test", "test") == 1);
	assert(libsimple_strcaseends("test", "testx") == 0);
	assert(libsimple_strcaseends("test", "est") == 1);
	assert(libsimple_strcaseends("test", "st") == 1);
	assert(libsimple_strcaseends("test", "t") == 1);
	assert(libsimple_strcaseends("test", "x") == 0);
	assert(libsimple_strcaseends("test", "xx") == 0);

	assert(libsimple_strcaseends("TEST", "") == 1);
	assert(libsimple_strcaseends("TEST", "test") == 1);
	assert(libsimple_strcaseends("TEST", "testx") == 0);
	assert(libsimple_strcaseends("TEST", "est") == 1);
	assert(libsimple_strcaseends("TEST", "st") == 1);
	assert(libsimple_strcaseends("TEST", "t") == 1);
	assert(libsimple_strcaseends("TEST", "x") == 0);
	assert(libsimple_strcaseends("TEST", "xx") == 0);

	assert(libsimple_strcaseends("", "TEST") == 0);
	assert(libsimple_strcaseends("test", "TEST") == 1);
	assert(libsimple_strcaseends("test", "TESTX") == 0);
	assert(libsimple_strcaseends("test", "EST") == 1);
	assert(libsimple_strcaseends("test", "ST") == 1);
	assert(libsimple_strcaseends("test", "T") == 1);
	assert(libsimple_strcaseends("test", "X") == 0);
	assert(libsimple_strcaseends("test", "XX") == 0);
	return 0;
}

#endif
