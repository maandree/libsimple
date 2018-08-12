/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


ssize_t
libsimple_recvfrom_timestamped(int fd, void *restrict buf, size_t n, int flags, struct sockaddr *restrict addr, /* TODO test */
                               socklen_t addrlen, struct timespec *restrict ts)
{
	struct iovec iov;
	struct msghdr msg;
	struct cmsghdr *cmsg;
	char cms[CMSG_SPACE(sizeof(*ts))];
	size_t r;

	iov.iov_base = buf;
	iov.iov_len = n;

	memset(&msg, 0, sizeof(msg));
	msg.msg_name = addr;
	msg.msg_namelen = addrlen;
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;

	msg.msg_control = (caddr_t)cms;
	msg.msg_controllen = sizeof(cms);

	switch ((r = recvmsg(fd, &msg, flags))) {
	case -1:
		return -1;
	case 0:
	       	errno = ECONNRESET;
		return -1;
	default:
		break;
	}

	if (!ts)
		return r;

	cmsg = CMSG_FIRSTHDR(&msg);
	if (cmsg &&
	    cmsg->cmsg_level == SOL_SOCKET &&
	    cmsg->cmsg_type  == SCM_TIMESTAMPNS &&
	    cmsg->cmsg_len   == CMSG_LEN(sizeof(*ts))) {
		memcpy(ts, CMSG_DATA(cmsg), sizeof(*ts));
	} else if (cmsg &&
	           cmsg->cmsg_level == SOL_SOCKET &&
	           cmsg->cmsg_type  == SCM_TIMESTAMP &&
	           cmsg->cmsg_len   == CMSG_LEN(sizeof(*ts))) {
		memcpy(ts, CMSG_DATA(cmsg), sizeof(*ts));
		ts->tv_nsec *= 1000;
	} else {
		memset(ts, 0, sizeof(*ts));
	}

	return r;
}
