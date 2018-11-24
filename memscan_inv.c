/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memscan_inv(const void *s_, int c_, size_t n)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	size_t i = 0;
	for (; i < n && s[i] == c; i++);
	return &s[i];
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memscan_inv("xxoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_memscan_inv("xxXxx", 'x', 5), "Xxx"));
	assert(!strcmpnul(libsimple_memscan_inv("XXoxx", 'x', 5), "XXoxx"));
	assert(!strcmpnul(libsimple_memscan_inv("zzzzz", 'z', 5), ""));
	assert(!strcmpnul(libsimple_memscan_inv("zzzzx", 'z', 3), "zx"));
	return 0;
}

#endif
