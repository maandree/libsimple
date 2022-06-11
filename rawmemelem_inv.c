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
		return rawmemchr_inv(hay_, *(const char *)sub_);
	case 2:
		{
			const uint16_t *hay = hay_;
			uint16_t sub = *(const uint16_t *)sub_;
			for (; *hay == sub; hay++);
			return REMOVE_CONST(hay, uint16_t *);
		}
	case 4:
		{
			const uint32_t *hay = hay_;
			uint32_t sub = *(const uint32_t *)sub_;
			for (; *hay == sub; hay++);
			return REMOVE_CONST(hay, uint32_t *);
		}
	case 8:
		{
			const uint64_t *hay = hay_;
			uint64_t sub = *(const uint64_t *)sub_;
			for (; *hay == sub; hay++);
			return REMOVE_CONST(hay, uint64_t *);
		}
	default:
		{
			const char *hay = hay_;
			const char *sub = sub_;
			size_t i;
			for (;; hay += width)
				for (i = 0; i < width; i++)
					if (hay[i] != sub[i])
						return REMOVE_CONST(hay, void *);
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
