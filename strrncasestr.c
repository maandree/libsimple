/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_strrncasestr(const char *h_, const char *n, size_t len)
{
	char *h = *(char **)(void *)&h_;
	size_t hn = strlen(h);
	size_t nn = strlen(n);
	hn = MIN(hn, len);
	nn = MIN(nn, len);
	if (!nn)
		return &h[hn];
	if (hn < nn)
		return NULL;
	for (h += hn -= nn; hn--; h--)
		if (!strncasecmp(h, n, nn))
			return h;
	if (!strncasecmp(h, n, nn))
		return h;
	return NULL;
}
