/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
vputenvf(const char *fmt, va_list ap)
{
	va_list ap2;
	int n;
	char *s;
	va_copy(ap2, ap);
	n = vsnprintf(NULL, 0, fmt, ap2);
	va_end(ap2);
	if (n < 0)
		return -1;
	if ((size_t)n == SIZE_MAX) {
		errno = ENOMEM;
		return -1;
	}
	s = alloca((size_t)n + 1);
	vsprintf(s, fmt, ap);
	return putenv(s);
}
