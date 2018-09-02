/* See LICENSE file for copyright and license details. */

#if defined(__GNUC__) || defined(__clang__)
# define libsimple_strdupa(s)\
	({\
		const char *__s = (s);\
		size_t __n = strlen(__s) + 1;\
		char *__r = alloca(__n);\
		memcpy(__r, __s, __n);\
	})
# ifndef strdupa
#  define strdupa(s) libsimple_strdupa(s)
# endif
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __assume_aligned__(1), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
char *libsimple_enstrdup(int, const char *);
#ifndef enstrdup
# define enstrdup libsimple_enstrdup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __assume_aligned__(1), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
static inline char *libsimple_estrdup(const char *__s)
{ return enstrdup(libsimple_default_failure_exit, __s); }
#ifndef estrdup
# define estrdup libsimple_estrdup
#endif
