/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_memsetelem(void *, const void *, size_t, size_t);


#else
#include "test.h"

int
main(void)
{
	char p_[4096];
	char *p = p_;
	size_t i;

	memset(p, 0, sizeof(p_));
	assert(libsimple_memsetelem(p, &(uint64_t){~(uint64_t)0}, 0, 0) == p);
	assert(libsimple_memsetelem(p, &(uint64_t){~(uint64_t)0}, 0, 10) == p);
	assert(libsimple_memsetelem(p, &(uint64_t){~(uint64_t)0}, 1, 0) == p);
	assert(libsimple_memsetelem(p, &(uint64_t){~(uint64_t)0}, 2, 0) == p);
	assert(libsimple_memsetelem(p, &(uint64_t){~(uint64_t)0}, 4, 0) == p);
	assert(libsimple_memsetelem(p, &(uint64_t){~(uint64_t)0}, 8, 0) == p);
	assert(libsimple_memsetelem(p, &(uint64_t){~(uint64_t)0}, 16, 0) == p);
	assert(libsimple_memsetelem(p, &(uint64_t){~(uint64_t)0}, 3, 0) == p);
	assert(libsimple_memsetelem(p, &(uint8_t){0x09}, 1, 3000) == p);
	assert(libsimple_memsetelem(p, &(uint16_t){0x0807}, 2, 1000) == p);
	assert(libsimple_memsetelem(p, &(uint32_t){0x10203040UL}, 4, 300) == p);
	assert(libsimple_memsetelem(p, &(uint64_t){0x0102030450607080ULL}, 8, 100) == p);
	assert(libsimple_memsetelem(p, (char []){(char)0xA0, (char)0xB0, (char)0xC0}, 3, 16) == p);

	for (i = 0; i < 48; i++)
		assert(p[i] == ((char []){(char)0xA0, (char)0xB0, (char)0xC0})[i % 3]);
	for (; i < 800; i += 8)
		assert(*(uint64_t *)&p[i] == 0x0102030450607080ULL);
	for (; i < 1200; i += 4)
		assert(*(uint32_t *)&p[i] == 0x10203040UL);
	for (; i < 2000; i += 2)
		assert(*(uint16_t *)&p[i] == 0x0807);
	for (; i < 3000; i++)
		assert(p[i] == 0x09);
	for (; i < sizeof(p_); i++)
		assert(p[i] == 0);

	return 0;
}

#endif
