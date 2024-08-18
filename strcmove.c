/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_strcmove(char *d, const char *s, int c_)
{
	char c = (char)c_, *p;
	size_t n;
	if (d <= s) {
		do {
			if ((*d++ = *s) == c) {
				*d = '\0';
				return d;
			}
		} while (*s++);
	} else {
		for (p = *(char **)(void *)&s;; p++) {
			if (*p == c || !*p) {
				n = (size_t)(p - s);
				p = &d[n];
				do { d[n] = s[n]; } while (n--);
				if (*p)
					p[1] = '\0';
				return *p == c ? &p[1] : NULL;
			}
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
	assert(libsimple_strcmove(&buf[5], &buf[5], '\0') == &buf[5 + 6]);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[5], &buf[5], 'o') == &buf[5 + 5]);
	assert(!strcmp(buf, "-----hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[5], &buf[5], 'l') == &buf[5 + 3]);
	assert(!strcmp(buf, "-----hel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[5], &buf[5], 'x') == NULL);
	assert(!strcmp(buf, "-----hello"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[3], &buf[5], '\0') == &buf[3 + 6]);
	assert(!strcmp(buf, "---hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[3], &buf[5], 'o') == &buf[3 + 5]);
	assert(!strcmp(buf, "---hello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[3], &buf[5], 'l') == &buf[3 + 3]);
	assert(!strcmp(buf, "---hel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[3], &buf[5], 'x') == NULL);
	assert(!strcmp(buf, "---hello"));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[8], &buf[5], '\0') == &buf[8 + 6]);
	assert(!strcmp(buf, "-----helhello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[8], &buf[5], 'o') == &buf[8 + 5]);
	assert(!strcmp(buf, "-----helhello"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[8], &buf[5], 'l') == &buf[8 + 3]);
	assert(!strcmp(buf, "-----helhel"));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(&buf[5], "hello");
	assert(libsimple_strcmove(&buf[8], &buf[5], 'x') == NULL);
	assert(!strcmp(buf, "-----helhello"));


	return 0;
}

#endif
