/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memelemscan_inv(const void *hay_, size_t hayn, const void *sub_, size_t subn)
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
	assert(!strcmpnul(libsimple_memelemscan_inv("xxoxx", 5, "x", 0), "xxoxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("xxXxx", 5, "x", 0), "xxXxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("XXoxx", 5, "x", 0), "XXoxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("zzzzz", 5, "z", 0), "zzzzz"));
	assert(!strcmpnul(libsimple_memelemscan_inv("zzzzx", 3, "z", 0), "zzzzx"));

	assert(!strcmpnul(libsimple_memelemscan_inv("xxoxx", 5, "x", 1), "oxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("xxXxx", 5, "x", 1), "Xxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("XXoxx", 5, "x", 1), "XXoxx"));
	assert(!strcmpnul(libsimple_memelemscan_inv("zzzzz", 5, "z", 1), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("zzzzx", 3, "z", 1), "zx"));

	assert(!strcmpnul(libsimple_memelemscan_inv("-x-x-o-x-x", 5, "-x", 2), "-o-x-x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-x-x-X-x-x", 5, "-x", 2), "-X-x-x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-X-X-o-x-x", 5, "-x", 2), "-X-X-o-x-x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-z-z-z-z-z", 5, "-z", 2), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("-z-z-z-z-x", 3, "-z", 2), "-z-x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---z-z-z-x", 5, "--", 2), "-z-z-z-x"));

	assert(!strcmpnul(libsimple_memelemscan_inv("--x--x--o--x--x", 5, "--x", 3), "--o--x--x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("--x--x--X--x--x", 5, "--x", 3), "--X--x--x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("--X--X--o--x--x", 5, "--x", 3), "--X--X--o--x--x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("--z--z--z--z--z", 5, "--z", 3), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("--z--z--z--z--x", 3, "--z", 3), "--z--x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-----z--z--z--x", 5, "---", 3), "--z--z--z--x"));

	assert(!strcmpnul(libsimple_memelemscan_inv("---x---x---o---x---x", 5, "---x", 4), "---o---x---x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---x---x---X---x---x", 5, "---x", 4), "---X---x---x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---X---X---o---x---x", 5, "---x", 4), "---X---X---o---x---x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---z---z---z---z---z", 5, "---z", 4), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("---z---z---z---z---x", 3, "---z", 4), "---z---x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------z---z---z---x", 5, "----", 4), "---z---z---z---x"));

	assert(!strcmpnul(libsimple_memelemscan_inv("-------x-------x-------o-------x-------x", 5, "-------x", 8),
	                  "-------o-------x-------x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------x-------x-------X-------x-------x", 5, "-------x", 8),
	                  "-------X-------x-------x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------X-------X-------o-------x-------x", 5, "-------x", 8),
	                  "-------X-------X-------o-------x-------x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------z-------z-------z-------z-------z", 5, "-------z", 8), ""));
	assert(!strcmpnul(libsimple_memelemscan_inv("-------z-------z-------z-------z-------x", 3, "-------z", 8),
	                  "-------z-------x"));
	assert(!strcmpnul(libsimple_memelemscan_inv("---------------z-------z-------z-------x", 5, "--------", 8),
	                  "-------z-------z-------z-------x"));

	return 0;
}

#endif
