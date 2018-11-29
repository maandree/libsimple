/* See LICENSE file for copyright and license details. */


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size; `NULL` on failure
 * @throws  EINVAL     `n` is 0
 * @throws  EINVAL     `alignment` is not a valid alignment
 * @throws  ENOMEM     Could not allocated enough memory
 * @throws  ENOSYS     Not implemented (requires non-standard libc functions)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __alloc_size__(3), __warn_unused_result__)))
#if defined(__GLIBC__)
# define LIBSIMPLE_HAVE_ALIGNED_REALLOC
# include <malloc.h>
static inline void *
libsimple_aligned_realloc(void *__ptr, size_t __alignment, size_t __n) /* TODO test, musl */
{
	size_t __old = malloc_usable_size(__ptr);
#if __STDC_VERSION__ >= 201112L || defined(_ISOC11_SOURCE)
	size_t __extra = (__alignment - __n % __alignment) % __alignment;
	void *__new = aligned_alloc(__alignment, __n + __extra);
#else
	void *__new = memalign(__alignment, __n);
#endif
	if (__new) {
		memcpy(__new, __ptr, __old < __n ? __old : __n);
		free(__ptr);
	}
	return __new;
}
#else
static inline void *
libsimple_aligned_realloc(void *__ptr, size_t __alignment, size_t __n)
{
	(void) __ptr;
	(void) __alignment;
	(void) __n;
	errno = ENOSYS;
	return NULL;
}
#endif
#ifndef aligned_realloc
# define aligned_realloc libsimple_aligned_realloc
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enaligned_realloc(int, void *, size_t, size_t);
#ifndef enaligned_realloc
# define enaligned_realloc libsimple_enaligned_realloc
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ealigned_realloc(void *__ptr, size_t __alignment, size_t __n)
{ return libsimple_enaligned_realloc(libsimple_default_failure_exit, __ptr, __alignment, __n); }
#ifndef ealigned_realloc
# define ealigned_realloc libsimple_ealigned_realloc
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is deallocated. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * The allocation size will be at least `n * m`
 * 
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          The number of bytes to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size; `NULL` on failure
 * @throws  EINVAL     `n` is 0
 * @throws  EINVAL     `alignment` is not a valid alignment
 * @throws  ENOMEM     Could not allocated enough memory
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __alloc_size__(3), __warn_unused_result__)))
static inline void *
libsimple_aligned_reallocf(void *__ptr, size_t __alignment, size_t __n) /* TODO test */
{
	void *__new = __n ? libsimple_aligned_realloc(__ptr, __alignment, __n) : NULL;
	if (!__new)
		free(__ptr);
	return NULL;
}
#ifndef aligned_reallocf
# define aligned_reallocf libsimple_aligned_reallocf
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is still valid. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * The allocation size will be at least `n * m`
 * 
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          The number of elements to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @param   m          Size, in bytes, of each element, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size; `NULL` on failure
 * @throws  EINVAL     `n` or `m` is 0
 * @throws  EINVAL     `alignment` is not a valid alignment
 * @throws  ENOMEM     Could not allocated enough memory
 * @throws  ENOSYS     Not implemented (requires non-standard libc functions)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __alloc_size__(3, 4), __warn_unused_result__)))
static inline void *
libsimple_aligned_reallocarray(void *__ptr, size_t __alignment, size_t __n, size_t __m) /* TODO test */
{
	if (LIBSIMPLE_UMUL_OVERFLOW(__n, __m, &__n, SIZE_MAX)) {
		errno = ENOMEM;
		return NULL;
	}
	return libsimple_aligned_realloc(__ptr, __alignment, __n);
}
#ifndef aligned_reallocarray
# define aligned_reallocarray libsimple_aligned_reallocarray
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          The number of elements to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @param   m          Size, in bytes, of each element, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(3), __alloc_size__(4, 5), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_enaligned_reallocarray(int, void *, size_t, size_t, size_t);
#ifndef enaligned_reallocarray
# define enaligned_reallocarray libsimple_enaligned_reallocarray
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          The number of elements to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @param   m          Size, in bytes, of each element, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __alloc_size__(3, 4), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ealigned_reallocarray(void *__ptr, size_t __alignment, size_t __n, size_t __m)
{ return libsimple_enaligned_reallocarray(libsimple_default_failure_exit, __ptr, __alignment, __n, __m); }
#ifndef ealigned_reallocarray
# define ealigned_reallocarray libsimple_ealigned_reallocarray
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
 * 
 * On success, either `ptr` is returned, or a new non-null
 * pointer is returned with the same content (truncated to
 * `n` bytes if size shrunk), in which case `ptr` is
 * deallocated. On failure `ptr` is deallocated. If `ptr`
 * is `NULL` a new allocation is made.
 * 
 * The allocation size will be at least `n * m`
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          The number of elements to allocate, the behaviour of
 *                     this function is unspecified for the value 0
 * @param   m          Size, in bytes, of each element, the behaviour of
 *                     this function is unspecified for the value 0
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size; `NULL` on failure
 * @throws  EINVAL     `n` or `m` is 0
 * @throws  EINVAL     `alignment` is not a valid alignment
 * @throws  ENOMEM     Could not allocated enough memory
 * @throws  ENOSYS     Not implemented (requires non-standard libc functions)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __alloc_size__(3, 4), __warn_unused_result__)))
static inline void *
libsimple_aligned_reallocarrayf(void *__ptr, size_t __alignment, size_t __n, size_t __m) /* TODO test */
{
	void *__new = (__n && __m) ? libsimple_aligned_reallocarray(__ptr, __alignment, __n, __m) : NULL;
	if (!__new)
		free(__ptr);
	return NULL;
}
#ifndef aligned_reallocarrayf
# define aligned_reallocarrayf libsimple_aligned_reallocarrayf
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size; `NULL` on failure
 * @throws  EINVAL     `n` is 0
 * @throws  EINVAL     `alignment` is not a valid alignment
 * @throws  ENOMEM     Could not allocated enough memory
 * @throws  ENOSYS     Not implemented (requires non-standard libc functions)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __warn_unused_result__)))
void *libsimple_valigned_reallocn(void *, size_t, size_t, va_list);
#ifndef valigned_reallocn
# define valigned_reallocn libsimple_valigned_reallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
void *libsimple_envaligned_reallocn(int, void *, size_t, size_t, va_list);
#ifndef envaligned_reallocn
# define envaligned_reallocn libsimple_envaligned_reallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evaligned_reallocn(void *__ptr, size_t __alignment, size_t __n, va_list __ap)
{ return libsimple_envaligned_reallocn(libsimple_default_failure_exit, __ptr, __alignment, __n, __ap); }
#ifndef evaligned_reallocn
# define evaligned_reallocn libsimple_evaligned_reallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ap         The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size; `NULL` on failure
 * @throws  EINVAL     `n` is 0
 * @throws  EINVAL     `alignment` is not a valid alignment
 * @throws  ENOMEM     Could not allocated enough memory
 * @throws  ENOSYS     Not implemented (requires non-standard libc functions)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_valigned_reallocfn(void *__ptr, size_t __alignment, size_t __n, va_list __ap) /* TODO test (aligned_reallocfn) */
{
	void *__new = libsimple_valigned_reallocn(__ptr, __alignment, __n, __ap);
	if (!__new)
		free(__ptr);
	return __new;
}
#ifndef valigned_reallocfn
# define valigned_reallocfn libsimple_aligned_reallocnf
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size; `NULL` on failure
 * @throws  EINVAL     `n` is 0
 * @throws  EINVAL     `alignment` is not a valid alignment
 * @throws  ENOMEM     Could not allocated enough memory
 * @throws  ENOSYS     Not implemented (requires non-standard libc functions)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_aligned_reallocn(void *__ptr, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_valigned_reallocn(__ptr, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef aligned_reallocn
# define aligned_reallocn libsimple_aligned_reallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   status     The exit value for the process in case of failure
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enaligned_reallocn(int __status, void *__ptr, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envaligned_reallocn(__status, __ptr, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef enaligned_reallocn
# define enaligned_reallocn libsimple_enaligned_reallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ealigned_reallocn(void *__ptr, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evaligned_reallocn(__ptr, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef ealigned_reallocn
# define ealigned_reallocn libsimple_ealigned_reallocn
#endif


/**
 * Dynamically reallocates heap allocated, uninitialised,
 * memory with custom alignment as the new alignment
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
 * This function may not be supported, check for the
 * existance of the macro `LIBSIMPLE_HAVE_ALIGNED_REALLOC`
 * to determine if it is supported
 * 
 * @param   ptr        Pointer to reallocated, `NULL` for a new allocation
 * @param   alignment  The alignment of the new pointer
 * @param   n          First factor for the allocation size, must not be 0
 * @param   ...        The rest of the factors for the allocation size,
 *                     all arguments should have the type `size_t`, and
 *                     list must end with 0 (which is not factor)
 * @return             Either `ptr` or a unique pointer with at least
 *                     the specified size; `NULL` on failure
 * @throws  EINVAL     `n` is 0
 * @throws  EINVAL     `alignment` is not a valid alignment
 * @throws  ENOMEM     Could not allocated enough memory
 * @throws  ENOSYS     Not implemented (requires non-standard libc functions)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__alloc_align__(2), __warn_unused_result__)))
static inline void *
libsimple_aligned_reallocfn(void *__ptr, size_t __alignment, size_t __n, ... /*, (size_t)0 */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_valigned_reallocfn(__ptr, __alignment, __n, __ap);
	va_end(__ap);
}
#ifndef aligned_reallocfn
# define aligned_reallocfn libsimple_aligned_reallocfn
#endif
