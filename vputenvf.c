/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_vputenvf(const char *fmt, va_list ap)
{
	va_list ap2;
	int n;
	char *s, *p;
	va_copy(ap2, ap);
	n = vsnprintf(NULL, 0, fmt, ap2);
	va_end(ap2);
	if (n < 0)
		return -1;
	s = alloca((size_t)n + 1);
	vsprintf(s, fmt, ap);
	p = strchr(s, '=');
	if (p) {
		*p++ = '\0';
		return setenv(s, p, 1);
	} else {
		s = strdup(s);
		return s ? putenv(s) : -1;
	}
}


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
