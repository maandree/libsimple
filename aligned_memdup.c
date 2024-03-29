/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_aligned_memdup(const void *s, size_t alignment, size_t n)
{
	size_t size = n + (alignment - n % alignment) % alignment;
	void *ret;
	ret = aligned_alloc(alignment, size ? size : alignment);
	if (!ret)
		return NULL;
	return memcpy(ret, s, n);
}


#else
#include "test.h"
#undef memset

int
main(void)
{
	struct allocinfo *info;
	const char *s = "test";
	void *p = libsimple_aligned_memdup(s, 4, 5);
	assert(p);
	assert(p != s);
	assert(!((uintptr_t)p % 4));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(p)));
		assert(info->size == 8);
		assert(info->alignment == 4);
	}
	assert(!strcmpnul(p, s));
	memset(p, 0, 5);
	assert(!strcmpnul(s, "test"));
	free(p);
	return 0;
}

#endif
