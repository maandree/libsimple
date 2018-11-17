/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memrelem(const void *hay_, size_t hayn, const void *sub_, size_t subn)
{
	if (!subn)
		return (void *)hay_;

	switch (subn) {
	case 1:
		{
			uint8_t *hay = (void *)hay_;
			uint8_t sub = *(uint8_t *)sub_;
			for (hay += hayn; hayn--;)
				if (*--hay == sub)
					return hay;
			break;
		}
	case 2:
		{
			uint16_t *hay = (void *)hay_;
			uint16_t sub = *(uint16_t *)sub_;
			for (hay += hayn; hayn--;)
				if (*--hay == sub)
					return hay;
			break;
		}
	case 4:
		{
			uint32_t *hay = (void *)hay_;
			uint32_t sub = *(uint32_t *)sub_;
			for (hay += hayn; hayn--;)
				if (*--hay == sub)
					return hay;
			break;
		}
	case 8:
		{
			uint64_t *hay = (void *)hay_;
			uint64_t sub = *(uint64_t *)sub_;
			for (hay += hayn; hayn--;)
				if (*--hay == sub)
					return hay;
			break;
		}
	default:
		{
			char *hay = (void *)hay_;
			const char *sub = sub_;
			size_t i;
			for (hay += hayn * subn; hayn--;) {
				hay -= subn;
				for (i = 0; i < subn; i++)
					if (hay[i] != sub[i])
						goto next;
				return hay;
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
	assert(!strcmpnul(libsimple_memrelem("12345634", 8, "", 0), "12345634"));
	assert(!strcmpnul(libsimple_memrelem("12345634", 0, "", 0), "12345634"));

	assert(!strcmpnul(libsimple_memrelem("12345634", 8, "3", 1), "34"));
	assert(!libsimple_memrelem("12345634", 8, "x", 1));
	assert(!strcmpnul(libsimple_memrelem("13456342", 8, "3", 1), "342"));
	assert(!libsimple_memrelem("12345634", 0, "3", 1));

	assert(!strcmpnul(libsimple_memrelem("12345634", 4, "34", 2), "34"));
	assert(!libsimple_memrelem("12345634", 4, "xx", 2));
	assert(!libsimple_memrelem("13456342", 4, "34", 2));
	assert(!libsimple_memrelem("12345634", 0, "34", 2));

	assert(!strcmpnul(libsimple_memrelem("abcd1234abcd1234", 4, "1234", 4), "1234"));
	assert(!libsimple_memrelem("abcd1234abcd1234", 4, "zzzz", 4));
	assert(!libsimple_memrelem("cd1234abcd1234ab", 4, "1234", 4));
	assert(!libsimple_memrelem("abcd1234abcd1234", 0, "1234", 4));

	assert(!strcmpnul(libsimple_memrelem("abcdefgh12345678abcdefgh12345678", 4, "12345678", 8), "12345678"));
	assert(!libsimple_memrelem("abcdefgh12345678abcdefgh12345678", 4, "zzzzzzzz", 8));
	assert(!libsimple_memrelem("efgh12345678abcdefgh12345678abcd", 4, "12345678", 8));
	assert(!libsimple_memrelem("abcdefgh12345678abcdefgh12345678", 0, "12345678", 8));

	assert(!strcmpnul(libsimple_memrelem("abc123abc123", 4, "123", 3), "123"));
	assert(!libsimple_memrelem("abc123abc123", 4, "zzz", 3));
	assert(!libsimple_memrelem("bc123abc123a", 4, "123", 3));
	assert(!libsimple_memrelem("abc123abc123", 0, "123", 3));

	return 0;
}

#endif
