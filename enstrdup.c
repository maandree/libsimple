/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_enstrdup(int status, const char *s) /* TODO test */
{
	char *ret = strdup(s);
	if (!ret)
		enprintf(status, "strdup:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
