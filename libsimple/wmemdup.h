/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_wmemdup`
 * 
 * @param   s:const wchar_t *  The wide characters to copy
 * @param   n:size_t           The number of wide characters to copy
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_wmemdupa(s, n)\
	({\
		const wchar_t *__s = (s);\
		size_t __n = (n);\
		wchar_t *__r = alloca(__n * sizeof(wchar_t) + !__n);\
		wmemcpy(__r, __s, __n);\
	})
# ifndef wmemdupa
#  define wmemdupa(s, n) libsimple_wmemdupa(s, n)
# endif
#endif


/**
 * Create a new allocation and copy wide characters into it
 * 
 * @param   s  The wide characters to copy
 * @param   n  The number of wide characters to copy
 * @return     Duplicate of `s`, `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, _libsimple_assume_aligned_as(wchar_t), __alloc_size__(2), __warn_unused_result__)))
wchar_t *libsimple_wmemdup(const wchar_t *, size_t);
#ifndef wmemdup
# define wmemdup libsimple_wmemdup
#endif


/**
 * Version of `libsimple_wmemdup` that calls `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @param   s       The wide characters to copy
 * @param   n       The number of wide characters to copy
 * @return          Duplicate of `s`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, _libsimple_assume_aligned_as(wchar_t), __alloc_size__(3),
                                   __warn_unused_result__, __returns_nonnull__)))
wchar_t *libsimple_enwmemdup(int, const wchar_t *, size_t);
#ifndef enwmemdup
# define enwmemdup libsimple_enwmemdup
#endif


/**
 * Version of `libsimple_wmemdup` that calls `libsimple_eprintf` on error
 * 
 * @param   s  The wide characters to copy
 * @param   n  The number of wide characters to copy
 * @return     Duplicate of `s`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, _libsimple_assume_aligned_as(wchar_t), __alloc_size__(2),
                                   __warn_unused_result__, __returns_nonnull__)))
inline wchar_t *
libsimple_ewmemdup(const wchar_t *__s, size_t __n)
{
	return libsimple_enwmemdup(libsimple_default_failure_exit, __s, __n);
}
#ifndef ewmemdup
# define ewmemdup libsimple_ewmemdup
#endif
