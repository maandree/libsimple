/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_memdup`
 * 
 * @param   s:const void *  The bytes to copy
 * @param   n:size_t        The number of bytes to copy
 * @return  :void *         Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_memdupa(s, n)\
	LIBSIMPLE_EXTENSION__\
	({\
		const char *s__ = (s);\
		size_t n__ = (n);\
		char *r__ = alloca(n__ + !n__);\
		memcpy(r__, s__, n__);\
	})
# ifndef memdupa
#  define memdupa(s, n) libsimple_memdupa(s, n)
# endif
#endif


/**
 * Create a new allocation and copy bytes into it
 * 
 * @param   s  The bytes to copy
 * @param   n  The number of bytes to copy
 * @return     Duplicate of `s`, `NULL` on failure
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(2), __nonnull__, __warn_unused_result__)))
void *libsimple_memdup(const void *, size_t);
#ifndef memdup
# define memdup libsimple_memdup
#endif


/**
 * Version of `libsimple_memdup` that calls `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @param   s       The bytes to copy
 * @param   n       The number of bytes to copy
 * @return          Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmemdup(int, const void *, size_t);
#ifndef enmemdup
# define enmemdup libsimple_enmemdup
#endif


/**
 * Version of `libsimple_memdup` that calls `libsimple_eprintf` on error
 * 
 * @param   s  The bytes to copy
 * @param   n  The number of bytes to copy
 * @return     Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ememdup(const void *s__, size_t n__)
{
	return libsimple_enmemdup(libsimple_default_failure_exit, s__, n__);
}
#ifndef ememdup
# define ememdup libsimple_ememdup
#endif
