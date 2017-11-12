/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


void *
libsimple_memmem(const void *hay_, size_t hayn, const void *sub_, size_t subn)
{
	char *hay = (void *)hay_, *end;
	const char *sub = sub_;

	if (!subn)
		return hay;
	if (hayn < subn)
		return NULL;
	if (subn == 1)
		return memchr(hay, *sub, hayn);

	for (end = &hay[hayn - subn + 1]; hay != end; hay++)
		if (*hay == *sub && !memcmp(hay, sub, subn))
			return hay;

	return NULL;
}
