/* See LICENSE file for copyright and license details. */


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__)))
void *libsimple_vreallocn(void *, size_t, va_list);
#ifndef vreallocn
# define vreallocn libsimple_vreallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__)))
inline void *
libsimple_reallocn(void *ptr__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vreallocn(ptr__, n__, ap__);
	va_end(ap__);
}
#ifndef reallocn
# define reallocn libsimple_reallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       The number of bytes to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enrealloc(int, void *, size_t);
#ifndef enrealloc
# define enrealloc libsimple_enrealloc
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * The product of all arguments except `status`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__, __returns_nonnull__)))
void *libsimple_envreallocn(int, void *, size_t, va_list);
#ifndef envreallocn
# define envreallocn libsimple_envreallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * The product of all arguments except `status`, up to the
 * first 0, will be used as the number of bytes to allocated
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param   status  The exit value for the process in case of failure
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_enreallocn(int status__, void *ptr__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envreallocn(status__, ptr__, n__, ap__);
	va_end(ap__);
}
#ifndef enreallocn
# define enreallocn libsimple_enreallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   ptr  Pointer to reallocated, `NULL` for a new allocation
 * @param   n    The number of bytes to allocate, the behaviour of
 *               this function is unspecified for the value 0
 * @return       Either `ptr` or a unique pointer with at least
 *               the specified size and with the alignment
 *               `alignof(max_align_t)`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_erealloc(void *ptr__, size_t n__)
{
	return libsimple_enrealloc(libsimple_default_failure_exit, ptr__, n__);
}
#ifndef erealloc
# define erealloc libsimple_erealloc
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   ptr  Pointer to reallocated, `NULL` for a new allocation
 * @param   n    First factor for the allocation size, must not be 0
 * @param   ap   The rest of the factors for the allocation size,
 *               all arguments should have the type `size_t`, and
 *               list must end with 0 (which is not factor)
 * @return       Either `ptr` or a unique pointer with at least
 *               the specified size and with the alignment
 *               `alignof(max_align_t)`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evreallocn(void *ptr__, size_t n__, va_list ap__)
{
	return libsimple_envreallocn(libsimple_default_failure_exit, ptr__, n__, ap__);
}
#ifndef evreallocn
# define evreallocn libsimple_evreallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param   ptr  Pointer to reallocated, `NULL` for a new allocation
 * @param   n    First factor for the allocation size, must not be 0
 * @param   ...  The rest of the factors for the allocation size,
 *               all arguments should have the type `size_t`, and
 *               list must end with 0 (which is not factor)
 * @return       Either `ptr` or a unique pointer with at least
 *               the specified size and with the alignment
 *               `alignof(max_align_t)`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ereallocn(void *ptr__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evreallocn(ptr__, n__, ap__);
	va_end(ap__);
}
#ifndef ereallocn
# define ereallocn libsimple_ereallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is deallocated. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * The allocation size will be at least `n * m`
 * 
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       The number of bytes to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(2), __warn_unused_result__)))
inline void *
libsimple_reallocf(void *ptr__, size_t n__)
{
	void *new__ = n__ ? realloc(ptr__, n__) : NULL;
	if (!new__)
		free(ptr__);
	return new__;
}
#ifndef reallocf
# define reallocf libsimple_reallocf
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * The allocation size will be at least `n * m`
 * 
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       The number of elements to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @param   m       Size, in bytes, of each element, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`; `NULL` on failure
 * @throws  EINVAL  `n` or `m` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(2, 3), __warn_unused_result__)))
inline void *
libsimple_reallocarray(void *ptr__, size_t n__, size_t m__)
{
	if (LIBSIMPLE_UMUL_OVERFLOW(n__, m__, &n__, SIZE_MAX)) {
		errno = ENOMEM;
		return NULL;
	}
	return realloc(ptr__, n__);
}
#ifndef reallocarray
# define reallocarray libsimple_reallocarray
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * The allocation size will be at least `n * m`
 * 
 * @param   ptr  Pointer to reallocated, `NULL` for a new allocation
 * @param   n    The number of elements to allocate, the behaviour of
 *               this function is unspecified for the value 0
 * @param   m    Size, in bytes, of each element, the behaviour of
 *               this function is unspecified for the value 0
 * @return       Either `ptr` or a unique pointer with at least
 *               the specified size and with the alignment
 *               `alignof(max_align_t)`
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(3, 4), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enreallocarray(int, void *, size_t, size_t);
#ifndef enreallocarray
# define enreallocarray libsimple_enreallocarray
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * The allocation size will be at least `n * m`
 * 
 * @param   ptr  Pointer to reallocated, `NULL` for a new allocation
 * @param   n    The number of elements to allocate, the behaviour of
 *               this function is unspecified for the value 0
 * @param   m    Size, in bytes, of each element, the behaviour of
 *               this function is unspecified for the value 0
 * @return       Either `ptr` or a unique pointer with at least
 *               the specified size and with the alignment
 *               `alignof(max_align_t)`
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(2, 3), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ereallocarray(void *ptr__, size_t n__, size_t m__)
{
	return libsimple_enreallocarray(libsimple_default_failure_exit, ptr__, n__, m__);
}
#ifndef ereallocarray
# define ereallocarray libsimple_ereallocarray
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is deallocated. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * The allocation size will be at least `n * m`
 * 
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       The number of elements to allocate, the behaviour of
 *                  this function is unspecified for the value 0
 * @param   m       Size, in bytes, of each element, the behaviour of
 *                  this function is unspecified for the value 0
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`; `NULL` on failure
 * @throws  EINVAL  `n` or `m` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_size__(2, 3), __warn_unused_result__)))
inline void *
libsimple_reallocarrayf(void *ptr__, size_t n__, size_t m__)
{
	void *new__ = n__ ? libsimple_reallocarray(ptr__, n__, m__) : NULL;
	if (!new__)
		free(ptr__);
	return new__;
}
#ifndef reallocarrayf
# define reallocarrayf libsimple_reallocarrayf
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is deallocated. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ap      The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__)))
inline void *
libsimple_vreallocfn(void *ptr__, size_t n__, va_list ap__)
{
	void *new__ = libsimple_vreallocn(ptr__, n__, ap__);
	if (!new__)
		free(ptr__);
	return new__;
}
#ifndef vreallocfn
# define vreallocfn libsimple_vreallocfn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with default alignment (`alignof(max_align_t)`)
 * as the new alignment
 * 
 * The product of all arguments, up to the first 0,
 * will be used as the number of bytes to allocated
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is deallocated. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * @param   ptr     Pointer to reallocated, `NULL` for a new allocation
 * @param   n       First factor for the allocation size, must not be 0
 * @param   ...     The rest of the factors for the allocation size,
 *                  all arguments should have the type `size_t`, and
 *                  list must end with 0 (which is not factor)
 * @return          Either `ptr` or a unique pointer with at least
 *                  the specified size and with the alignment
 *                  `alignof(max_align_t)`; `NULL` on failure
 * @throws  EINVAL  `n` is 0
 * @throws  ENOMEM  Could not allocated enough memory
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__)))
inline void *
libsimple_reallocfn(void *ptr__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vreallocfn(ptr__, n__, ap__);
	va_end(ap__);
}
#ifndef reallocfn
# define reallocfn libsimple_reallocfn
#endif
