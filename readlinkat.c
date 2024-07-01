/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_readlinkat(int dirfd, const char *path)
{
	char *ret = NULL, *new;
	size_t size = 0;
	ssize_t r;

	do {
		new = realloc(ret, size += 128);
		if (!new) {
			errno = ENOMEM;
		fail:
			free(ret);
			return NULL;
		}
		ret = new;
		r = readlinkat(dirfd, path, ret, size - 1U);
		if (r < 0)
			goto fail;
	} while ((size_t)r >= size - 2U);

	ret[r] = '\0';
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
