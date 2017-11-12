/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_strndup(const char *s, size_t n)
{
	void *ret;
	if (n == SIZE_MAX) {
		errno = ENOMEM;
		return NULL;
	}
	if (!(ret = malloc(n + 1)))
		return NULL;
	memcpy(ret, s, n);
	((char *)ret)[n] = '\0';
	return ret;
}
