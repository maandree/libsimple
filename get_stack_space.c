/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_get_stack_space(uintptr_t *restrict low, uintptr_t *restrict high)
{
	char buf[4096], *line;
	int fd;
	ssize_t r;
	size_t off = 0;
	size_t lineoff, linelen;

	fd = open("/proc/thread-self/maps", O_RDONLY);
	if (fd < 0)
		return -1;

	for (;;) {
	read_again:
		r = read(fd, &buf[off], sizeof(buf) - off);
		if (r <= 0) {
			if (r && errno == EINTR)
				continue;
			close(fd);
			if (!r)
				errno = EIO;
			return -1;
		}
		off += (size_t)r;

		for (lineoff = 0; lineoff < off; lineoff += linelen) {
			char *lf = strchr(&buf[lineoff], '\n');
			if (!lf) {
				memmove(&buf[0], &buf[lineoff], off -= lineoff);
				goto read_again;
			}
			line = &buf[lineoff];
			linelen = (size_t)(&lf[1] - line);
			if (linelen > sizeof(" [stack]\n") - 1U)
				if (!strcmp(&line[linelen - (sizeof(" [stack]\n") - 1U)], " [stack]\n"))
					goto line_found;
		}
	}

line_found:
	close(fd);

	*low = (uintptr_t)strtoumax(line, &line, 16);
	*high = (uintptr_t)strtoumax(&line[1], &line, 16);
	if (*low > *high) {
		*low ^= *high;
		*high ^= *low;
		*low ^= *high;
	}

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
