/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_vexeclpe(const char *file, va_list argv_null_envp)
{
	return libsimple_vxexecle(-1, file, -1, NULL, argv_null_envp);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
