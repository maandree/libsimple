/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#include "test.h"
#include <malloc.h>

#undef strndup
#undef memdup


size_t alloc_fail_in = 0;

static int custom_malloc = 0;


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
	void *ret;
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
	void *ret;
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
	void *ptr;
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
	void **volatile ptrp = memptr;
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
