/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_memends(const void *s_, size_t n, const void *t_, size_t m)
{
	const char *s = s_, *t = t_;
	if (n < m)
		return 0;
	while (n--, m--)
		if (s[n] != t[m])
			return 0;
	return 1;
}
