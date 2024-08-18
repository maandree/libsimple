/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `memptr` and
 * `alignment`, up to the first 0, will be used as the
 * number of bytes to allocated
 * 
 * @param   memptr     Output parameter for the new allocation, which
 *                     will on successful completion be set to a unique
 *                     pointer with at least the specified size and
 *                     alignment
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1))))
inline int
libsimple_vposix_memalignn(void **memptr__, size_t alignment__, size_t n__, va_list ap__)
{
	return libsimple_vposix_memalignzn(memptr__, 0, alignment__, n__, ap__);
}
#ifndef vposix_memalignn
# define vposix_memalignn libsimple_vposix_memalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `memptr` and
 * `alignment`, up to the first 0, will be used as the
 * number of bytes to allocated
 * 
 * @param   memptr     Output parameter for the new allocation, which
 *                     will on successful completion be set to a unique
 *                     pointer with at least the specified size and
 *                     alignment
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1))))
inline int
libsimple_posix_memalignn(void **memptr__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vposix_memalignn(memptr__, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef posix_memalignn
# define posix_memalignn libsimple_posix_memalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status     The exit value for the process in case of failure
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          The number of bytes to allocate, the behaviour of
 *                    this function is unspecified for the value 0
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(2))))
inline void
libsimple_enposix_memalign(int status__, void **memptr__, size_t alignment__, size_t n__)
{
	libsimple_enposix_memalignz(status__, memptr__, 0, alignment__, n__);
}
#ifndef enposix_memalign
# define enposix_memalign libsimple_enposix_memalign
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `status`, `memptr`,
 * and `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status     The exit value for the process in case of failure
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          First factor for the allocation size, must not be 0
 * @param  ap         The rest of the factors for the allocation size,
 *                    all arguments should have the type `size_t`, and
 *                    list must end with 0 (which is not factor)
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(2))))
inline void
libsimple_envposix_memalignn(int status__, void **memptr__, size_t alignment__, size_t n__, va_list ap__)
{
	libsimple_envposix_memalignzn(status__, memptr__, 0, alignment__, n__, ap__);
}
#ifndef envposix_memalignn
# define envposix_memalignn libsimple_envposix_memalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `status`, `memptr`,
 * and `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status     The exit value for the process in case of failure
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          First factor for the allocation size, must not be 0
 * @param  ...        The rest of the factors for the allocation size,
 *                    all arguments should have the type `size_t`, and
 *                    list must end with 0 (which is not factor)
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(2))))
inline void
libsimple_enposix_memalignn(int status__, void **memptr__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	libsimple_envposix_memalignzn(status__, memptr__, 0, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef enposix_memalignn
# define enposix_memalignn libsimple_enposix_memalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          The number of bytes to allocate, the behaviour of
 *                    this function is unspecified for the value 0
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1))))
inline void
libsimple_eposix_memalign(void **memptr__, size_t alignment__, size_t n__)
{
	libsimple_enposix_memalign(libsimple_default_failure_exit, memptr__, alignment__, n__);
}
#ifndef eposix_memalign
# define eposix_memalign libsimple_eposix_memalign
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `memptr` and
 * `alignment`, up to the first 0, will be used as the
 * number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          First factor for the allocation size, must not be 0
 * @param  ap         The rest of the factors for the allocation size,
 *                    all arguments should have the type `size_t`, and
 *                    list must end with 0 (which is not factor)
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1))))
inline void
libsimple_evposix_memalignn(void **memptr__, size_t alignment__, size_t n__, va_list ap__)
{
	libsimple_envposix_memalignn(libsimple_default_failure_exit, memptr__, alignment__, n__, ap__);
}
#ifndef evposix_memalignn
# define evposix_memalignn libsimple_evposix_memalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `memptr` and
 * `alignment`, up to the first 0, will be used as the
 * number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  memptr     Output parameter for the new allocation, which
 *                    will be set to a unique pointer with at least the
 *                    specified size and alignment
 * @param  alignment  The alignment, must be a power of 2 and a multiple
 *                    of `sizeof(void *)`
 * @param  n          First factor for the allocation size, must not be 0
 * @param  ...        The rest of the factors for the allocation size,
 *                    all arguments should have the type `size_t`, and
 *                    list must end with 0 (which is not factor)
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1))))
inline void
libsimple_eposix_memalignn(void **memptr__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	libsimple_evposix_memalignn(memptr__, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef eposix_memalignn
# define eposix_memalignn libsimple_eposix_memalignn
#endif
