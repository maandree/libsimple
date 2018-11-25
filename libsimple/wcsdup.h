/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of wcsdup(3)
 * 
 * @param   s:const wchar_t *  The string to copy
 * @return  :wchar_t *         Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_wcsdupa(s) /* TODO test, man */\
	({\
		const wchar_t *__s = (s);\
		size_t __n = wcslen(__s) + 1;\
		wchar_t *__r = alloca(__n * sizeof(wchar_t));\
		wmemcpy(__r, __s, __n);\
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __nonnull__, __warn_unused_result__, __returns_nonnull__)))
wchar_t *libsimple_enwcsdup(int, const wchar_t *); /* TODO man */
#ifndef enwcsdup
# define enwcsdup libsimple_enwcsdup
#endif


/**
 * Version of wcsdup(3) that calls `libsimple_eprintf` on error
 * 
 * @param   s  The string to copy
 * @return     Duplicate of `s`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __nonnull__, __warn_unused_result__, __returns_nonnull__)))
static inline wchar_t *libsimple_ewcsdup(const wchar_t *__s) /* TODO man */
{ return enwcsdup(libsimple_default_failure_exit, __s); }
#ifndef ewcsdup
# define ewcsdup libsimple_ewcsdup
#endif
