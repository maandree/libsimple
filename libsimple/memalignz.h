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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_vmemalignzn(int __clear, size_t __alignment, size_t __n, va_list __ap) /* TODO test ([v]memalign[z]n) */
{
	if (!__alignment || (__alignment & (__alignment - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_memalloc(0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_ALIGNMENT, __alignment,
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__)))
static inline void *
libsimple_memalignz(int __clear, size_t __alignment, size_t __n) /* TODO test (memalign[z]) */
{
	if (!__alignment || (__alignment & (__alignment - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_memalloc(__n,
	                          LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                          LIBSIMPLE_MEMALLOC_ALIGNMENT, __alignment,
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_memalignzn(int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmemalignzn(__clear, __alignment, __n, __ap);
	va_end(__ap);
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmemalignz(int __status, int __clear, size_t __alignment, size_t __n) /* TODO test (e[n]memalign[z]) */
{
	if (!__alignment || (__alignment & (__alignment - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_enmemalloc(__status, __n,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_ALIGNMENT, __alignment,
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envmemalignzn(int __status, int __clear, size_t __alignment, size_t __n, va_list __ap) /* TODO test (e[n][v]memalign[z]n) */
{
	if (!__alignment || (__alignment & (__alignment - 1UL))) {
		errno = EINVAL;
		return NULL;
	}
	return libsimple_enmemalloc(__status,
	                            0, LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE, __n, __ap,
	                            LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT, __clear,
	                            LIBSIMPLE_MEMALLOC_ALIGNMENT, __alignment,
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmemalignzn(int __status, int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmemalignzn(__status, __clear, __alignment, __n, __ap);
	va_end(__ap);
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ememalignz(int __clear, size_t __alignment, size_t __n)
{ return libsimple_enmemalignz(libsimple_default_failure_exit, __alignment, __clear, __n); }
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmemalignzn(int __clear, size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envmemalignzn(libsimple_default_failure_exit, __alignment, __clear, __n, __ap); }
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ememalignzn(int __clear, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evmemalignzn(__clear, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef ememalignzn
# define ememalignzn libsimple_ememalignzn
#endif
