/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_execlat(int dirfd, const char *pathname, ... /* argv, NULL, int flags */)
{
	int ret;
	va_list args;
	va_start(args, pathname);
	ret = libsimple_vexeclat(dirfd, pathname, args);
	va_end(args);
	return ret;
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
