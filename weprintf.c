/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void libsimple_weprintf(const char *, ...);


#else
#include "test.h"

#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic ignored "-Wformat-zero-length"
#endif

static void
preprint(void)
{
	test_fprintf(stderr, "pre\n");
}

static void
postprint(void)
{
	test_fprintf(stderr, "post\n");
}

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
			libsimple_eprintf_preprint = preprint;
			T("%s%s%s\n", "abc", "123", "\n");
			assert_stderr("pre\n%s%s\n", prefix, "abc123\n");
			libsimple_eprintf_preprint = NULL;
			libsimple_eprintf_postprint = postprint;
			T("%s%s%s", "abc", "123", "xyz");
			assert_stderr("%s%s\npost\n", prefix, "abc123xyz");
			libsimple_eprintf_postprint = NULL;
			T("%s%s%s", "abc", "123", "\n");
			assert_stderr("%s%s\n", prefix, "abc123\n");
			errno = EDOM;
			libsimple_eprintf_preprint = preprint;
			libsimple_eprintf_postprint = postprint;
			T("%s%s%s:", "abc", "123", "\n");
			assert_stderr("pre\n%s%s: %s\npost\n", prefix, "abc123\n", strerror(EDOM));
			libsimple_eprintf_preprint = NULL;
			libsimple_eprintf_postprint = NULL;
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
