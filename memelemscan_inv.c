/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memelemscan_inv(const void *hay_, size_t hayn, const void *sub_, size_t subn) /* TODO test, man */
{
	switch (subn) {
	case 0:
		return (void *)hay_;
	case 1:
		return libsimple_memscan_inv(hay_, *(char *)sub_, hayn);
	case 2:
		{
			uint16_t *hay = (void *)hay_;
			uint16_t sub = *(uint16_t *)sub_;
			for (; hayn-- && *hay == sub; hay++);
			return hay;
		}
	case 4:
		{
			uint32_t *hay = (void *)hay_;
			uint32_t sub = *(uint32_t *)sub_;
			for (; hayn-- && *hay == sub; hay++);
			return hay;
		}
	case 8:
		{
			uint64_t *hay = (void *)hay_;
			uint64_t sub = *(uint64_t *)sub_;
			for (; hayn-- && *hay == sub; hay++);
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
						return hay;
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
	return 0;
}

#endif
