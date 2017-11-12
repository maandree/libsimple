/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_strchrnul(const char *s_, int c)
{
	char *s = *(char **)(void *)&s_;
	for (; *s && (int)*s != c; s++);
	return s;
}
