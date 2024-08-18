/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_envaligned_reallocn(int status, void *ptr, size_t alignment, size_t n, va_list ap) /* TODO test (evaligned_reallocn, aligned_reallocn, enaligned_reallocn, ealigned_reallocn) */
{
	void *ret = valigned_reallocn(ptr, alignment, n, ap);
	if (!ret)
		enprintf(status, "valigned_reallocn:");
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
