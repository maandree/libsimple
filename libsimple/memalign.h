/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `alignment`,
 * up to the first 0, will be used as the number of
 * bytes to allocated
 * 
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment; `NULL` on failure
 * @throws  EINVAL     `n` is 0 or `alignment` is not a power of 2
 * @throws  ENOMEM     Could not allocated enough memory
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__)))
inline void *
libsimple_vmemalignn(size_t alignment__, size_t n__, va_list ap__)
{
	return libsimple_vmemalignzn(0, alignment__, n__, ap__);
}
#ifndef vmemalignn
# define vmemalignn libsimple_vmemalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          The number of bytes to allocate
 * @return             A unique pointer with at least the specified size
 *                     and alignment; `NULL` on failure
 * @throws  EINVAL     `n` is 0 or `alignment` is not a power of 2
 * @throws  ENOMEM     Could not allocated enough memory
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(1), __alloc_size__(2), __warn_unused_result__)))
inline void *
libsimple_memalign(size_t alignment__, size_t n__)
{
	return libsimple_memalignz(0, alignment__, n__);
}
#ifndef memalign
# define memalign libsimple_memalign
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `alignment`,
 * up to the first 0, will be used as the number of
 * bytes to allocated
 * 
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment; `NULL` on failure
 * @throws  EINVAL     `n` is 0 or `alignment` is not a power of 2
 * @throws  ENOMEM     Could not allocated enough memory
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__)))
inline void *
libsimple_memalignn(size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vmemalignn(alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef memalignn
# define memalignn libsimple_memalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_enmemalign(int status__, size_t alignment__, size_t n__)
{
	return libsimple_enmemalignz(status__, 0, alignment__, n__);
}
#ifndef enmemalign
# define enmemalign libsimple_enmemalign
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `status` and
 * `alignment`, up to the first 0, will be used as the
 * number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_envmemalignn(int status__, size_t alignment__, size_t n__, va_list ap__)
{
	return libsimple_envmemalignzn(status__, 0, alignment__, n__, ap__);
}
#ifndef envmemalignn
# define envmemalignn libsimple_envmemalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `status` and
 * `alignment`, up to the first 0, will be used as the
 * number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_enmemalignn(int status__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envmemalignzn(status__, 0, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef enmemalignn
# define enmemalignn libsimple_enmemalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(1), __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ememalign(size_t alignment__, size_t n__)
{
	return libsimple_enmemalign(libsimple_default_failure_exit, alignment__, n__);
}
#ifndef ememalign
# define ememalign libsimple_ememalign
#endif



/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `alignment`,
 * up to the first 0, will be used as the number of
 * bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evmemalignn(size_t alignment__, size_t n__, va_list ap__)
{
	return libsimple_envmemalignn(libsimple_default_failure_exit, alignment__, n__, ap__);
}
#ifndef evmemalignn
# define evmemalignn libsimple_evmemalignn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with custom alignment
 * 
 * The product of all arguments except `alignment`,
 * up to the first 0, will be used as the number of
 * bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ememalignn(size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evmemalignn(alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef ememalignn
# define ememalignn libsimple_ememalignn
#endif
