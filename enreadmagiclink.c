/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_enreadmagiclink(int status, const char *path)
{
	char *ret = libsimple_readmagiclink(path);
	if (!ret)
		libsimple_enprintf(status, "libsimple_readmagiclinkat %s:", path);
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
