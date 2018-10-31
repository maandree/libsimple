/* See LICENSE file for copyright and license details. */

/*
 * Alignment must be a power of 2.
 * Allocation size must be a mutiple of the alignment.
 */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__)))
static inline void *libsimple_valigned_allocn(size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_valigned_alloczn(0, __alignment, __n, __ap); }
#ifndef valigned_allocn
# define valigned_allocn libsimple_valigned_allocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__)))
static inline void *
libsimple_aligned_allocn(size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_valigned_allocn(__alignment, __n, __ap);
	va_end(__ap);
}
#ifndef aligned_allocn
# define aligned_allocn libsimple_aligned_allocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_enaligned_alloc(int __status, size_t __alignment, size_t __n)
{ return libsimple_enaligned_allocz(__status, 0, __alignment, __n); }
#ifndef enaligned_alloc
# define enaligned_alloc libsimple_enaligned_alloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envaligned_allocn(int __status, size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envaligned_alloczn(__status, 0, __alignment, __n, __ap); }
#ifndef envaligned_allocn
# define envaligned_allocn libsimple_envaligned_allocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enaligned_allocn(int __status, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envaligned_alloczn(__status, 0, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef enaligned_allocn
# define enaligned_allocn libsimple_enaligned_allocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ealigned_alloc(size_t __alignment, size_t __n)
{ return libsimple_enaligned_alloc(libsimple_default_failure_exit, __alignment, __n); }
#ifndef ealigned_alloc
# define ealigned_alloc libsimple_ealigned_alloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evaligned_allocn(size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envaligned_allocn(libsimple_default_failure_exit, __alignment, __n, __ap); }
#ifndef evaligned_allocn
# define evaligned_allocn libsimple_evaligned_allocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ealigned_allocn(size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evaligned_allocn(__alignment, __n, __ap);
	va_end(__ap);
}
#ifndef ealigned_allocn
# define ealigned_allocn libsimple_ealigned_allocn
#endif
