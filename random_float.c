/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#include <math.h>


long double
libsimple_random_float(uintmax_t (*rng)(size_t bits, void *user), void *user, long double min, long double postmax) /* TODO add test */
{
	long double range, offset, mantissa, value;
	uintmax_t r;
	int exp;
	size_t bits;

	if (min < postmax) {
		range = postmax - min;
		offset = min;
	} else if (min > postmax) {
		range = min - postmax;
		offset = postmax;
	} else {
		return min;
	}

	mantissa = frexpl(range, &exp);
	do {
		bits = sizeof(uintmax_t) * CHAR_BIT;
		r = (*rng)(bits, user);
		while (bits && (r & 1)) {
			exp -= 1;
			bits -= 1;
			r >>= 1;
		}
	} while (!bits);

	bits = sizeof(uintmax_t) * CHAR_BIT;
	r = (*rng)(bits, user);
	value = (long double)r;
	value = fmal(value, 0.5, 0.5);
	value = ldexpl(value, -(int)bits);

	value = ldexpl(value, exp);
	value *= mantissa;
	return value + offset;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
