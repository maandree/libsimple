/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_strstarts(const char *s, const char *t)
{
	for (; *t && *s == *t; s++, t++);
	return !*t;
}
