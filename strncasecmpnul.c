/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_strncasecmpnul(const char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
