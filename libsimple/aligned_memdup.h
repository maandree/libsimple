/* See LICENSE file for copyright and license details. */


/**
 * Stack allocation version of `libsimple_aligned_memdup`
 * 
 * @param   s:const void *    The bytes to copy
 * @param   alignment:size_t  The alignment of the returned pointer
 * @param   n:size_t          The number of bytes to copy
 * @return  :void *           Duplicate of `s` with automatic storage
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_memdupa(s, alignment, n)\
	LIBSIMPLE_EXTENSION__\
	({\
		const char *s__ = (s);\
		size_t n__ = (n);\
		size_t a__ = (alignment);\
		size_t size__;\
		uintptr_t misalignment__;\
		char *r__;\
		a__ += !a__;\
		size__ = n__ + (a__ - 1);\
		r__ = alloca(size__ + !size__);\
		misalignment__ = (uintptr_t)r__ % (uintptr_t)a__;\
		if (misalignment__)\
			r__ += (uintptr_t)a__ - misalignment__;\
		memcpy(r__, s__, n__);\
	})
# ifndef aligned_memdupa
#  define aligned_memdupa(s, alignment, n) libsimple_aligned_memdupa(s, alignment, n)
# endif
#endif


/**
 * Create a new allocation, with custom alignment, and copy bytes into it
 * 
 * @param   s          The bytes to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The number of bytes to copy
 * @return             Duplicate of `s`, `NULL` on failure
 */	
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __alloc_size__(3), __nonnull__, __warn_unused_result__)))
void *libsimple_aligned_memdup(const void *, size_t, size_t);
#ifndef aligned_memdup
# define aligned_memdup libsimple_aligned_memdup
#endif


/**
 * Version of `libsimple_aligned_memdup` that calls `libsimple_enprintf` on error
 * 
 * @param   status     Exit value in case of failure
 * @param   s          The bytes to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The number of bytes to copy
 * @return             Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enaligned_memdup(int, const void *, size_t, size_t);
#ifndef enaligned_memdup
# define enaligned_memdup libsimple_enaligned_memdup
#endif


/**
 * Version of `libsimple_aligned_memdup` that calls `libsimple_eprintf` on error
 * 
 * @param   s          The bytes to copy
 * @param   alignment  The alignment of the returned pointer
 * @param   n          The number of bytes to copy
 * @return             Duplicate of `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ealigned_memdup(const void *s__, size_t alignment__, size_t n__)
{
	return libsimple_enaligned_memdup(libsimple_default_failure_exit, s__, alignment__, n__);
}
#ifndef ealigned_memdup
# define ealigned_memdup libsimple_ealigned_memdup
#endif
