/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern char *argv0;


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


#else
#include "test.h"

#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic ignored "-Wformat-zero-length"
#endif

int
main(void)
{
	char prefix[100];
	int i, j;

#define T(...)\
	do {\
		stderr_n = 0;\
		if (j == 0) {\
			libsimple_weprintf(__VA_ARGS__);\
		} else if (j == 1) {\
			assert_exit(libsimple_enprintf(107, __VA_ARGS__));\
			assert(exit_status == 107);\
		} else {\
			libsimple_default_failure_exit = 108;\
			assert_exit(libsimple_eprintf(__VA_ARGS__));\
			assert(exit_status == 108);\
		}\
	} while (0)

	sprintf(prefix, "%s: ", argv0);
	stderr_ok = 1;

	for (i = 0; i < 2; i++, argv0 = NULL, *prefix = '\0') {
		for (j = 0; j < 3; j++) {
			T("%s%s%s\n", "abc", "123", "xyz");
			assert_stderr("%s%s\n", prefix, "abc123xyz");
			T("%s%s%s\n", "abc", "123", "\n");
			assert_stderr("%s%s\n", prefix, "abc123\n");
			T("%s%s%s", "abc", "123", "xyz");
			assert_stderr("%s%s\n", prefix, "abc123xyz");
			T("%s%s%s", "abc", "123", "\n");
			assert_stderr("%s%s\n", prefix, "abc123\n");
			errno = EDOM;
			T("%s%s%s:", "abc", "123", "\n");
			assert_stderr("%s%s: %s\n", prefix, "abc123\n", strerror(EDOM));
			errno = ERANGE;
			T("%s%s%s:", "abc", "123", "\n");
			assert_stderr("%s%s: %s\n", prefix, "abc123\n", strerror(ERANGE));
			errno = EOVERFLOW;
			T("");
			assert_stderr("%s%s\n", prefix, strerror(EOVERFLOW));

			T("%s%s%s\n", "usage: ", "123", "xyz");
			assert_stderr("%s%s\n", prefix, "usage: 123xyz");
			T("%s%s%s\n", "usage: ", "123", "\n");
			assert_stderr("%s%s\n", prefix, "usage: 123\n");
			T("%s%s%s", "usage: ", "123", "xyz");
			assert_stderr("%s%s\n", prefix, "usage: 123xyz");
			T("%s%s%s", "usage: ", "123", "\n");
			assert_stderr("%s%s\n", prefix, "usage: 123\n");
			errno = EDOM;
			T("%s%s%s:", "usage: ", "123", "\n");
			assert_stderr("%s%s: %s\n", prefix, "usage: 123\n", strerror(EDOM));
			errno = ERANGE;
			T("%s%s%s:", "usage: ", "123", "\n");
			assert_stderr("%s%s: %s\n", prefix, "usage: 123\n", strerror(ERANGE));

			T("usage: %s%s%s\n", "abc", "123", "xyz");
			assert_stderr("%s: %s\n", "usage", "abc123xyz");
			T("usage: %s%s%s\n", "abc", "123", "\n");
			assert_stderr("%s: %s\n", "usage", "abc123\n");
			T("usage: %s%s%s", "abc", "123", "xyz");
			assert_stderr("%s: %s\n", "usage", "abc123xyz");
			T("usage: %s%s%s", "abc", "123", "\n");
			assert_stderr("%s: %s\n", "usage", "abc123\n");
			errno = EDOM;
			T("usage: %s%s%s:", "abc", "123", "\n");
			assert_stderr("%s: %s: %s\n", "usage", "abc123\n", strerror(EDOM));
			errno = ERANGE;
			T("usage: %s%s%s:", "abc", "123", "\n");
			assert_stderr("%s: %s: %s\n", "usage", "abc123\n", strerror(ERANGE));
			T("usage: ");
			assert_stderr("%s", "usage: \n");
		}
	}

#undef T

	return 0;
}

#endif
