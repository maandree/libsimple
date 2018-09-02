/* See LICENSE file for copyright and license details. */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *libsimple_vcallocn(size_t __n, va_list __ap)
{ return libsimple_vmalloczn(1, __n, __ap); }
#ifndef vcallocn
# define vcallocn libsimple_vcallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_callocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(1, __n, __ap);
	va_end(__ap);
}
#ifndef callocn
# define callocn libsimple_callocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2, 3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_encalloc(int, size_t, size_t);
#ifndef encalloc
# define encalloc libsimple_encalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envcallocn(int __st, size_t __n, va_list __ap)
{ return libsimple_envmalloczn(__st, 1, __n, __ap); }
#ifndef envcallocn
# define envcallocn libsimple_envcallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_encallocn(int __status, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envcallocn(__status, __n, __ap);
	va_end(__ap);
}
#ifndef encallocn
# define encallocn libsimple_encallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(1, 2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ecalloc(size_t __n, size_t __m)
{ return encalloc(libsimple_default_failure_exit, __n, __m); }
#ifndef ecalloc
# define ecalloc libsimple_ecalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evcallocn(size_t __n, va_list __ap)
{ return libsimple_envcallocn(libsimple_default_failure_exit, __n, __ap); }
#ifndef evcallocn
# define evcallocn libsimple_evcallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ecallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evcallocn(__n, __ap);
	va_end(__ap);
}
#ifndef ecallocn
# define ecallocn libsimple_ecallocn
#endif
