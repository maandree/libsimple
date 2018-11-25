/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrelem(const void *hay_, const void *sub_, size_t width, size_t n)
{
	switch (width) {
	case 0:
		return (void *)hay_;
	case 1:
		{
			uint8_t *hay = (void *)hay_;
			uint8_t sub = *(uint8_t *)sub_;
			for (hay += n; *--hay != sub;);
			return hay;
		}
	case 2:
		{
			uint16_t *hay = (void *)hay_;
			uint16_t sub = *(uint16_t *)sub_;
			for (hay += n; *--hay != sub;);
			return hay;
		}
	case 4:
		{
			uint32_t *hay = (void *)hay_;
			uint32_t sub = *(uint32_t *)sub_;
			for (hay += n; *--hay != sub;);
			return hay;
		}
	case 8:
		{
			uint64_t *hay = (void *)hay_;
			uint64_t sub = *(uint64_t *)sub_;
			for (hay += n; *--hay != sub;);
			return hay;
		}
	default:
		{
			char *hay = (void *)hay_;
			const char *sub = sub_;
			size_t i;
			for (hay += n * width;;) {
				hay -= width;
				for (i = 0; i < width; i++)
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
	assert(!strcmpnul(libsimple_rawmemrelem("12345634", "", 0, 8), "12345634"));
	assert(!strcmpnul(libsimple_rawmemrelem("12345634", "3", 1, 8), "34"));
	assert(!strcmpnul(libsimple_rawmemrelem("13456342", "3", 1, 8), "342"));
	assert(!strcmpnul(libsimple_rawmemrelem("12345634", "34", 2, 4), "34"));
	assert(!strcmpnul(libsimple_rawmemrelem("abcd1234abcd1234", "1234", 4, 4), "1234"));
	assert(!strcmpnul(libsimple_rawmemrelem("abcdefgh12345678abcdefgh12345678", "12345678", 8, 4), "12345678"));
	assert(!strcmpnul(libsimple_rawmemrelem("abc123abc123", "123", 3, 4), "123"));

	assert(!strcmpnul(libsimple_rawmemrelem("-aa--a-a", "a-", 2, 4), "a--a-a"));
	assert(!strcmpnul(libsimple_rawmemrelem("--aa----a--a", "a--", 3, 4), "a----a--a"));
	assert(!strcmpnul(libsimple_rawmemrelem("---aa------a---a", "a---", 4, 4), "a------a---a"));
	assert(!strcmpnul(libsimple_rawmemrelem("-------aa--------------a-------a", "a-------", 8, 4), "a--------------a-------a"));
	return 0;
}

#endif
