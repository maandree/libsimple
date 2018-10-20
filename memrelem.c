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
			for (hay += hayn * subn; hayn--;) {
				hay -= subn;
				if (!memcmp(hay, sub, subn))
					return hay;
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
	assert(!strcmpnul(libsimple_memrelem("12345634", 4, "", 0), "12345634"));
	assert(!strcmpnul(libsimple_memrelem("12345634", 4, "34", 2), "34"));
	assert(!libsimple_memrelem("12345634", 4, "xx", 2));
	assert(!libsimple_memrelem("13456342", 4, "34", 2));
	assert(!libsimple_memrelem("12345634", 0, "34", 2));
	assert(!strcmpnul(libsimple_memrelem("12345634", 0, "34", 0), "12345634"));
	return 0;
}

#endif
