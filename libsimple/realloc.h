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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *
libsimple_reallocn(void *__ptr, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vreallocn(__ptr, __n, __ap);
	va_end(__ap);
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enreallocn(int __status, void *__ptr, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envreallocn(__status, __ptr, __n, __ap);
	va_end(__ap);
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_erealloc(void *__ptr, size_t __n)
{ return libsimple_enrealloc(libsimple_default_failure_exit, __ptr, __n); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evreallocn(void *__ptr, size_t __n, va_list __ap)
{ return libsimple_envreallocn(libsimple_default_failure_exit, __ptr, __n, __ap); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ereallocn(void *__ptr, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evreallocn(__ptr, __n, __ap);
	va_end(__ap);
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2), __warn_unused_result__)))
static inline void *
libsimple_reallocf(void *__ptr, size_t __n) /* TODO test */
{
	void *__new = __n ? realloc(__ptr, __n) : NULL;
	if (!__new)
		free(__ptr);
	return __new;
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2, 3), __warn_unused_result__)))
static inline void *
libsimple_reallocarray(void *__ptr, size_t __n, size_t __m) /* TODO test */
{
	if (LIBSIMPLE_UMUL_OVERFLOW(__n, __m, &__n, SIZE_MAX)) {
		errno = ENOMEM;
		return NULL;
	}
	return realloc(__ptr, __n);
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(3, 4), __warn_unused_result__, __returns_nonnull__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2, 3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ereallocarray(void *__ptr, size_t __n, size_t __m) /* TODO test */
{ return libsimple_enreallocarray(libsimple_default_failure_exit, __ptr, __n, __m); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_size__(2, 3), __warn_unused_result__)))
static inline void *
libsimple_reallocarrayf(void *__ptr, size_t __n, size_t __m) /* TODO test */
{
	void *__new = __n ? libsimple_reallocarray(__ptr, __n, __m) : NULL;
	if (!__new)
		free(__ptr);
	return __new;
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *
libsimple_vreallocfn(void *__ptr, size_t __n, va_list __ap) /* TODO test (reallocfn) */
{
	void *__new = libsimple_vreallocn(__ptr, __n, __ap);
	if (!__new)
		free(__ptr);
	return __new;
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *
libsimple_reallocfn(void *__ptr, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vreallocfn(__ptr, __n, __ap);
	va_end(__ap);
}
#ifndef reallocfn
# define reallocfn libsimple_reallocfn
#endif
