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
libsimple_memelemmove(void *d, const void *s, const void *restrict elem, size_t size, size_t n) /* TODO test, man */
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
	return 0;
}

#endif
