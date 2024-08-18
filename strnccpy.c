/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_strnccpy(char *restrict, const char *restrict, int, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[1024];

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", '\0', 1024) == &buf[6]);
	assert(!strcmp(buf, "hello"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'o', 1024) == &buf[5]);
	assert(!strcmp(buf, "hello"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'l', 1024) == &buf[3]);
	assert(!strcmp(buf, "hel"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'x', 1024) == NULL);
	assert(!strcmp(buf, "hello"));


	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", '\0', 6) == &buf[6]);
	assert(!strcmp(buf, "hello"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'o', 6) == &buf[5]);
	assert(!strcmp(buf, "hello"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'l', 6) == &buf[3]);
	assert(!strcmp(buf, "hel"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'x', 6) == NULL);
	assert(!strcmp(buf, "hello"));


	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", '\0', 5) == NULL);
	assert(!strncmp(buf, "hellox", 6));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'o', 5) == &buf[5]);
	assert(!strncmp(buf, "hellox", 6));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'l', 5) == &buf[3]);
	assert(!strcmp(buf, "hel"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'x', 5) == NULL);
	assert(!strncmp(buf, "hellox", 6));


	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	assert(libsimple_strnccpy(buf, "hello", 'o', 3) == NULL);
	assert(!strncmp(buf, "helx", 4));

	return 0;
}

#endif
