/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_aligned_strdup`
 * 
 * @param   s:const char *    The string to copy
 * @param   alignment:size_t  The alignment of the returned pointer
 * @return  :char *           Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_strdupa(s, alignment)\
	LIBSIMPLE_EXTENSION__\
	({\
		const char *s__ = (s);\
		size_t n__ = strlen(s__) + 1;\
		size_t a__ = (alignment);\
		uintptr_t misalignment__;\
		char *r__;\
		a__ += !a__;\
		r__ = alloca(n__ + (a__ - 1));\
		misalignment__ = (uintptr_t)r__ % (uintptr_t)a__;\
		if (misalignment__)\
			r__ += (uintptr_t)a__ - misalignment__;\
		memcpy(r__, s__, n__);\
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__)))
inline char *
libsimple_aligned_strdup(const char *s__, size_t alignment__)
{
	return libsimple_aligned_memdup(s__, alignment__, strlen(s__) + 1);
}
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(3), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __nonnull__, __warn_unused_result__, __returns_nonnull__)))
inline char *
libsimple_ealigned_strdup(const char *s__, size_t alignment__)
{
	return libsimple_enaligned_strdup(libsimple_default_failure_exit, s__, alignment__);
}
#ifndef ealigned_strdup
# define ealigned_strdup libsimple_ealigned_strdup
#endif
