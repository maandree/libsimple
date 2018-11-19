/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memelemscan(const void *hay_, size_t hayn, const void *sub_, size_t subn)
{
	switch (subn) {
	case 0:
		return (void *)hay_;
	case 1:
		return libsimple_memscan(hay_, *(char *)sub_, hayn);
	case 2:
		{
			uint16_t *hay = (void *)hay_;
			uint16_t sub = *(uint16_t *)sub_;
			for (; hayn-- && *hay != sub; hay++);
			return hay;
		}
	case 4:
		{
			uint32_t *hay = (void *)hay_;
			uint32_t sub = *(uint32_t *)sub_;
			for (; hayn-- && *hay != sub; hay++);
			return hay;
		}
	case 8:
		{
			uint64_t *hay = (void *)hay_;
			uint64_t sub = *(uint64_t *)sub_;
			for (; hayn-- && *hay != sub; hay++);
			return hay;
		}
	default:
		{
			char *hay = (void *)hay_;
			const char *sub = sub_;
			size_t i;
			for (; hayn--; hay += subn) {
				for (i = 0; i < subn; i++)
					if (hay[i] != sub[i])
						goto next;
				return hay;
			next:;
			}
			return hay;
		}
	}
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memelemscan("12345634", 8, "", 0), "12345634"));
	assert(!strcmpnul(libsimple_memelemscan("12345634", 0, "", 0), "12345634"));

	assert(!strcmpnul(libsimple_memelemscan("12345634", 8, "3", 1), "345634"));
	assert(!strcmpnul(libsimple_memelemscan("12345634", 8, "x", 1), ""));
	assert(!strcmpnul(libsimple_memelemscan("13456342", 8, "3", 1), "3456342"));
	assert(!strcmpnul(libsimple_memelemscan("12345634", 0, "3", 1), "12345634"));

	assert(!strcmpnul(libsimple_memelemscan("12345634", 4, "34", 2), "345634"));
	assert(!strcmpnul(libsimple_memelemscan("12345634z", 4, "xx", 2), "z"));
	assert(!strcmpnul(libsimple_memelemscan("13456342z", 4, "34", 2), "z"));
	assert(!strcmpnul(libsimple_memelemscan("12345634z", 0, "34", 2), "12345634z"));

	assert(!strcmpnul(libsimple_memelemscan("abcd1234abcd1234", 4, "1234", 4), "1234abcd1234"));
	assert(!strcmpnul(libsimple_memelemscan("abcd1234abcd1234z", 4, "zzzz", 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("cd1234abcd1234abz", 4, "1234", 4), "z"));
	assert(!strcmpnul(libsimple_memelemscan("abcd1234abcd1234z", 0, "1234", 4), "abcd1234abcd1234z"));

	assert(!strcmpnul(libsimple_memelemscan("abcdefgh12345678abcdefgh12345678", 4, "12345678", 8), "12345678abcdefgh12345678"));
	assert(!strcmpnul(libsimple_memelemscan("abcdefgh12345678abcdefgh12345678z", 4, "zzzzzzzz", 8), "z"));
	assert(!strcmpnul(libsimple_memelemscan("efgh12345678abcdefgh12345678abcdz", 4, "12345678", 8), "z"));
	assert(!strcmpnul(libsimple_memelemscan("abcdefgh12345678abcdefgh12345678z", 0, "12345678", 8),
	                  "abcdefgh12345678abcdefgh12345678z"));

	assert(!strcmpnul(libsimple_memelemscan("abc123abc123", 4, "123", 3), "123abc123"));
	assert(!strcmpnul(libsimple_memelemscan("abc123abc123z", 4, "zzz", 3), "z"));
	assert(!strcmpnul(libsimple_memelemscan("bc123abc123az", 4, "123", 3), "z"));
	assert(!strcmpnul(libsimple_memelemscan("abc123abc123z", 0, "123", 3), "abc123abc123z"));

	return 0;
}

#endif
