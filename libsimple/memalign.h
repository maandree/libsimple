/* See LICENSE file for copyright and license details. */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__)))
static inline void *libsimple_vmemalignn(size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_vmemalignzn(0, __alignment, __n, __ap); }
#ifndef vmemalignn
# define vmemalignn libsimple_vmemalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __alloc_size__(2), __warn_unused_result__)))
static inline void *libsimple_memalign(size_t __alignment, size_t __n)
{ return libsimple_memalignz(0, __alignment, __n); }
#ifndef memalign
# define memalign libsimple_memalign
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__)))
static inline void *
libsimple_memalignn(size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmemalignn(__alignment, __n, __ap);
	va_end(__ap);
}
#ifndef memalignn
# define memalignn libsimple_memalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_enmemalign(int __status, size_t __alignment, size_t __n)
{ return libsimple_enmemalignz(__status, 0, __alignment, __n); }
#ifndef enmemalign
# define enmemalign libsimple_enmemalign
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envmemalignn(int __status, size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envmemalignzn(__status, 0, __alignment, __n, __ap); }
#ifndef envmemalignn
# define envmemalignn libsimple_envmemalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmemalignn(int __status, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmemalignzn(__status, 0, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef enmemalignn
# define enmemalignn libsimple_enmemalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ememalign(size_t __alignment, size_t __n)
{ return libsimple_enmemalign(libsimple_default_failure_exit, __alignment, __n); }
#ifndef ememalign
# define ememalign libsimple_ememalign
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmemalignn(size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envmemalignn(libsimple_default_failure_exit, __alignment, __n, __ap); }
#ifndef evmemalignn
# define evmemalignn libsimple_evmemalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ememalignn(size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evmemalignn(__alignment, __n, __ap);
	va_end(__ap);
}
#ifndef ememalignn
# define ememalignn libsimple_ememalignn
#endif
