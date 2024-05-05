/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


/**
 * Fill a buffer with random alphanumerical symbols, and '_' and '-'
 * 
 * @param  buf  The buffer to fill
 * @param  n    The size of the buffer
 */
static void
random_alnum(char *buf, size_t n)
{
	size_t i;
	int rnd;
	double drnd;

#if defined(__linux__) && defined(GRND_NONBLOCK)
	ssize_t r = getrandom(buf, n, GRND_NONBLOCK);
	i = r < 0 ? 0 : (size_t)r;
#else
	i = 0;
#endif

	for (; i < n; i++) {
		rnd = rand();
		drnd = (double)rnd / (double)RAND_MAX;
		drnd *= 63;
		rnd = (int)drnd;
		buf[i] = (char)rnd;
	}

	for (i = 0; i < n; i++)
		buf[i] = "0123456789_abcdefghijklmnopqrstuvwxyz-ABCDEFGHIJKLMNOPQRSTUVWXYZ"[buf[i] & 63];
}


int
libsimple_bindtemp_un(int fd, int dir_fd, struct sockaddr_un *addr, socklen_t *addrlen)
{
	int len, saved_errno = errno;
	size_t rem, try_limit = 1000;
	struct sockaddr_un addr_;

	if (!addr)
		addr = &addr_;
	if (addrlen)
		*addrlen = sizeof(*addr);

	memset(addr, 0, sizeof(*addr));
	addr->sun_family = AF_UNIX;

	if (dir_fd == AT_FDCWD)
		len = snprintf(addr->sun_path, sizeof(addr->sun_path), "tmp");
	else
		len = snprintf(addr->sun_path, sizeof(addr->sun_path), "/dev/fd/%i/tmp", dir_fd);
	if (len < 0 || (size_t)len >= sizeof(addr->sun_path) || sizeof(addr->sun_path) - (size_t)len < 6)
		abort();
	rem = sizeof(addr->sun_path) - 1U - (size_t)len;
	addr->sun_path[sizeof(addr->sun_path) - 1U] = 0;

	while (try_limit--) {
	again:
		random_alnum(&addr->sun_path[len], rem);
		if (!bind(fd, (void *)&addr, (socklen_t)sizeof(*addr))) {
			errno = saved_errno;
			return 0;
		} else if (errno == ENAMETOOLONG && rem > 5) {
			addr->sun_path[(size_t)len + --rem] = 0;
			goto again;
		} else if (errno != EEXIST && errno != EADDRINUSE) {
			return -1;
		}
	}
	return -1;
}


#else
#include "test.h"

int
main(void) /* TODO add test */
{
	return 0;
}

#endif
