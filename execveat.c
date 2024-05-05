/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_execveat(int dirfd, const char *pathname, char *const argv[], char *const envp[], int flags)
{
	struct stat st;
	int fd, saved_errno;

#if defined(__linux__)
	execveat(dirfd, pathname, argv, envp, flags);
	if (errno != ENOSYS)
		return -1;
#endif

	if (flags & AT_EMPTY_PATH)
		return fexecve(dirfd, argv, envp);

#ifndef O_PATH
# define O_PATH O_RDONLY
#endif

	fd = openat(dirfd, pathname, O_PATH | ((flags & AT_SYMLINK_NOFOLLOW) ? O_NOFOLLOW : 0));
	if (fd < 0)
		return -1;

	if (flags & AT_SYMLINK_NOFOLLOW) {
		if (fstat(fd, &st)) {
			saved_errno = errno;
			close(fd);
			errno = saved_errno;
			return -1;
		}
		if (S_ISLNK(st.st_mode)) {
			close(fd);
			errno = ELOOP;
			return -1;
		}
	}

	return fexecve(fd, argv, envp);
}


#else
#include "test.h"

int
main(void)
{
        return 0;
}

#endif
