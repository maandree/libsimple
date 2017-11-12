/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


void *
libsimple_rawmemrchr(const void *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	while ((int)s[--n] != c);
	return &s[n];
}
