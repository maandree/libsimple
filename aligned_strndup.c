/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_aligned_strndup(const char *s, size_t alignment, size_t n)
{
	char *ret;
	n = strnlen(s, n);
	ret = aligned_alloc(alignment, (n + 1) + (alignment - (n + 1) % alignment) % alignment);
	if (!ret)
		return NULL;
	memcpy(ret, s, n);
	ret[n] = '\0';
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *s;

	assert((s = libsimple_aligned_strndup("hello", 2, SIZE_MAX)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_aligned_strndup("hello", 2, 100)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_aligned_strndup("hello", 4, 6)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 8);
		assert(info->alignment == 4);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_aligned_strndup("hello", 8, 6)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 8);
		assert(info->alignment == 8);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_aligned_strndup("hello", 16, 6)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 16);
		assert(info->alignment == 16);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_aligned_strndup("hello", 2, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	assert((s = libsimple_aligned_strndup("hello", 2, 4)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hell", 5));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert(!libsimple_aligned_strndup("hello", 2, 10) && errno == ENOMEM);
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
