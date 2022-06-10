/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline wchar_t *libsimple_ewcsdup(const wchar_t *);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	wchar_t *s;

	assert((s = libsimple_ewcsdup(L"test")));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 5 * sizeof(wchar_t));
		assert(info->alignment == _Alignof(wchar_t));
		assert(!info->zeroed);
	}
	assert(!wcscmp(s, L"test"));
	free(s);

	if (have_custom_malloc()) {
		libsimple_default_failure_exit = 5;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ewcsdup(L"test"));
		assert(exit_status == 5);
		assert_stderr("%s: wcsdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
