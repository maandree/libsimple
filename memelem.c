/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_memelem(const void *hay_, const void *sub_, size_t width, size_t n)
{
	switch (width) {
	case 0:
		return REMOVE_CONST(hay_, void *);
	case 1:
		return memchr(hay_, *(const char *)sub_, n);
	case 2:
		{
			const uint16_t *hay = hay_;
			uint16_t sub = *(const uint16_t *)sub_;
			for (; n--; hay++)
				if (*hay == sub)
					return REMOVE_CONST(hay, uint16_t *);
			break;
		}
	case 4:
		{
			const uint32_t *hay = hay_;
			uint32_t sub = *(const uint32_t *)sub_;
			for (; n--; hay++)
				if (*hay == sub)
					return REMOVE_CONST(hay, uint32_t *);
			break;
		}
	case 8:
		{
			const uint64_t *hay = hay_;
			uint64_t sub = *(const uint64_t *)sub_;
			for (; n--; hay++)
				if (*hay == sub)
					return REMOVE_CONST(hay, uint64_t *);
			break;
		}
	default:
		{
			const char *hay = hay_;
			const char *sub = sub_;
			size_t i;
			for (; n--; hay += width) {
				for (i = 0; i < width; i++)
					if (hay[i] != sub[i])
						goto next;
				return REMOVE_CONST(hay, char *);
			next:;
			}
			break;
		}
	}

	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memelem("12345634", "", 0, 8), "12345634"));
	assert(!strcmpnul(libsimple_memelem("12345634", "", 0, 0), "12345634"));

	assert(!strcmpnul(libsimple_memelem("12345634", "3", 1, 8), "345634"));
	assert(!libsimple_memelem("12345634", "x", 1, 8));
	assert(!strcmpnul(libsimple_memelem("13456342", "3", 1, 8), "3456342"));
	assert(!libsimple_memelem("12345634", "3", 1, 0));

	assert(!strcmpnul(libsimple_memelem("12345634", "34", 2, 4), "345634"));
	assert(!libsimple_memelem("12345634", "xx", 2, 4));
	assert(!libsimple_memelem("13456342", "34", 2, 4));
	assert(!libsimple_memelem("12345634", "34", 2, 0));

	assert(!strcmpnul(libsimple_memelem("abcd1234abcd1234", "1234", 4, 4), "1234abcd1234"));
	assert(!libsimple_memelem("abcd1234abcd1234", "zzzz", 4, 4));
	assert(!libsimple_memelem("cd1234abcd1234ab", "1234", 4, 4));
	assert(!libsimple_memelem("abcd1234abcd1234", "1234", 4, 0));

	assert(!strcmpnul(libsimple_memelem("abcdefgh12345678abcdefgh12345678", "12345678", 8, 4), "12345678abcdefgh12345678"));
	assert(!libsimple_memelem("abcdefgh12345678abcdefgh12345678", "zzzzzzzz", 8, 4));
	assert(!libsimple_memelem("efgh12345678abcdefgh12345678abcd", "12345678", 8, 4));
	assert(!libsimple_memelem("abcdefgh12345678abcdefgh12345678", "12345678", 8, 0));

	assert(!strcmpnul(libsimple_memelem("abc123abc123", "123", 3, 4), "123abc123"));
	assert(!libsimple_memelem("abc123abc123", "zzz", 3, 4));
	assert(!libsimple_memelem("bc123abc123a", "123", 3, 4));
	assert(!libsimple_memelem("abc123abc123", "123", 3, 0));

	assert(!strcmpnul(libsimple_memelem("-a-aa--a", "a-", 2, 4), "a--a"));
	assert(!strcmpnul(libsimple_memelem("--a--aa----a", "a--", 3, 4), "a----a"));
	assert(!strcmpnul(libsimple_memelem("---a---aa------a", "a---", 4, 4), "a------a"));
	assert(!strcmpnul(libsimple_memelem("-------a-------aa--------------a", "a-------", 8, 4), "a--------------a"));

	return 0;
}

#endif
