/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline char *libsimple_getenv_ne(const char *);


#else
#include "test.h"

int
main(void)
{
	char env1[] = "X=xyz";
	char env2[] = "X=";

	unsetenv("X");
	assert(!getenv("X"));
	assert(!libsimple_getenv_ne("X"));
	putenv(env1);
	assert(!strcmpnul(getenv("X"), "xyz"));
	assert(!strcmpnul(libsimple_getenv_ne("X"), "xyz"));
	putenv(env2);
	assert(!strcmpnul(getenv("X"), ""));
	assert(!libsimple_getenv_ne("X"));

	return 0;
}

#endif
