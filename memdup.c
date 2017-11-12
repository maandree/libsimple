/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


void *
libsimple_memdup(const void *s, size_t n)
{
	void *ret = malloc(n);
	if (!ret)
		return NULL;
	return memcpy(ret, s, n);
}
