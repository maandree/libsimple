/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


#define RAWMEMELEMMOVE(TYPE)\
	do {\
		TYPE *p;\
		size_t n;\
		if (d <= s) {\
			for (; (*d++ = *s) != elem; s++);\
			return d;\
		} else {\
			for (p = *(TYPE **)(void *)&s; *p++ != elem;);\
			n = (size_t)(p - s);\
			p = &d[n];\
			while (n) {\
				n--;\
				d[n] = s[n];\
			}\
			return p;\
		}\
	} while (0)


static uint16_t *
rawmemelemmove16(uint16_t *restrict d, const uint16_t *restrict s, uint16_t elem)
{
	RAWMEMELEMMOVE(uint16_t);
}


static uint32_t *
rawmemelemmove32(uint32_t *restrict d, const uint32_t *restrict s, uint32_t elem)
{
	RAWMEMELEMMOVE(uint32_t);
}


static uint64_t *
rawmemelemmove64(uint64_t *restrict d, const uint64_t *restrict s, uint64_t elem)
{
	RAWMEMELEMMOVE(uint64_t);
}


static char *
rawmemelemmovex(char *restrict d, const char *restrict s, const char *restrict elem, size_t width)
{
	char *p;
	size_t i, n;
	if (d <= s) {
		for (;; s += width) {
			for (i = 0; i < width; i++)
				d[i] = s[i];
			for (i = 0; i < width; i++)
				if (d[i] != elem[i])
					goto next_forwards;
			d += width;
			return d;
		next_forwards:
			d += width;
		}
	} else {
		for (p = *(char **)(void *)&s;;) {
			for (i = 0; i < width; i++)
				if (p[i] != elem[i])
					goto next_backwards;
			p += width;
			break;
		next_backwards:
			p += width;
		}
		n = (size_t)(p - s);
		p = &d[n];
		while (n) {
			n--;
			d[n] = s[n];
		}
		return p;
	}
}


void *
libsimple_rawmemelemmove(void *d, const void *s, const void *restrict elem, size_t width) /* TODO man */
{
	switch (width) {
	case 0:
		return d;
	case 1:
		return rawmemcmove(d, s, *(const char *)elem);
	case 2:
		return rawmemelemmove16(d, s, *(const uint16_t *)elem);
	case 4:
		return rawmemelemmove32(d, s, *(const uint32_t *)elem);
	case 8:
		return rawmemelemmove64(d, s, *(const uint64_t *)elem);
	default:
		return rawmemelemmovex(d, s, elem, width);
	}
}


#else
#include "test.h"

int
main(void)
{
	char buf[1024];


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "", 0) == &buf[5]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "", 0) == &buf[3]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[3], "", 0) == &buf[5]);
	assert(!strncmp(buf, "-----hello-", 11));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "o", 1) == &buf[5 + 5]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';;
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "l", 1) == &buf[5 + 3]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "o", 1) == &buf[3 + 5]);
	assert(!strncmp(buf, "---hellolo-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "l", 1) == &buf[3 + 3]);
	assert(!strncmp(buf, "---helello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "o", 1) == &buf[8 + 5]);
	assert(!strncmp(buf, "-----helhello-", 14));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "l", 1) == &buf[8 + 3]);
	assert(!strncmp(buf, "-----helhel-", 12));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], ".o", 2) == &buf[5 + 5 * 2]);
	assert(!strncmp(buf, "-----.h.e.l.l.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';;
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], ".l", 2) == &buf[5 + 3 * 2]);
	assert(!strncmp(buf, "-----.h.e.l.l.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], ".o", 2) == &buf[3 + 5 * 2]);
	assert(!strncmp(buf, "---.h.e.l.l.o.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], ".l", 2) == &buf[3 + 3 * 2]);
	assert(!strncmp(buf, "---.h.e.l.l.l.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], ".o", 2) == &buf[8 + 5 * 2]);
	assert(!strncmp(buf, "-----.h..h.e.l.l.o-", 19));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], ".l", 2) == &buf[8 + 3 * 2]);
	assert(!strncmp(buf, "-----.h..h.e.lo-", 16));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "..o", 3) == &buf[5 + 5 * 3]);
	assert(!strncmp(buf, "-----..h..e..l..l..o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';;
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "..l", 3) == &buf[5 + 3 * 3]);
	assert(!strncmp(buf, "-----..h..e..l..l..o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "..o", 3) == &buf[3 + 5 * 3]);
	assert(!strncmp(buf, "---..h..e..l..l..o.o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "..l", 3) == &buf[3 + 3 * 3]);
	assert(!strncmp(buf, "---..h..e..l.l..l..o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "..o", 3) == &buf[8 + 5 * 3]);
	assert(!strncmp(buf, "-----..h..h..e..l..l..o-", 24));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "..l", 3) == &buf[8 + 3 * 3]);
	assert(!strncmp(buf, "-----..h..h..e..l..o-", 21));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "...o", 4) == &buf[5 + 5 * 4]);
	assert(!strncmp(buf, "-----...h...e...l...l...o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';;
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "...l", 4) == &buf[5 + 3 * 4]);
	assert(!strncmp(buf, "-----...h...e...l...l...o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "...o", 4) == &buf[3 + 5 * 4]);
	assert(!strncmp(buf, "---...h...e...l...l...o.o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "...l", 4) == &buf[3 + 3 * 4]);
	assert(!strncmp(buf, "---...h...e...l.l...l...o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "...o", 4) == &buf[8 + 5 * 4]);
	assert(!strncmp(buf, "-----......h...e...l...l...o-", 29));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "...l", 4) == &buf[8 + 3 * 4]);
	assert(!strncmp(buf, "-----......h...e...ll...o-", 26));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], ".......o", 8) == &buf[5 + 5 * 8]);
	assert(!strncmp(buf, "-----.......h.......e.......l.......l.......o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';;
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], ".......l", 8) == &buf[5 + 3 * 8]);
	assert(!strncmp(buf, "-----.......h.......e.......l.......l.......o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], ".......o", 8) == &buf[3 + 5 * 8]);
	assert(!strncmp(buf, "---.......h.......e.......l.......l.......o.o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], ".......l", 8) == &buf[3 + 3 * 8]);
	assert(!strncmp(buf, "---.......h.......e.......l.l.......l.......o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], ".......o", 8) == &buf[8 + 5 * 8]);
	assert(!strncmp(buf, "-----..........h.......e.......l.......l.......o-", 49));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], ".......l", 8) == &buf[8 + 3 * 8]);
	assert(!strncmp(buf, "-----..........h.......e.......l....l.......o-", 46));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".a.a.aa..a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "a.", 2) == &buf[5 + 4 * 2]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".a.a.aa..a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "a.", 2) == &buf[3 + 4 * 2]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".a.a.aa..a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "a.", 2) == &buf[8 + 4 * 2]);


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..a..a..aa....a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "a..", 3) == &buf[5 + 4 * 3]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..a..a..aa....a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "a..", 3) == &buf[3 + 4 * 3]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..a..a..aa....a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "a..", 3) == &buf[8 + 4 * 3]);


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...a...a...aa......a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "a...", 4) == &buf[5 + 4 * 4]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...a...a...aa......a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "a...", 4) == &buf[3 + 4 * 4]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...a...a...aa......a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "a...", 4) == &buf[8 + 4 * 4]);


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......a.......a.......aa..............a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[5], &buf[5], "a.......", 8) == &buf[5 + 4 * 8]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......a.......a.......aa..............a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[3], &buf[5], "a.......", 8) == &buf[3 + 4 * 8]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......a.......a.......aa..............a")[0] = '-';
	assert(libsimple_rawmemelemmove(&buf[8], &buf[5], "a.......", 8) == &buf[8 + 4 * 8]);


	return 0;
}

#endif
