/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of strdup(3)
 * 
 * @param   s:const char *  The string to copy
 * @return  :char *         Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_strdupa(s)\
	LIBSIMPLE_EXTENSION__\
	({\
		const char *s__ = (s);\
		size_t n__ = strlen(s__) + 1;\
		char *r__ = alloca(n__);\
		memcpy(r__, s__, n__);\
	})
# ifndef strdupa
#  define strdupa(s) libsimple_strdupa(s)
# endif
#endif


/**
 * Version of strdup(3) that calls `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @param   s       The string to copy
 * @return          Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
char *libsimple_enstrdup(int, const char *);
#ifndef enstrdup
# define enstrdup libsimple_enstrdup
#endif


/**
 * Version of strdup(3) that calls `libsimple_eprintf` on error
 * 
 * @param   s  The string to copy
 * @return     Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
inline char *
libsimple_estrdup(const char *s__)
{
	return libsimple_enstrdup(libsimple_default_failure_exit, s__);
}
#ifndef estrdup
# define estrdup libsimple_estrdup
#endif
