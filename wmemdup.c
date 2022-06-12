/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


wchar_t *
libsimple_wmemdup(const wchar_t *s, size_t n)
{
	wchar_t *ret;
	size_t size;
	if (LIBSIMPLE_UMUL_OVERFLOW_NONZERO(n + !n, sizeof(wchar_t), &size, SIZE_MAX)) {
		errno = ENOMEM;
		return NULL;
	}
	ret = aligned_alloc(_Alignof(wchar_t), size);
	if (!ret)
		return NULL;
	return wmemcpy(ret, s, n);
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	const wchar_t *s = L"test";
	wchar_t *p;

	p = libsimple_wmemdup(s, 5);
	assert(p);
	assert(p != s);
	assert(!((uintptr_t)s % _Alignof(wchar_t)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(p)));
		assert(info->size == 5 * sizeof(wchar_t));
		assert(info->alignment == _Alignof(wchar_t));
	}
	assert(!wmemcmp(p, s, 5));
	wmemset(p, 0, 5);
	assert(!wmemcmp(s, L"test", 5));
	free(p);

	errno = 0;
	assert(!libsimple_wmemdup(NULL, SSIZE_MAX) && errno == ENOMEM);

	return 0;
}

#endif
