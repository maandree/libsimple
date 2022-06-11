/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline wchar_t *libsimple_aligned_wcsdup(const wchar_t *, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *s;

	assert((s = libsimple_aligned_wcsdup(L"test", 4)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 5 * sizeof(wchar_t) + (4 - 5 * sizeof(wchar_t) % 4) % 4);
		assert(info->alignment == 4);
		assert(!info->zeroed);
	}
	assert(!wmemcmp(s, L"test", 5));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert(!libsimple_aligned_wcsdup(L"test", 16) && errno == ENOMEM);
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
