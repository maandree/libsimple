/* See LICENSE file for copyright and license details. */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2, 3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_encalloc(int, size_t, size_t);

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmalloc(int, size_t);


_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
void *libsimple_vmalloczn(int, size_t, va_list);
#ifndef vmalloczn
# define vmalloczn libsimple_vmalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__)))
static inline void *libsimple_mallocz(int __clear, size_t __n)
{ return __clear ? calloc(1, __n) : malloc(__n); }
#ifndef mallocz
# define mallocz libsimple_mallocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_malloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef malloczn
# define malloczn libsimple_malloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_enmallocz(int __status, int __clear, size_t __n)
{ return __clear ? libsimple_encalloc(__status, 1, __n) : libsimple_enmalloc(__status, __n); }
#ifndef enmallocz
# define enmallocz libsimple_enmallocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
void *libsimple_envmalloczn(int, int, size_t, va_list);
#ifndef envmalloczn
# define envmalloczn libsimple_envmalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmalloczn(int __status, int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(__status, __clear, __n, __ap);
	va_end(__ap);
}
#ifndef enmalloczn
# define enmalloczn libsimple_enmalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_emallocz(int __clear, size_t __n)
{ return libsimple_enmallocz(libsimple_default_failure_exit, __clear, __n); }
#ifndef emallocz
# define emallocz libsimple_emallocz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmalloczn(int __clear, size_t __n, va_list __ap)
{ return libsimple_envmalloczn(libsimple_default_failure_exit, __clear, __n, __ap); }
#ifndef evmalloczn
# define evmalloczn libsimple_evmalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_emalloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evmalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef emalloczn
# define emalloczn libsimple_emalloczn
#endif
