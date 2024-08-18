/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_aligned_wcsndup`
 * 
 * @param   s:const wchar_t *  The string to copy
 * @param   alignment:size_t   The alignment of the returned pointer
 * @param   n:size_t           The maximum number of wide characters to copy
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_wcsndupa(s, alignment, n)\
	({\
		const wchar_t *__s = (s);\
		size_t __n = wcsnlen(__s, n);\
		size_t __a = (alignment);\
		uintptr_t __misalignment;\
		wchar_t *__r;\
		__a += !__a;\
		__r = alloca((__n + 1) * sizeof(wchar_t) + (__a - 1));\
		__misalignment = (uintptr_t)__r % (uintptr_t)__a;\
		if (__misalignment)\
			__r += (uintptr_t)__a - __misalignment;\
		wmemcpy(__r, __s, __n);\
		__r[__n] = 0;\
		__r;\
	})
# ifndef aligned_wcsndupa
#  define aligned_wcsndupa(s, alignment, n) libsimple_aligned_wcsndupa(s, alignment, n)
# endif
#endif


/**
 * Version of wcsndup(3) that returns a pointer with a custom alignment
 * 
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The maximum number of wide characters to copy
 * @return             Duplicate of `s`, `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__)))
wchar_t *libsimple_aligned_wcsndup(const wchar_t * __s, size_t __alignment, size_t __n);
#ifndef aligned_wcsndup
# define aligned_wcsndup libsimple_aligned_wcsndup
#endif


/**
 * Version of `libsimple_aligned_wcsndup` that calls `libsimple_enprintf` on error
 * 
 * @param   status     Exit value in case of failure
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The maximum number of wide characters to copy
 * @return             Duplicate of `s`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
wchar_t *libsimple_enaligned_wcsndup(int, const wchar_t *, size_t, size_t);
#ifndef enaligned_wcsndup
# define enaligned_wcsndup libsimple_enaligned_wcsndup
#endif


/**
 * Version of `libsimple_aligned_wcsndup` that calls `libsimple_eprintf` on error
 * 
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The maximum number of wide characters to copy
 * @return             Duplicate of `s`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
static inline wchar_t *libsimple_ealigned_wcsndup(const wchar_t *__s, size_t __alignment, size_t __n)
{ return libsimple_enaligned_wcsndup(libsimple_default_failure_exit, __s, __alignment, __n); }
#ifndef ealigned_wcsndup
# define ealigned_wcsndup libsimple_ealigned_wcsndup
#endif
