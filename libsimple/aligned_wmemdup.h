/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_aligned_wmemdup`
 * 
 * @param   s:const wchar_t *  The wide characters to copy
 * @param   alignment:size_t   The alignment of the returned pointer
 * @param   n:size_t           The number of wide characters to copy
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_wmemdupa(s, alignment, n)\
	LIBSIMPLE_EXTENSION__\
	({\
		const wchar_t *s__ = (s);\
		size_t n__ = (n);\
		size_t a__ = (alignment);\
		size_t size__;\
		uintptr_t misalignment__;\
		wchar_t *r__;\
		a__ += !a__;\
		size__ = n__ * sizeof(wchar_t) + (a__ - 1);\
		r__ = alloca(size__ + !size__);\
		misalignment__ = (uintptr_t)r__ % (uintptr_t)a__;\
		if (misalignment__)\
			r__ += (uintptr_t)a__ - misalignment__;\
		wmemcpy(r__, s__, n__);\
	})
# ifndef aligned_wmemdupa
#  define aligned_wmemdupa(s, alignment, n) libsimple_aligned_wmemdupa(s, alignment, n)
# endif
#endif


/**
 * Create a new allocation, with custom alignment, and copy wide characters into it
 * 
 * @param   s          The wide characters to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The number of wide characters to copy
 * @return             Duplicate of `s`, `NULL` on failure
 */	
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __nonnull__, __warn_unused_result__)))
wchar_t *libsimple_aligned_wmemdup(const wchar_t *, size_t, size_t);
#ifndef aligned_wmemdup
# define aligned_wmemdup libsimple_aligned_wmemdup
#endif


/**
 * Version of `libsimple_aligned_wmemdup` that calls `libsimple_enprintf` on error
 * 
 * @param   status     Exit value in case of failure
 * @param   s          The wide characters to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The number of wide characters to copy
 * @return             Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
wchar_t *libsimple_enaligned_wmemdup(int, const wchar_t *, size_t, size_t);
#ifndef enaligned_wmemdup
# define enaligned_wmemdup libsimple_enaligned_wmemdup
#endif


/**
 * Version of `libsimple_aligned_wmemdup` that calls `libsimple_eprintf` on error
 * 
 * @param   s          The wide characters to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The number of wide characters to copy
 * @return             Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
inline wchar_t *
libsimple_ealigned_wmemdup(const wchar_t *s__, size_t alignment__, size_t n__)
{
	return libsimple_enaligned_wmemdup(libsimple_default_failure_exit, s__, alignment__, n__);
}
#ifndef ealigned_wmemdup
# define ealigned_wmemdup libsimple_ealigned_wmemdup
#endif
