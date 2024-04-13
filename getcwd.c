/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_getcwd(void)
{
	char *cwd = NULL, *new;
	size_t cwd_size = 0;

	for (;;) {
		new = realloc(cwd, cwd_size += 512);
		if (!new)
			goto error;
		cwd = new;
		if (getcwd(cwd, cwd_size))
			break;
		if (errno != ERANGE)
			goto error;
	}

	return cwd;

error:
	free(cwd);
	return NULL;
}


#else
#include "test.h"

int
main(void) /* TODO test */
{
	return 0;
}

#endif
