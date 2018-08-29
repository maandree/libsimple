/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#include "test.h"
#include <sys/syscall.h>
#include <malloc.h>

#undef strndup
#undef memdup


char *argv0 = (char []){"<test>"};

volatile size_t alloc_fail_in = 0;
volatile int exit_real = 0;
volatile int exit_ok = 0;
volatile int exit_status;
jmp_buf exit_jmp;
volatile char stderr_buf[8 << 10];
volatile size_t stderr_n = 0;
volatile int stderr_real = 0;
volatile int stderr_ok = 0;

static volatile int custom_malloc = 0;


size_t
get_pagesize(void)
{
	long r;
	assert((r = sysconf(_SC_PAGESIZE)) >= 0);
	return (size_t)r;
}


size_t
round_up(size_t size)
{
	size_t ps = get_pagesize();
	return size + (ps - size % ps) % ps;
}


int
have_custom_malloc(void)
{
	free(malloc(1));
	return custom_malloc;
}


struct allocinfo *
get_allocinfo(void *ptr)
{
	assert(ptr);
	return (void *)((char *)ptr - sizeof(struct allocinfo));
}


void *
malloc(size_t size)
{
	size_t alignment = get_pagesize();
	while (alignment < sizeof(long long int))
		alignment *= 2;
	while (alignment < sizeof(long double))
		alignment *= 2;
	return memalign(alignment, size);
}


void *
calloc(size_t nelem, size_t elsize)
{
	struct allocinfo *info;
	void *volatile ret;
	assert(nelem && elsize); /* unspecified behaviour otherwise */
	if (nelem > SIZE_MAX / elsize) {
		errno = ENOMEM;
		return NULL;
	}
	ret = malloc(nelem * elsize);
	if (!ret)
		return NULL;
	memset(ret, 0, nelem * elsize);
	info = get_allocinfo(ret);
	info->zeroed = nelem * elsize;
	return ret;
}


void *
realloc(void *ptr, size_t size)
{
	struct allocinfo *info;
	void *volatile ret;
	size_t n;
	assert(size); /* unspecified behaviour otherwise */
	if (!ptr)
		return malloc(size);
	ret = malloc(size);
	if (!ret)
		return malloc;
	info = get_allocinfo(ret);
	n = MIN(size, info->size);
	info->zeroed = MIN(n, info->zeroed);
	memcpy(ret, ptr, n);
	free(ptr);
	return ret;
}


void *
memalign(size_t alignment, size_t size)
{
	struct allocinfo *info;
	void *volatile ptr;
	size_t n;
	uintptr_t off;

	custom_malloc = 1;

	assert(alignment);
	assert(!(alignment & (alignment - 1UL)));
	assert(size); /* unspecified behaviour otherwise */

	if (alloc_fail_in && alloc_fail_in-- == 1)
		goto enomem;

	n = size;
	if (n > SIZE_MAX - alignment)
		goto enomem;
	n += alignment;
	if (n > SIZE_MAX - sizeof(struct allocinfo))
		goto enomem;
	n += sizeof(struct allocinfo);

	ptr = mmap(NULL, n, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (!ptr)
		goto enomem;

	off = (uintptr_t)ptr;
	off += sizeof(struct allocinfo);
	off += (alignment - off % alignment) % alignment;
	off -= (uintptr_t)ptr;

	ptr = (char *)ptr + off;
	info = get_allocinfo(ptr);

	info->real_beginning = (char *)ptr - off;
	info->real_size      = n;
	info->size           = size;
	info->extent         = n - size - off;
	info->alignment      = alignment;
	info->zeroed         = 0;
	info->refcount       = 1;

	return ptr;

enomem:
	errno = ENOMEM;
	return NULL;
}


int
posix_memalign(void **memptr, size_t alignment, size_t size)
{
	int ret, saved_errno = errno;
	void *volatile *volatile ptrp = memptr;
	assert(!(alignment % sizeof(void *)));
	assert(ptrp);
	*memptr = memalign(alignment, size);
	ret = *memptr ? ENOMEM : 0;
	errno = saved_errno;
	return ret;
}


void *
aligned_alloc(size_t alignment, size_t size)
{
	assert(alignment);
	assert(!(size % alignment));
	return memalign(alignment, size);
}


void *
valloc(size_t size)
{
	return memalign(get_pagesize(), size);
}


void *
pvalloc(size_t size)
{
	return memalign(get_pagesize(), round_up(size));
}


char *
strdup(const char *s)
{
	char *r = malloc(strlen(s) + 1);
	return r ? strcpy(r, s) : r;
}


char *
strndup(const char *s, size_t size)
{
	return libsimple_strndup(s, size);
}


void *
memdup(const void *s, size_t size)
{
	return libsimple_memdup(s, size);
}


void
free(void *ptr)
{
	struct allocinfo *info;
	if (!ptr)
		return;
	info = get_allocinfo(ptr);
	assert(info->refcount);
	if (info->refcount-- > 1)
		return;
	assert(!munmap(info->real_beginning, info->real_size));
}


void
exit(int status)
{
	exit_status = status;
	if (exit_real) {
#ifdef SYS_exit_group
		syscall(SYS_exit_group, status);
#else
		syscall(SYS_exit, status);
#endif
	}
	assert(exit_ok);
	longjmp(exit_jmp, 1);
}


int
fprintf(FILE *restrict stream, const char *restrict format, ...)
{
	va_list ap;
	va_start(ap, format);
	return vfprintf(stream, format, ap);
	va_end(ap);
}


int
vfprintf(FILE *restrict stream, const char *restrict format, va_list ap)
{
	size_t old_alloc_fail_in = alloc_fail_in;
	va_list ap2;
	int r;
	char *buf;
	size_t n;

	va_copy(ap2, ap);
	r = vsnprintf(NULL, 0, format, ap2);
	va_end(ap2);

	if (r >= 0) {
		n = (size_t)r;
		alloc_fail_in = 0;
		assert((buf = malloc(n + 1)));
		n = vsnprintf(buf, n + 1, format, ap);
		if (fileno(stream) != STDERR_FILENO || stderr_real) {
			fwrite(buf, 1, n, stream);
		} else {
			assert(stderr_ok);
			assert(stderr_n + n <= sizeof(stderr_buf));
			memcpy((char *)(void *)(&stderr_buf[stderr_n]), buf, n);
			stderr_n += n;
		}
		free(buf);
	}

	alloc_fail_in = old_alloc_fail_in;
	return r;
}
