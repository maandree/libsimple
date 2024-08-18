/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `memptr`, `clear`
 * and `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * @param   memptr     Output parameter for the new allocation, which
 *                     will on successful completion be set to a unique
 *                     pointer with at least the specified size and
 *                     alignment
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2 and a multiple
 *                     of `sizeof(void *)`
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             0 on success, the error code on failure (errno is
 *                     not set)
 * @throws  EINVAL     `n` is 0, `alignment` is not a power of 2, or
 *                     `alignment` is not a multiple of `sizeof(void *)`
 * @throws  ENOMEM     Could not allocated enough memory
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
int libsimple_vposix_memalignzn(void **, int, size_t, size_t, va_list);
#ifndef vposix_memalignzn
# define vposix_memalignzn libsimple_vposix_memalignzn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * @param   memptr     Output parameter for the new allocation, which
 *                     will on successful completion be set to a unique
 *                     pointer with at least the specified size and
 *                     alignment
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2 and a multiple
 *                     of `sizeof(void *)`
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             0 on success, the error code on failure (errno is
 *                     not set)
 * @throws  EINVAL     `n` is 0, `alignment` is not a power of 2, or
 *                     `alignment` is not a multiple of `sizeof(void *)`
 * @throws  ENOMEM     Could not allocated enough memory
 * 
 * @since  1.1
 */
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


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `memptr`, `clear`
 * and `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * @param   memptr     Output parameter for the new allocation, which
 *                     will on successful completion be set to a unique
 *                     pointer with at least the specified size and
 *                     alignment
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2 and a multiple
 *                     of `sizeof(void *)`
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             0 on success, the error code on failure (errno is
 *                     not set)
 * @throws  EINVAL     `n` is 0, `alignment` is not a power of 2, or
 *                     `alignment` is not a multiple of `sizeof(void *)`
 * @throws  ENOMEM     Could not allocated enough memory
 * 
 * @since  1.1
 */
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


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status     The exit value for the process in case of failure
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  clear      Non-zero if the memory should be initialised
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          The number of bytes to allocate, the behaviour of
 *                    this function is unspecified for the value 0
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
void libsimple_enposix_memalignz(int, void **, int, size_t, size_t);
#ifndef enposix_memalignz
# define enposix_memalignz libsimple_enposix_memalignz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `status`, `memptr`,
 * `clear`, and `alignment`, up to the first 0, will be
 * used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status     The exit value for the process in case of failure
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  clear      Non-zero if the memory should be initialised
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          First factor for the allocation size, must not be 0
 * @param  ap         The rest of the factors for the allocation size,
 *                    all arguments should have the type `size_t`, and
 *                    list must end with 0 (which is not factor)
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
void libsimple_envposix_memalignzn(int, void **, int, size_t, size_t, va_list);
#ifndef envposix_memalignzn
# define envposix_memalignzn libsimple_envposix_memalignzn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `status`, `memptr`,
 * `clear`, and `alignment`, up to the first 0, will be
 * used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status     The exit value for the process in case of failure
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  clear      Non-zero if the memory should be initialised
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          First factor for the allocation size, must not be 0
 * @param  ...        The rest of the factors for the allocation size,
 *                    all arguments should have the type `size_t`, and
 *                    list must end with 0 (which is not factor)
 * 
 * @since  1.1
 */
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


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  clear      Non-zero if the memory should be initialised
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          The number of bytes to allocate, the behaviour of
 *                    this function is unspecified for the value 0
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline void libsimple_eposix_memalignz(void **__memptr, int __clear, size_t __alignment, size_t __n)
{ libsimple_enposix_memalignz(libsimple_default_failure_exit, __memptr, __clear, __alignment, __n); }
#ifndef eposix_memalignz
# define eposix_memalignz libsimple_eposix_memalignz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `memptr`, `clear`
 * and `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  clear      Non-zero if the memory should be initialised
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          First factor for the allocation size, must not be 0
 * @param  ap         The rest of the factors for the allocation size,
 *                    all arguments should have the type `size_t`, and
 *                    list must end with 0 (which is not factor)
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
static inline void libsimple_evposix_memalignzn(void **__memptr, int __clear, size_t __alignment, size_t __n, va_list __ap)
{ libsimple_envposix_memalignzn(libsimple_default_failure_exit, __memptr, __clear, __alignment, __n, __ap); }
#ifndef evposix_memalignzn
# define evposix_memalignzn libsimple_evposix_memalignzn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `memptr`, `clear`
 * and `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  clear      Non-zero if the memory should be initialised
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          First factor for the allocation size, must not be 0
 * @param  ...        The rest of the factors for the allocation size,
 *                    all arguments should have the type `size_t`, and
 *                    list must end with 0 (which is not factor)
 * 
 * @since  1.1
 */
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
