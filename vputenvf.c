/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_vputenvf(const char *fmt, va_list ap)
{
	va_list ap2;
	int n, r;
	char *s, *p;
	va_copy(ap2, ap);
	n = vsnprintf(NULL, 0, fmt, ap2);
	va_end(ap2);
	if (n < 0)
		return -1;
	s = malloc((size_t)n + 1);
	if (!s)
		return -1;
	vsprintf(s, fmt, ap);
	p = strchr(s, '=');
	if (p) {
		*p++ = '\0';
		r = setenv(s, p, 1);
		free(s);
	} else {
		r = putenv(s);
	}
	return r;
}


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested via libsimple_putenvf */
}

#endif
