/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


void *
libsimple_rawmemchr(const void *s_, int c)
{
	char *s = *(char **)(void *)&s_;
	while ((int)*s++ != c);
	return &s[-1];
}
