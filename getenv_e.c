/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline const char *libsimple_getenv_e(const char *);


#else
#include "test.h"

int
main(void)
{
	unsetenv("X");
	assert(!getenv("X"));
	assert(!strcmpnul(libsimple_getenv_e("X"), ""));
	putenv("X=xyz");
	assert(!strcmpnul(getenv("X"), "xyz"));
	assert(!strcmpnul(libsimple_getenv_e("X"), "xyz"));
	putenv("X=");
	assert(!strcmpnul(getenv("X"), ""));
	assert(!strcmpnul(libsimple_getenv_e("X"), ""));

	return 0;
}

#endif
