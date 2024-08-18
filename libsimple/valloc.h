/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *libsimple_vvallocn(size_t __n, va_list __ap)
{ return libsimple_vvalloczn(0, __n, __ap); }
#ifndef vvallocn
# define vvallocn libsimple_vvallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * @param   n       The number of bytes to allocate
 * @return          A unique pointer with at least the specified size
 *                  and with page size alignment; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(1), __warn_unused_result__)))
static inline void *libsimple_valloc(size_t __n)
{ return libsimple_vallocz(0, __n); }
#ifndef valloc
# define valloc libsimple_valloc
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
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
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_vallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vvallocn(__n, __ap);
	va_end(__ap);
}
#ifndef vallocn
# define vallocn libsimple_vallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   n       The number of bytes to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          A unique pointer with at least the specified size
 *                  and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envalloc(int __status, size_t __n)
{ return libsimple_envallocz(__status, 0, __n); }
#ifndef envalloc
# define envalloc libsimple_envalloc
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
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
 *                  and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envvallocn(int __status, size_t __n, va_list __ap)
{ return libsimple_envvalloczn(__status, 0, __n, __ap); }
#ifndef envvallocn
# define envvallocn libsimple_envvallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
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
 *                  and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envallocn(int __status, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envvalloczn(__status, 0, __n, __ap);
	va_end(__ap);
}
#ifndef envallocn
# define envallocn libsimple_envallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   n  The number of bytes to allocate, the behaviour of
 *             this function is unspecified for the value 0
 * @return     A unique pointer with at least the specified size
 *             and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evalloc(size_t __n)
{ return libsimple_envalloc(libsimple_default_failure_exit, __n); }
#ifndef evalloc
# define evalloc libsimple_evalloc
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
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
 *              and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evvallocn(size_t __n, va_list __ap)
{ return libsimple_envvallocn(libsimple_default_failure_exit, __n, __ap); }
#ifndef evvallocn
# define evvallocn libsimple_evvallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
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
 *               and with page size alignment
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_evallocn(size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evvallocn(__n, __ap);
	va_end(__ap);
}
#ifndef evallocn
# define evallocn libsimple_evallocn
#endif
