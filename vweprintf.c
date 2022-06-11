/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern char *argv0;


int libsimple_default_failure_exit = 1;
void (*libsimple_eprintf_preprint)(void) = NULL;
void (*libsimple_eprintf_postprint)(void) = NULL;


void
libsimple_vweprintf(const char *fmt, va_list ap)
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

	if (!argv0 || !strncmp(fmt, "usage: ", sizeof("usage: ") - 1))
		prefix1 = prefix2 = "";

	va_copy(ap1, ap);
	va_copy(ap2, ap);
	r = vsnprintf(NULL, 0, fmt, ap1);
	if (0 <= r && r < 8096) {
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

	if (libsimple_eprintf_preprint)
		libsimple_eprintf_preprint();
	if (message) {
		/* This is to avoid mangling when multiple processes are writting. */
		fprintf(stderr, "%s%s%s%s%s%s", prefix1, prefix2, message, suffix1, suffix2, suffix3);
	} else {
		fprintf(stderr, "%s%s", prefix1, prefix2);
		vfprintf(stderr, fmt, ap);
		fprintf(stderr, "%s%s%s", suffix1, suffix2, suffix3);
	}
	if (libsimple_eprintf_postprint)
		libsimple_eprintf_postprint();

	errno = saved_errno;
}


#else
#include "test.h"

int
main(void)
{
	return 0; /* Tested via libsimple_weprintf */
}

#endif
