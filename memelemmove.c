/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


#define MEMELEMMOVE(TYPE)\
	do {\
		TYPE *p;\
		if (d <= s) {\
			for (; n; n--, s++)\
				if ((*d++ = *s) == elem)\
					return d;\
		} else {\
			for (p = *(TYPE **)(void *)&s; n; n--, p++) {\
				if (*p == elem) {\
					n = (size_t)(p - s);\
					p = &d[n + 1];\
					do { d[n] = s[n]; } while (n--);\
					return p;\
				}\
			}\
			for (n = (size_t)(p - s); n;) {\
				n--;\
				d[n] = s[n];\
			}\
		}\
		return NULL;\
	} while (0)


static uint16_t *
memelemmove16(uint16_t *restrict d, const uint16_t *restrict s, uint16_t elem, size_t n)
{
	MEMELEMMOVE(uint16_t);
}


static uint32_t *
memelemmove32(uint32_t *restrict d, const uint32_t *restrict s, uint32_t elem, size_t n)
{
	MEMELEMMOVE(uint32_t);
}


static uint64_t *
memelemmove64(uint64_t *restrict d, const uint64_t *restrict s, uint64_t elem, size_t n)
{
	MEMELEMMOVE(uint64_t);
}


static char *
memelemmovex(char *restrict d, const char *restrict s, const char *restrict elem, size_t size, size_t n)
{
	char *p;
	size_t i;
	if (d <= s) {
		for (; n; s += size, n--) {
			for (i = 0; i < size; i++)
				d[i] = s[i];
			for (i = 0; i < size; i++)
				if (d[i] != elem[i])
					goto next_forwards;
			d += size;
			return d;
		next_forwards:
			d += size;
		}
		return NULL;
	} else {
		for (p = *(char **)(void *)&s; n; n--) {
			for (i = 0; i < size; i++)
				if (p[i] != elem[i])
					goto next_backwards;
			
			p += size;
			n = (size_t)(p - s);
			p = &d[n];
			goto out_backwards;
		next_backwards:
			p += size;
		}
		n = (size_t)(p - s);
		p = NULL;
	out_backwards:
		while (n) {
			n--;
			d[n] = s[n];
		}
		return p;
	}
}


void *
libsimple_memelemmove(void *d, const void *s, const void *restrict elem, size_t size, size_t n) /* TODO man */
{
	switch (size) {
	case 0:
		return d;
	case 1:
		return memcmove(d, s, *(const char *)elem, n);
	case 2:
		return memelemmove16(d, s, *(const uint16_t *)elem, n);
	case 4:
		return memelemmove32(d, s, *(const uint32_t *)elem, n);
	case 8:
		return memelemmove64(d, s, *(const uint64_t *)elem, n);
	default:
		return memelemmovex(d, s, elem, size, n);
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
	assert(libsimple_memelemmove(&buf[5], &buf[5], "", 0, 5) == &buf[5]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "", 0, 5) == &buf[3]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[3], "", 0, 5) == &buf[5]);
	assert(!strncmp(buf, "-----hello-", 11));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "o", 1, 5) == &buf[5 + 5]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';;
	assert(libsimple_memelemmove(&buf[5], &buf[5], "l", 1, 5) == &buf[5 + 3]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "x", 1, 5) == NULL);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "o", 1, 5) == &buf[3 + 5]);
	assert(!strncmp(buf, "---hellolo-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "l", 1, 5) == &buf[3 + 3]);
	assert(!strncmp(buf, "---helello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "x", 1, 5) == NULL);
	assert(!strncmp(buf, "---hellolo-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "o", 1, 5) == &buf[8 + 5]);
	assert(!strncmp(buf, "-----helhello-", 14));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "l", 1, 5) == &buf[8 + 3]);
	assert(!strncmp(buf, "-----helhel-", 12));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "x", 1, 5) == NULL);
	assert(!strncmp(buf, "-----helhello-", 14));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], ".o", 2, 5) == &buf[5 + 5 * 2]);
	assert(!strncmp(buf, "-----.h.e.l.l.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';;
	assert(libsimple_memelemmove(&buf[5], &buf[5], ".l", 2, 5) == &buf[5 + 3 * 2]);
	assert(!strncmp(buf, "-----.h.e.l.l.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], ".x", 2, 5) == NULL);
	assert(!strncmp(buf, "-----.h.e.l.l.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], ".o", 2, 5) == &buf[3 + 5 * 2]);
	assert(!strncmp(buf, "---.h.e.l.l.o.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], ".l", 2, 5) == &buf[3 + 3 * 2]);
	assert(!strncmp(buf, "---.h.e.l.l.l.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], ".x", 2, 5) == NULL);
	assert(!strncmp(buf, "---.h.e.l.l.o.o-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], ".o", 2, 5) == &buf[8 + 5 * 2]);
	assert(!strncmp(buf, "-----.h..h.e.l.l.o-", 19));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], ".l", 2, 5) == &buf[8 + 3 * 2]);
	assert(!strncmp(buf, "-----.h..h.e.lo-", 16));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".h.e.l.l.o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], ".x", 2, 5) == NULL);
	assert(!strncmp(buf, "-----.h..h.e.l.l.o-", 19));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "..o", 3, 5) == &buf[5 + 5 * 3]);
	assert(!strncmp(buf, "-----..h..e..l..l..o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';;
	assert(libsimple_memelemmove(&buf[5], &buf[5], "..l", 3, 5) == &buf[5 + 3 * 3]);
	assert(!strncmp(buf, "-----..h..e..l..l..o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "..x", 3, 5) == NULL);
	assert(!strncmp(buf, "-----..h..e..l..l..o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "..o", 3, 5) == &buf[3 + 5 * 3]);
	assert(!strncmp(buf, "---..h..e..l..l..o.o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "..l", 3, 5) == &buf[3 + 3 * 3]);
	assert(!strncmp(buf, "---..h..e..l.l..l..o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "..x", 3, 5) == NULL);
	assert(!strncmp(buf, "---..h..e..l..l..o.o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "..o", 3, 5) == &buf[8 + 5 * 3]);
	assert(!strncmp(buf, "-----..h..h..e..l..l..o-", 24));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "..l", 3, 5) == &buf[8 + 3 * 3]);
	assert(!strncmp(buf, "-----..h..h..e..l..o-", 21));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..h..e..l..l..o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "..x", 3, 5) == NULL);
	assert(!strncmp(buf, "-----..h..h..e..l..l..o-", 24));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "...o", 4, 5) == &buf[5 + 5 * 4]);
	assert(!strncmp(buf, "-----...h...e...l...l...o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';;
	assert(libsimple_memelemmove(&buf[5], &buf[5], "...l", 4, 5) == &buf[5 + 3 * 4]);
	assert(!strncmp(buf, "-----...h...e...l...l...o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "...x", 4, 5) == NULL);
	assert(!strncmp(buf, "-----...h...e...l...l...o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "...o", 4, 5) == &buf[3 + 5 * 4]);
	assert(!strncmp(buf, "---...h...e...l...l...o.o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "...l", 4, 5) == &buf[3 + 3 * 4]);
	assert(!strncmp(buf, "---...h...e...l.l...l...o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "...x", 4, 5) == NULL);
	assert(!strncmp(buf, "---...h...e...l...l...o.o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "...o", 4, 5) == &buf[8 + 5 * 4]);
	assert(!strncmp(buf, "-----......h...e...l...l...o-", 29));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "...l", 4, 5) == &buf[8 + 3 * 4]);
	assert(!strncmp(buf, "-----......h...e...ll...o-", 26));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...h...e...l...l...o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "...x", 4, 5) == NULL);
	assert(!strncmp(buf, "-----......h...e...l...l...o-", 29));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], ".......o", 8, 5) == &buf[5 + 5 * 8]);
	assert(!strncmp(buf, "-----.......h.......e.......l.......l.......o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';;
	assert(libsimple_memelemmove(&buf[5], &buf[5], ".......l", 8, 5) == &buf[5 + 3 * 8]);
	assert(!strncmp(buf, "-----.......h.......e.......l.......l.......o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], ".......x", 8, 5) == NULL);
	assert(!strncmp(buf, "-----.......h.......e.......l.......l.......o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], ".......o", 8, 5) == &buf[3 + 5 * 8]);
	assert(!strncmp(buf, "---.......h.......e.......l.......l.......o.o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], ".......l", 8, 5) == &buf[3 + 3 * 8]);
	assert(!strncmp(buf, "---.......h.......e.......l.l.......l.......o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], ".......x", 8, 5) == NULL);
	assert(!strncmp(buf, "---.......h.......e.......l.......l.......o.o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], ".......o", 8, 5) == &buf[8 + 5 * 8]);
	assert(!strncmp(buf, "-----..........h.......e.......l.......l.......o-", 49));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], ".......l", 8, 5) == &buf[8 + 3 * 8]);
	assert(!strncmp(buf, "-----..........h.......e.......l....l.......o-", 46));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......h.......e.......l.......l.......o")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], ".......x", 8, 5) == NULL);
	assert(!strncmp(buf, "-----..........h.......e.......l.......l.......o-", 49));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".a.a.aa..a")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "a.", 2, 5) == &buf[5 + 4 * 2]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".a.a.aa..a")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "a.", 2, 5) == &buf[3 + 4 * 2]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".a.a.aa..a")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "a.", 2, 5) == &buf[8 + 4 * 2]);


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..a..a..aa....a")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "a..", 3, 5) == &buf[5 + 4 * 3]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..a..a..aa....a")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "a..", 3, 5) == &buf[3 + 4 * 3]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "..a..a..aa....a")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "a..", 3, 5) == &buf[8 + 4 * 3]);


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...a...a...aa......a")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "a...", 4, 5) == &buf[5 + 4 * 4]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...a...a...aa......a")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "a...", 4, 5) == &buf[3 + 4 * 4]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "...a...a...aa......a")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "a...", 4, 5) == &buf[8 + 4 * 4]);


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......a.......a.......aa..............a")[0] = '-';
	assert(libsimple_memelemmove(&buf[5], &buf[5], "a.......", 8, 5) == &buf[5 + 4 * 8]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......a.......a.......aa..............a")[0] = '-';
	assert(libsimple_memelemmove(&buf[3], &buf[5], "a.......", 8, 5) == &buf[3 + 4 * 8]);

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], ".......a.......a.......aa..............a")[0] = '-';
	assert(libsimple_memelemmove(&buf[8], &buf[5], "a.......", 8, 5) == &buf[8 + 4 * 8]);


	return 0;
}

#endif
