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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_vcallocn(size_t n__, va_list ap__)
{
	return libsimple_vmalloczn(1, n__, ap__);
}
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_callocn(size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vmalloczn(1, n__, ap__);
	va_end(ap__);
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
 *                  and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
#ifndef LIBSIMPLE_DEFINED_LIBSIMPLE_ENCALLOC__
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(2, 3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_encalloc(int, size_t, size_t);
# define LIBSIMPLE_DEFINED_LIBSIMPLE_ENCALLOC__
#endif
#ifndef encalloc
# define encalloc libsimple_encalloc
#endif


/**
 * Dynamically allocates heap allocated, initialised,
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_envcallocn(int status__, size_t n__, va_list ap__)
{
	return libsimple_envmalloczn(status__, 1, n__, ap__);
}
#ifndef envcallocn
# define envcallocn libsimple_envcallocn
#endif


/**
 * Dynamically allocates heap allocated, initialised,
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_encallocn(int status__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envcallocn(status__, n__, ap__);
	va_end(ap__);
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
 *             and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(1, 2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ecalloc(size_t n__, size_t m__)
{
	return encalloc(libsimple_default_failure_exit, n__, m__);
}
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
 * @param   n   First factor for the allocation size, must not be 0
 * @param   ap  The rest of the factors for the allocation size,
 *              all arguments should have the type `size_t`, and
 *              list must end with 0 (which is not factor)
 * @return      A unique pointer with at least the specified size
 *              and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evcallocn(size_t n__, va_list ap__)
{
	return libsimple_envcallocn(libsimple_default_failure_exit, n__, ap__);
}
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
 * @param   n    First factor for the allocation size, must not be 0
 * @param   ...  The rest of the factors for the allocation size,
 *               all arguments should have the type `size_t`, and
 *               list must end with 0 (which is not factor)
 * @return       A unique pointer with at least the specified size
 *               and with the alignment `alignof(max_align_t)`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ecallocn(size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evcallocn(n__, ap__);
	va_end(ap__);
}
#ifndef ecallocn
# define ecallocn libsimple_ecallocn
#endif
