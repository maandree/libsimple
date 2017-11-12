/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_strcasestr(const char *h_, const char *n)
{
	char *h = *(char **)(void *)&h_;
	size_t hn = strlen(h);
	size_t nn = strlen(n);
	if (hn < nn)
		return NULL;
	for (hn -= nn; hn--; h++)
		if (!strcasecmp(h, n))
			return h;
	return NULL;
}
