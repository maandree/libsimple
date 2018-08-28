/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


int
libsimple_recvfd(int sock) /* TODO test */
{
	int fd;
	char buf[1];
	struct iovec iov;
	struct msghdr msg;
	struct cmsghdr *cmsg;
	char cms[CMSG_SPACE(sizeof(fd))];

	iov.iov_base = buf;
	iov.iov_len = 1;

	memset(&msg, 0, sizeof(msg));
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;

	msg.msg_control = (caddr_t)cms;
	msg.msg_controllen = sizeof(cms);

	switch (recvmsg(sock, &msg, 0)) {
	case -1:
		return -1;
	case 0:
		errno = ECONNRESET;
		return -1;
	default:
		break;
	}

	cmsg = CMSG_FIRSTHDR(&msg);
	memcpy(&fd, CMSG_DATA(cmsg), sizeof(fd));
	return fd;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
