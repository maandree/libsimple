/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void
libsimple_envposix_memalignzn(int status, void **memptr, int clear, size_t alignment, size_t n, va_list ap)
{
	int err = libsimple_vposix_memalignzn(memptr, clear, alignment, n, ap);
	if (err) {
		errno = err;
		enprintf(status, "posix_memalign:");
	}
}


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested via libsimple_enposix_memalignzn */
}

#endif
