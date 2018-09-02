/* See LICENSE file for copyright and license details. */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *libsimple_vpvallocn(size_t __n, va_list __ap)
{ return libsimple_vpvalloczn(0, __n, __ap); }
#ifndef vpvallocn
# define vpvallocn libsimple_vpvallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *libsimple_pvalloc(size_t __n)
{ return libsimple_pvallocz(0, __n); }
#ifndef pvalloc
# define pvalloc libsimple_pvalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_pvallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vpvallocn(__n, __ap);
	va_end(__ap);
}
#ifndef pvallocn
# define pvallocn libsimple_pvallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_enpvalloc(int __status, size_t __n)
{ return libsimple_enpvallocz(__status, 0, __n); }
#ifndef enpvalloc
# define enpvalloc libsimple_enpvalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envpvallocn(int __status, size_t __n, va_list __ap)
{ return libsimple_envpvalloczn(__status, 0, __n, __ap); }
#ifndef envpvallocn
# define envpvallocn libsimple_envpvallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enpvallocn(int __status, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envpvalloczn(__status, 0, __n, __ap);
	va_end(__ap);
}
#ifndef enpvallocn
# define enpvallocn libsimple_enpvallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_epvalloc(size_t __n)
{ return libsimple_enpvalloc(libsimple_default_failure_exit, __n); }
#ifndef epvalloc
# define epvalloc libsimple_epvalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evpvallocn(size_t __n, va_list __ap)
{ return libsimple_envpvallocn(libsimple_default_failure_exit, __n, __ap); }
#ifndef evpvallocn
# define evpvallocn libsimple_evpvallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_epvallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evpvallocn(__n, __ap);
	va_end(__ap);
}
#ifndef epvallocn
# define epvallocn libsimple_epvallocn
#endif
