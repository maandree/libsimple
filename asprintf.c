/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


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


#ifdef TEST
#include <assert.h>

int
main(void)
{
	char *s = "";
	char *old = s;

	assert(libsimple_asprintf(&s, "%i %X", 99999, 255) == sizeof("99999 FF") - 1);
	assert(s && s != old);
	assert(!strcmp(s, "99999 FF"));
	free(s);

	return 0;
}

#endif
