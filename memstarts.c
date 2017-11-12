/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_memstarts(const void *s_, size_t n, const void *t_, size_t m)
{
	const char *s = s_, *t = t_;
	size_t i = 0;
	if (n < m)
		return 0;
	while (i < m && s[i] == t[i]) i++;
	return i == m;
}
