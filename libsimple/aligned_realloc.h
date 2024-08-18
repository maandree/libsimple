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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __alloc_size__(3), __warn_unused_result__)))
#if defined(__GLIBC__)
# define LIBSIMPLE_HAVE_ALIGNED_REALLOC
# include <malloc.h>
inline void *
libsimple_aligned_realloc(void *ptr__, size_t alignment__, size_t n__) /* TODO musl */
{
	size_t old__ = malloc_usable_size(ptr__);
#if __STDC_VERSION__ >= 201112L || defined(_ISOC11_SOURCE)
	size_t extra__ = (alignment__ - n__ % alignment__) % alignment__;
	void *new__ = aligned_alloc(alignment__, n__ + extra__);
#else
	void *new__ = memalign(alignment__, n__);
#endif
	if (new__) {
		memcpy(new__, ptr__, old__ < n__ ? old__ : n__);
		free(ptr__);
	}
	return new__;
}
#else
inline void *
libsimple_aligned_realloc(void *ptr__, size_t alignment__, size_t n__)
{
	(void) ptr__;
	(void) alignment__;
	(void) n__;
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(3), __alloc_size__(4), __warn_unused_result__, __returns_nonnull__)))
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __alloc_size__(3), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ealigned_realloc(void *ptr__, size_t alignment__, size_t n__)
{
	return libsimple_enaligned_realloc(libsimple_default_failure_exit, ptr__, alignment__, n__);
}
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __alloc_size__(3), __warn_unused_result__)))
inline void *
libsimple_aligned_reallocf(void *ptr__, size_t alignment__, size_t n__)
{
	void *new__ = n__ ? libsimple_aligned_realloc(ptr__, alignment__, n__) : NULL;
	if (!new__)
		free(ptr__);
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __alloc_size__(3, 4), __warn_unused_result__)))
inline void *
libsimple_aligned_reallocarray(void *ptr__, size_t alignment__, size_t n__, size_t m__)
{
	if (LIBSIMPLE_UMUL_OVERFLOW(n__, m__, &n__, SIZE_MAX)) {
		errno = ENOMEM;
		return NULL;
	}
	return libsimple_aligned_realloc(ptr__, alignment__, n__);
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(3), __alloc_size__(4, 5), __warn_unused_result__, __returns_nonnull__)))
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __alloc_size__(3, 4), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ealigned_reallocarray(void *ptr__, size_t alignment__, size_t n__, size_t m__)
{
	return libsimple_enaligned_reallocarray(libsimple_default_failure_exit, ptr__, alignment__, n__, m__);
}
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __alloc_size__(3, 4), __warn_unused_result__)))
inline void *
libsimple_aligned_reallocarrayf(void *ptr__, size_t alignment__, size_t n__, size_t m__)
{
	void *new__ = (n__ && m__) ? libsimple_aligned_reallocarray(ptr__, alignment__, n__, m__) : NULL;
	if (!new__)
		free(ptr__);
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __warn_unused_result__)))
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_evaligned_reallocn(void *ptr__, size_t alignment__, size_t n__, va_list ap__)
{
	return libsimple_envaligned_reallocn(libsimple_default_failure_exit, ptr__, alignment__, n__, ap__);
}
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __warn_unused_result__)))
inline void *
libsimple_valigned_reallocfn(void *ptr__, size_t alignment__, size_t n__, va_list ap__)
{
	void *new__ = libsimple_valigned_reallocn(ptr__, alignment__, n__, ap__);
	if (!new__)
		free(ptr__);
	return new__;
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __warn_unused_result__)))
inline void *
libsimple_aligned_reallocn(void *ptr__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_valigned_reallocn(ptr__, alignment__, n__, ap__);
	va_end(ap__);
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(3), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_enaligned_reallocn(int status__, void *ptr__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envaligned_reallocn(status__, ptr__, alignment__, n__, ap__);
	va_end(ap__);
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __warn_unused_result__, __returns_nonnull__)))
inline void *
libsimple_ealigned_reallocn(void *ptr__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evaligned_reallocn(ptr__, alignment__, n__, ap__);
	va_end(ap__);
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
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__alloc_align__(2), __warn_unused_result__)))
inline void *
libsimple_aligned_reallocfn(void *ptr__, size_t alignment__, size_t n__, ... /*, (size_t)0 */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_valigned_reallocfn(ptr__, alignment__, n__, ap__);
	va_end(ap__);
}
#ifndef aligned_reallocfn
# define aligned_reallocfn libsimple_aligned_reallocfn
#endif
