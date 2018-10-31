/* See LICENSE file for copyright and license details. */

/*
 * Alignment must be a power of 2.
 */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_vmemalignzn(int __clear, size_t __alignment, size_t __n, va_list __ap) /* TODO test ([v]memalign[z]n) */
{
	if (!__alignment || (__alignment & (__alignment - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_memalloc(0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_ALIGNMENT, __alignment,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef vmemalignzn
# define vmemalignzn libsimple_vmemalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__)))
static inline void *
libsimple_memalignz(int __clear, size_t __alignment, size_t __n) /* TODO test (memalign[z]) */
{
	if (!__alignment || (__alignment & (__alignment - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_memalloc(__n,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_ALIGNMENT, __alignment,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef memalignz
# define memalignz libsimple_memalignz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_memalignzn(int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmemalignzn(__clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef memalignzn
# define memalignzn libsimple_memalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmemalignz(int __status, int __clear, size_t __alignment, size_t __n) /* TODO test (e[n]memalign[z]) */
{
	if (!__alignment || (__alignment & (__alignment - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_enmemalloc(__status, __n,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_ALIGNMENT, __alignment,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef enmemalignz
# define enmemalignz libsimple_enmemalignz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envmemalignzn(int __status, int __clear, size_t __alignment, size_t __n, va_list __ap) /* TODO test (e[n][v]memalign[z]n) */
{
	if (!__alignment || (__alignment & (__alignment - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_enmemalloc(__status,
	                            0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_ALIGNMENT, __alignment,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef envmemalignzn
# define envmemalignzn libsimple_envmemalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmemalignzn(int __status, int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmemalignzn(__status, __clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef enmemalignzn
# define enmemalignzn libsimple_enmemalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ememalignz(int __clear, size_t __alignment, size_t __n)
{ return libsimple_enmemalignz(libsimple_default_failure_exit, __alignment, __clear, __n); }
#ifndef ememalignz
# define ememalignz libsimple_ememalignz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmemalignzn(int __clear, size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envmemalignzn(libsimple_default_failure_exit, __alignment, __clear, __n, __ap); }
#ifndef evmemalignzn
# define evmemalignzn libsimple_evmemalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ememalignzn(int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evmemalignzn(__clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef ememalignzn
# define ememalignzn libsimple_ememalignzn
#endif
