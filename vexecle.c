/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_vexecle(const char *pathname, va_list argv_null_envp)
{
	return libsimple_vxexecle(-1, pathname, -1, "", argv_null_envp);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
