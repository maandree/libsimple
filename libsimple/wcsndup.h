/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_wcsndup`
 * 
 * @param   s:const wchar_t *  The string to copy
 * @param   n:size_t           The maximum number of wide characters to copy
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_wcsndupa(s, n)\
	LIBSIMPLE_GCC_ONLY__(__extension__)\
	({\
		const wchar_t *s__ = (s);\
		size_t n__ = wcsnlen(s__, n);\
		wchar_t *r__;\
		r__ = alloca((n__ + 1) * sizeof(wchar_t));\
		wmemcpy(r__, s__, n__);\
		r__[n__] = 0;\
		r__;\
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, libsimple_assume_aligned_as__(wchar_t), __nonnull__,
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, libsimple_assume_aligned_as__(wchar_t), __nonnull__,
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, libsimple_assume_aligned_as__(wchar_t),
                                   __nonnull__, __warn_unused_result__, __returns_nonnull__)))
inline wchar_t *
libsimple_ewcsndup(const wchar_t *s__, size_t n__)
{
	return libsimple_enwcsndup(libsimple_default_failure_exit, s__, n__);
}
#ifndef ewcsndup
# define ewcsndup libsimple_ewcsndup
#endif
