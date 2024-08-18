/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#include <sys/auxv.h>


unsigned int
libsimple_generate_seed(void) /* TODO add test */
{
	uintptr_t longseed = 1;
	void *ptr;
	uintptr_t ptri;
	unsigned int seed;
	struct timespec ts;
	uint8_t (*at_random)[16];
	size_t i;

	if (!clock_gettime(CLOCK_REALTIME, &ts))
		longseed ^= (uintptr_t)ts.tv_sec * (uintptr_t)1000000000UL + (uintptr_t)ts.tv_nsec;

	ptr = malloc(1);
	ptri = (uintptr_t)ptr;
	free(ptr);
	longseed ^= ptri;
	longseed ^= (uintptr_t)&ptri;
	longseed ^= (uintptr_t)clock();

	if (!clock_gettime(CLOCK_MONOTONIC_RAW, &ts))
		longseed ^= (uintptr_t)ts.tv_sec * (uintptr_t)1000000000UL + (uintptr_t)ts.tv_nsec;

	ptri = (uintptr_t)getauxval(AT_RANDOM);
	if (ptri) {
		at_random = (void *)ptri;
		for (i = 0; i < ELEMSOF(*at_random); i++)
			longseed ^= (*at_random)[i] << (i % sizeof(longseed) * (size_t)CHAR_BIT);
	}

	seed = 0;
	while (longseed) {
		seed ^= (unsigned int)longseed;
		longseed >>= sizeof(unsigned int) * (CHAR_BIT - 1);
		longseed >>= sizeof(unsigned int);
	}

	return seed;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
