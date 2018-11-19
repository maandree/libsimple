/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memrelem_inv(const void *hay_, size_t hayn, const void *sub_, size_t subn) /* TODO test, man */
{
	switch (subn) {
	case 0:
		return NULL;
	case 1:
		{
			uint8_t *hay = (void *)hay_;
			uint8_t sub = *(uint8_t *)sub_;
			for (hay += hayn; hayn--;)
				if (*--hay != sub)
					return hay;
			break;
		}
	case 2:
		{
			uint16_t *hay = (void *)hay_;
			uint16_t sub = *(uint16_t *)sub_;
			for (hay += hayn; hayn--;)
				if (*--hay != sub)
					return hay;
			break;
		}
	case 4:
		{
			uint32_t *hay = (void *)hay_;
			uint32_t sub = *(uint32_t *)sub_;
			for (hay += hayn; hayn--;)
				if (*--hay != sub)
					return hay;
			break;
		}
	case 8:
		{
			uint64_t *hay = (void *)hay_;
			uint64_t sub = *(uint64_t *)sub_;
			for (hay += hayn; hayn--;)
				if (*--hay != sub)
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
	return 0;
}

#endif
