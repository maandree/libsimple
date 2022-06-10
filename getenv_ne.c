/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline char *libsimple_getenv_ne(const char *);


#else
#include "test.h"

int
main(void)
{
	unsetenv("X");
	assert(!getenv("X"));
	assert(!libsimple_getenv_ne("X"));
	putenv("X=xyz");
	assert(!strcmpnul(getenv("X"), "xyz"));
	assert(!strcmpnul(libsimple_getenv_ne("X"), "xyz"));
	putenv("X=");
	assert(!strcmpnul(getenv("X"), ""));
	assert(!libsimple_getenv_ne("X"));

	return 0;
}

#endif
