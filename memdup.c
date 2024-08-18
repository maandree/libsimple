/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_memdup(const void *s, size_t n)
{
	void *ret = malloc(n + !n);
	if (!ret)
		return NULL;
	return memcpy(ret, s, n);
}


#else
#include "test.h"

int
main(void)
{
	const char *s = "test";
	void *p = libsimple_memdup(s, 5);
	assert(p);
	assert(p != s);
	assert(!strcmpnul(p, s));
	memset(p, 0, 5);
	assert(!strcmpnul(s, "test"));
	free(p);
	return 0;
}

#endif
