/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memreplaceelem(void *restrict s_, const void *old_, const void *new_, size_t n, size_t width) /* TODO test, man */
{
	switch (width) {
	case 0:
		return s_;
	case 1:
		{
			uint8_t *restrict s = s_;
			uint8_t old = *(const uint8_t *)old_;
			uint8_t new = *(const uint8_t *)new_;
			for (; n; s++, n--)
				if (*s == old)
					*s = new;
			return s;
		}
	case 2:
		{
			uint16_t *restrict s = s_;
			uint16_t old = *(const uint16_t *)old_;
			uint16_t new = *(const uint16_t *)new_;
			for (; n; s++, n--)
				if (*s == old)
					*s = new;
			return s;
		}
	case 4:
		{
			uint32_t *restrict s = s_;
			uint32_t old = *(const uint32_t *)old_;
			uint32_t new = *(const uint32_t *)new_;
			for (; n; s++, n--)
				if (*s == old)
					*s = new;
			return s;
		}
	case 8:
		{
			uint64_t *restrict s = s_;
			uint64_t old = *(const uint64_t *)old_;
			uint64_t new = *(const uint64_t *)new_;
			for (; n; s++, n--)
				if (*s == old)
					*s = new;
			return s;
		}
	default:
		{
			char *restrict s = s_;
			const char *old = old_;
			const char *new = new_;
			size_t i;
			for (; n; s += width, n--) {
				if (*s == *old) {
					for (i = 0; i < width; i++)
						if (s[i] != old[i])
							goto next;
					for (i = 0; i < width; i++)
						s[i] = new[i];
				}
			next:;
			}
			return s;
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
