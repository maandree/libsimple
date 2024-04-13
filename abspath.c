/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_abspath(const char *path, const char *relto)
{
	size_t size;
	int add_slash;
	char *p, *ret;

	if (*path == '/') {
		ret = strdup(path);
		return ret;
	}

	while (path[0] == '.' && path[1] == '/')
		path = &path[2];

	add_slash = (strchr(relto, '\0')[-1] != '/');
	size = strlen(relto) + strlen(path) + (size_t)(1 + add_slash);

	ret = malloc(size);
	if (ret) {
		p = stpcpy(ret, relto);
		if (add_slash)
			*p++ = '/';
		stpcpy(p, path);
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
