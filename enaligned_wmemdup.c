/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


wchar_t *
libsimple_enaligned_wmemdup(int status, const wchar_t *s, size_t alignment, size_t n)
{
	void *ret = aligned_wmemdup(s, alignment, n);
	if (!ret)
		enprintf(status, "aligned_wmemdup:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *s;

	assert((s = libsimple_enaligned_wmemdup(1, L"hello", 2, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 5 * sizeof(wchar_t));
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!wmemcmp(s, L"hello", 5));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_wmemdup(44, L"hello", 2, 2));
		assert(exit_status == 44);
		assert_stderr("%s: aligned_wmemdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
