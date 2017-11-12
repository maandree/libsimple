/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


void *
libsimple_memrchr(const void *s_, int c, size_t n_)
{
	char *s = *(char **)(void *)&s_;
	ssize_t n = n_;
	while (n-- && (int)s[n] != c);
	return n < 0 ? NULL : &s[n];
}
