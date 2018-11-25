/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_aligned_strndup(const char *s, size_t alignment, size_t n) /* TODO test */
{
	char *ret;
	n = strnlen(s, n);
	ret = aligned_alloc(alignment, (n + 1) + (alignment - (n + 1) % alignment) % alignment);
	if (!ret)
		return NULL;
	memcpy(ret, s, n);
	ret[n] = '\0';
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
