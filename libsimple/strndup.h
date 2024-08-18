/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of strndup(3)
 * 
 * @param   s:const char *  The string to copy
 * @param   n:size_t        The maximum number of bytes to copy
 * @return  :char *         Duplicate of `s` with automatic storage
 * 
 * @since  1.0
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_strndupa(s, n)\
	LIBSIMPLE_EXTENSION__\
	({\
		const char *s__ = (s);\
		size_t n__ = strnlen(s__, n);\
		char *r__;\
		r__ = alloca(n__ + 1);\
		memcpy(r__, s__, n__);\
		r__[n__] = '\0';\
		r__;\
	})
# ifndef strndupa
#  define strndupa(s, n) libsimple_strndupa(s, n)
# endif
#endif


/**
 * Version of strndup(3) that calls `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @param   s       The string to copy
 * @param   n       The maximum number of bytes to copy
 * @return          Duplicate of `s`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
char *libsimple_enstrndup(int, const char *, size_t);
#ifndef enstrndup
# define enstrndup libsimple_enstrndup
#endif


/**
 * Version of strndup(3) that calls `libsimple_eprintf` on error
 * 
 * @param   s  The string to copy
 * @param   n  The maximum number of bytes to copy
 * @return     Duplicate of `s`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
inline char *
libsimple_estrndup(const char *s__, size_t n__)
{
	return libsimple_enstrndup(libsimple_default_failure_exit, s__, n__);
}
#ifndef estrndup
# define estrndup libsimple_estrndup
#endif
