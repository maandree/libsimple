/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


uintmax_t
libsimple_random_unsigned(uintmax_t (*rng)(size_t bits, void *user), void *user, uintmax_t min, uintmax_t max) /* TODO add test */
{
	uintmax_t range, offset, t, r;
	size_t bits = 0;

	if (min < max) {
		range = max - min;
		offset = min;
	} else {
		range = min - max;
		offset = max;
	}

	for (t = range; t; t >>= 1)
		bits += 1;

	do {
		r = (*rng)(bits, user);
	} while (r > range);

	return r + offset;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
