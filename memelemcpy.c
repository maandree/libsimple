/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


static inline uint8_t *
memelemcpy8(uint8_t *restrict d, const uint8_t *restrict s, uint8_t elem, size_t n)
{
	for (; n; s++, n--)
		if ((*d++ = *s) == elem)
			return d;
	return NULL;
}


static inline uint16_t *
memelemcpy16(uint16_t *restrict d, const uint16_t *restrict s, uint16_t elem, size_t n)
{
	for (; n; s++, n--)
		if ((*d++ = *s) == elem)
			return d;
	return NULL;
}


static inline uint32_t *
memelemcpy32(uint32_t *restrict d, const uint32_t *restrict s, uint32_t elem, size_t n)
{
	for (; n; s++, n--)
		if ((*d++ = *s) == elem)
			return d;
	return NULL;
}


static inline uint64_t *
memelemcpy64(uint64_t *restrict d, const uint64_t *restrict s, uint64_t elem, size_t n)
{
	for (; n; s++, n--)
		if ((*d++ = *s) == elem)
			return d;
	return NULL;
}


static inline char *
memelemcpyx(char *restrict d, const char *restrict s, const char *restrict elem, size_t size, size_t n)
{
	size_t i;
	for (; n; s += size, n--) {
		for (i = 0; i < size; i++)
			d[i] = s[i];
		for (i = 0; i < size; i++)
			if (d[i] != elem[i])
				goto next;
		d += size;
		return d;
	next:
		d += size;
	}
	return NULL;
}


void *
libsimple_memelemcpy(void *restrict d, const void *restrict s, const void *restrict elem, size_t size, size_t n) /* TODO test, man */
{
	switch (size) {
	case 0:
		return d;
	case 1:
		return memelemcpy8(d, s, *(const uint8_t *)elem, n);
	case 2:
		return memelemcpy16(d, s, *(const uint16_t *)elem, n);
	case 4:
		return memelemcpy32(d, s, *(const uint32_t *)elem, n);
	case 8:
		return memelemcpy64(d, s, *(const uint64_t *)elem, n);
	default:
		return memelemcpyx(d, s, elem, size, n);
	}
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
