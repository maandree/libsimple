/* See LICENSE file for copyright and license details. */

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
void *libsimple_vreallocn(void *, size_t, va_list);
#ifndef vreallocn
# define vreallocn libsimple_vreallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *
libsimple_reallocn(void *__ptr, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vreallocn(__ptr, __n, __ap);
	va_end(__ap);
}
#ifndef reallocn
# define reallocn libsimple_reallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enrealloc(int, void *, size_t);
#ifndef enrealloc
# define enrealloc libsimple_enrealloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
void *libsimple_envreallocn(int, void *, size_t, va_list);
#ifndef envreallocn
# define envreallocn libsimple_envreallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enreallocn(int __status, void *__ptr, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envreallocn(__status, __ptr, __n, __ap);
	va_end(__ap);
}
#ifndef enreallocn
# define enreallocn libsimple_enreallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_erealloc(void *__ptr, size_t __n)
{ return enrealloc(libsimple_default_failure_exit, __ptr, __n); }
#ifndef erealloc
# define erealloc libsimple_erealloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evreallocn(void *__ptr, size_t __n, va_list __ap)
{ return libsimple_envreallocn(libsimple_default_failure_exit, __ptr, __n, __ap); }
#ifndef evreallocn
# define evreallocn libsimple_evreallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ereallocn(void *__ptr, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evreallocn(__ptr, __n, __ap);
	va_end(__ap);
}
#ifndef ereallocn
# define ereallocn libsimple_ereallocn
#endif
