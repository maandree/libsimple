/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_vfexecle(int fd, va_list argv_null_envp)
{
	char *const *envp;
	va_list args;
	va_copy(args, argv_null_envp);
	while (va_arg(args, char *));
	envp = va_arg(args, char *const *);
	va_end(args);
	return libsimple_vxexecl(fd, "", AT_EMPTY_PATH, "", envp, argv_null_envp);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
