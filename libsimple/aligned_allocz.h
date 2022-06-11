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
void *libsimple_valigned_alloczn(int, size_t, size_t, va_list);
#ifndef valigned_alloczn
# define valigned_alloczn libsimple_valigned_alloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
 * 
 * @param   clear      Non-zero if the memory should be initialised
 * @param   alignment  The alignment, must be a power of 2
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             A unique pointer with at least the specified size
 *                     and alignment; `NULL` on failure
 * @throws  EINVAL     `n` is 0 or `alignment` is not a power of 2
 * @throws  ENOMEM     Could not allocated enough memory
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__)))
inline void *
libsimple_aligned_allocz(int clear__, size_t alignment__, size_t n__)
{
	void *ret__ = aligned_alloc(alignment__, n__);
	if (ret__ && clear__)
		memset(ret__, 0, n__);
	return ret__;
}
#ifndef aligned_allocz
# define aligned_allocz libsimple_aligned_allocz
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
inline void *
libsimple_aligned_alloczn(int clear__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_valigned_alloczn(clear__, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef aligned_alloczn
# define aligned_alloczn libsimple_aligned_alloczn
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
void *libsimple_enaligned_allocz(int, int, size_t, size_t);
#ifndef enaligned_allocz
# define enaligned_allocz libsimple_enaligned_allocz
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
void *libsimple_envaligned_alloczn(int, int, size_t, size_t, va_list);
#ifndef envaligned_alloczn
# define envaligned_alloczn libsimple_envaligned_alloczn
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
inline void *
libsimple_enaligned_alloczn(int status__, int clear__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envaligned_alloczn(status__, clear__, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef enaligned_alloczn
# define enaligned_alloczn libsimple_enaligned_alloczn
#endif


/**
 * Dynamically allocates heap allocated, optionally
 * initialised, memory with custom alignment
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ealigned_allocz(int clear__, size_t alignment__, size_t n__)
{
	return libsimple_enaligned_allocz(libsimple_default_failure_exit, clear__, alignment__, n__);
}
#ifndef ealigned_allocz
# define ealigned_allocz libsimple_ealigned_allocz
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
inline void *
libsimple_evaligned_alloczn(int clear__, size_t alignment__, size_t n__, va_list ap__)
{
	return libsimple_envaligned_alloczn(libsimple_default_failure_exit, clear__, alignment__, n__, ap__);
}
#ifndef evaligned_alloczn
# define evaligned_alloczn libsimple_evaligned_alloczn
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
inline void *
libsimple_ealigned_alloczn(int clear__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evaligned_alloczn(clear__, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef ealigned_alloczn
# define ealigned_alloczn libsimple_ealigned_alloczn
#endif
