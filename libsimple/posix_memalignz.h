/* See LICENSE file for copyright and license details. */

/*
 * Alignment must be a power of 2 and a multiple of `sizeof(void *)`.
 */

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
int libsimple_vposix_memalignzn(void **, int, size_t, size_t, va_list);
#ifndef vposix_memalignzn
# define vposix_memalignzn libsimple_vposix_memalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline int
libsimple_posix_memalignz(void **__memptr, int __clear, size_t __alignment, size_t __n)
{
	int __ret = posix_memalign(__memptr, __alignment, __n);
	if (!__ret && __clear)
		memset(*__memptr, 0, __n);
	return __ret;
}
#ifndef posix_memalignz
# define posix_memalignz libsimple_posix_memalignz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline int
libsimple_posix_memalignzn(void **__memptr, int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vposix_memalignzn(__memptr, __clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef posix_memalignzn
# define posix_memalignzn libsimple_posix_memalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
void libsimple_enposix_memalignz(int, void **, int, size_t, size_t);
#ifndef enposix_memalignz
# define enposix_memalignz libsimple_enposix_memalignz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
void libsimple_envposix_memalignzn(int, void **, int, size_t, size_t, va_list);
#ifndef envposix_memalignzn
# define envposix_memalignzn libsimple_envposix_memalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
static inline void
libsimple_enposix_memalignzn(int __status, void **__memptr, int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	libsimple_envposix_memalignzn(__status, __memptr, __clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef enposix_memalignzn
# define enposix_memalignzn libsimple_enposix_memalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline void libsimple_eposix_memalignz(void **__memptr, int __clear, size_t __alignment, size_t __n)
{ libsimple_enposix_memalignz(libsimple_default_failure_exit, __memptr, __clear, __alignment, __n); }
#ifndef eposix_memalignz
# define eposix_memalignz libsimple_eposix_memalignz
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline void libsimple_evposix_memalignzn(void **__memptr, int __clear, size_t __alignment, size_t __n, va_list __ap)
{ libsimple_envposix_memalignzn(libsimple_default_failure_exit, __memptr, __clear, __alignment, __n, __ap); }
#ifndef evposix_memalignzn
# define evposix_memalignzn libsimple_evposix_memalignzn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline void
libsimple_eposix_memalignzn(void **__memptr, int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	libsimple_evposix_memalignzn(__memptr, __clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef eposix_memalignzn
# define eposix_memalignzn libsimple_eposix_memalignzn
#endif
