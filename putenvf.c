/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_putenvf(const char *, ...);


#else
#include "test.h"

int
main(void)
{
	unsetenv("X");
	assert(!getenv("X"));
	unsetenv("Y");
	assert(!getenv("Y"));

	putenvf("X=xyz");
	assert(!strcmpnul(getenv("X"), "xyz"));
	putenvf("Y=xyz");
	assert(!strcmpnul(getenv("Y"), "xyz"));

	putenvf("X=x%sz", "abc");
	assert(!strcmpnul(getenv("X"), "xabcz"));
	putenvf("Y=x%sz", "abc");
	assert(!strcmpnul(getenv("Y"), "xabcz"));

	putenvf("X=%ix%sz%i", 10, "abc", -11);
	assert(!strcmpnul(getenv("X"), "10xabcz-11"));
	putenvf("Y=%ix%sz%i", 10, "abc", -11);
	assert(!strcmpnul(getenv("Y"), "10xabcz-11"));

	return 0;
}

#endif
