/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_mempsetelem(void *buf_, const void *item, size_t width, size_t n)
{
	switch (width) {
	case 0:
		return buf_;
	case 1:
		return &((char *)memset(buf_, *(const char *)item, n))[n];
	case 2:
		if ((uintptr_t)buf_ % _Alignof(uint16_t) || (uintptr_t)item % _Alignof(uint16_t))
			goto misaligned;
		{
			uint16_t *buf = buf_;
			uint16_t *end = &buf[n];
			uint16_t e = *(const uint16_t *)item;
			for (; buf != end; buf++)
				*buf = e;
			return buf;
		}
	case 4:
		if ((uintptr_t)buf_ % _Alignof(uint32_t) || (uintptr_t)item % _Alignof(uint32_t))
			goto misaligned;
		{
			uint32_t *buf = buf_;
			uint32_t *end = &buf[n];
			uint32_t e = *(const uint32_t *)item;
			for (; buf != end; buf++)
				*buf = e;
			return buf;
		}
	case 8:
		if ((uintptr_t)buf_ % _Alignof(uint64_t) || (uintptr_t)item % _Alignof(uint64_t))
			goto misaligned;
		{
			uint64_t *buf = buf_;
			uint64_t *end = &buf[n];
			uint64_t e = *(const uint64_t *)item;
			for (; buf != end; buf++)
				*buf = e;
			return buf;
		}
	default:
	misaligned:
		{
			char *buf = buf_;
			size_t i;
			for (; n--; buf += width)
				for (i = 0; i < width; i++)
					buf[i] = ((const char *)item)[i];
			return buf;
		}
	}
}


#else
#include "test.h"

int
main(void)
{
	_Alignas(8) char buf_[4096];
	_Alignas(8) char *buf = buf_;
	size_t i;

	memset(buf, 0, sizeof(buf_));
	assert(libsimple_mempsetelem(buf, &(uint64_t){~(uint64_t)0}, 0, 0) == &buf[0]);
	assert(libsimple_mempsetelem(buf, &(uint64_t){~(uint64_t)0}, 0, 10) == &buf[0]);
	assert(libsimple_mempsetelem(buf, &(uint64_t){~(uint64_t)0}, 1, 0) == &buf[0]);
	assert(libsimple_mempsetelem(buf, &(uint64_t){~(uint64_t)0}, 2, 0) == &buf[0]);
	assert(libsimple_mempsetelem(buf, &(uint64_t){~(uint64_t)0}, 4, 0) == &buf[0]);
	assert(libsimple_mempsetelem(buf, &(uint64_t){~(uint64_t)0}, 8, 0) == &buf[0]);
	assert(libsimple_mempsetelem(buf, &(uint64_t){~(uint64_t)0}, 16, 0) == &buf[0]);
	assert(libsimple_mempsetelem(buf, &(uint64_t){~(uint64_t)0}, 3, 0) == &buf[0]);
	assert(libsimple_mempsetelem(buf, &(uint8_t){0x09}, 1, 3000) == &buf[3000]);
	assert(libsimple_mempsetelem(buf, &(uint16_t){0x0807}, 2, 1000) == &buf[2000]);
	assert(libsimple_mempsetelem(buf, &(uint32_t){0x10203040UL}, 4, 300) == &buf[1200]);
	assert(libsimple_mempsetelem(buf, &(uint64_t){0x0102030450607080ULL}, 8, 100) == &buf[800]);
	assert(libsimple_mempsetelem(buf, (char []){(char)0xA0, (char)0xB0, (char)0xC0}, 3, 16) == &buf[48]);

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
