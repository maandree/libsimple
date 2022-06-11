/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemelem(const void *hay_, const void *sub_, size_t width)
{
	switch (width) {
	case 0:
		return REMOVE_CONST(hay_, void *);
	case 1:
		return rawmemchr(hay_, *(const char *)sub_);
	case 2:
		{
			const uint16_t *hay = hay_;
			uint16_t sub = *(const uint16_t *)sub_;
			for (; *hay != sub; hay++);
			return REMOVE_CONST(hay, uint16_t *);
		}
	case 4:
		{
			const uint32_t *hay = hay_;
			uint32_t sub = *(const uint32_t *)sub_;
			for (; *hay != sub; hay++);
			return REMOVE_CONST(hay, uint32_t *);
		}
	case 8:
		{
			const uint64_t *hay = hay_;
			uint64_t sub = *(const uint64_t *)sub_;
			for (; *hay != sub; hay++);
			return REMOVE_CONST(hay, uint64_t *);
		}
	default:
		{
			const char *hay = hay_;
			const char *sub = sub_;
			size_t i;
			for (;; hay += width) {
				for (i = 0; i < width; i++)
					if (hay[i] != sub[i])
						goto next;
				return REMOVE_CONST(hay, char *);
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

	assert(!strcmpnul(libsimple_rawmemelem("-a-aa--a", "a-", 2), "a--a"));
	assert(!strcmpnul(libsimple_rawmemelem("--a--aa----a", "a--", 3), "a----a"));
	assert(!strcmpnul(libsimple_rawmemelem("---a---aa------a", "a---", 4), "a------a"));
	assert(!strcmpnul(libsimple_rawmemelem("-------a-------aa--------------a", "a-------", 8), "a--------------a"));
	return 0;
}

#endif
