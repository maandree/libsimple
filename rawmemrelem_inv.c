/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrelem_inv(const void *hay_, const void *sub_, size_t width, size_t n)
{
	switch (width) {
	case 0:
		abort();
	case 1:
		{
			const uint8_t *hay = hay_;
			uint8_t sub = *(const uint8_t *)sub_;
			for (hay += n; *--hay == sub;);
			return REMOVE_CONST(hay, uint8_t *);
		}
	case 2:
		{
			const uint16_t *hay = hay_;
			uint16_t sub = *(const uint16_t *)sub_;
			for (hay += n; *--hay == sub;);
			return REMOVE_CONST(hay, uint16_t *);
		}
	case 4:
		{
			const uint32_t *hay = hay_;
			uint32_t sub = *(const uint32_t *)sub_;
			for (hay += n; *--hay == sub;);
			return REMOVE_CONST(hay, uint32_t *);
		}
	case 8:
		{
			const uint64_t *hay = hay_;
			uint64_t sub = *(const uint64_t *)sub_;
			for (hay += n; *--hay == sub;);
			return REMOVE_CONST(hay, uint64_t *);
		}
	default:
		{
			const char *hay = hay_;
			const char *sub = sub_;
			size_t i;
			for (hay += n * width;;) {
				hay -= width;
				for (i = 0; i < width; i++)
					if (hay[i] != sub[i])
						return REMOVE_CONST(hay, char *);
			}
		}
	}
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aabbaabb", "b", 1, 8), "abb"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aabbaabb", "B", 1, 8), "b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("AABBAABB", "b", 1, 8), "B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("AABBAABB", "B", 1, 8), "ABB"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aabbaabb", "a", 1, 8), "b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aabbbb\0\0", "\0", 1, 8), "b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("-a-a-b-b-a-a-b-b", "-b", 2, 8), "-a-b-b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-a-a-b-b-a-a-b-b", "-B", 2, 8), "-b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-A-A-B-B-A-A-B-B", "-b", 2, 8), "-B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-A-A-B-B-A-A-B-B", "-B", 2, 8), "-A-B-B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-a-a-b-b-a-a-b-b", "-a", 2, 8), "-b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-a-a-b-b-b-b\0\0\0\0", "\0\0", 2, 8), "-b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("--a--a--b--b--a--a--b--b", "--b", 3, 8), "--a--b--b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--a--a--b--b--a--a--b--b", "--B", 3, 8), "--b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--A--A--B--B--A--A--B--B", "--b", 3, 8), "--B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--A--A--B--B--A--A--B--B", "--B", 3, 8), "--A--B--B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--a--a--b--b--a--a--b--b", "--a", 3, 8), "--b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--a--a--b--b--b--b\0\0\0\0\0\0", "\0\0\0", 3, 8), "--b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("---a---a---b---b---a---a---b---b", "---b", 4, 8), "---a---b---b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---a---a---b---b---a---a---b---b", "---B", 4, 8), "---b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---A---A---B---B---A---A---B---B", "---b", 4, 8), "---B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---A---A---B---B---A---A---B---B", "---B", 4, 8), "---A---B---B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---a---a---b---b---a---a---b---b", "---a", 4, 8), "---b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---a---a---b---b---b---b\0\0\0\0\0\0\0\0", "\0\0\0\0", 4, 8), "---b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------a-------a-------b-------b-------a-------a-------b-------b",
	                                            "-------b", 8, 8), "-------a-------b-------b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------a-------a-------b-------b-------a-------a-------b-------b",
	                                            "-------B", 8, 8), "-------b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------A-------A-------B-------B-------A-------A-------B-------B",
	                                            "-------b", 8, 8), "-------B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------A-------A-------B-------B-------A-------A-------B-------B",
	                                            "-------B", 8, 8), "-------A-------B-------B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------a-------a-------b-------b-------a-------a-------b-------b",
	                                            "-------a", 8, 8), "-------b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------a-------a-------b-------b-------b-------b"
	                                            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", "\0\0\0\0\0\0\0\0", 8, 8), "-------b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("aaaa-aaa", "aa", 2, 4), "-aaa"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aaaaaa-aaaaa", "aaa", 3, 4), "-aaaaa"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aaaaaaaa-aaaaaaa", "aaaa", 4, 4), "-aaaaaaa"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aaaaaaaaaaaaaaaa-aaaaaaaaaaaaaaa", "aaaaaaaa", 8, 4), "-aaaaaaaaaaaaaaa"));

	return 0;
}

#endif
