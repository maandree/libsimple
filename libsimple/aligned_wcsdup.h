/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_aligned_wcsdup`
 * 
 * @param   s:const wchar_t *  The string to copy
 * @param   alignment:size_t   The alignment of the returned pointer
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_wcsdupa(s, alignment)\
	LIBSIMPLE_GCC_ONLY__(__extension__)\
	({\
		const wchar_t *s__ = (s);\
		size_t n__ = wcslen(s__) + 1;\
		size_t a__ = (alignment);\
		uintptr_t misalignment__;\
		wchar_t *r__;\
		a__ += !a__;\
		r__ = alloca(n__ * sizeof(wchar_t) + (a__ - 1));\
		misalignment__ = (uintptr_t)r__ % (uintptr_t)a__;\
		if (misalignment__)\
			r__ += (uintptr_t)a__ - misalignment__;\
		wmemcpy(r__, s__, n__);\
	})
# ifndef aligned_wcsdupa
#  define aligned_wcsdupa(s, alignment) libsimple_aligned_wcsdupa(s, alignment)
# endif
#endif


/**
 * Version of wcsdup(3) that returns a pointer with a custom alignment
 * 
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @return             Duplicate of `s`, `NULL` on failure
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__)))
inline wchar_t *
libsimple_aligned_wcsdup(const wchar_t *s__, size_t alignment__)
{
	return libsimple_aligned_wmemdup(s__, alignment__, wcslen(s__) + 1);
}
#ifndef aligned_wcsdup
# define aligned_wcsdup libsimple_aligned_wcsdup
#endif


/**
 * Version of `libsimple_aligned_wcsdup` that calls `libsimple_enprintf` on error
 * 
 * @param   status     Exit value in case of failure
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @return             Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(3), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
wchar_t *libsimple_enaligned_wcsdup(int, const wchar_t *, size_t);
#ifndef enaligned_wcsdup
# define enaligned_wcsdup libsimple_enaligned_wcsdup
#endif


/**
 * Version of `libsimple_aligned_wcsdup` that calls `libsimple_eprintf` on error
 * 
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @return             Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
inline wchar_t *
libsimple_ealigned_wcsdup(const wchar_t *s__, size_t alignment__)
{
	return libsimple_enaligned_wcsdup(libsimple_default_failure_exit, s__, alignment__);
}
#ifndef ealigned_wcsdup
# define ealigned_wcsdup libsimple_ealigned_wcsdup
#endif
