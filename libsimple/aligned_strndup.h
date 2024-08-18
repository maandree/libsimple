/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_aligned_strndup`
 * 
 * @param   s:const char *    The string to copy
 * @param   alignment:size_t  The alignment of the returned pointer
 * @param   n:size_t          The maximum number of bytes to copy
 * @return  :char *           Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_strndupa(s, alignment, n)\
	({\
		const char *__s = (s);\
		size_t __n = strnlen(__s, n);\
		size_t __a = (alignment);\
		uintptr_t __misalignment;\
		char *__r;\
		__a += !__a;\
		__r = alloca(__n + 1 + (__a - 1));\
		__misalignment = (uintptr_t)__r % (uintptr_t)__a;\
		if (__misalignment)\
			__r += (uintptr_t)__a - __misalignment;\
		memcpy(__r, __s, __n);\
		__r[__n] = '\0';\
		__r;\
	})
# ifndef aligned_strndupa
#  define aligned_strndupa(s, alignment, n) libsimple_aligned_strndupa(s, alignment, n)
# endif
#endif


/**
 * Version of strndup(3) that returns a pointer with a custom alignment
 * 
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The maximum number of bytes to copy
 * @return             Duplicate of `s`, `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__)))
char *libsimple_aligned_strndup(const char * __s, size_t __alignment, size_t __n);
#ifndef aligned_strndup
# define aligned_strndup libsimple_aligned_strndup
#endif


/**
 * Version of `libsimple_aligned_strndup` that calls `libsimple_enprintf` on error
 * 
 * @param   status     Exit value in case of failure
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The maximum number of bytes to copy
 * @return             Duplicate of `s`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
char *libsimple_enaligned_strndup(int, const char *, size_t, size_t);
#ifndef enaligned_strndup
# define enaligned_strndup libsimple_enaligned_strndup
#endif


/**
 * Version of `libsimple_aligned_strndup` that calls `libsimple_eprintf` on error
 * 
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The maximum number of bytes to copy
 * @return             Duplicate of `s`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
static inline char *libsimple_ealigned_strndup(const char *__s, size_t __alignment, size_t __n)
{ return libsimple_enaligned_strndup(libsimple_default_failure_exit, __s, __alignment, __n); }
#ifndef ealigned_strndup
# define ealigned_strndup libsimple_ealigned_strndup
#endif
