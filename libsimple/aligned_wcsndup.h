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
	LIBSIMPLE_GCC_ONLY__(__extension__)\
	({\
		const wchar_t *s__ = (s);\
		size_t n__ = wcsnlen(s__, n);\
		size_t a__ = (alignment);\
		uintptr_t misalignment__;\
		wchar_t *r__;\
		a__ += !a__;\
		r__ = alloca((n__ + 1) * sizeof(wchar_t) + (a__ - 1));\
		misalignment__ = (uintptr_t)r__ % (uintptr_t)a__;\
		if (misalignment__)\
			r__ += (uintptr_t)a__ - misalignment__;\
		wmemcpy(r__, s__, n__);\
		r__[n__] = 0;\
		r__;\
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__)))
wchar_t *libsimple_aligned_wcsndup(const wchar_t * s__, size_t alignment__, size_t n__);
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(3), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
inline wchar_t *
libsimple_ealigned_wcsndup(const wchar_t *s__, size_t alignment__, size_t n__)
{
	return libsimple_enaligned_wcsndup(libsimple_default_failure_exit, s__, alignment__, n__);
}
#ifndef ealigned_wcsndup
# define ealigned_wcsndup libsimple_ealigned_wcsndup
#endif
