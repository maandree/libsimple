/* See LICENSE file for copyright and license details. */

/*
 * The alignment will be the page size.
 */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *libsimple_vvallocn(size_t __n, va_list __ap)
{ return libsimple_vvalloczn(0, __n, __ap); }
#ifndef vvallocn
# define vvallocn libsimple_vvallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(1), __warn_unused_result__)))
static inline void *libsimple_valloc(size_t __n)
{ return libsimple_vallocz(0, __n); }
#ifndef valloc
# define valloc libsimple_valloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_vallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vvallocn(__n, __ap);
	va_end(__ap);
}
#ifndef vallocn
# define vallocn libsimple_vallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envalloc(int __status, size_t __n)
{ return libsimple_envallocz(__status, 0, __n); }
#ifndef envalloc
# define envalloc libsimple_envalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envvallocn(int __status, size_t __n, va_list __ap)
{ return libsimple_envvalloczn(__status, 0, __n, __ap); }
#ifndef envvallocn
# define envvallocn libsimple_envvallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envallocn(int __status, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envvalloczn(__status, 0, __n, __ap);
	va_end(__ap);
}
#ifndef envallocn
# define envallocn libsimple_envallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evalloc(size_t __n)
{ return libsimple_envalloc(libsimple_default_failure_exit, __n); }
#ifndef evalloc
# define evalloc libsimple_evalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evvallocn(size_t __n, va_list __ap)
{ return libsimple_envvallocn(libsimple_default_failure_exit, __n, __ap); }
#ifndef evvallocn
# define evvallocn libsimple_evvallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_evallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evvallocn(__n, __ap);
	va_end(__ap);
}
#ifndef evallocn
# define evallocn libsimple_evallocn
#endif
