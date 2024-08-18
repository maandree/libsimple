/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_fexecl(int fd, ... /* argv, NULL */)
{
	int ret;
	va_list args;
	va_start(args, fd);
	ret = libsimple_vfexecl(fd, args);
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
