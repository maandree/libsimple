/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


wchar_t *
libsimple_wcsndup(const wchar_t *s, size_t n)
{
	size_t size;
	wchar_t *ret;
	n = wcsnlen(s, n);
	size = (n + 1) * sizeof(wchar_t);
	ret = aligned_alloc(_Alignof(wchar_t), size);
	if (!ret)
		return NULL;
	wmemcpy(ret, s, n);
	ret[n] = 0;
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	const wchar_t *s = L"test";
	wchar_t *p;

	p = libsimple_wcsndup(s, SIZE_MAX);
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

	p = libsimple_wcsndup(s, 10);
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

	p = libsimple_wcsndup(s, 5);
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

	p = libsimple_wcsndup(s, 4);
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

	p = libsimple_wcsndup(s, 2);
	assert(p);
	assert(p != s);
	assert(!((uintptr_t)s % _Alignof(wchar_t)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(p)));
		assert(info->size == 3 * sizeof(wchar_t));
		assert(info->alignment == _Alignof(wchar_t));
	}
	assert(!wmemcmp(p, s, 2));
	assert(!p[2]);
	wmemset(p, 0, 3);
	assert(!wmemcmp(s, L"test", 5));
	free(p);

	return 0;
}

#endif
