/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_vexecl(const char *pathname, va_list argv_null)
{
	return libsimple_vxexecl(-1, pathname, -1, "", environ, argv_null);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
