/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_mempsetelem(void *buf_, const void *item, size_t size, size_t nitems) /* TODO test */
{
	switch (size) {
	case 0:
		return buf_;
	case 1:
		return &((char *)memset(buf_, *(char *)item, nitems))[nitems];
	case 2:
		{
			uint16_t *buf = buf_, e = *(uint16_t *)item;
			uint16_t *end = &buf[nitems];
			for (; buf != end; buf++)
				*buf = e;
			return buf;
		}
	case 4:
		{
			uint32_t *buf = buf_, e = *(uint32_t *)item;
			uint32_t *end = &buf[nitems];
			for (; buf != end; buf++)
				*buf = e;
			return buf;
		}
	case 8:
		{
			uint64_t *buf = buf_, e = *(uint64_t *)item;
			uint64_t *end = &buf[nitems];
			for (; buf != end; buf++)
				*buf = e;
			return buf;
		}
	default:
		{
			char *buf = buf_;
			size_t i;
			for (; nitems--; buf += size)
				for (i = 0; i < size; i++)
					buf[i] = ((const char *)item)[i];
			return buf;
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
