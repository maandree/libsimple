/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrelem_inv(const void *hay_, size_t hayn, const void *sub_, size_t subn) /* TODO man */
{
	switch (subn) {
	case 0:
		abort();
	case 1:
		{
			uint8_t *hay = (void *)hay_;
			uint8_t sub = *(uint8_t *)sub_;
			for (hay += hayn; *--hay == sub;);
			return hay;
		}
	case 2:
		{
			uint16_t *hay = (void *)hay_;
			uint16_t sub = *(uint16_t *)sub_;
			for (hay += hayn; *--hay == sub;);
			return hay;
		}
	case 4:
		{
			uint32_t *hay = (void *)hay_;
			uint32_t sub = *(uint32_t *)sub_;
			for (hay += hayn; *--hay == sub;);
			return hay;
		}
	case 8:
		{
			uint64_t *hay = (void *)hay_;
			uint64_t sub = *(uint64_t *)sub_;
			for (hay += hayn; *--hay == sub;);
			return hay;
		}
	default:
		{
			char *hay = (void *)hay_;
			const char *sub = sub_;
			size_t i;
			for (hay += hayn * subn;;) {
				hay -= subn;
				for (i = 0; i < subn; i++)
					if (hay[i] != sub[i])
						return hay;
			}
		}
	}
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aabbaabb", 8, "b", 1), "abb"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aabbaabb", 8, "B", 1), "b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("AABBAABB", 8, "b", 1), "B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("AABBAABB", 8, "B", 1), "ABB"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aabbaabb", 8, "a", 1), "b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aabbbb\0\0", 8, "\0", 1), "b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("-a-a-b-b-a-a-b-b", 8, "-b", 2), "-a-b-b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-a-a-b-b-a-a-b-b", 8, "-B", 2), "-b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-A-A-B-B-A-A-B-B", 8, "-b", 2), "-B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-A-A-B-B-A-A-B-B", 8, "-B", 2), "-A-B-B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-a-a-b-b-a-a-b-b", 8, "-a", 2), "-b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-a-a-b-b-b-b\0\0\0\0", 8, "\0\0", 2), "-b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("--a--a--b--b--a--a--b--b", 8, "--b", 3), "--a--b--b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--a--a--b--b--a--a--b--b", 8, "--B", 3), "--b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--A--A--B--B--A--A--B--B", 8, "--b", 3), "--B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--A--A--B--B--A--A--B--B", 8, "--B", 3), "--A--B--B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--a--a--b--b--a--a--b--b", 8, "--a", 3), "--b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("--a--a--b--b--b--b\0\0\0\0\0\0", 8, "\0\0\0", 3), "--b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("---a---a---b---b---a---a---b---b", 8, "---b", 4), "---a---b---b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---a---a---b---b---a---a---b---b", 8, "---B", 4), "---b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---A---A---B---B---A---A---B---B", 8, "---b", 4), "---B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---A---A---B---B---A---A---B---B", 8, "---B", 4), "---A---B---B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---a---a---b---b---a---a---b---b", 8, "---a", 4), "---b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("---a---a---b---b---b---b\0\0\0\0\0\0\0\0", 8, "\0\0\0\0", 4), "---b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------a-------a-------b-------b-------a-------a-------b-------b", 8,
	                                            "-------b", 8), "-------a-------b-------b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------a-------a-------b-------b-------a-------a-------b-------b", 8,
	                                            "-------B", 8), "-------b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------A-------A-------B-------B-------A-------A-------B-------B", 8,
	                                            "-------b", 8), "-------B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------A-------A-------B-------B-------A-------A-------B-------B", 8,
	                                            "-------B", 8), "-------A-------B-------B"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------a-------a-------b-------b-------a-------a-------b-------b", 8,
	                                            "-------a", 8), "-------b"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("-------a-------a-------b-------b-------b-------b"
	                                            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 8, "\0\0\0\0\0\0\0\0", 8), "-------b"));

	assert(!strcmpnul(libsimple_rawmemrelem_inv("aaaa-aaa", 4, "aa", 2), "-aaa"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aaaaaa-aaaaa", 4, "aaa", 3), "-aaaaa"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aaaaaaaa-aaaaaaa", 4, "aaaa", 4), "-aaaaaaa"));
	assert(!strcmpnul(libsimple_rawmemrelem_inv("aaaaaaaaaaaaaaaa-aaaaaaaaaaaaaaa", 4, "aaaaaaaa", 8), "-aaaaaaaaaaaaaaa"));

	return 0;
}

#endif
