/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memcasechr_inv(const void *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	size_t i = 0;
	c = tolower(c);
	for (; i < n && tolower(s[i]) == c; i++);
	return i < n ? &s[i] : NULL;
}


#else
#include "test.h"

int
main(void)
{
	assert(!strcmpnul(libsimple_memcasechr_inv("xxoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_memcasechr_inv("xxXxx", 'x', 5), NULL));
	assert(!strcmpnul(libsimple_memcasechr_inv("XXoxx", 'x', 5), "oxx"));
	assert(!strcmpnul(libsimple_memcasechr_inv("zzzzz", 'z', 5), NULL));
	assert(!strcmpnul(libsimple_memcasechr_inv("zzzzx", 'z', 3), NULL));
	return 0;
}

#endif
