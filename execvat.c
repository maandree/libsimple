/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_execvat(int dirfd, const char *pathname, char *const argv[], int flags)
{
	return execveat(dirfd, pathname, argv, environ, flags);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
