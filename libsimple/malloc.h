/* See LICENSE file for copyright and license details. */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *libsimple_vmallocn(size_t __n, va_list __ap)
{ return libsimple_vmalloczn(0, __n, __ap); }
#ifndef vmallocn
# define vmallocn libsimple_vmallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_mallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(0, __n, __ap);
	va_end(__ap);
}
#ifndef mallocn
# define mallocn libsimple_mallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmalloc(int, size_t);
#ifndef enmalloc
# define enmalloc libsimple_enmalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envmallocn(int __st, size_t __n, va_list __ap)
{ return libsimple_envmalloczn(__st, 0, __n, __ap); }
#ifndef envmallocn
# define envmallocn libsimple_envmallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmallocn(int __status, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmallocn(__status, __n, __ap);
	va_end(__ap);
}
#ifndef enmallocn
# define enmallocn libsimple_enmallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_emalloc(size_t __n)
{ return libsimple_enmalloc(libsimple_default_failure_exit, __n); }
#ifndef emalloc
# define emalloc libsimple_emalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmallocn(size_t __n, va_list __ap)
{ return libsimple_envmallocn(libsimple_default_failure_exit, __n, __ap); }
#ifndef evmallocn
# define evmallocn libsimple_evmallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_emallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evmallocn(__n, __ap);
	va_end(__ap);
}
#ifndef emallocn
# define emallocn libsimple_emallocn
#endif
