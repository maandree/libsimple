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


#ifdef TEST
#include <assert.h>

int
main(void)
{
	const char *s = "test";
	void *p = libsimple_memdup(s, 5);
	assert(p);
	assert(p != s);
	assert(!strcmp(p, s));
	memset(p, 0, 5);
	assert(!strcmp(s, "test"));
	free(p);
	return 0;
}

#endif
