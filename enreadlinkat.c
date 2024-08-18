/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_enreadlinkat(int status, int dirfd, const char *path)
{
	char *ret = libsimple_readlinkat(dirfd, path);
	if (!ret) {
		if (dirfd == AT_FDCWD)
			libsimple_enprintf(status, "libsimple_readlinkat AT_FDCWD %s:", path);
		else
			libsimple_enprintf(status, "libsimple_readlinkat %i %s:", dirfd, path);
	}
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
