/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


char *
libsimple_strndup(const char *s, size_t n) /* FIXME */
{
	char *ret;
	size_t m = strlen(s);
	n = MIN(n, m);
	if (n == SIZE_MAX) {
		errno = ENOMEM;
		return NULL;
	}
	if (!(ret = malloc(n + 1)))
		return NULL;
	memcpy(ret, s, n);
	ret[n] = '\0';
	return ret;
}


#ifdef TEST
#include <assert.h>

int
main(void)
{
	const char *s = "test";
	void *p;

	p = libsimple_memdup(s, 5);
	assert(p && p != s);
	assert(!strcmp(p, "test"));
	memset(p, 0, 5);
	assert(!strcmp(s, "test"));
	free(p);

	p = libsimple_memdup(s, 3);
	assert(p && p != s);
	assert(!strcmp(p, "tes"));
	memset(p, 0, 5);
	assert(!strcmp(s, "test"));
	free(p);

	p = libsimple_memdup(s, 0);
	assert(p && p != s);
	assert(!strcmp(p, ""));
	memset(p, 0, 5);
	assert(!strcmp(s, "test"));
	free(p);

	return 0;
}

#endif
