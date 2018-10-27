/* See LICENSE file for copyright and license details. */

#if defined(__GNUC__) || defined(__clang__)
# define libsimple_strndupa(s, n)\
	({\
		const char *__s = (s);\
		size_t __n = strnlen(__s, n);\
		char *__r;\
		__r = alloca(__n + 1);\
		memcpy(__r, __s, __n);\
		__r[__n] = '\0';\
		__r;\
	})
# ifndef strndupa
#  define strndupa(s, n) libsimple_strndupa(s, n)
# endif
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __assume_aligned__(1), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
char *libsimple_enstrndup(int, const char *, size_t);
#ifndef enstrndup
# define enstrndup libsimple_enstrndup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __assume_aligned__(1), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
static inline char *libsimple_estrndup(const char *__s, size_t __n)
{ return enstrndup(libsimple_default_failure_exit, __s, __n); }
#ifndef estrndup
# define estrndup libsimple_estrndup
#endif
