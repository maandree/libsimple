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
static inline void *libsimple_vmemalignn(size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_vmemalignzn(0, __alignment, __n, __ap); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __alloc_size__(2), __warn_unused_result__)))
static inline void *libsimple_memalign(size_t __alignment, size_t __n)
{ return libsimple_memalignz(0, __alignment, __n); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__)))
static inline void *
libsimple_memalignn(size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmemalignn(__alignment, __n, __ap);
	va_end(__ap);
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_enmemalign(int __status, size_t __alignment, size_t __n)
{ return libsimple_enmemalignz(__status, 0, __alignment, __n); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envmemalignn(int __status, size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envmemalignzn(__status, 0, __alignment, __n, __ap); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmemalignn(int __status, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmemalignzn(__status, 0, __alignment, __n, __ap);
	va_end(__ap);
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ememalign(size_t __alignment, size_t __n)
{ return libsimple_enmemalign(libsimple_default_failure_exit, __alignment, __n); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmemalignn(size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envmemalignn(libsimple_default_failure_exit, __alignment, __n, __ap); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_align__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ememalignn(size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evmemalignn(__alignment, __n, __ap);
	va_end(__ap);
}
#ifndef ememalignn
# define ememalignn libsimple_ememalignn
#endif
