/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_xexecl(int dirfd, const char *file, int atflags, const char *path, char *const *envp, ... /* argv, NULL */)
{
	int ret;
	va_list args;
	va_start(args, envp);
	ret = libsimple_vxexecl(dirfd, file, atflags, path, envp, args);
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
