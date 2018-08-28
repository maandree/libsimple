/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern char *argv0;


char *
libsimple_enstrndup(int status, const char *s, size_t n) /* TODO test */
{
	void *ret = strndup(s, n);
	if (!ret) {
		fprintf(stderr, "%s: strndup: %s\n", argv0, strerror(errno));
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
