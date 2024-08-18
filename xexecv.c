/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_xexecv(int dirfd, const char *file, int atflags, const char *path, char *const *envp, char *const *argv)
{
	char *free_this;
	int ret;
	if (dirfd == -1 && atflags == -1) {
		file = libsimple_which(file, AT_FDCWD, path, &free_this);
		ret = execve(file, argv, envp);
		free(free_this);
		return ret;
	} else {
		return execveat(dirfd, file, argv, envp, atflags);
	}
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
