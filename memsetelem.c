/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void *libsimple_memsetelem(void *, const void *, size_t, size_t);


#else
#include "test.h"

int
main(void)
{
	_Alignas(8) char buf_[4096];
	_Alignas(8) char *buf = buf_;
	size_t i;

	memset(buf, 0, sizeof(buf_));
	assert(libsimple_memsetelem(buf, &(uint64_t){~(uint64_t)0}, 0, 0) == buf);
	assert(libsimple_memsetelem(buf, &(uint64_t){~(uint64_t)0}, 0, 10) == buf);
	assert(libsimple_memsetelem(buf, &(uint64_t){~(uint64_t)0}, 1, 0) == buf);
	assert(libsimple_memsetelem(buf, &(uint64_t){~(uint64_t)0}, 2, 0) == buf);
	assert(libsimple_memsetelem(buf, &(uint64_t){~(uint64_t)0}, 4, 0) == buf);
	assert(libsimple_memsetelem(buf, &(uint64_t){~(uint64_t)0}, 8, 0) == buf);
	assert(libsimple_memsetelem(buf, &(uint64_t){~(uint64_t)0}, 16, 0) == buf);
	assert(libsimple_memsetelem(buf, &(uint64_t){~(uint64_t)0}, 3, 0) == buf);
	assert(libsimple_memsetelem(buf, &(uint8_t){0x09}, 1, 3000) == buf);
	assert(libsimple_memsetelem(buf, &(uint16_t){0x0807}, 2, 1000) == buf);
	assert(libsimple_memsetelem(buf, &(uint32_t){0x10203040UL}, 4, 300) == buf);
	assert(libsimple_memsetelem(buf, &(uint64_t){0x0102030450607080ULL}, 8, 100) == buf);
	assert(libsimple_memsetelem(buf, (char []){(char)0xA0, (char)0xB0, (char)0xC0}, 3, 16) == buf);

#if defined(__clang__)
# pragma clang diagnostic ignored "-Wcast-align"
#endif

	for (i = 0; i < 48; i++)
		assert(buf[i] == ((char []){(char)0xA0, (char)0xB0, (char)0xC0})[i % 3]);
	for (; i < 800; i += 8)
		assert(*(uint64_t *)&buf[i] == 0x0102030450607080ULL);
	for (; i < 1200; i += 4)
		assert(*(uint32_t *)&buf[i] == 0x10203040UL);
	for (; i < 2000; i += 2)
		assert(*(uint16_t *)&buf[i] == 0x0807);
	for (; i < 3000; i++)
		assert(buf[i] == 0x09);
	for (; i < sizeof(buf_); i++)
		assert(buf[i] == 0);

	return 0;
}

#endif
