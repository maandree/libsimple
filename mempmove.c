/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline void *libsimple_mempmove(void *, const void *, size_t);


#else
#include "test.h"

int
main(void)
{
	char buf[100];

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_mempmove(&buf[5], &buf[5], 5) == &buf[5 + 5]);
	assert(!strncmp(buf, "-----hello-", 11));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_mempmove(&buf[3], &buf[5], 5) == &buf[3 + 5]);
	assert(!strncmp(buf, "---hellolo-", 11));

	memset(buf, '-', sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';
	stpcpy(&buf[5], "hello")[0] = '-';
	assert(libsimple_mempmove(&buf[8], &buf[5], 5) == &buf[8 + 5]);
	assert(!strncmp(buf, "-----helhello-", 14));

	return 0;
}

#endif
