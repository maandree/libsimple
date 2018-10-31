/* See LICENSE file for copyright and license details. */


/* Properly declared elsewhere { */

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2, 3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_encalloc(int, size_t, size_t);

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmalloc(int, size_t);

/* } */


/**
 * Dynamically allocates heap allocated, optinally initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * @param   clear   Non-zero if the memory should be initialised
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
void *libsimple_vmalloczn(int, size_t, va_list);
#ifndef vmalloczn
# define vmalloczn libsimple_vmalloczn
#endif


/**
 * Dynamically allocates heap allocated, optinally initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       Th number of bytes to allocate
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`;
 *                  `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__)))
static inline void *libsimple_mallocz(int __clear, size_t __n)
{ return __clear ? calloc(1, __n) : malloc(__n); }
#ifndef mallocz
# define mallocz libsimple_mallocz
#endif


/**
 * Dynamically allocates heap allocated, optinally initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments except `clear`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * @param   clear   Non-zero if the memory should be initialised
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
libsimple_malloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef malloczn
# define malloczn libsimple_malloczn
#endif


/**
 * Dynamically allocates heap allocated, optinally initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       Th number of bytes to allocate
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_enmallocz(int __status, int __clear, size_t __n)
{ return __clear ? libsimple_encalloc(__status, 1, __n) : libsimple_enmalloc(__status, __n); }
#ifndef enmallocz
# define enmallocz libsimple_enmallocz
#endif


/**
 * Dynamically allocates heap allocated, optinally initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments except `clear` and `status`,
 * up to the first 0, will be used as the number of bytes to
 * allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
void *libsimple_envmalloczn(int, int, size_t, va_list);
#ifndef envmalloczn
# define envmalloczn libsimple_envmalloczn
#endif


/**
 * Dynamically allocates heap allocated, optinally initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments except `clear` and `status`,
 * up to the first 0, will be used as the number of bytes to
 * allocated
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   clear   Non-zero if the memory should be initialised
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          A unique pointer with at least the specified size
 *                  and with the alignment `alignof(max_align_t)`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmalloczn(int __status, int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(__status, __clear, __n, __ap);
	va_end(__ap);
}
#ifndef enmalloczn
# define enmalloczn libsimple_enmalloczn
#endif


/**
 * Dynamically allocates heap allocated, optinally initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear  Non-zero if the memory should be initialised
 * @param   n      Th number of bytes to allocate
 * @return         A unique pointer with at least the specified size
 *                 and with the alignment `alignof(max_align_t)`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_emallocz(int __clear, size_t __n)
{ return libsimple_enmallocz(libsimple_default_failure_exit, __clear, __n); }
#ifndef emallocz
# define emallocz libsimple_emallocz
#endif


/**
 * Dynamically allocates heap allocated, optinally initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments except `clear`, up to the
 * first 0 will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear  Non-zero if the memory should be initialised
 * @param   n      First factor for the allocation size, must not be 0
 * @param   ap     The rest of the factors for the allocation size,
 *                 all arguments should have the type `size_t`, and
 *                 list must end with 0 (which is not factor)
 * @return         A unique pointer with at least the specified size
 *                 and with the alignment `alignof(max_align_t)`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmalloczn(int __clear, size_t __n, va_list __ap)
{ return libsimple_envmalloczn(libsimple_default_failure_exit, __clear, __n, __ap); }
#ifndef evmalloczn
# define evmalloczn libsimple_evmalloczn
#endif


/**
 * Dynamically allocates heap allocated, optinally initialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * 
 * The product of all arguments except `clear` up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   clear  Non-zero if the memory should be initialised
 * @param   n      First factor for the allocation size, must not be 0
 * @param   ...    The rest of the factors for the allocation size,
 *                 all arguments should have the type `size_t`, and
 *                 list must end with 0 (which is not factor)
 * @return         A unique pointer with at least the specified size
 *                 and with the alignment `alignof(max_align_t)`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_emalloczn(int __clear, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evmalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef emalloczn
# define emalloczn libsimple_emalloczn
#endif
