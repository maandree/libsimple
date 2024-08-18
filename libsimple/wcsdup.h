/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of wcsdup(3)
 * 
 * @param   s:const wchar_t *  The string to copy
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 * 
 * @since  1.2
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_wcsdupa(s)\
	LIBSIMPLE_EXTENSION__\
	({\
		const wchar_t *s__ = (s);\
		size_t n__ = wcslen(s__) + 1;\
		wchar_t *r__ = alloca(n__ * sizeof(wchar_t));\
		wmemcpy(r__, s__, n__);\
	})
# ifndef wcsdupa
#  define wcsdupa(s) libsimple_wcsdupa(s)
# endif
#endif


/**
 * Version of wcsdup(3) that calls `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @param   s       The string to copy
 * @return          Duplicate of `s`
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, libsimple_assume_aligned_as__(wchar_t), __nonnull__,
                                   __warn_unused_result__, __returns_nonnull__)))
wchar_t *libsimple_enwcsdup(int, const wchar_t *);
#ifndef enwcsdup
# define enwcsdup libsimple_enwcsdup
#endif


/**
 * Version of wcsdup(3) that calls `libsimple_eprintf` on error
 * 
 * @param   s  The string to copy
 * @return     Duplicate of `s`
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, libsimple_assume_aligned_as__(wchar_t),
                                   __nonnull__, __warn_unused_result__, __returns_nonnull__)))
inline wchar_t *
libsimple_ewcsdup(const wchar_t *s__)
{
	return enwcsdup(libsimple_default_failure_exit, s__);
}
#ifndef ewcsdup
# define ewcsdup libsimple_ewcsdup
#endif
