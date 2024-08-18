/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_vfexecl(int fd, va_list argv_null)
{
	return libsimple_vxexecl(fd, "", AT_EMPTY_PATH, "", environ, argv_null);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
