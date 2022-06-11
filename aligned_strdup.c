/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline char *libsimple_aligned_strdup(const char *, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *s;

	assert((s = libsimple_aligned_strdup("test", 4)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 8);
		assert(info->alignment == 4);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "test", 5));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert(!libsimple_aligned_strdup("test", 16) && errno == ENOMEM);
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
