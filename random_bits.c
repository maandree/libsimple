/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


uintmax_t
libsimple_random_bits(size_t bits, void *unused)
{
	uintmax_t ret = 0;

	while (bits >= 8) {
		ret <<= 8;
		ret |= (uintmax_t)(rand() & 0xFF);
		bits -= 8;
	}

	ret <<= bits;
	ret |= (uintmax_t)(rand() & ((1 << bits) - 1));

	(void) unused;
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
