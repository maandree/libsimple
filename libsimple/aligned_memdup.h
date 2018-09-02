/* See LICENSE file for copyright and license details. */

#if defined(__GNUC__) || defined(__clang__)
# define libsimple_aligned_memdupa(s, alignment, n)\
	({\
		const char *__s = (s);\
		size_t __n = (n);\
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
# ifndef aligned_memdupa
#  define aligned_memdupa(s, alignment, n) libsimple_aligned_memdupa(s, alignment, n)
# endif
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __alloc_size__(3), __nonnull__, __warn_unused_result__)))
void *libsimple_aligned_memdup(const void *, size_t, size_t);
#ifndef aligned_memdup
# define aligned_memdup libsimple_aligned_memdup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enaligned_memdup(int, const void *, size_t, size_t);
#ifndef enaligned_memdup
# define enaligned_memdup libsimple_enaligned_memdup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ealigned_memdup(const void *__s, size_t __alignment, size_t __n)
{ return enaligned_memdup(libsimple_default_failure_exit, __s, __alignment, __n); }
#ifndef ealigned_memdup
# define ealigned_memdup libsimple_ealigned_memdup
#endif
