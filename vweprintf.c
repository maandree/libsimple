/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


extern char *argv0;


void
vweprintf(const char *fmt, va_list ap) /* TODO test */
{
	int saved_errno = errno, r;
	const char *end = strchr(fmt, '\0');
	const char *prefix1 = argv0;
	const char *prefix2 = ": ";
	const char *suffix1 = "";
	const char *suffix2 = "";
	const char *suffix3 = "";
	char *message = NULL;
	va_list ap1;
	va_list ap2;

	if (!argv0 || !strncmp(fmt, "usage: ", strlen("usage: ")))
		prefix1 = prefix2 = "";

	va_copy(ap1, ap);
	va_copy(ap2, ap);
	r = vsnprintf(NULL, 0, fmt, ap1);
	if (0 <= r && (size_t)r < SIZE_MAX) {
		message = alloca((size_t)r + 1);
		vsprintf(message, fmt, ap2);
	}
	va_end(ap2);
	va_end(ap1);

	if (!*fmt) {
		suffix1 = strerror(saved_errno);
		suffix2 = "\n";
	} else if (end[-1] == ':') {
		suffix1 = " ";
		suffix2 = strerror(saved_errno);
		suffix3 = "\n";
	} else if (end[-1] != '\n') {
		suffix1 = "\n";
	}

	if (message) {
		/* This is to avoid mangling when multiple processes are writting. */
		fprintf(stderr, "%s%s%s%s%s%s", prefix1, prefix2, message, suffix1, suffix2, suffix3);
	} else {
		fprintf(stderr, "%s%s", prefix1, prefix2);
		vfprintf(stderr, fmt, ap);
		fprintf(stderr, "%s%s%s", suffix1, suffix2, suffix3);
	}

	errno = saved_errno;
}
