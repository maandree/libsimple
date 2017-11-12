/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#include <ifaddrs.h>


extern char *argv0;


int libsimple_default_failure_exit = 1;


void *
libsimple_rawmemchr(const void *s_, int c)
{
	char *s = *(char **)(void *)&s_;
	while ((int)*s++ != c);
	return &s[-1];
}


void *
libsimple_memrchr(const void *s_, int c, size_t n_)
{
	char *s = *(char **)(void *)&s_;
	ssize_t n = n_;
	while (n-- && (int)s[n] != c);
	return n < 0 ? NULL : &s[n];
}


void *
libsimple_rawmemrchr(const void *s_, int c, size_t n)
{
	char *s = *(char **)(void *)&s_;
	while ((int)s[--n] != c);
	return &s[n];
}


char *
libsimple_strchrnul(const char *s_, int c)
{
	char *s = *(char **)(void *)&s_;
	for (; *s && (int)*s != c; s++)
	return s;
}


void *
libsimple_memdup(const void *s, size_t n)
{
	void *ret = malloc(n);
	if (!ret)
		return NULL;
	return memcpy(ret, s, n);
}


char *
libsimple_strndup(const char *s, size_t n)
{
	void *ret;
	if (n == SIZE_MAX) {
		errno = ENOMEM;
		return NULL;
	}
	if (!(ret = malloc(n + 1)))
		return NULL;
	memcpy(ret, s, n);
	((char *)ret)[n] = '\0';
	return ret;
}


int
libsimple_isutf8(const char *string, int allow_modified_nul)
{
	static long BYTES_TO_MIN_BITS[] = {0, 0,  8, 12, 17, 22, 37};
        static long BYTES_TO_MAX_BITS[] = {0, 7, 11, 16, 21, 26, 31};
        long int bytes = 0, read_bytes = 0, bits = 0, c, character;

        /*                                                      min bits  max bits
          0.......                                                 0         7
          110..... 10......                                        8        11
          1110.... 10...... 10......                              12        16
          11110... 10...... 10...... 10......                     17        21
          111110.. 10...... 10...... 10...... 10......            22        26
          1111110. 10...... 10...... 10...... 10...... 10......   27        31
        */

	while ((c = (long int)(*string++))) {
                if (!read_bytes) {
                        /* First byte of the character. */

                        if (!(c & 0x80))
                                /* Single-byte character. */
                                continue;

                        if ((c & 0xC0) == 0x80)
                                /* Single-byte character marked as multibyte, or
                                   a non-first byte in a multibyte character. */
                                return -1;

                        /* Multibyte character. */
                        while ((c & 0x80))
                                bytes++, c <<= 1;
                        read_bytes = 1;
                        character = c & 0x7F;
                        if (bytes > 6)
                                /* 31-bit characters can be encoded with 6-bytes,
                                   and UTF-8 does not cover higher code points. */
                                return -1;
                } else {
                        /* Not first byte of the character. */

                        if ((c & 0xC0) != 0x80)
                                /* Beginning of new character before a
                                   multibyte character has ended. */
                                return -1;

                        character = (character << 6) | (c & 0x7F);

                        if (++read_bytes < bytes)
                                /* Not at last byte yet. */
                                continue;

                        /* Check that the character is not unnecessarily long. */
                        while (character)
                                character >>= 1, bits++;
                        bits = (!bits && bytes == 2 && allow_modified_nul) ? 8 : bits;
                        if (bits < BYTES_TO_MIN_BITS[bytes] || BYTES_TO_MAX_BITS[bytes] < bits)
                                return -1;

                        read_bytes = bytes = bits = 0;
                }
        }

        /* Make sure we did not stop at the middle of a multibyte character. */
        return !read_bytes;
}


int
libsimple_asprintf(char **strp, const char *fmt, ...)
{
	va_list ap;
	int r;
	va_start(ap, fmt);
	r = libsimple_vasprintf(strp, fmt, ap);
	va_end(ap);
	return r;
}


int
libsimple_vasprintf(char **strp, const char *fmt, va_list ap)
{
	FILE *fp;
	size_t siz = 0;
	int ret;
	*strp = NULL;
	fp = open_memstream(strp, &siz);
	if (!fp)
		goto fail;
	ret = vfprintf(fp, fmt, ap);
	if (ret < 0)
		goto fail;
	if (fputc(0, fp))
		goto fail;
	fclose(fp);
	return ret;
fail:
	free(*strp);
	*strp = NULL;
	return -1;
}


void *
libsimple_memmem(const void *hay_, size_t hayn, const void *sub_, size_t subn)
{
	char *hay = *(char **)(void *)&hay_, *end;
	const char *sub = sub_;

	if (!subn)
		return hay;
	if (hayn < subn)
		return NULL;
	if (subn == 1)
		return memchr(hay, *sub, hayn);

	for (end = &hay[hayn - subn + 1]; hay != end; hay++)
		if (*hay == *sub && !memcmp(hay, sub, subn))
			return hay;

	return NULL;
}


char *
libsimple_strcasestr(const char *h_, const char *n)
{
	char *h = *(char **)(void *)&h_;
	size_t hn = strlen(h);
	size_t nn = strlen(n);
	if (hn < nn)
		return NULL;
	for (hn -= nn; hn--; h++)
		if (!strcasecmp(h, n))
			return h;
	return NULL;
}


int
libsimple_memstarts(const void *s_, size_t n, const void *t_, size_t m)
{
	const char *s = s_, *t = t_;
	size_t i = 0;
	if (n < m)
		return 0;
	while (i < m && s[i] == t[i]) i++;
	return i == m;
}


int
libsimple_memends(const void *s_, size_t n, const void *t_, size_t m)
{
	const char *s = s_, *t = t_;
	if (n < m)
		return 0;
	while (n--, m--)
		if (s[n] != t[m])
			return 0;
	return 1;
}


int
libsimple_strstarts(const char *s, const char *t)
{
	for (; *t && *s == *t; s++, t++);
	return !*t;
}


int
libsimple_strends(const char *s, const char *t)
{
	return memends(s, strlen(s), t, strlen(t));
}


static inline size_t
alloc_size_product(size_t n, va_list ap)
{
	size_t prod = n;
	if (!n) {
		errno = EINVAL;
		return 0;
	}
	for (;;) {
		n = va_arg(ap, size_t);
		if (!n)
			break;
		if (n >= SIZE_MAX / prod) {
			errno = ENOMEM;
			return 0;
		}
		prod *= n;
	}
	return prod;
}

void *
libsimple_vmalloczn(int clear, size_t n, va_list ap)
{
	n = alloc_size_product(n, ap);
	return !n ? NULL : clear ? calloc(1, n) : malloc(n);
}

void *
libsimple_vreallocn(void *ptr, size_t n, va_list ap)
{
	n = alloc_size_product(n, ap);
	return !n ? NULL : realloc(ptr, n);
}


void *
enmalloc(int status, size_t n)
{
	void *ret = malloc(n);
	if (!ret) {
		fprintf(stderr, "%s: malloc: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}


void *
encalloc(int status, size_t n, size_t m)
{
	void *ret = calloc(n, m);
	if (!ret) {
		fprintf(stderr, "%s: calloc: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}


void *
enrealloc(int status, void *ptr, size_t n)
{
	char *ret = realloc(ptr, n);
	if (!ret) {
		fprintf(stderr, "%s: realloc: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}


char *
enstrdup(int status, const char *s)
{
	char *ret = strdup(s);
	if (!ret) {
		fprintf(stderr, "%s: strdup: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}


char *
enstrndup(int status, const char *s, size_t n)
{
	void *ret = strndup(s, n);
	if (!ret) {
		fprintf(stderr, "%s: strndup: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}


void *
enmemdup(int status, const void *s, size_t n)
{
	void *ret = memdup(s, n);
	if (!ret) {
		fprintf(stderr, "%s: memdup: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}


void *
libsimple_envmalloczn(int status, int clear, size_t n, va_list ap)
{
	void *ret = libsimple_vmalloczn(clear, n, ap);
	if (!ret) {
		fprintf(stderr, "%s: %s: %s\n", argv0, clear ? "calloc" : "malloc", strerror(errno));
		exit(status);
	}
	return ret;
}


void *
libsimple_envreallocn(int status, void *ptr, size_t n, va_list ap)
{
	void *ret = libsimple_vreallocn(ptr, n, ap);
	if (!ret) {
		fprintf(stderr, "%s: realloc: %s\n", argv0, strerror(errno));
		exit(status);
	}
	return ret;
}


int
vputenvf(const char *fmt, va_list ap)
{
	va_list ap2;
	int n;
	char *s;
	va_copy(ap2, ap);
	n = vsnprintf(NULL, 0, fmt, ap2);
	va_end(ap2);
	if (n < 0)
		return -1;
	if ((size_t)n == SIZE_MAX) {
		errno = ENOMEM;
		return -1;
	}
	s = alloca((size_t)n + 1);
	vsprintf(s, fmt, ap);
	return putenv(s);
}


void
envputenvf(int status, const char *fmt, va_list ap)
{
	if (vputenvf(fmt, ap)) {
		fprintf(stderr, "%s: putenvf: %s\n", argv0, strerror(errno));
		exit(status);
	}
}


void
vweprintf(const char *fmt, va_list ap)
{
	int saved_errno = errno, r;
	const char *end = strchr(fmt, '\0');
	const char *prefix1 = argv0;
	const char *prefix2 = ": ";
	const char *suffix1 = "";
	const char *suffix2 = "";
	const char *suffix3 = "";
	char *message = NULL;
	va_list ap1;
	va_list ap2;

	if (!argv0 || !strncmp(fmt, "usage: ", strlen("usage: ")))
		prefix1 = prefix2 = "";

	va_copy(ap1, ap);
	va_copy(ap2, ap);
	r = vsnprintf(NULL, 0, fmt, ap1);
	if (0 <= r && (size_t)r < SIZE_MAX) {
		message = alloca((size_t)r + 1);
		vsprintf(message, fmt, ap2);
	}
	va_end(ap2);
	va_end(ap1);

	if (!*fmt) {
		suffix1 = strerror(saved_errno);
		suffix2 = "\n";
	} else if (end[-1] == ':') {
		suffix1 = " ";
		suffix2 = strerror(saved_errno);
		suffix3 = "\n";
	} else if (end[-1] != '\n') {
		suffix1 = "\n";
	}

	if (message) {
		/* This is to avoid mangling when multiple processes are writting. */
		fprintf(stderr, "%s%s%s%s%s%s", prefix1, prefix2, message, suffix1, suffix2, suffix3);
	} else {
		fprintf(stderr, "%s%s", prefix1, prefix2);
		vfprintf(stderr, fmt, ap);
		fprintf(stderr, "%s%s%s", suffix1, suffix2, suffix3);
	}

	errno = saved_errno;
}



int
libsimple_sendfd(int sock, int fd)
{
	char buf[1];
	struct iovec iov;
	struct msghdr msg;
	struct cmsghdr *cmsg;
	char cms[CMSG_SPACE(sizeof(fd))];

	buf[0] = 0;
	iov.iov_base = buf;
	iov.iov_len = 1;

	memset(&msg, 0, sizeof(msg));
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	msg.msg_control = (caddr_t)cms;
	msg.msg_controllen = CMSG_LEN(sizeof(fd));

	cmsg = CMSG_FIRSTHDR(&msg);
	cmsg->cmsg_len = CMSG_LEN(sizeof(fd));
	cmsg->cmsg_level = SOL_SOCKET;
	cmsg->cmsg_type = SCM_RIGHTS;
	memcpy(CMSG_DATA(cmsg), &fd, sizeof(fd));

	return -(sendmsg(sock, &msg, 0) != (ssize_t)iov.iov_len);
}


int
libsimple_recvfd(int sock)
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


ssize_t
libsimple_recvfrom_timestamped(int fd, void *restrict buf, size_t n, int flags, struct sockaddr *restrict addr,
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


int
libsimple_sumtimespec(struct timespec *sum, const struct timespec *augend, const struct timespec *addend)
{
	long int ns = augend->tv_nsec + addend->tv_nsec;
	time_t s;
	int ret = 0;

	s = augend->tv_sec + addend->tv_sec;
	if ((augend->tv_sec < 0) == (addend->tv_sec < 0)) {
		if (augend->tv_sec >= 0 && augend->tv_sec > TIME_MAX - addend->tv_sec) {
			s = TIME_MAX;
			ns = 999999999L;
			errno = ERANGE;
			ret = -1;
		} else if (augend->tv_sec < 0 && augend->tv_sec + addend->tv_sec < TIME_MIN) {
			s = TIME_MIN;
			ns = 0;
			errno = ERANGE;
			ret = -1;
		}
	}

	if (ns < 0) {
		if (s == TIME_MIN) {
			ns = 0L;
			errno = ERANGE;
			ret = -1;
		} else {
			s -= 1;
			ns += 1000000000L;
		}
	} else if (ns >= 1000000000L) {
		if (s == TIME_MAX) {
			ns = 999999999L;
			errno = ERANGE;
			ret = -1;
		} else {
			s += 1;
			ns -= 1000000000L;
		}
	}

	sum->tv_sec = s;
	sum->tv_nsec = ns;
	return ret;
}


int
libsimple_difftimespec(struct timespec *diff, const struct timespec *minuend, const struct timespec *subtrahend)
{
	long int ns = minuend->tv_nsec - subtrahend->tv_nsec;
	time_t s;
	int ret = 0;

	s = minuend->tv_sec - subtrahend->tv_sec;
	if ((minuend->tv_sec <= 0) != (subtrahend->tv_sec <= 0)) {
		if (minuend->tv_sec < 0 && minuend->tv_sec < TIME_MIN + subtrahend->tv_sec) {
			s = TIME_MIN;
			ns = 0;
			errno = ERANGE;
			ret = -1;
		} else if (minuend->tv_sec >= 0 && minuend->tv_sec > TIME_MAX + subtrahend->tv_sec) {
			s = TIME_MAX;
			ns = 999999999L;
			errno = ERANGE;
			ret = -1;
		}
	}

	if (ns < 0) {
		if (s == TIME_MIN) {
			ns = 0L;
			errno = ERANGE;
			ret = -1;
		} else {
			s -= 1;
			ns += 1000000000L;
		}
	} else if (ns >= 1000000000L) {
		if (s == TIME_MAX) {
			ns = 999999999L;
			errno = ERANGE;
			ret = -1;
		} else {
			s += 1;
			ns -= 1000000000L;
		}
	}

	diff->tv_sec = s;
	diff->tv_nsec = ns;
	return ret;
}


int
libsimple_multimespec(struct timespec *prod, const struct timespec *multiplicand, int multiplier)
{
	time_t s = multiplicand->tv_sec;
	long long int ns = (long long int)(multiplicand->tv_nsec);
	long long int xs;
	int neg = (s < 0) ^ (multiplier < 0);

	if (multiplier == 0 || multiplier == 1) {
		prod->tv_sec = multiplier * multiplicand->tv_sec;
		prod->tv_nsec = multiplier * multiplicand->tv_nsec;
		return 0;
	}

	if (s < 0) {
		if (TIME_MIN != -TIME_MAX && s == TIME_MIN)
			goto overflow;
		s = -s;
		if (ns)
			ns = 1000000000L - ns;
	}
	if (multiplier < 0)
		multiplier = -multiplier;

	ns *= multiplier;
	xs /= 1000000000L;
	ns %= 1000000000L;

	if (s > TIME_MAX / multiplier)
		goto overflow;
	s *= multiplier;

	if (s > TIME_MAX - (time_t)xs)
		goto overflow;
	s += (time_t)xs;

	if (neg) {
		s = -s;
		if (ns) {
			if (s == TIME_MIN)
				goto overflow;
			ns = 1000000000L - ns;
			s -= 1;
		}
	}

	prod->tv_sec = s;
	prod->tv_nsec = ns;
	return 0;

overflow:
	if (neg) {
		prod->tv_sec = TIME_MIN;
		prod->tv_nsec = 0;
	} else {
		prod->tv_sec = TIME_MAX;
		prod->tv_nsec = 999999999L;
	}
	errno = ERANGE;
	return -1;
}


int
libsimple_sumtimeval(struct timeval *sum, const struct timeval *augend, const struct timeval *addend)
{
	struct timespec a, b, s;
	int r;
	libsimple_timeval2timespec(&a, augend);
	libsimple_timeval2timespec(&b, addend);
	r = libsimple_sumtimespec(&s, &a, &b);
	if (r && errno != ERANGE)
		return r;
	return r | libsimple_timespec2timeval(sum, &s);
}


int
libsimple_difftimeval(struct timeval *diff, const struct timeval *minuend, const struct timeval *subtrahend)
{
	struct timespec a, b, d;
	int r;
	libsimple_timeval2timespec(&a, minuend);
	libsimple_timeval2timespec(&b, subtrahend);
	r = libsimple_difftimespec(&d, &a, &b);
	if (r && errno != ERANGE)
		return r;
	return r | libsimple_timespec2timeval(diff, &d);
}


int
libsimple_multimeval(struct timeval *prod, const struct timeval *multiplicand, int multiplier)
{
	struct timespec a, p;
	int r;
	libsimple_timeval2timespec(&a, multiplicand);
	r = libsimple_multimespec(&p, &a, multiplier);
	if (r && errno != ERANGE)
		return r;
	return r | libsimple_timespec2timeval(prod, &p);
}


int
libsimple_timespec2timeval(struct timeval *restrict tv, const struct timespec *restrict ts)
{
        tv->tv_sec = ts->tv_sec;
        tv->tv_usec = ts->tv_nsec / 1000L;
        if ((ts->tv_nsec % 1000L) >= 500L) {
                if (++(tv->tv_usec) == 1000000L) {
                        tv->tv_usec = 0;
                        if (tv->tv_sec == TIME_MAX) {
                                tv->tv_usec = 999999L;
                                errno = EOVERFLOW;
                                return -1;
                        } else {
                                tv->tv_sec += 1;
                        }
                }
        }
        return 0;
}


int
libsimple_strtotimespec(struct timespec *restrict ts, const char *restrict s, char **restrict end)
{
	int neg = 0, bracket = 0;
	time_t sec = 0;
	long int nsec = 0;
	long int mul = 100000000L;
	const char *p;

	if (end)
		*end = (void *)s;

	while (isspace(*s))
		s++;

	if (!isdigit(s) && *s != '+' && *s != '-' && *s != '.') {
		errno = EINVAL;
		return -1;
	}

	if (*s == '-') {
		neg = 1;
		s++;
	} else if (*s == '+') {
		s++;
	}

	if (*s == '.') {
		if (s[1] == '.' || s[1] == '(') {
			if (!isdigit(s[2])) {
				errno = EINVAL;
				return -1;
			}
		} else if (!isdigit(s[1])) {
			errno = EINVAL;
			return -1;
		}
	}

	for (; isdigit(*s); s++) {
		if (sec < TIME_MIN / 10)
			goto overflow;
		sec *= 10;
		if (sec < TIME_MIN + (*s & 15))
			goto overflow;
		sec -= *s & 15;
	}

	if (!neg) {
		if (TIME_MIN != -TIME_MAX && sec == TIME_MIN)
			goto overflow;
		sec = -sec;
	}

	if (*s != '.') {
		ts->tv_sec = sec;
		ts->tv_nsec = 0;
		if (end)
			*end = (void *)s;
		return 0;
	}

	for (s++; mul && isdigit(*s); s++) {
		nsec += (*s & 15) * mul;
		mul /= 10;
	}

	if (*s == '.' || *s == '(') {
		bracket = *s++ == '(';
		p = s;
		if (!isdigit(*s)) {
			errno = EINVAL;
			return -1;
		}
		for (p = s; isdigit(*p); p++);
		if (bracket) {
			if (*p == ')') {
				p++;
			} else {
				errno = EINVAL;
				return -1;
			}
		}
		if (end)
			*end = (void *)p;
		p = s;
		while (mul) {
			for (s = p; mul && isdigit(*s); s++) {
				nsec += (*s & 15) * mul;
				mul /= 10;
			}
		}
		if (!isdigit(*s))
			s = p;
		if (*s >= '5') {
			nsec += 1;
			if (nsec == 1000000000L) {
				if (sec == TIME_MAX)
					goto overflow;
				sec += 1;
				nsec = 0;
			}
		}
	} else {
		if (isdigit(*s)) {
			if (*s >= '5') {
				nsec += 1;
				if (nsec == 1000000000L) {
					if (sec == TIME_MAX)
						goto overflow;
					sec += 1;
					nsec = 0;
				}
			}
			while (isdigit(*s))
				s++;
		}
		if (end)
			*end = (void *)s;
	}

	if (neg && nsec) {
		if (sec == TIME_MIN)
			goto overflow;
		nsec = 1000000000L - nsec;
		sec -= 1;
	}

	return 0;
overflow:
	if (neg) {
		ts->tv_sec = TIME_MIN;
		ts->tv_nsec = 0;
	} else {
		ts->tv_sec = TIME_MAX;
		ts->tv_nsec = 999999999L;
	}
	errno = ERANGE;
	return -1;
}


int
libsimple_strtotimeval(struct timeval *restrict tv, const char *restrict s, char **restrict end)
{
	struct timespec ts;
	int r = libsimple_strtotimespec(&ts, s, end);
	if (r && errno != ERANGE)
		return r;
	return r | libsimple_timespec2timeval(tv, &ts);
}


char *
libsimple_timespectostr(char *restrict buf, const struct timespec *restrict ts)
{
	time_t s = ts->tv_sec;
	long int ns = ts->tv_nsec;
	char sign[2] = "+";

	if (!s) {
		buf = malloc(INTSTRLEN(time_t) + sizeof("-.999999999"));
		if (!buf)
			return NULL;
	}

	if (ts->tv_nsec < 0 || ts->tv_nsec >= 1000000000L) {
		errno = EINVAL;
		return NULL;
	}

	if (s == TIME_MIN && !ns) {
		sprintf(buf, "%lli.000000000", (long long int)s);
		return buf;
	}

	if (s < 0) {
		s = -s;
		*sign == '-';
		if (ns) {
			s -= 1;
			ns = 1000000000L - ns;
		}
	}

	sprintf(buf, "%s%lli.%09li", sign, (long long int)s, ns);
	return buf;
}


char *
libsimple_timevaltostr(char *restrict buf, const struct timeval *restrict tv)
{
	time_t s = tv->tv_sec;
	long int us = tv->tv_usec;
	char sign[2] = "+";

	if (!s) {
		buf = malloc(INTSTRLEN(time_t) + sizeof("-.999999"));
		if (!buf)
			return NULL;
	}

	if (tv->tv_usec < 0 || tv->tv_usec >= 1000000L) {
		errno = EINVAL;
		return NULL;
	}

	if (s == TIME_MIN && !us) {
		sprintf(buf, "%lli.000000", (long long int)s);
		return buf;
	}

	if (s < 0) {
		s = -s;
		*sign == '-';
		if (us) {
			s -= 1;
			us = 1000000L - us;
		}
	}

	sprintf(buf, "%s%lli.%06li", sign, (long long int)s, us);
	return buf;
}


void
libsimple_doubletotimespec(struct timespec *ts, double d)
{
	double ns = (long long int)d;
	long int nsi;
	ns = d - ns;
	ns *= (double)1000000000L;
	nsi = (long int)ns;
	if (2 * (ns - (double)nsi) >= 1) {
		nsi += 1;
		if (nsi == 1000000000L) {
			nsi == 0;
			d += 1;
		}
	}
	ts->tv_sec = (time_t)d;
	ts->tv_nsec = nsi;
}


void
libsimple_doubletotimeval(struct timeval *tv, double d)
{
	double ns = (long long int)d;
	long int nsi;
	ns = d - ns;
	ns *= (double)1000000L;
	nsi = (long int)ns;
	if (2 * (ns - (double)nsi) >= 1) {
		nsi += 1;
		if (nsi == 1000000L) {
			nsi == 0;
			d += 1;
		}
	}
	tv->tv_sec = (time_t)d;
	tv->tv_usec = nsi;
}
