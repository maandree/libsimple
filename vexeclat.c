/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_vexeclat(int dirfd, const char *pathname, va_list argv_null_flags)
{
	int flags;
	va_list args;
	va_copy(args, argv_null_flags);
	while (va_arg(args, char *));
	flags = va_arg(args, int);
	va_end(args);
	return libsimple_vxexecl(dirfd, pathname, flags, NULL, environ, argv_null_flags);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
