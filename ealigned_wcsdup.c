/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline wchar_t *libsimple_ealigned_wcsdup(const wchar_t *, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *s;

	assert((s = libsimple_ealigned_wcsdup(L"test", 8)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 5 * sizeof(wchar_t) + (8 - 5 * sizeof(wchar_t) % 8) % 8);
		assert(info->alignment == 8);
		assert(!info->zeroed);
	}
	assert(!wmemcmp(s, L"test", 5));
	free(s);

	if (have_custom_malloc()) {
		libsimple_default_failure_exit = 55;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ealigned_wcsdup(L"test", 8));
		assert(exit_status == 55);
		assert_stderr("%s: aligned_wcsdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
