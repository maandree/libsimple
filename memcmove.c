/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_memcmove(void *d_, const void *s_, int c_, size_t n)
{
	char *d = d_, c = (char)c_, *p;
	const char *s = s_;
	if (d <= s) {
		for (; n; n--, s++)
			if ((*d++ = *s) == c)
				return d;
	} else {
		for (p = *(char **)(void *)&s; n; n--, p++) {
			if (*p == c) {
				n = (size_t)(p - s);
				p = &d[n + 1];
				do { d[n] = s[n]; } while (n--);
				return p;
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

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memcmove(&buf[5], &buf[5], 'o', 5) == &buf[5 + 5]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';;
	assert(libsimple_memcmove(&buf[5], &buf[5], 'l', 5) == &buf[5 + 3]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memcmove(&buf[5], &buf[5], 'x', 5) == NULL);
	assert(!strncmp(buf, "-----hello-", 11));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memcmove(&buf[3], &buf[5], 'o', 5) == &buf[3 + 5]);
	assert(!strncmp(buf, "---hellolo-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memcmove(&buf[3], &buf[5], 'l', 5) == &buf[3 + 3]);
	assert(!strncmp(buf, "---helello-", 11));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memcmove(&buf[3], &buf[5], 'x', 5) == NULL);
	assert(!strncmp(buf, "---hellolo-", 11));


	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memcmove(&buf[8], &buf[5], 'o', 5) == &buf[8 + 5]);
	assert(!strncmp(buf, "-----helhello-", 14));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memcmove(&buf[8], &buf[5], 'l', 5) == &buf[8 + 3]);
	assert(!strncmp(buf, "-----helhel-", 12));

	memset(buf, '-', sizeof(buf)), buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_memcmove(&buf[8], &buf[5], 'x', 5) == NULL);
	assert(!strncmp(buf, "-----helhello-", 14));

	return 0;
}

#endif
