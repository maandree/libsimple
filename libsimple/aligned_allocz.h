/* See LICENSE file for copyright and license details. */

/*
 * Alignment must be a power of 2.
 * Allocation size must be a mutiple of the alignment.
 */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__)))
void *libsimple_valigned_alloczn(int, size_t, size_t, va_list);
#ifndef valigned_alloczn
# define valigned_alloczn libsimple_valigned_alloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__)))
static inline void *
libsimple_aligned_allocz(int __clear, size_t __alignment, size_t __n)
{
	void *__ret = aligned_alloc(__alignment, __n);
	if (__ret && __clear)
		memset(__ret, 0, __n);
	return __ret;
}
#ifndef aligned_allocz
# define aligned_allocz libsimple_aligned_allocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_aligned_alloczn(int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_valigned_alloczn(__clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef aligned_alloczn
# define aligned_alloczn libsimple_aligned_alloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enaligned_allocz(int, int, size_t, size_t);
#ifndef enaligned_allocz
# define enaligned_allocz libsimple_enaligned_allocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_envaligned_alloczn(int, int, size_t, size_t, va_list);
#ifndef envaligned_alloczn
# define envaligned_alloczn libsimple_envaligned_alloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enaligned_alloczn(int __status, int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envaligned_alloczn(__status, __clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef enaligned_alloczn
# define enaligned_alloczn libsimple_enaligned_alloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ealigned_allocz(int __clear, size_t __alignment, size_t __n)
{ return libsimple_enaligned_allocz(libsimple_default_failure_exit, __clear, __alignment, __n); }
#ifndef ealigned_allocz
# define ealigned_allocz libsimple_ealigned_allocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evaligned_alloczn(int __clear, size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envaligned_alloczn(libsimple_default_failure_exit, __clear, __alignment, __n, __ap); }
#ifndef evaligned_alloczn
# define evaligned_alloczn libsimple_evaligned_alloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ealigned_alloczn(int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evaligned_alloczn(__clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef ealigned_alloczn
# define ealigned_alloczn libsimple_ealigned_alloczn
#endif
