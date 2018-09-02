/* See LICENSE file for copyright and license details. */

#if defined(__GNUC__) || defined(__clang__)
# define libsimple_memdupa(s, n)\
	({\
		const char *__s = (s);\
		size_t __n = (n);\
		char *__r = alloca(__n);\
		memcpy(__r, __s, __n);\
	})
# ifndef memdupa
#  define memdupa(s, n) libsimple_memdupa(s, n)
# endif
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2), __nonnull__, __warn_unused_result__)))
void *libsimple_memdup(const void *, size_t);
#ifndef memdup
# define memdup libsimple_memdup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmemdup(int, const void *, size_t);
#ifndef enmemdup
# define enmemdup libsimple_enmemdup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ememdup(const void *__s, size_t __n)
{ return enmemdup(libsimple_default_failure_exit, __s, __n); }
#ifndef ememdup
# define ememdup libsimple_ememdup
#endif
