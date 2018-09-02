/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_envmemalloc(int status, size_t n, va_list ap) /* TODO test (e[n][v]{mem,array}alloc) */
{
	void *ret;
	int saved_errno = errno;
	errno = 0;
	ret = libsimple_vmemalloc(n, ap);
	if (errno)
		enprintf(status, "libsimple_vmemalloc:");
	errno = saved_errno;
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
