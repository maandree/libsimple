/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_vexecleat(int dirfd, const char *pathname, va_list argv_null_envp_flags)
{
	char *const *envp;
	int flags;
	va_list args;
	va_copy(args, argv_null_envp_flags);
	while (va_arg(args, char *));
	envp = va_arg(args, char *const *);
	flags = va_arg(args, int);
	va_end(args);
	return libsimple_vxexecl(dirfd, pathname, flags, NULL, envp, argv_null_envp_flags);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
