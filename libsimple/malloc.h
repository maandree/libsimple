/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, uninitialised,
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
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *libsimple_vmallocn(size_t __n, va_list __ap)
{ return libsimple_vmalloczn(0, __n, __ap); }
#ifndef vmallocn
# define vmallocn libsimple_vmallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
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
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_mallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(0, __n, __ap);
	va_end(__ap);
}
#ifndef mallocn
# define mallocn libsimple_mallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   n       The number of bytes to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmalloc(int, size_t);
#ifndef enmalloc
# define enmalloc libsimple_enmalloc
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments except `status`, up to the
 * first 0, will be used as the number of bytes to allocated
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
 *                  and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envmallocn(int __status, size_t __n, va_list __ap)
{ return libsimple_envmalloczn(__status, 0, __n, __ap); }
#ifndef envmallocn
# define envmallocn libsimple_envmallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments except `status`, up to the
 * first 0, will be used as the number of bytes to allocated
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
 *                  and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmallocn(int __status, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmallocn(__status, __n, __ap);
	va_end(__ap);
}
#ifndef enmallocn
# define enmallocn libsimple_enmallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   n  The number of bytes to allocate, the behaviour of
 *             this function is unspecified for the value 0
 * @return     A unique pointer with at least the specified size
 *             and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_emalloc(size_t __n)
{ return libsimple_enmalloc(libsimple_default_failure_exit, __n); }
#ifndef emalloc
# define emalloc libsimple_emalloc
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   n   First factor for the allocation size, must not be 0
 * @param   ap  The rest of the factors for the allocation size,
 *              all arguments should have the type `size_t`, and
 *              list must end with 0 (which is not factor)
 * @return      A unique pointer with at least the specified size
 *              and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmallocn(size_t __n, va_list __ap)
{ return libsimple_envmallocn(libsimple_default_failure_exit, __n, __ap); }
#ifndef evmallocn
# define evmallocn libsimple_evmallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   n    First factor for the allocation size, must not be 0
 * @param   ...  The rest of the factors for the allocation size,
 *               all arguments should have the type `size_t`, and
 *               list must end with 0 (which is not factor)
 * @return       A unique pointer with at least the specified size
 *               and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_emallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evmallocn(__n, __ap);
	va_end(__ap);
}
#ifndef emallocn
# define emallocn libsimple_emallocn
#endif
