/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_vpvalloczn(int __clear, size_t __n, va_list __ap)
{
	return libsimple_memalloc(0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef vpvalloczn
# define vpvalloczn libsimple_vpvalloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       The number of bytes to allocate
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__)))
static inline void *
libsimple_pvallocz(int __clear, size_t __n)
{
	return libsimple_memalloc(__n,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	                          LIBSIMPLE_MEMALLOC_END);
}
#ifndef pvallocz
# define pvallocz libsimple_pvallocz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_pvalloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vpvalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef pvalloczn
# define pvalloczn libsimple_pvalloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       The number of bytes to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enpvallocz(int __status, int __clear, size_t __n)
{
	return libsimple_enmemalloc(__status, __n,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef enpvallocz
# define enpvallocz libsimple_enpvallocz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `status` and
 * `clear`, up to the first 0, will be used as the number
 * of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
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
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envpvalloczn(int __status, int __clear, size_t __n, va_list __ap)
{
	return libsimple_enmemalloc(__status,
	                            0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	                            LIBSIMPLE_MEMALLOC_END);
}
#ifndef envpvalloczn
# define envpvalloczn libsimple_envpvalloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `status` and
 * `clear`, up to the first 0, will be used as the number
 * of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
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
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enpvalloczn(int __status, int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envpvalloczn(__status, __clear, __n, __ap);
	va_end(__ap);
}
#ifndef enpvalloczn
# define enpvalloczn libsimple_enpvalloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear  Non-zero if the memory should be initialised
 * @param   n      The number of bytes to allocate, the behaviour of
 *                 this function is unspecified for the value 0
 * @return         A unique pointer with at least the specified size,
 *                 rounded up to the next multiple of the page size,
 *                 and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_epvallocz(int __clear, size_t __n)
{ return libsimple_enpvallocz(libsimple_default_failure_exit, __clear, __n); }
#ifndef epvallocz
# define epvallocz libsimple_epvallocz
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
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
 * @return         A unique pointer with at least the specified size,
 *                 rounded up to the next multiple of the page size,
 *                 and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evpvalloczn(int __clear, size_t __n, va_list __ap)
{ return libsimple_envpvalloczn(libsimple_default_failure_exit, __clear, __n, __ap); }
#ifndef evpvalloczn
# define evpvalloczn libsimple_evpvalloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with page size alignment
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
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
 * @return         A unique pointer with at least the specified size,
 *                 rounded up to the next multiple of the page size,
 *                 and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_epvalloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evpvalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef epvalloczn
# define epvalloczn libsimple_epvalloczn
#endif
