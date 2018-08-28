/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


static inline size_t
alloc_size_product(size_t n, va_list ap) /* TODO test */
{
	size_t prod = n;
	if (!n) {
		errno = EINVAL;
		return 0;
	}
	for (;;) {
		n = va_arg(ap, size_t);
		if (!n)
			break;
		if (n >= SIZE_MAX / prod) {
			errno = ENOMEM;
			return 0;
		}
		prod *= n;
	}
	return prod;
}

void *
libsimple_vmalloczn(int clear, size_t n, va_list ap) /* TODO test */
{
	n = alloc_size_product(n, ap);
	return !n ? NULL : clear ? calloc(1, n) : malloc(n);
}

void *
libsimple_vreallocn(void *ptr, size_t n, va_list ap) /* TODO test */
{
	n = alloc_size_product(n, ap);
	return !n ? NULL : realloc(ptr, n);
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
