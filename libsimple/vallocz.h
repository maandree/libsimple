/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with page size alignment; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_vvalloczn(int clear__, size_t n__, va_list ap__)
{
	return libsimple_memalloc(0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, n__, ap__,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, clear__,
	                          LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef vvalloczn
# define vvalloczn libsimple_vvalloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       The number of bytes to allocate
 * @return          A unique pointer with at least the specified size
 *                  and with page size alignment; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__)))
inline void *
libsimple_vallocz(int clear__, size_t n__)
{
	return libsimple_memalloc(n__,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, clear__,
	                          LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef vallocz
# define vallocz libsimple_vallocz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with page size alignment; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_valloczn(int clear__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vvalloczn(clear__, n__, ap__);
	va_end(ap__);
}
#ifndef valloczn
# define valloczn libsimple_valloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       The number of bytes to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          A unique pointer with at least the specified size
 *                  and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_envallocz(int status__, int clear__, size_t n__)
{
	return libsimple_enmemalloc(status__, n__,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, clear__,
	                            LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef envallocz
# define envallocz libsimple_envallocz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `status` and
 * `clear`, up to the first 0, will be used as the number
 * of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_envvalloczn(int status__, int clear__, size_t n__, va_list ap__)
{
	return libsimple_enmemalloc(status__,
	                            0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, n__, ap__,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, clear__,
	                            LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef envvalloczn
# define envvalloczn libsimple_envvalloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `status` and
 * `clear`, up to the first 0, will be used as the number
 * of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_envalloczn(int status__, int clear__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envvalloczn(status__, clear__, n__, ap__);
	va_end(ap__);
}
#ifndef envalloczn
# define envalloczn libsimple_envalloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear  Non-zero if the memory should be initialised
 * @param   n      The number of bytes to allocate, the behaviour of
 *                 this function is unspecified for the value 0
 * @return         A unique pointer with at least the specified size
 *                 and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evallocz(int clear__, size_t n__)
{
	return libsimple_envallocz(libsimple_default_failure_exit, clear__, n__);
}
#ifndef evallocz
# define evallocz libsimple_evallocz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear  Non-zero if the memory should be initialised
 * @param   n      First factor for the allocation size, must not be 0
 * @param   ap     The rest of the factors for the allocation size,
 *                 all arguments should have the type `size_t`, and
 *                 list must end with 0 (which is not factor)
 * @return         A unique pointer with at least the specified size
 *                 and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evvalloczn(int clear__, size_t n__, va_list ap__)
{
	return libsimple_envvalloczn(libsimple_default_failure_exit, clear__, n__, ap__);
}
#ifndef evvalloczn
# define evvalloczn libsimple_evvalloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear  Non-zero if the memory should be initialised
 * @param   n      First factor for the allocation size, must not be 0
 * @param   ...    The rest of the factors for the allocation size,
 *                 all arguments should have the type `size_t`, and
 *                 list must end with 0 (which is not factor)
 * @return         A unique pointer with at least the specified size
 *                 and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evalloczn(int clear__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evvalloczn(clear__, n__, ap__);
	va_end(ap__);
}
#ifndef evalloczn
# define evalloczn libsimple_evalloczn
#endif
