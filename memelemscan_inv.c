/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_memelemscan_inv(const void *hay_, const void *sub_, size_t width, size_t n)
{
	switch (width) {
	case 0:
		return REMOVE_CONST(hay_, void *);
	case 1:
		return libsimple_memscan_inv(hay_, *(const char *)sub_, n);
	case 2:
		{
			const uint16_t *hay = hay_;
			uint16_t sub = *(const uint16_t *)sub_;
			for (; n-- && *hay == sub; hay++);
			return REMOVE_CONST(hay, uint16_t *);
		}
	case 4:
		{
			const uint32_t *hay = hay_;
			uint32_t sub = *(const uint32_t *)sub_;
			for (; n-- && *hay == sub; hay++);
			return REMOVE_CONST(hay, uint32_t *);
		}
	case 8:
		{
			const uint64_t *hay = hay_;
			uint64_t sub = *(const uint64_t *)sub_;
			for (; n-- && *hay == sub; hay++);
			return REMOVE_CONST(hay, uint64_t *);
		}
	default:
		{
			const char *hay = hay_;
			const char *sub = sub_;
			size_t i;
			for (; n--; hay += width) {
				for (i = 0; i < width; i++)
					if (hay[i] != sub[i])
						return REMOVE_CONST(hay, char *);
			}
			return REMOVE_CONST(hay, char *);
		}
	}
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memelemscan_inv("xxoxx", "x", 0, 5), "xxoxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("xxXxx", "x", 0, 5), "xxXxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("XXoxx", "x", 0, 5), "XXoxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("zzzzz", "z", 0, 5), "zzzzz"));
	assert(!strcmpnul(libsimple_memelemscan_inv("zzzzx", "z", 0, 3), "zzzzx"));

	assert(!strcmpnul(libsimple_memelemscan_inv("xxoxx", "x", 1, 5), "oxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("xxXxx", "x", 1, 5), "Xxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("XXoxx", "x", 1, 5), "XXoxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("zzzzz", "z", 1, 5), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("zzzzx", "z", 1, 3), "zx"));

	assert(!strcmpnul(libsimple_memelemscan_inv("-x-x-o-x-x", "-x", 2, 5), "-o-x-x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-x-x-X-x-x", "-x", 2, 5), "-X-x-x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-X-X-o-x-x", "-x", 2, 5), "-X-X-o-x-x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-z-z-z-z-z", "-z", 2, 5), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("-z-z-z-z-x", "-z", 2, 3), "-z-x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---z-z-z-x", "--", 2, 5), "-z-z-z-x"));

	assert(!strcmpnul(libsimple_memelemscan_inv("--x--x--o--x--x", "--x", 3, 5), "--o--x--x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("--x--x--X--x--x", "--x", 3, 5), "--X--x--x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("--X--X--o--x--x", "--x", 3, 5), "--X--X--o--x--x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("--z--z--z--z--z", "--z", 3, 5), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("--z--z--z--z--x", "--z", 3, 3), "--z--x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-----z--z--z--x", "---", 3, 5), "--z--z--z--x"));

	assert(!strcmpnul(libsimple_memelemscan_inv("---x---x---o---x---x", "---x", 4, 5), "---o---x---x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---x---x---X---x---x", "---x", 4, 5), "---X---x---x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---X---X---o---x---x", "---x", 4, 5), "---X---X---o---x---x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---z---z---z---z---z", "---z", 4, 5), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("---z---z---z---z---x", "---z", 4, 3), "---z---x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------z---z---z---x", "----", 4, 5), "---z---z---z---x"));

	assert(!strcmpnul(libsimple_memelemscan_inv("-------x-------x-------o-------x-------x", "-------x", 8, 5),
	                  "-------o-------x-------x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------x-------x-------X-------x-------x", "-------x", 8, 5),
	                  "-------X-------x-------x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------X-------X-------o-------x-------x", "-------x", 8, 5),
	                  "-------X-------X-------o-------x-------x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------z-------z-------z-------z-------z", "-------z", 8, 5), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------z-------z-------z-------z-------x", "-------z", 8, 3),
	                  "-------z-------x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---------------z-------z-------z-------x", "--------", 8, 5),
	                  "-------z-------z-------z-------x"));

	return 0;
}

#endif
