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
	LIBSIMPLE_EXTENSION__\
	({\
		const char *s__ = (s);\
		size_t n__ = strnlen(s__, n);\
		size_t a__ = (alignment);\
		uintptr_t misalignment__;\
		char *r__;\
		a__ += !a__;\
		r__ = alloca(n__ + 1 + (a__ - 1));\
		misalignment__ = (uintptr_t)r__ % (uintptr_t)a__;\
		if (misalignment__)\
			r__ += (uintptr_t)a__ - misalignment__;\
		memcpy(r__, s__, n__);\
		r__[n__] = '\0';\
		r__;\
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__)))
char *libsimple_aligned_strndup(const char * s__, size_t alignment__, size_t n__);
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(3), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
inline char *
libsimple_ealigned_strndup(const char *s__, size_t alignment__, size_t n__)
{
	return libsimple_enaligned_strndup(libsimple_default_failure_exit, s__, alignment__, n__);
}
#ifndef ealigned_strndup
# define ealigned_strndup libsimple_ealigned_strndup
#endif
