/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline const char *libsimple_getenv_e(const char *);


#else
#include "test.h"

int
main(void)
{
	char env1[] = "X=xyz";
	char env2[] = "X=";

	unsetenv("X");
	assert(!getenv("X"));
	assert(!strcmpnul(libsimple_getenv_e("X"), ""));
	putenv(env1);
	assert(!strcmpnul(getenv("X"), "xyz"));
	assert(!strcmpnul(libsimple_getenv_e("X"), "xyz"));
	putenv(env2);
	assert(!strcmpnul(getenv("X"), ""));
	assert(!strcmpnul(libsimple_getenv_e("X"), ""));

	return 0;
}

#endif
