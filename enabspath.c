/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_enabspath(int status, const char *path, const char *relto)
{
	char *ret = libsimple_abspath(path, relto);
	if (!ret)
		libsimple_enprintf(status, "libsimple_abspath %s %s:", path, relto ? relto : "NULL");
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
