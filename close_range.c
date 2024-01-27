/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST

#ifdef __linux__
# include <sys/syscall.h>
#endif


static int
uintpcmp(const void *av, const void *bv)
{
	const unsigned int *ap = av;
	const unsigned int *bp = bv;
	const unsigned int a = *ap;
	const unsigned int b = *bp;
	return a < b ? -1 : a > b;
}

static unsigned int *
list_fds(unsigned int min, unsigned int max, size_t *count)
{
	DIR *dir;
	int ignore_fd;
	unsigned int *ret = NULL, *new;
	size_t size = 0;
	struct dirent *f;
	unsigned long int fd;
	char *end;

	*count = 0;

	dir = opendir("/dev/fd");
	if (!dir)
		return NULL;
	ignore_fd = dirfd(dir);

	errno = 0;
	while ((f = readdir(dir))) {
		if (!isdigit(f->d_name[0]))
			continue;
		fd = strtoul(f->d_name, &end, 10);
		if ((int)fd == ignore_fd || (unsigned int)fd < min || (unsigned int)fd > max)
			continue;
		if (*end || fd > INT_MAX || (!fd && errno))
			continue;
		if (*count == size) {
			size += 16;
			new = realloc(ret, size * sizeof(*ret));
			if (!new)
				goto fail;
			ret = new;
		}
		ret[(*count)++] = (unsigned int)fd;
	}

	if (errno) {
	fail:
		closedir(dir);
	fail_closed:
		free(ret);
		return NULL;
	}

	if (closedir(dir))
		goto fail_closed;

	return ret;
}

int
libsimple_close_range(unsigned int first, unsigned int last, unsigned int *next) /* TODO test */
{
	int saved_errno;

	*next = first;

	if (first > last) {
		errno = EINVAL;
		return -1;
	}

	if (first > INT_MAX)
		return 0;
	if (last > INT_MAX)
		last = INT_MAX;

	saved_errno = errno;

#if defined(__linux__) && defined(__NR_close_range)
	if (!syscall(__NR_close_range, first, last, 0))
		return 0;
	else if (errno != ENOSYS)
		return -1;
#endif

	if (last - first > 100) { /* TODO best limit should be researched */
		unsigned int *fds;
		size_t n, i;
		fds = list_fds(first, last, &n);
		if (!fds)
			goto fallback;
		qsort(fds, n, sizeof(*fds), uintpcmp);
		for (i = 0; i < n; i++) {
			if (close((int)fds[i]) && errno != EBADF) {
				if (i + 1 < n)
					*next = fds[i + 1];
				else
					*next = fds[i] + (fds[i] < LIBSIMPLE_CLOSE_RANGE_MAX);
				free(fds);
				return -1;
			}
		}
		free(fds);
		goto out;
	}

fallback:
	do {
		if (close((int)first) && errno != EBADF) {
			*next = first + (first < LIBSIMPLE_CLOSE_RANGE_MAX);
			return -1;
		}
	} while (first++ < last);

out:
	*next = last + (last < LIBSIMPLE_CLOSE_RANGE_MAX);
	errno = saved_errno;
	return 0;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
