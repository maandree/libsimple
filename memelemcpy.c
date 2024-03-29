/* See LICENSE file for copyright and license details. */
#include "common.h"
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
libsimple_memelemcpy(void *restrict d, const void *restrict s, const void *restrict elem, size_t size, size_t n)
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
	char buf[1024];


	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "hello", "o", 0, 5) == &buf[0]);
	assert(!strncmp(buf, "x", 1));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "hello", "l", 0, 5) == &buf[0]);
	assert(!strncmp(buf, "x", 1));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "hello", "x", 0, 5) == &buf[0]);
	assert(!strncmp(buf, "x", 1));


	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "hello", "o", 1, 5) == &buf[5]);
	assert(!strncmp(buf, "hellox", 6));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "hello", "l", 1, 5) == &buf[3]);
	assert(!strncmp(buf, "helx", 4));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "hello", "x", 1, 5) == NULL);
	assert(!strncmp(buf, "hellox", 6));


	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, ".h.e.l.l.o", ".o", 2, 5) == &buf[5 * 2]);
	assert(!strncmp(buf, ".h.e.l.l.ox", 11));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, ".h.e.l.l.o", ".l", 2, 5) == &buf[3 * 2]);
	assert(!strncmp(buf, ".h.e.lx", 7));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, ".h.e.l.l.o", ".x", 2, 5) == NULL);
	assert(!strncmp(buf, ".h.e.l.l.ox", 11));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, ".h.l.ll..o", "l.", 2, 5) == &buf[4 * 2]);
	assert(!strncmp(buf, ".h.l.ll.x", 9));


	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "..h..e..l..l..o", "..o", 3, 5) == &buf[5 * 3]);
	assert(!strncmp(buf, "..h..e..l..l..ox", 16));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "..h..e..l..l..o", "..l", 3, 5) == &buf[3 * 3]);
	assert(!strncmp(buf, "..h..e..lx", 10));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "..h..e..l..l..o", "..x", 3, 5) == NULL);
	assert(!strncmp(buf, "..h..e..l..l..ox", 16));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "..h..l..ll....o", "l..", 3, 5) == &buf[4 * 3]);
	assert(!strncmp(buf, "..h..l..ll..x", 13));


	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "...h...e...l...l...o", "...o", 4, 5) == &buf[5 * 4]);
	assert(!strncmp(buf, "...h...e...l...l...ox", 21));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "...h...e...l...l...o", "...l", 4, 5) == &buf[3 * 4]);
	assert(!strncmp(buf, "...h...e...lx", 13));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "...h...e...l...l...o", "...x", 4, 5) == NULL);
	assert(!strncmp(buf, "...h...e...l...l...ox", 21));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, "...h...l...ll......o", "l...", 4, 5) == &buf[4 * 4]);
	assert(!strncmp(buf, "...h...l...ll...x", 17));


	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, ".......h.......e.......l.......l.......o", ".......o", 8, 5) == &buf[5 * 8]);
	assert(!strncmp(buf, ".......h.......e.......l.......l.......ox", 21));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, ".......h.......e.......l.......l.......o", ".......l", 8, 5) == &buf[3 * 8]);
	assert(!strncmp(buf, ".......h.......e.......lx", 13));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, ".......h.......e.......l.......l.......o", ".......x", 8, 5) == NULL);
	assert(!strncmp(buf, ".......h.......e.......l.......l.......ox", 21));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_memelemcpy(buf, ".......h.......l.......ll..............o", "l.......", 8, 5) == &buf[4 * 8]);
	assert(!strncmp(buf, ".......h.......l.......ll.......x", 21));


	return 0;
}

#endif
