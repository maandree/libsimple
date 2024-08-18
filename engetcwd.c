/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_engetcwd(int status)
{
	char *ret = libsimple_getcwd();
	if (!ret)
		libsimple_enprintf(status, "libsimple_getcwd:");
	return ret;
}


#else
#include "test.h"

int
main(void) /* TODO test */
{
	return 0;
}

#endif
