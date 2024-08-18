/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_memelemscan(const void *hay_, const void *sub_, size_t width, size_t n)
{
	switch (width) {
	case 0:
		return REMOVE_CONST(hay_, void *);
	case 1:
		return libsimple_memscan(hay_, *(const char *)sub_, n);
	case 2:
		{
			const uint16_t *hay = hay_;
			uint16_t sub = *(const uint16_t *)sub_;
			for (; n-- && *hay != sub; hay++);
			return REMOVE_CONST(hay, uint16_t *);
		}
	case 4:
		{
			const uint32_t *hay = hay_;
			uint32_t sub = *(const uint32_t *)sub_;
			for (; n-- && *hay != sub; hay++);
			return REMOVE_CONST(hay, uint32_t *);
		}
	case 8:
		{
			const uint64_t *hay = hay_;
			uint64_t sub = *(const uint64_t *)sub_;
			for (; n-- && *hay != sub; hay++);
			return REMOVE_CONST(hay, uint64_t *);
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
			return REMOVE_CONST(hay, char *);
		}
	}
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memelemscan("12345634", "", 0, 8), "12345634"));
	assert(!strcmpnul(libsimple_memelemscan("12345634", "", 0, 0), "12345634"));

	assert(!strcmpnul(libsimple_memelemscan("12345634", "3", 1, 8), "345634"));
	assert(!strcmpnul(libsimple_memelemscan("12345634", "x", 1, 8), ""));
	assert(!strcmpnul(libsimple_memelemscan("13456342", "3", 1, 8), "3456342"));
	assert(!strcmpnul(libsimple_memelemscan("12345634", "3", 1, 0), "12345634"));

	assert(!strcmpnul(libsimple_memelemscan("12345634", "34", 2, 4), "345634"));
	assert(!strcmpnul(libsimple_memelemscan("12345634z", "xx", 2, 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("13456342z", "34", 2, 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("12345634z", "34", 2, 0), "12345634z"));

	assert(!strcmpnul(libsimple_memelemscan("abcd1234abcd1234", "1234", 4, 4), "1234abcd1234"));
	assert(!strcmpnul(libsimple_memelemscan("abcd1234abcd1234z", "zzzz", 4, 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("cd1234abcd1234abz", "1234", 4, 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("abcd1234abcd1234z", "1234", 4, 0), "abcd1234abcd1234z"));

	assert(!strcmpnul(libsimple_memelemscan("abcdefgh12345678abcdefgh12345678", "12345678", 8, 4), "12345678abcdefgh12345678"));
	assert(!strcmpnul(libsimple_memelemscan("abcdefgh12345678abcdefgh12345678z", "zzzzzzzz", 8, 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("efgh12345678abcdefgh12345678abcdz", "12345678", 8, 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("abcdefgh12345678abcdefgh12345678z", "12345678", 8, 0),
	                  "abcdefgh12345678abcdefgh12345678z"));

	assert(!strcmpnul(libsimple_memelemscan("abc123abc123", "123", 3, 4), "123abc123"));
	assert(!strcmpnul(libsimple_memelemscan("abc123abc123z", "zzz", 3, 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("bc123abc123az", "123", 3, 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("abc123abc123z", "123", 3, 0), "abc123abc123z"));

	assert(!strcmpnul(libsimple_memelemscan("-a-aa--a", "a-", 2, 4), "a--a"));
	assert(!strcmpnul(libsimple_memelemscan("--a--aa----a", "a--", 3, 4), "a----a"));
	assert(!strcmpnul(libsimple_memelemscan("---a---aa------a", "a---", 4, 4), "a------a"));
	assert(!strcmpnul(libsimple_memelemscan("-------a-------aa--------------a", "a-------", 8, 4), "a--------------a"));

	return 0;
}

#endif
