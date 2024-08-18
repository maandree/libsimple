/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void libsimple_unlist(void *, size_t, size_t *, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[10];
	int intarray[10];
	size_t i, n;

	for (i = 0, n = 10; i < n; i++)
		buf[i] = (char)i;
	LIBSIMPLE_UNLIST(buf, 4, &n);
	LIBSIMPLE_UNLIST(buf, 9 - 1, &n);
	LIBSIMPLE_UNLIST(buf, 6 - 1, &n);
	assert(n == 7);
	assert(buf[0] == 0);
	assert(buf[1] == 1);
	assert(buf[2] == 2);
	assert(buf[3] == 3);
	assert(buf[4] == 5);
	assert(buf[5] == 7);
	assert(buf[6] == 8);

	for (i = 0, n = 10; i < n; i++)
		intarray[i] = (int)i;
	LIBSIMPLE_UNLIST(intarray, 4, &n);
	LIBSIMPLE_UNLIST(intarray, 9 - 1, &n);
	LIBSIMPLE_UNLIST(intarray, 6 - 1, &n);
	assert(n == 7);
	assert(intarray[0] == 0);
	assert(intarray[1] == 1);
	assert(intarray[2] == 2);
	assert(intarray[3] == 3);
	assert(intarray[4] == 5);
	assert(intarray[5] == 7);
	assert(intarray[6] == 8);

	return 0;
}

#endif
