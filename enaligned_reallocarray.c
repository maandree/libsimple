/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_enaligned_reallocarray(int status, void *ptr, size_t alignment, size_t n, size_t m) /* TODO test (ealigned_reallocarray) */
{
	void *ret = aligned_reallocarray(ptr, alignment, n, m);
	if (!ret)
		enprintf(status, "aligned_reallocarray:");
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
