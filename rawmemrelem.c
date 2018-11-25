/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrelem(const void *hay_, size_t hayn, const void *sub_, size_t subn)
{
	switch (subn) {
	case 0:
		return (void *)hay_;
	case 1:
		{
			uint8_t *hay = (void *)hay_;
			uint8_t sub = *(uint8_t *)sub_;
			for (hay += hayn; *--hay != sub;);
			return hay;
		}
	case 2:
		{
			uint16_t *hay = (void *)hay_;
			uint16_t sub = *(uint16_t *)sub_;
			for (hay += hayn; *--hay != sub;);
			return hay;
		}
	case 4:
		{
			uint32_t *hay = (void *)hay_;
			uint32_t sub = *(uint32_t *)sub_;
			for (hay += hayn; *--hay != sub;);
			return hay;
		}
	case 8:
		{
			uint64_t *hay = (void *)hay_;
			uint64_t sub = *(uint64_t *)sub_;
			for (hay += hayn; *--hay != sub;);
			return hay;
		}
	default:
		{
			char *hay = (void *)hay_;
			const char *sub = sub_;
			size_t i;
			for (hay += hayn * subn;;) {
				hay -= subn;
				for (i = 0; i < subn; i++)
					if (hay[i] != sub[i])
						goto next;
				return hay;
			next:;
			}
		}
	}
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemrelem("12345634", 8, "", 0), "12345634"));
	assert(!strcmpnul(libsimple_rawmemrelem("12345634", 8, "3", 1), "34"));
	assert(!strcmpnul(libsimple_rawmemrelem("13456342", 8, "3", 1), "342"));
	assert(!strcmpnul(libsimple_rawmemrelem("12345634", 4, "34", 2), "34"));
	assert(!strcmpnul(libsimple_rawmemrelem("abcd1234abcd1234", 4, "1234", 4), "1234"));
	assert(!strcmpnul(libsimple_rawmemrelem("abcdefgh12345678abcdefgh12345678", 4, "12345678", 8), "12345678"));
	assert(!strcmpnul(libsimple_rawmemrelem("abc123abc123", 4, "123", 3), "123"));

	assert(!strcmpnul(libsimple_rawmemrelem("-aa--a-a", 4, "a-", 2), "a--a-a"));
	assert(!strcmpnul(libsimple_rawmemrelem("--aa----a--a", 4, "a--", 3), "a----a--a"));
	assert(!strcmpnul(libsimple_rawmemrelem("---aa------a---a", 4, "a---", 4), "a------a---a"));
	assert(!strcmpnul(libsimple_rawmemrelem("-------aa--------------a-------a", 4, "a-------", 8), "a--------------a-------a"));
	return 0;
}

#endif
