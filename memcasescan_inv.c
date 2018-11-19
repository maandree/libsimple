/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memcasescan_inv(const void *s_, int c, size_t n) /* TODO man */
{
	char *s = *(char **)(void *)&s_;
	size_t i = 0;
	c = tolower(c);
	for (; i < n && tolower(s[i]) == c; i++);
	return &s[i];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memcasescan_inv("xxoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_memcasescan_inv("xxXxx", 'x', 5), ""));
	assert(!strcmpnul(libsimple_memcasescan_inv("XXoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_memcasescan_inv("zzzzz", 'z', 5), ""));
	assert(!strcmpnul(libsimple_memcasescan_inv("zzzzx", 'z', 3), "zx"));
	return 0;
}

#endif
