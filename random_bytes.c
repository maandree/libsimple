/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_random_bytes(uintmax_t (*rng)(size_t bits, void *user), void *user, void *buffer, size_t bytes)
{
	char *buf = buffer;
	uintmax_t rnd;

	while (bytes >= sizeof(uintmax_t)) {
		rnd = (*rng)(sizeof(uintmax_t) * 8U, user);
		memcpy(buf, &rnd, sizeof(uintmax_t));
		bytes -= sizeof(uintmax_t);
		buf = &buf[sizeof(uintmax_t)];
	}

	if (bytes) {
		rnd = (*rng)(bytes * 8U, user);
		while (bytes) {
			*buf++ = (char)(rnd & 255U);
			bytes--;
			rnd >>= 8;
		}
	}

	return buf;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
