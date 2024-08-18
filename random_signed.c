/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


intmax_t
libsimple_random_signed(uintmax_t (*rng)(size_t bits, void *user), void *user, intmax_t min, intmax_t max) /* TODO add test */
{
	uintmax_t range, offset, t, r;
	size_t bits = 0;

	range = libsimple_imaxabs(max, min);
	offset = (uintmax_t)MIN(min, max);

	for (t = range; t; t >>= 1)
		bits += 1;

	do {
		r = (*rng)(bits, user);
	} while (r > range);

	return libsimple_toimax(r + offset);
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
