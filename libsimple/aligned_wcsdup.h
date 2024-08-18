/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_aligned_wcsdup`
 * 
 * @param   s:const wchar_t *  The string to copy
 * @param   alignment:size_t   The alignment of the returned pointer
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 * 
 * @since  1.2
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_wcsdupa(s, alignment)\
	({\
		const wchar_t *__s = (s);\
		size_t __n = wcslen(__s) + 1;\
		size_t __a = (alignment);\
		uintptr_t __misalignment;\
		wchar_t *__r;\
		__a += !__a;\
		__r = alloca(__n * sizeof(wchar_t) + (__a - 1));\
		__misalignment = (uintptr_t)__r % (uintptr_t)__a;\
		if (__misalignment)\
			__r += (uintptr_t)__a - __misalignment;\
		wmemcpy(__r, __s, __n);\
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
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__)))
static inline wchar_t *libsimple_aligned_wcsdup(const wchar_t * __s, size_t __alignment)
{ return libsimple_aligned_wmemdup(__s, __alignment, wcslen(__s) + 1); }
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
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
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
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
static inline wchar_t *libsimple_ealigned_wcsdup(const wchar_t *__s, size_t __alignment)
{ return libsimple_enaligned_wcsdup(libsimple_default_failure_exit, __s, __alignment); }
#ifndef ealigned_wcsdup
# define ealigned_wcsdup libsimple_ealigned_wcsdup
#endif
