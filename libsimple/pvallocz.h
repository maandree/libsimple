/* See LICENSE file for copyright and license details. */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_vpvalloczn(int __clear, size_t __n, va_list __ap) /* TODO test ([v]pvalloc[z]n) */
{
	return libsimple_memalloc(0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef vpvalloczn
# define vpvalloczn libsimple_vpvalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__)))
static inline void *
libsimple_pvallocz(int __clear, size_t __n) /* TODO test (pvalloc[z]) */
{
	return libsimple_memalloc(__n,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef pvallocz
# define pvallocz libsimple_pvallocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_pvalloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vpvalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef pvalloczn
# define pvalloczn libsimple_pvalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enpvallocz(int __status, int __clear, size_t __n) /* TODO test (e[n]pvalloc[z]) */
{
	return libsimple_enmemalloc(__status, __n,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef enpvallocz
# define enpvallocz libsimple_enpvallocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envpvalloczn(int __status, int __clear, size_t __n, va_list __ap) /* TODO test (e[n][v]pvalloc[z]n) */
{
	return libsimple_enmemalloc(__status,
	                            0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef envpvalloczn
# define envpvalloczn libsimple_envpvalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enpvalloczn(int __status, int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envpvalloczn(__status, __clear, __n, __ap);
	va_end(__ap);
}
#ifndef enpvalloczn
# define enpvalloczn libsimple_enpvalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_epvallocz(int __clear, size_t __n)
{ return libsimple_enpvallocz(libsimple_default_failure_exit, __clear, __n); }
#ifndef epvallocz
# define epvallocz libsimple_epvallocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evpvalloczn(int __clear, size_t __n, va_list __ap)
{ return libsimple_envpvalloczn(libsimple_default_failure_exit, __clear, __n, __ap); }
#ifndef evpvalloczn
# define evpvalloczn libsimple_evpvalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_epvalloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evpvalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef epvalloczn
# define epvalloczn libsimple_epvalloczn
#endif
