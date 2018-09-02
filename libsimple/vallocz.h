/* See LICENSE file for copyright and license details. */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_vvalloczn(int __clear, size_t __n, va_list __ap) /* TODO test ([v]valloc[z]n) */
{
	return libsimple_memalloc(0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef vvalloczn
# define vvalloczn libsimple_vvalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__)))
static inline void *
libsimple_vallocz(int __clear, size_t __n) /* TODO test (valloc[z]) */
{
	return libsimple_memalloc(__n,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef vallocz
# define vallocz libsimple_vallocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_valloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vvalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef valloczn
# define valloczn libsimple_valloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envallocz(int __status, int __clear, size_t __n) /* TODO test (e[n]valloc[z]) */
{
	return libsimple_enmemalloc(__status, __n,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef envallocz
# define envallocz libsimple_envallocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envvalloczn(int __status, int __clear, size_t __n, va_list __ap) /* TODO test (e[n][v]valloc[z]n, e[n]vallocn) */
{
	return libsimple_enmemalloc(__status,
	                            0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef envvalloczn
# define envvalloczn libsimple_envvalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envalloczn(int __status, int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envvalloczn(__status, __clear, __n, __ap);
	va_end(__ap);
}
#ifndef envalloczn
# define envalloczn libsimple_envalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evallocz(int __clear, size_t __n)
{ return libsimple_envallocz(libsimple_default_failure_exit, __clear, __n); }
#ifndef evallocz
# define evallocz libsimple_evallocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evvalloczn(int __clear, size_t __n, va_list __ap)
{ return libsimple_envvalloczn(libsimple_default_failure_exit, __clear, __n, __ap); }
#ifndef evvalloczn
# define evvalloczn libsimple_evvalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_evalloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evvalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef evalloczn
# define evalloczn libsimple_evalloczn
#endif
