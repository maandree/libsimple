/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void * libsimple_rawmemcmove(void *__d_, const void *__s_, int __c_);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemcmove(&buf[5], &buf[5], 'o') == &buf[5 + 5]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemcmove(&buf[5], &buf[5], 'l') == &buf[5 + 3]);
	assert(!strncmp(buf, "-----hello-", 11));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemcmove(&buf[3], &buf[5], 'o') == &buf[3 + 5]);
	assert(!strncmp(buf, "---hellolo-", 11));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemcmove(&buf[3], &buf[5], 'l') == &buf[3 + 3]);
	assert(!strncmp(buf, "---helello-", 11));


	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemcmove(&buf[8], &buf[5], 'o') == &buf[8 + 5]);
	assert(!strncmp(buf, "-----helhello-", 14));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_rawmemcmove(&buf[8], &buf[5], 'l') == &buf[8 + 3]);
	assert(!strncmp(buf, "-----helhel-", 12));

	return 0;
}

#endif
