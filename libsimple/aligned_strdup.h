/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_aligned_strdup`
 * 
 * @param   s:const char *    The string to copy
 * @param   alignment:size_t  The alignment of the returned pointer
 * @return  :char *           Duplicate of `s` with automatic storage
 * 
 * @since  1.2
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_strdupa(s, alignment)\
	({\
		const char *__s = (s);\
		size_t __n = strlen(__s) + 1;\
		size_t __a = (alignment);\
		uintptr_t __misalignment;\
		char *__r;\
		__a += !__a;\
		__r = alloca(__n + (__a - 1));\
		__misalignment = (uintptr_t)__r % (uintptr_t)__a;\
		if (__misalignment)\
			__r += (uintptr_t)__a - __misalignment;\
		memcpy(__r, __s, __n);\
	})
# ifndef aligned_strdupa
#  define aligned_strdupa(s, alignment) libsimple_aligned_strdupa(s, alignment)
# endif
#endif


/**
 * Version of strdup(3) that returns a pointer with a custom alignment
 * 
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @return             Duplicate of `s`, `NULL` on failure
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__)))
static inline char *libsimple_aligned_strdup(const char * __s, size_t __alignment)
{ return libsimple_aligned_memdup(__s, __alignment, strlen(__s) + 1); }
#ifndef aligned_strdup
# define aligned_strdup libsimple_aligned_strdup
#endif


/**
 * Version of `libsimple_aligned_strdup` that calls `libsimple_enprintf` on error
 * 
 * @param   status     Exit value in case of failure
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @return             Duplicate of `s`
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
char *libsimple_enaligned_strdup(int, const char *, size_t);
#ifndef enaligned_strdup
# define enaligned_strdup libsimple_enaligned_strdup
#endif


/**
 * Version of `libsimple_aligned_strdup` that calls `libsimple_eprintf` on error
 * 
 * @param   s          The string to copy
 * @param   alignment  The alignment of the returned pointer
 * @return             Duplicate of `s`
 * 
 * @since  1.2
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
static inline char *libsimple_ealigned_strdup(const char *__s, size_t __alignment)
{ return libsimple_enaligned_strdup(libsimple_default_failure_exit, __s, __alignment); }
#ifndef ealigned_strdup
# define ealigned_strdup libsimple_ealigned_strdup
#endif
