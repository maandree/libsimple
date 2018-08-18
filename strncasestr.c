/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_strncasestr(const char *h_, const char *n, size_t len)
{
	char *h = *(char **)(void *)&h_;
	size_t nn = strlen(n);
	nn = MIN(nn, len);
	if (!nn)
		return h;
	for (; *h && len--; h++)
		if (!strncasecmp(h, n, nn))
			return h;
	return NULL;
}
