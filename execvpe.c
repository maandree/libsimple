/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_execvpe(const char *file, char *const argv[], char *const envp[])
{
	return libsimple_xexecv(-1, file, -1, NULL, envp, argv);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
