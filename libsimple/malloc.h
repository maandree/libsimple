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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_vmallocn(size_t n__, va_list ap__)
{
	return libsimple_vmalloczn(0, n__, ap__);
}
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_mallocn(size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vmalloczn(0, n__, ap__);
	va_end(ap__);
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
 */
#ifndef LIBSIMPLE_DEFINED_LIBSIMPLE_ENMALLOC__
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmalloc(int, size_t);
# define LIBSIMPLE_DEFINED_LIBSIMPLE_ENMALLOC__
#endif
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_envmallocn(int status__, size_t n__, va_list ap__)
{
	return libsimple_envmalloczn(status__, 0, n__, ap__);
}
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmallocn(int status__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envmallocn(status__, n__, ap__);
	va_end(ap__);
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __alloc_size__(1), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_emalloc(size_t n__)
{
	return libsimple_enmalloc(libsimple_default_failure_exit, n__);
}
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_evmallocn(size_t n__, va_list ap__)
{
	return libsimple_envmallocn(libsimple_default_failure_exit, n__, ap__);
}
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_emallocn(size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evmallocn(n__, ap__);
	va_end(ap__);
}
#ifndef emallocn
# define emallocn libsimple_emallocn
#endif
