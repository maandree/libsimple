/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_engetexecpath(int status)
{
	int saved_errno;
	char *ret;
	saved_errno = errno;;
	errno = 0;
	ret = libsimple_getexecpath();
	if (!ret) {
		if (errno)
			libsimple_enprintf(status, "libsimple_getexecpath:");
		else
			libsimple_enprintf(status, "libsimple_getexecpath: unable to determine path\n");
	}
	errno = saved_errno;
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
