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


/**
 * Create a new allocation and copy bytes into it
 * 
 * @param   s  The bytes to copy
 * @param   n  The number of bytes to copy
 * @return     Duplicate of `s`, `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2), __nonnull__, __warn_unused_result__)))
void *libsimple_memdup(const void *, size_t);
#ifndef memdup
# define memdup libsimple_memdup
#endif


/**
 * Version of `libsimple_memdup` that calles `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @param   s       The bytes to copy
 * @param   n       The number of bytes to copy
 * @return          Duplicate of `s`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmemdup(int, const void *, size_t);
#ifndef enmemdup
# define enmemdup libsimple_enmemdup
#endif


/**
 * Version of `libsimple_memdup` that calles `libsimple_eprintf` on error
 * 
 * @param   s  The bytes to copy
 * @param   n  The number of bytes to copy
 * @return     Duplicate of `s`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ememdup(const void *__s, size_t __n)
{ return enmemdup(libsimple_default_failure_exit, __s, __n); }
#ifndef ememdup
# define ememdup libsimple_ememdup
#endif
