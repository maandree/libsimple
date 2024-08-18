/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


const char *
libsimple_which(const char *file, int cwdfd, const char *path, char **free_this_out)
{
	const char *p, *q;
	char *buf = NULL;
	size_t bufsize, len, filelen;
	int got_eacces = 0, saved_errno = errno;

	free_this_out = NULL;

	if (!file || !free_this_out) {
		errno = EINVAL;
		return NULL;
	}

	if (strchr(file, '/'))
		return file;

	if (!path) {
		path = getenv("PATH");
		if (!path)
			path = "";
	}
	if (!*path) {
		errno = ENOENT;
		return NULL;
	}

	bufsize = 0;
	for (p = path; p; p = q) {
		q = strchr(p, ':');
		if (q)
			len = (size_t)(q++ - p);
		else
			len = strlen(p);
		if (len > bufsize)
			bufsize = len;
	}
	if (bufsize) {
		filelen = strlen(file) + 1U;
		bufsize += 1U + filelen;
		buf = malloc(bufsize);
		if (!buf)
			return NULL;
	}

	for (p = path; p; p = q) {
		q = strchr(p, ':');
		if (q)
			len = (size_t)(q++ - p);
		else
			len = strlen(p);
		if (len) {
			memcpy(buf, p, len);
			buf[len] = '/';
			memcpy(&buf[len + 1], file, filelen);
			if (!faccessat(cwdfd, buf, X_OK, AT_EACCESS)) {
				*free_this_out = buf;
				errno = saved_errno;
				return buf;
			}
		} else {
			if (!faccessat(cwdfd, file, X_OK, AT_EACCESS)) {
				errno = saved_errno;
				return file;
			}
		}
		if (errno == EACCES)
			got_eacces = 1;
	}

	free(buf);
	errno = got_eacces ? EACCES : ENOENT;
	return NULL;
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
