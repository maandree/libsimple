/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_vexeclp(const char *file, va_list argv_null)
{
	return libsimple_vxexecl(-1, file, -1, NULL, environ, argv_null);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
