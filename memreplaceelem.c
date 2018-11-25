/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memreplaceelem(void *restrict s_, const void *old_, const void *new_, size_t n, size_t width)
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
	char buf[1024];

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_memreplaceelem(buf, "o", "x", 46, 0) == &buf[0]);
	assert(!memcmp(buf, "hello world\0goodbye world", 26));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_memreplaceelem(buf, "o", "x", 12, 0) == &buf[0]);
	assert(!memcmp(buf, "hello world\0goodbye world", 26));


	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_memreplaceelem(buf, "o", "x", 46, 1) == &buf[46]);
	assert(!memcmp(buf, "hellx wxrld\0gxxdbye wxrld", 26));

	stpcpy(mempcpy(buf, "hello world", 12), "goodbye world");
	assert(libsimple_memreplaceelem(buf, "o", "x", 12, 1) == &buf[12]);
	assert(!memcmp(buf, "hellx wxrld\0goodbye world", 26));


	stpcpy(mempcpy(buf, "-h-e-l-l-o- -w-o-r-l-d\0", 12 * 2), "-g-o-o-d-b-y-e- -w-o-r-l-d");
	assert(libsimple_memreplaceelem(buf, "-o", "=x", 46, 2) == &buf[46 * 2]);
	assert(!memcmp(buf, "-h-e-l-l=x- -w=x-r-l-d\0\0-g=x=x-d-b-y-e- -w=x-r-l-d", 25 * 2 + 1));

	stpcpy(mempcpy(buf, "-h-e-l-l-o- -w-o-r-l-d\0", 12 * 2), "-g-o-o-d-b-y-e- -w-o-r-l-d");
	assert(libsimple_memreplaceelem(buf, "-o", "=x", 12, 2) == &buf[12 * 2]);
	assert(!memcmp(buf, "-h-e-l-l=x- -w=x-r-l-d\0\0-g-o-o-d-b-y-e- -w-o-r-l-d", 25 * 2 + 1));

	stpcpy(mempcpy(buf, "-h-e-l-l-o- -w-o-r-l-d\0", 12 * 2), "-g-o-o-d-b-y-e- -w-o-r-l-d");
	assert(libsimple_memreplaceelem(buf, "o-", "x=", 12, 2) == &buf[12 * 2]);
	assert(!memcmp(buf, "-h-e-l-l-o- -w-o-r-l-d\0\0-g-o-o-d-b-y-e- -w-o-r-l-d", 25 * 2 + 1));


	stpcpy(mempcpy(buf, "--h--e--l--l--o-- --w--o--r--l--d\0\0", 12 * 3), "--g--o--o--d--b--y--e-- --w--o--r--l--d");
	assert(libsimple_memreplaceelem(buf, "--o", "==x", 46, 3) == &buf[46 * 3]);
	assert(!memcmp(buf, "--h--e--l--l==x-- --w==x--r--l--d\0\0\0--g==x==x--d--b--y--e-- --w==x--r--l--d", 25 * 3 + 1));

	stpcpy(mempcpy(buf, "--h--e--l--l--o-- --w--o--r--l--d\0\0", 12 * 3), "--g--o--o--d--b--y--e-- --w--o--r--l--d");
	assert(libsimple_memreplaceelem(buf, "--o", "==x", 12, 3) == &buf[12 * 3]);
	assert(!memcmp(buf, "--h--e--l--l==x-- --w==x--r--l--d\0\0\0--g--o--o--d--b--y--e-- --w--o--r--l--d", 25 * 3 + 1));

	stpcpy(mempcpy(buf, "--h--e--l--l--o-- --w--o--r--l--d\0\0", 12 * 3), "--g--o--o--d--b--y--e-- --w--o--r--l--d");
	assert(libsimple_memreplaceelem(buf, "o--", "x==", 12, 3) == &buf[12 * 3]);
	assert(!memcmp(buf, "--h--e--l--l--o-- --w--o--r--l--d\0\0\0--g--o--o--d--b--y--e-- --w--o--r--l--d", 25 * 3 + 1));


	stpcpy(mempcpy(buf, "---h---e---l---l---o--- ---w---o---r---l---d\0\0\0", 12 * 4),
	       "---g---o---o---d---b---y---e--- ---w---o---r---l---d");
	assert(libsimple_memreplaceelem(buf, "---o", "===x", 46, 4) == &buf[46 * 4]);
	assert(!memcmp(buf, "---h---e---l---l===x--- ---w===x---r---l---d\0\0\0\0"
	                    "---g===x===x---d---b---y---e--- ---w===x---r---l---d", 25 * 4 + 1));

	stpcpy(mempcpy(buf, "---h---e---l---l---o--- ---w---o---r---l---d\0\0\0", 12 * 4),
	       "---g---o---o---d---b---y---e--- ---w---o---r---l---d");
	assert(libsimple_memreplaceelem(buf, "---o", "===x", 12, 4) == &buf[12 * 4]);
	assert(!memcmp(buf, "---h---e---l---l===x--- ---w===x---r---l---d\0\0\0\0"
	                    "---g---o---o---d---b---y---e--- ---w---o---r---l---d", 25 * 4 + 1));

	stpcpy(mempcpy(buf, "---h---e---l---l---o--- ---w---o---r---l---d\0\0\0", 12 * 4),
	       "---g---o---o---d---b---y---e--- ---w---o---r---l---d");
	assert(libsimple_memreplaceelem(buf, "o---", "x===", 12, 4) == &buf[12 * 4]);
	assert(!memcmp(buf, "---h---e---l---l---o--- ---w---o---r---l---d\0\0\0\0"
	                    "---g---o---o---d---b---y---e--- ---w---o---r---l---d", 25 * 4 + 1));


	stpcpy(mempcpy(buf, "-------h-------e-------l-------l-------o------- -------w-------o-------r-------l-------d\0\0\0\0\0\0\0",
	               12 * 8),
	       "-------g-------o-------o-------d-------b-------y-------e------- -------w-------o-------r-------l-------d");
	assert(libsimple_memreplaceelem(buf, "-------o", "=======x", 46, 8) == &buf[46 * 8]);
	assert(!memcmp(buf, "-------h-------e-------l-------l=======x------- -------w=======x-------r-------l-------d\0\0\0\0\0\0\0\0"
	                    "-------g=======x=======x-------d-------b-------y-------e------- "
	                    "-------w=======x-------r-------l-------d", 25 * 8 + 1));

	stpcpy(mempcpy(buf, "-------h-------e-------l-------l-------o------- -------w-------o-------r-------l-------d\0\0\0\0\0\0\0",
	               12 * 8),
	       "-------g-------o-------o-------d-------b-------y-------e------- -------w-------o-------r-------l-------d");
	assert(libsimple_memreplaceelem(buf, "-------o", "=======x", 12, 8) == &buf[12 * 8]);
	assert(!memcmp(buf, "-------h-------e-------l-------l=======x------- -------w=======x-------r-------l-------d\0\0\0\0\0\0\0\0"
	                    "-------g-------o-------o-------d-------b-------y-------e------- "
	                    "-------w-------o-------r-------l-------d", 25 * 8 + 1));

	stpcpy(mempcpy(buf, "-------h-------e-------l-------l-------o------- -------w-------o-------r-------l-------d\0\0\0\0\0\0\0",
	               12 * 8),
	       "-------g-------o-------o-------d-------b-------y-------e------- -------w-------o-------r-------l-------d");
	assert(libsimple_memreplaceelem(buf, "o-------", "x=======", 12, 8) == &buf[12 * 8]);
	assert(!memcmp(buf, "-------h-------e-------l-------l-------o------- -------w-------o-------r-------l-------d\0\0\0\0\0\0\0\0"
	                    "-------g-------o-------o-------d-------b-------y-------e------- "
	                    "-------w-------o-------r-------l-------d", 25 * 8 + 1));

	return 0;
}

#endif
