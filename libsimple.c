/* See LICENSE file for copyright and license details. */
#include "libsimple.h"


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

	if (*end == ':') {
		suffix1 = " ";
		suffix2 = strerror(saved_errno);
		suffix3 = "\n";
	} else if (*end != '\n') {
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
