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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_vvallocn(size_t n__, va_list ap__)
{
	return libsimple_vvalloczn(0, n__, ap__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(1), __warn_unused_result__)))
inline void *
libsimple_valloc(size_t n__)
{
	return libsimple_vallocz(0, n__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_vallocn(size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vvallocn(n__, ap__);
	va_end(ap__);
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_envalloc(int status__, size_t n__)
{
	return libsimple_envallocz(status__, 0, n__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_envvallocn(int status__, size_t n__, va_list ap__)
{
	return libsimple_envvalloczn(status__, 0, n__, ap__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_envallocn(int status__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envvalloczn(status__, 0, n__, ap__);
	va_end(ap__);
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(1), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evalloc(size_t n__)
{
	return libsimple_envalloc(libsimple_default_failure_exit, n__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evvallocn(size_t n__, va_list ap__)
{
	return libsimple_envvallocn(libsimple_default_failure_exit, n__, ap__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evallocn(size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evvallocn(n__, ap__);
	va_end(ap__);
}
#ifndef evallocn
# define evallocn libsimple_evallocn
#endif
