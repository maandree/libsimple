/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_asprintf(char **strp, const char *fmt, ...)
{
	va_list ap;
	int r;
	va_start(ap, fmt);
	r = libsimple_vasprintf(strp, fmt, ap);
	va_end(ap);
	return r;
}


#else
#include "test.h"

int
main(void)
{
	char empty[1] = "";
	char *s = empty;
	char *old = s;

	assert(libsimple_asprintf(&s, "%i %X", 99999, 255U) == sizeof("99999 FF") - 1);
	assert(s && s != old);
	assert(!strcmpnul(s, "99999 FF"));
	free(s);

	return 0;
}

#endif
