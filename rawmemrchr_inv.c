/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_rawmemrchr_inv(const void *s_, int c_, size_t n) /* TODO test, man */
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	while (s[--n] == c);
	return &s[n];
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
