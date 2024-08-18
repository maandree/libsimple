/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_stpnmove(char *, const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[1024];

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(&buf[3], buf, SIZE_MAX) == &buf[11 + 3]);
	assert(!strcmp(buf, "helhello world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(buf, &buf[3], SIZE_MAX) == &buf[11 - 3]);
	assert(!strcmp(buf, "lo world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(buf, buf, SIZE_MAX) == &buf[11]);
	assert(!strcmp(buf, "hello world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(&buf[3], buf, 12) == &buf[11 + 3]);
	assert(!strcmp(buf, "helhello world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(buf, &buf[3], 9) == &buf[11 - 3]);
	assert(!strcmp(buf, "lo world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(buf, buf, 12) == &buf[11]);
	assert(!strcmp(buf, "hello world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(&buf[3], buf, 11) == &buf[11 + 3]);
	assert(!strncmp(buf, "helhello worldx", 15));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(buf, &buf[3], 8) == &buf[8]);
	assert(!strcmp(buf, "lo worldrld"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(buf, buf, 11) == &buf[11]);
	assert(!strcmp(buf, "hello world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(&buf[3], buf, 2) == &buf[3 + 2]);
	assert(!strcmp(buf, "helhe world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(buf, &buf[3], 2) == &buf[2]);
	assert(!strcmp(buf, "lollo world"));

	memset(buf, 'x', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	strcpy(buf, "hello world");
	assert(libsimple_stpnmove(buf, buf, 2) == &buf[2]);
	assert(!strcmp(buf, "hello world"));

	return 0;
}

#endif
