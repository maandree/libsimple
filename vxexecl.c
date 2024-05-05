/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_vxexecl(int dirfd, const char *file, int atflags, const char *path, char *const *envp, va_list argv_null)
{
	char **argv;
	size_t argc = 0;
	va_list args;
	va_copy(args, argv_null);
	do {
		argc += 1;
	} while (va_arg(args, char *));
	va_end(args);
	argv = alloca((argc + 1) * sizeof(*argv));
	argc = 0;
	do {
		argv[argc] = va_arg(args, char *);
	} while (argv[argc++]);
	return libsimple_xexecv(dirfd, file, atflags, path, envp, argv);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
