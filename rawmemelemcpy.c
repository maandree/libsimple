/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


static inline uint8_t *
rawmemelemcpy8(uint8_t *restrict d, const uint8_t *restrict s, uint16_t elem)
{
	for (; (*d++ = *s) != elem; s++);
	return d;
}


static inline uint16_t *
rawmemelemcpy16(uint16_t *restrict d, const uint16_t *restrict s, uint16_t elem)
{
	for (; (*d++ = *s) != elem; s++);
	return d;
}


static inline uint32_t *
rawmemelemcpy32(uint32_t *restrict d, const uint32_t *restrict s, uint32_t elem)
{
	for (; (*d++ = *s) != elem; s++);
	return d;
}


static inline uint64_t *
rawmemelemcpy64(uint64_t *restrict d, const uint64_t *restrict s, uint64_t elem)
{
	for (; (*d++ = *s) != elem; s++);
	return d;
}


static inline char *
rawmemelemcpyx(char *restrict d, const char *restrict s, const char *restrict elem, size_t width)
{
	size_t i;
	for (;; s += width) {
		for (i = 0; i < width; i++)
			d[i] = s[i];
		for (i = 0; i < width; i++)
			if (d[i] != elem[i])
				goto next;
		d += width;
		return d;
	next:
		d += width;
	}
}


void *
libsimple_rawmemelemcpy(void *restrict d, const void *restrict s, const void *restrict elem, size_t width) /* TODO man */
{
	switch (width) {
	case 0:
		return d;
	case 1:
		return rawmemelemcpy8(d, s, *(const uint8_t *)elem);
	case 2:
		return rawmemelemcpy16(d, s, *(const uint16_t *)elem);
	case 4:
		return rawmemelemcpy32(d, s, *(const uint32_t *)elem);
	case 8:
		return rawmemelemcpy64(d, s, *(const uint64_t *)elem);
	default:
		return rawmemelemcpyx(d, s, elem, width);
	}
}


#else
#include "test.h"

int
main(void)
{
	char buf[1024];


	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "hello", "o", 0) == &buf[0]);
	assert(!strncmp(buf, "x", 1));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "hello", "l", 0) == &buf[0]);
	assert(!strncmp(buf, "x", 1));


	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "hello", "o", 1) == &buf[5]);
	assert(!strncmp(buf, "hellox", 6));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "hello", "l", 1) == &buf[3]);
	assert(!strncmp(buf, "helx", 4));


	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, ".h.e.l.l.o", ".o", 2) == &buf[5 * 2]);
	assert(!strncmp(buf, ".h.e.l.l.ox", 11));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, ".h.e.l.l.o", ".l", 2) == &buf[3 * 2]);
	assert(!strncmp(buf, ".h.e.lx", 7));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, ".h.l.ll..o", "l.", 2) == &buf[4 * 2]);
	assert(!strncmp(buf, ".h.l.ll.x", 9));


	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "..h..e..l..l..o", "..o", 3) == &buf[5 * 3]);
	assert(!strncmp(buf, "..h..e..l..l..ox", 16));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "..h..e..l..l..o", "..l", 3) == &buf[3 * 3]);
	assert(!strncmp(buf, "..h..e..lx", 10));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "..h..l..ll....o", "l..", 3) == &buf[4 * 3]);
	assert(!strncmp(buf, "..h..l..ll..x", 13));


	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "...h...e...l...l...o", "...o", 4) == &buf[5 * 4]);
	assert(!strncmp(buf, "...h...e...l...l...ox", 21));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "...h...e...l...l...o", "...l", 4) == &buf[3 * 4]);
	assert(!strncmp(buf, "...h...e...lx", 13));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, "...h...l...ll......o", "l...", 4) == &buf[4 * 4]);
	assert(!strncmp(buf, "...h...l...ll...x", 17));


	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, ".......h.......e.......l.......l.......o", ".......o", 8) == &buf[5 * 8]);
	assert(!strncmp(buf, ".......h.......e.......l.......l.......ox", 21));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, ".......h.......e.......l.......l.......o", ".......l", 8) == &buf[3 * 8]);
	assert(!strncmp(buf, ".......h.......e.......lx", 13));

	memset(buf, 'x', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_rawmemelemcpy(buf, ".......h.......l.......ll..............o", "l.......", 8) == &buf[4 * 8]);
	assert(!strncmp(buf, ".......h.......l.......ll.......x", 21));


	return 0;
}

#endif
