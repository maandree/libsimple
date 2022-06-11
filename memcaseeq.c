/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline int libsimple_memcaseeq(const void *, const void *, size_t);


#else
#include "test.h"

int
main(void)
{
	assert(libsimple_memcaseeq("abcxyz", "abc123", 3));
	assert(!libsimple_memcaseeq("abcxyz", "abc123", 4));
	assert(libsimple_memcaseeq("abcxyz", "abcx23", 4));
	assert(libsimple_memcaseeq("1", "2", 0));
	assert(!libsimple_memcaseeq("1", "2", 1));
	assert(libsimple_memcaseeq("abc", "ABC", 3));
	assert(libsimple_memcaseeq("ABC", "abc", 3));
	assert(libsimple_memcaseeq("ABC", "ABC", 3));
	return 0;
}

#endif
