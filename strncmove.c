/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strncmove(char *d, const char *s, int c_, size_t n)
{
	char c = (char)c_, *p, *end = &d[n];
	if (d <= s) {
		do {
			if (!n--)
				break;
			if ((*d++ = *s) == c) {
				if (n)
					*d = '\0';
				return d;
			}
		} while (*s++);
	} else {
		for (p = *(char **)(void *)&s; n; n--, p++) {
			if (*p == c || !*p) {
				n = (size_t)(p - s);
				p = &d[n];
				for (;; n--) {
					d[n] = s[n];
					if (!n)
						break;
				}
				if (&p[1] != end && *p)
					p[1] = '\0';
				return *p == c ? &p[1] : NULL;
			}
		}
		for (n = (size_t)(p - s); n;) {
			n--;
			d[n] = s[n];
		}
	}
	return NULL;
}


#else
#include "test.h"

int
main(void)
{
	char buf[1024];


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], '\0', 1024) == &buf[5 + 6]);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'o', 1024) == &buf[5 + 5]);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'l', 1024) == &buf[5 + 3]);
	assert(!strcmp(buf, "-----hel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'x', 1024) == NULL);
	assert(!strcmp(buf, "-----hello"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], '\0', 1024) == &buf[3 + 6]);
	assert(!strcmp(buf, "---hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'o', 1024) == &buf[3 + 5]);
	assert(!strcmp(buf, "---hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'l', 1024) == &buf[3 + 3]);
	assert(!strcmp(buf, "---hel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'x', 1024) == NULL);
	assert(!strcmp(buf, "---hello"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], '\0', 1024) == &buf[8 + 6]);
	assert(!strcmp(buf, "-----helhello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'o', 1024) == &buf[8 + 5]);
	assert(!strcmp(buf, "-----helhello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'l', 1024) == &buf[8 + 3]);
	assert(!strcmp(buf, "-----helhel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'x', 1024) == NULL);
	assert(!strcmp(buf, "-----helhello"));



	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], '\0', 6) == &buf[5 + 6]);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'o', 6) == &buf[5 + 5]);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'l', 6) == &buf[5 + 3]);
	assert(!strcmp(buf, "-----hel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'x', 6) == NULL);
	assert(!strcmp(buf, "-----hello"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], '\0', 6) == &buf[3 + 6]);
	assert(!strcmp(buf, "---hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'o', 6) == &buf[3 + 5]);
	assert(!strcmp(buf, "---hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'l', 6) == &buf[3 + 3]);
	assert(!strcmp(buf, "---hel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'x', 6) == NULL);
	assert(!strcmp(buf, "---hello"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], '\0', 6) == &buf[8 + 6]);
	assert(!strcmp(buf, "-----helhello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'o', 6) == &buf[8 + 5]);
	assert(!strcmp(buf, "-----helhello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'l', 6) == &buf[8 + 3]);
	assert(!strcmp(buf, "-----helhel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'x', 6) == NULL);
	assert(!strcmp(buf, "-----helhello"));



	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_strncmove(&buf[5], &buf[5], '\0', 5) == NULL);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_strncmove(&buf[5], &buf[5], 'o', 5) == &buf[5 + 5]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_strncmove(&buf[5], &buf[5], 'l', 5) == &buf[5 + 3]);
	assert(!strcmp(buf, "-----hel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_strncmove(&buf[5], &buf[5], 'x', 5) == NULL);
	assert(!strncmp(buf, "-----hello-", 11));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], '\0', 5) == NULL);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'o', 5) == &buf[5 + 5]);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'l', 5) == &buf[5 + 3]);
	assert(!strcmp(buf, "-----hel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'x', 5) == NULL);
	assert(!strcmp(buf, "-----hello"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], '\0', 5) == NULL);
	assert(!strcmp(buf, "---hellolo"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'o', 5) == &buf[3 + 5]);
	assert(!strcmp(buf, "---hellolo"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'l', 5) == &buf[3 + 3]);
	assert(!strcmp(buf, "---hel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'x', 5) == NULL);
	assert(!strcmp(buf, "---hellolo"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], '\0', 5) == NULL);
	assert(!strncmp(buf, "-----helhello-", 14));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'o', 5) == &buf[8 + 5]);
	assert(!strncmp(buf, "-----helhello-", 14));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'l', 5) == &buf[8 + 3]);
	assert(!strcmp(buf, "-----helhel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'x', 5) == NULL);
	assert(!strncmp(buf, "-----helhello-", 14));



	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], '\0', 3) == NULL);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'o', 3) == NULL);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'l', 3) == &buf[5 + 3]);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[5], &buf[5], 'x', 3) == NULL);
	assert(!strcmp(buf, "-----hello"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], '\0', 3) == NULL);
	assert(!strcmp(buf, "---helello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'o', 3) == NULL);
	assert(!strcmp(buf, "---helello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'l', 3) == &buf[3 + 3]);
	assert(!strcmp(buf, "---helello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[3], &buf[5], 'x', 3) == NULL);
	assert(!strcmp(buf, "---helello"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], '\0', 3) == NULL);
	assert(!strncmp(buf, "-----helhel-", 12));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'o', 3) == NULL);
	assert(!strncmp(buf, "-----helhel-", 12));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'l', 3) == &buf[8 + 3]);
	assert(!strncmp(buf, "-----helhel-", 12));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strncmove(&buf[8], &buf[5], 'x', 3) == NULL);
	assert(!strncmp(buf, "-----helhel-", 12));


	return 0;
}

#endif
