/* See LICENSE file for copyright and license details. */


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_vpvallocn(size_t n__, va_list ap__)
{
	return libsimple_vpvalloczn(0, n__, ap__);
}
#ifndef vpvallocn
# define vpvallocn libsimple_vpvallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * @param   n       The number of bytes to allocate
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_pvalloc(size_t n__)
{
	return libsimple_pvallocz(0, n__);
}
#ifndef pvalloc
# define pvalloc libsimple_pvalloc
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_pvallocn(size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vpvallocn(n__, ap__);
	va_end(ap__);
}
#ifndef pvallocn
# define pvallocn libsimple_pvallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   n       The number of bytes to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_enpvalloc(int status__, size_t n__)
{
	return libsimple_enpvallocz(status__, 0, n__);
}
#ifndef enpvalloc
# define enpvalloc libsimple_enpvalloc
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The product of all arguments except `status`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
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
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_envpvallocn(int status__, size_t n__, va_list ap__)
{
	return libsimple_envpvalloczn(status__, 0, n__, ap__);
}
#ifndef envpvallocn
# define envpvallocn libsimple_envpvallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The product of all arguments except `status`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
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
 * @return          A unique pointer with at least the specified size,
 *                  rounded up to the next multiple of the page size,
 *                  and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_enpvallocn(int status__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envpvalloczn(status__, 0, n__, ap__);
	va_end(ap__);
}
#ifndef enpvallocn
# define enpvallocn libsimple_enpvallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   n  The number of bytes to allocate, the behaviour of
 *             this function is unspecified for the value 0
 * @return     A unique pointer with at least the specified size,
 *             rounded up to the next multiple of the page size,
 *             and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_epvalloc(size_t n__)
{
	return libsimple_enpvalloc(libsimple_default_failure_exit, n__);
}
#ifndef epvalloc
# define epvalloc libsimple_epvalloc
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   n   First factor for the allocation size, must not be 0
 * @param   ap  The rest of the factors for the allocation size,
 *              all arguments should have the type `size_t`, and
 *              list must end with 0 (which is not factor)
 * @return      A unique pointer with at least the specified size,
 *              rounded up to the next multiple of the page size,
 *              and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evpvallocn(size_t n__, va_list ap__)
{
	return libsimple_envpvallocn(libsimple_default_failure_exit, n__, ap__);
}
#ifndef evpvallocn
# define evpvallocn libsimple_evpvallocn
#endif


/**
 * Dynamically allocates heap allocated, uninitialised,
 * memory with page size alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * The allocation size is rounded up to the next multiple
 * of the page size (the alignment)
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   n    First factor for the allocation size, must not be 0
 * @param   ...  The rest of the factors for the allocation size,
 *               all arguments should have the type `size_t`, and
 *               list must end with 0 (which is not factor)
 * @return       A unique pointer with at least the specified size,
 *               rounded up to the next multiple of the page size,
 *               and with page size alignment
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_epvallocn(size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evpvallocn(n__, ap__);
	va_end(ap__);
}
#ifndef epvallocn
# define epvallocn libsimple_epvallocn
#endif
