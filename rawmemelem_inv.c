/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemelem_inv(const void *hay_, const void *sub_, size_t width)
{
	switch (width) {
	case 0:
		abort();
	case 1:
		return rawmemchr_inv(hay_, *(char *)sub_);
	case 2:
		{
			uint16_t *hay = (void *)hay_;
			uint16_t sub = *(uint16_t *)sub_;
			for (; *hay == sub; hay++);
			return hay;
		}
	case 4:
		{
			uint32_t *hay = (void *)hay_;
			uint32_t sub = *(uint32_t *)sub_;
			for (; *hay == sub; hay++);
			return hay;
		}
	case 8:
		{
			uint64_t *hay = (void *)hay_;
			uint64_t sub = *(uint64_t *)sub_;
			for (; *hay == sub; hay++);
			return hay;
		}
	default:
		{
			char *hay = (void *)hay_;
			const char *sub = sub_;
			size_t i;
			for (;; hay += width)
				for (i = 0; i < width; i++)
					if (hay[i] != sub[i])
						return hay;
		}
	}
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemelem_inv("xxoxx", "x", 1), "oxx"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("xxXxx", "x", 1), "Xxx"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("XXoxx", "x", 1), "XXoxx"));

	assert(!strcmpnul(libsimple_rawmemelem_inv("-x-x-o-x-x", "-x", 2), "-o-x-x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("-x-x-X-x-x", "-x", 2), "-X-x-x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("-X-X-o-x-x", "-x", 2), "-X-X-o-x-x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("---X-o-x-x", "--", 2), "-X-o-x-x"));

	assert(!strcmpnul(libsimple_rawmemelem_inv("--x--x--o--x--x", "--x", 3), "--o--x--x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("--x--x--X--x--x", "--x", 3), "--X--x--x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("--X--X--o--x--x", "--x", 3), "--X--X--o--x--x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("-----X--o--x--x", "---", 3), "--X--o--x--x"));

	assert(!strcmpnul(libsimple_rawmemelem_inv("---x---x---o---x---x", "---x", 4), "---o---x---x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("---x---x---X---x---x", "---x", 4), "---X---x---x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("---X---X---o---x---x", "---x", 4), "---X---X---o---x---x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("-------X---o---x---x", "----", 4), "---X---o---x---x"));

	assert(!strcmpnul(libsimple_rawmemelem_inv("-------x-------x-------o-------x-------x", "-------x", 8),
	                  "-------o-------x-------x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("-------x-------x-------X-------x-------x", "-------x", 8),
	                  "-------X-------x-------x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("-------X-------X-------o-------x-------x", "-------x", 8),
	                  "-------X-------X-------o-------x-------x"));
	assert(!strcmpnul(libsimple_rawmemelem_inv("---------------X-------o-------x-------x", "--------", 8),
	                  "-------X-------o-------x-------x"));

	return 0;
}

#endif
