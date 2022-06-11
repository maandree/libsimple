/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `clear` and
 * `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment; `NULL` on failure
 * @throws  EINVAL     `n` is 0 or `alignment` is not a power of 2
 * @throws  ENOMEM     Could not allocated enough memory
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_vmemalignzn(int clear__, size_t alignment__, size_t n__, va_list ap__)
{
	if (!alignment__ || (alignment__ & (alignment__ - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_memalloc(0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, n__, ap__,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, clear__,
	                          LIBSIMPLE_MEMALLOC_ALIGNMENT, alignment__,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef vmemalignzn
# define vmemalignzn libsimple_vmemalignzn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          The number of bytes to allocate
 * @return             A unique pointer with at least the specified size
 *                     and alignment; `NULL` on failure
 * @throws  EINVAL     `n` is 0 or `alignment` is not a power of 2
 * @throws  ENOMEM     Could not allocated enough memory
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__)))
static inline void *
libsimple_memalignz(int clear__, size_t alignment__, size_t n__)
{
	if (!alignment__ || (alignment__ & (alignment__ - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_memalloc(n__,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, clear__,
	                          LIBSIMPLE_MEMALLOC_ALIGNMENT, alignment__,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef memalignz
# define memalignz libsimple_memalignz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `clear` and
 * `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment; `NULL` on failure
 * @throws  EINVAL     `n` is 0 or `alignment` is not a power of 2
 * @throws  ENOMEM     Could not allocated enough memory
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_memalignzn(int clear__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vmemalignzn(clear__, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef memalignzn
# define memalignzn libsimple_memalignzn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmemalignz(int status__, int clear__, size_t alignment__, size_t n__)
{
	if (!alignment__ || (alignment__ & (alignment__ - 1UL))) {
		errno = EINVAL;
		libsimple_enprintf(status__, "libsimple_vmemalignz:");
	}
	return libsimple_enmemalloc(status__, n__,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, clear__,
	                            LIBSIMPLE_MEMALLOC_ALIGNMENT, alignment__,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef enmemalignz
# define enmemalignz libsimple_enmemalignz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `status`,
 * `clear`, and `alignment`, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envmemalignzn(int status__, int clear__, size_t alignment__, size_t n__, va_list ap__)
{
	if (!alignment__ || (alignment__ & (alignment__ - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_enmemalloc(status__,
	                            0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, n__, ap__,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, clear__,
	                            LIBSIMPLE_MEMALLOC_ALIGNMENT, alignment__,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef envmemalignzn
# define envmemalignzn libsimple_envmemalignzn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `status`,
 * `clear`, and `alignment`, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmemalignzn(int status__, int clear__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envmemalignzn(status__, clear__, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef enmemalignzn
# define enmemalignzn libsimple_enmemalignzn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ememalignz(int clear__, size_t alignment__, size_t n__)
{
	return libsimple_enmemalignz(libsimple_default_failure_exit, clear__, alignment__, n__);
}
#ifndef ememalignz
# define ememalignz libsimple_ememalignz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `clear` and
 * `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_evmemalignzn(int clear__, size_t alignment__, size_t n__, va_list ap__)
{
	return libsimple_envmemalignzn(libsimple_default_failure_exit, clear__, alignment__, n__, ap__);
}
#ifndef evmemalignzn
# define evmemalignzn libsimple_evmemalignzn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * The product of all arguments except `clear` and
 * `alignment`, up to the first 0, will be used as
 * the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             A unique pointer with at least the specified size
 *                     and alignment
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ememalignzn(int clear__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evmemalignzn(clear__, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef ememalignzn
# define ememalignzn libsimple_ememalignzn
#endif
