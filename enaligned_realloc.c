/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_enaligned_realloc(int status, void *ptr, size_t alignment, size_t n) /* TODO test (ealigned_realloc) */
{
	void *ret = aligned_realloc(ptr, alignment, n);
	if (!ret)
		enprintf(status, "aligned_realloc:");
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
