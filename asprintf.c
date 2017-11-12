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
