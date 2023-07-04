/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


ssize_t
libsimple_bindex_r(const void *key, const void *base, size_t nel, size_t width,
                   int (*compar)(const void *, const void *, void *), void *arg)
{
	size_t index = 0, offset = 0;
	int cmp;

	while (nel) {
		index = offset + nel / 2;
		cmp = (*compar)(key, (const char *)base + width * index, arg);
		if (cmp < 0) {
			nel /= 2;
		} else if (cmp > 0) {
			offset = index += 1;
			nel -= nel / 2 + 1;
		} else {
			return (ssize_t)index;
		}
	}

	return ~(ssize_t)index;
}


#else
#include "test.h"

int
main(void) /* TODO add test */
{
	return 0;
}

#endif
