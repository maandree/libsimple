/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`;
 *                  `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *libsimple_vcallocn(size_t __n, va_list __ap)
{ return libsimple_vmalloczn(1, __n, __ap); }
#ifndef vcallocn
# define vcallocn libsimple_vcallocn
#endif


/**
 * Dynamically allocates heap allocated, initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`;
 *                  `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_callocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(1, __n, __ap);
	va_end(__ap);
}
#ifndef callocn
# define callocn libsimple_callocn
#endif


/**
 * Dynamically allocates heap allocated, initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   n       The number of elements to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @param   m       The size of each element, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          A unique pointer with at least the size `n * m`
 *                  and with the alignment `alignof(max_align_t)`;
 *                  `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2, 3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_encalloc(int, size_t, size_t);
#ifndef encalloc
# define encalloc libsimple_encalloc
#endif


/**
 * Dynamically allocates heap allocated, initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`;
 *                  `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envcallocn(int __st, size_t __n, va_list __ap)
{ return libsimple_envmalloczn(__st, 1, __n, __ap); }
#ifndef envcallocn
# define envcallocn libsimple_envcallocn
#endif


/**
 * Dynamically allocates heap allocated, initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`;
 *                  `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_encallocn(int __status, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envcallocn(__status, __n, __ap);
	va_end(__ap);
}
#ifndef encallocn
# define encallocn libsimple_encallocn
#endif


/**
 * Dynamically allocates heap allocated, initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   n  The number of elements to allocate, the behaviour of
 *             this function is unspecified for the value 0
 * @param   m  The size of each element, the behaviour of
 *             this function is unspecified for the value 0
 * @return     A unique pointer with at least the size `n * m`
 *             and with the alignment `alignof(max_align_t)`;
 *             `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(1, 2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ecalloc(size_t __n, size_t __m)
{ return encalloc(libsimple_default_failure_exit, __n, __m); }
#ifndef ecalloc
# define ecalloc libsimple_ecalloc
#endif


/**
 * Dynamically allocates heap allocated, initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`;
 *                  `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evcallocn(size_t __n, va_list __ap)
{ return libsimple_envcallocn(libsimple_default_failure_exit, __n, __ap); }
#ifndef evcallocn
# define evcallocn libsimple_evcallocn
#endif


/**
 * Dynamically allocates heap allocated, initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`;
 *                  `NULL` on failure
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ecallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evcallocn(__n, __ap);
	va_end(__ap);
}
#ifndef ecallocn
# define ecallocn libsimple_ecallocn
#endif
