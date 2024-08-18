/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_fexecv(int fd, char *const argv[])
{
	return fexecve(fd, argv, environ);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
