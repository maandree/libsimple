/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


int
libsimple_strends(const char *s, const char *t)
{
	return memends(s, strlen(s), t, strlen(t));
}
