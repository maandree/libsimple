/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_get_stack_limit(size_t *restrict soft, size_t *restrict hard)
{
	char buf[4096], *line;
	int fd;
	ssize_t r;
	size_t off = 0;
	size_t lineoff, linelen;

	fd = open("/proc/thread-self/limits", O_RDONLY);
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
			if (linelen > sizeof("Max stack size  ") - 1U)
				if (!strcmp(line, "Max stack size  "))
					goto line_found;
		}
	}

line_found:
	close(fd);
	line = &line[sizeof("Max stack size  ") - 1U];

	while (*line == ' ' || *line == '\t')
		line++;
	if (soft) {
		*soft = SIZE_MAX;
		if (isdigit(*line))
			*soft = (size_t)strtoull(line, NULL, 10);
	}

	while (*line != ' ' && *line != '\t' && *line && *line != '\n')
		line++;

	while (*line == ' ' || *line == '\t')
		line++;
	if (hard) {
		*hard = SIZE_MAX;
		if (isdigit(*line))
			*hard = (size_t)strtoull(line, NULL, 10);
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
