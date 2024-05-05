/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_fexecle(int fd, ... /* argv, NULL, char *const envp[] */)
{
	int ret;
	va_list args;
	va_start(args, fd);
	ret = libsimple_vfexecle(fd, args);
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
