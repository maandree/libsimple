/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_aligned_wmemdup`
 * 
 * @param   s:const wchar_t *  The wide characters to copy
 * @param   alignment:size_t   The alignment of the returned pointer
 * @param   n:size_t           The number of wide characters to copy
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 * 
 * @since  1.2
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_wmemdupa(s, alignment, n)\
	({\
		const wchar_t *__s = (s);\
		size_t __n = (n);\
		size_t __a = (alignment);\
		size_t __size;\
		uintptr_t __misalignment;\
		wchar_t *__r;\
		__a += !__a;\
		__size = __n * sizeof(wchar_t) + (__a - 1);\
		__r = alloca(__size + !__size);\
		__misalignment = (uintptr_t)__r % (uintptr_t)__a;\
		if (__misalignment)\
			__r += (uintptr_t)__a - __misalignment;\
		wmemcpy(__r, __s, __n);\
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
 * 
 * @since  1.2
 */	
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
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
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline wchar_t *libsimple_ealigned_wmemdup(const wchar_t *__s, size_t __alignment, size_t __n)
{ return libsimple_enaligned_wmemdup(libsimple_default_failure_exit, __s, __alignment, __n); }
#ifndef ealigned_wmemdup
# define ealigned_wmemdup libsimple_ealigned_wmemdup
#endif
