/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_wcsndup`
 * 
 * @param   s:const wchar_t *  The string to copy
 * @param   n:size_t           The maximum number of wide characters to copy
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 * 
 * @since  1.2
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_wcsndupa(s, n)\
	({\
		const wchar_t *__s = (s);\
		size_t __n = wcsnlen(__s, n);\
		wchar_t *__r;\
		__r = alloca((__n + 1) * sizeof(wchar_t));\
		wmemcpy(__r, __s, __n);\
		__r[__n] = 0;\
		__r;\
	})
# ifndef wcsndupa
#  define wcsndupa(s, n) libsimple_wcsndupa(s, n)
# endif
#endif


/**
 * Create a new allocation and copy a wide-character string into it
 * 
 * @param   s  The string to copy
 * @param   n  The maximum number of wide characters to copy
 * @return     Duplicate of `s`
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, _libsimple_assume_aligned_as(wchar_t), __nonnull__,
                                   __warn_unused_result__)))
wchar_t *libsimple_wcsndup(const wchar_t *, size_t);
#ifndef wcsndup
# define wcsndup libsimple_wcsndup
#endif


/**
 * Version of `libsimple_wcsndup` that calls `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @param   s       The string to copy
 * @param   n       The maximum number of wide characters to copy
 * @return          Duplicate of `s`
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, _libsimple_assume_aligned_as(wchar_t), __nonnull__,
                                   __warn_unused_result__, __returns_nonnull__)))
wchar_t *libsimple_enwcsndup(int, const wchar_t *, size_t);
#ifndef enwcsndup
# define enwcsndup libsimple_enwcsndup
#endif


/**
 * Version of `libsimple_wcsndup` that calls `libsimple_eprintf` on error
 * 
 * @param   s  The string to copy
 * @param   n  The maximum number of wide characters to copy
 * @return     Duplicate of `s`
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, _libsimple_assume_aligned_as(wchar_t),
                                   __nonnull__, __warn_unused_result__, __returns_nonnull__)))
static inline wchar_t *libsimple_ewcsndup(const wchar_t *__s, size_t __n)
{ return libsimple_enwcsndup(libsimple_default_failure_exit, __s, __n); }
#ifndef ewcsndup
# define ewcsndup libsimple_ewcsndup
#endif
