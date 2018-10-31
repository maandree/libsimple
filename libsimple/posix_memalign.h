/* See LICENSE file for copyright and license details. */

/*
 * Alignment must be a power of 2 and a multiple of `sizeof(void *)`.
 */

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline int libsimple_vposix_memalignn(void **__memptr, size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_vposix_memalignzn(__memptr, 0, __alignment, __n, __ap); }
#ifndef vposix_memalignn
# define vposix_memalignn libsimple_vposix_memalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline int
libsimple_posix_memalignn(void **__memptr, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vposix_memalignn(__memptr, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef posix_memalignn
# define posix_memalignn libsimple_posix_memalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
static inline void libsimple_enposix_memalign(int __status, void **__memptr, size_t __alignment, size_t __n)
{ libsimple_enposix_memalignz(__status, __memptr, 0, __alignment, __n); }
#ifndef enposix_memalign
# define enposix_memalign libsimple_enposix_memalign
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
static inline void libsimple_envposix_memalignn(int __status, void **__memptr, size_t __alignment, size_t __n, va_list __ap)
{ libsimple_envposix_memalignzn(__status, __memptr, 0, __alignment, __n, __ap); }
#ifndef envposix_memalignn
# define envposix_memalignn libsimple_envposix_memalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
static inline void
libsimple_enposix_memalignn(int __status, void **__memptr, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	libsimple_envposix_memalignzn(__status, __memptr, 0, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef enposix_memalignn
# define enposix_memalignn libsimple_enposix_memalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline void libsimple_eposix_memalign(void **__memptr, size_t __alignment, size_t __n)
{ libsimple_enposix_memalign(libsimple_default_failure_exit, __memptr, __alignment, __n); }
#ifndef eposix_memalign
# define eposix_memalign libsimple_eposix_memalign
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline void libsimple_evposix_memalignn(void **__memptr, size_t __alignment, size_t __n, va_list __ap)
{ libsimple_envposix_memalignn(libsimple_default_failure_exit, __memptr, __alignment, __n, __ap); }
#ifndef evposix_memalignn
# define evposix_memalignn libsimple_evposix_memalignn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline void
libsimple_eposix_memalignn(void **__memptr, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	libsimple_evposix_memalignn(__memptr, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef eposix_memalignn
# define eposix_memalignn libsimple_eposix_memalignn
#endif
