/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_readmagiclink(const char *path)
{
	int fd;
	struct stat st;
	char *target1;
	char *target2;

	fd = open(path, O_PATH | O_NOFOLLOW);
	if (fd < 0)
		return NULL;

	target1 = libsimple_efreadlink(fd);
	if (!strends(target1, " (deleted)")) {
		close(fd);
		return target1;
	}

	if (fstat(fd, &st)) {
		free(target1);
		close(fd);
		return NULL;
	}

	target2 = libsimple_efreadlink(fd);
	if (!strends(target2, " (deleted)")) {
		free(target1);
		close(fd);
		return target2;
	}

	close(fd);

	if (strcmp(target1, target2)) {
		free(target2);
		return target1;
	} else {
		free(target1);
		if (st.st_nlink)
			return target2;
		target2[strlen(target2) - (sizeof(" (deleted)") - 1U)] = '\0';
		return target2;
	}
}


#else
#include "test.h"

int
main(void) /* TODO test */
{
	return 0;
}

#endif
