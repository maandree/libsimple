/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_memchr_inv(const void *s_, int c_, size_t n)
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	size_t i = 0;
	for (; i < n && s[i] == c; i++);
	return i < n ? &s[i] : NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memchr_inv("xxoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_memchr_inv("xxXxx", 'x', 5), "Xxx"));
	assert(!strcmpnul(libsimple_memchr_inv("XXoxx", 'x', 5), "XXoxx"));
	assert(!strcmpnul(libsimple_memchr_inv("zzzzz", 'z', 5), NULL));
	assert(!strcmpnul(libsimple_memchr_inv("zzzzx", 'z', 3), NULL));
	return 0;
}

#endif
