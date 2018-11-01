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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__)))
static inline void *libsimple_valigned_allocn(size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_valigned_alloczn(0, __alignment, __n, __ap); }
#ifndef valigned_allocn
# define valigned_allocn libsimple_valigned_allocn
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__)))
static inline void *
libsimple_aligned_allocn(size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_valigned_allocn(__alignment, __n, __ap);
	va_end(__ap);
}
#ifndef aligned_allocn
# define aligned_allocn libsimple_aligned_allocn
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_enaligned_alloc(int __status, size_t __alignment, size_t __n)
{ return libsimple_enaligned_allocz(__status, 0, __alignment, __n); }
#ifndef enaligned_alloc
# define enaligned_alloc libsimple_enaligned_alloc
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envaligned_allocn(int __status, size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envaligned_alloczn(__status, 0, __alignment, __n, __ap); }
#ifndef envaligned_allocn
# define envaligned_allocn libsimple_envaligned_allocn
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enaligned_allocn(int __status, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envaligned_alloczn(__status, 0, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef enaligned_allocn
# define enaligned_allocn libsimple_enaligned_allocn
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ealigned_alloc(size_t __alignment, size_t __n)
{ return libsimple_enaligned_alloc(libsimple_default_failure_exit, __alignment, __n); }
#ifndef ealigned_alloc
# define ealigned_alloc libsimple_ealigned_alloc
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evaligned_allocn(size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envaligned_allocn(libsimple_default_failure_exit, __alignment, __n, __ap); }
#ifndef evaligned_allocn
# define evaligned_allocn libsimple_evaligned_allocn
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ealigned_allocn(size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evaligned_allocn(__alignment, __n, __ap);
	va_end(__ap);
}
#ifndef ealigned_allocn
# define ealigned_allocn libsimple_ealigned_allocn
#endif
