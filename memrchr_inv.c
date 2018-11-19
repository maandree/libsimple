/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memrchr_inv(const void *s_, int c_, size_t n_) /* TODO test, man */
{
	char *s = *(char **)(void *)&s_, c = (char)c_;
	ssize_t n = n_;
	while (n-- && s[n] == c);
	return n < 0 ? NULL : &s[n];
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
