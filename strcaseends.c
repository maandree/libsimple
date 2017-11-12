/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_strcaseends(const char *s, const char *t)
{
	size_t sn = strlen(s);
	size_t tn = strlen(t);
	if (tn > sn)
		return 0;
	return !strcasecmp(&s[sn - tn], t);
}
