/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemelem(const void *hay_, const void *sub_, size_t subn)
{
	switch (subn) {
	case 0:
		return (void *)hay_;
	case 1:
		return rawmemchr(hay_, *(char *)sub_);
	case 2:
		{
			uint16_t *hay = (void *)hay_;
			uint16_t sub = *(uint16_t *)sub_;
			for (; *hay != sub; hay++);
			return hay;
		}
	case 4:
		{
			uint32_t *hay = (void *)hay_;
			uint32_t sub = *(uint32_t *)sub_;
			for (; *hay != sub; hay++);
			return hay;
		}
	case 8:
		{
			uint64_t *hay = (void *)hay_;
			uint64_t sub = *(uint64_t *)sub_;
			for (; *hay != sub; hay++);
			return hay;
		}
	default:
		{
			char *hay = (void *)hay_;
			const char *sub = sub_;
			size_t i;
			for (;; hay += subn) {
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
	assert(!strcmpnul(libsimple_rawmemelem("12345634", "", 0), "12345634"));
	assert(!strcmpnul(libsimple_rawmemelem("12345634", "3", 1), "345634"));
	assert(!strcmpnul(libsimple_rawmemelem("13456342", "3", 1), "3456342"));
	assert(!strcmpnul(libsimple_rawmemelem("12345634", "34", 2), "345634"));
	assert(!strcmpnul(libsimple_rawmemelem("abcd1234abcd1234", "1234", 4), "1234abcd1234"));
	assert(!strcmpnul(libsimple_rawmemelem("abcdefgh12345678abcdefgh12345678", "12345678", 8), "12345678abcdefgh12345678"));
	assert(!strcmpnul(libsimple_rawmemelem("abc123abc123", "123", 3), "123abc123"));
	return 0;
}

#endif
