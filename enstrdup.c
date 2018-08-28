/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern char *argv0;


char *
libsimple_enstrdup(int status, const char *s) /* TODO test */
{
	char *ret = strdup(s);
	if (!ret) {
		fprintf(stderr, "%s: strdup: %s\n", argv0, strerror(errno));
		exit(status);
	}
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
