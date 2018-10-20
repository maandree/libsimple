/* See LICENSE file for copyright and license details. */


/**
 * Finds the first occurence of a byte value in an array of bytes
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if is no occurence
 * of the specified byte value in the specified byte array, this
 * behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @return     `s` with a miminal offset such that `*s == c`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
void *libsimple_rawmemchr(const void *, int);
#ifndef rawmemchr
# define rawmemchr libsimple_rawmemchr
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `*s == c`,
 *             `NULL` if no such offset exists within [0, n)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
void *libsimple_memrchr(const void *, int, size_t);
#ifndef memrchr
# define memrchr libsimple_memrchr
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if is no occurence
 * of the specified byte value in the specified byte array, this
 * behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `*s == c`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrchr(const void *, int, size_t);
#ifndef rawmemrchr
# define rawmemrchr libsimple_rawmemrchr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memmem(const void *, size_t, const void *, size_t);
#ifndef memmem
# define memmem libsimple_memmem
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrmem(const void *, size_t, const void *, size_t);
#ifndef memrmem
# define memrmem libsimple_memrmem
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memstarts(const void *, size_t, const void *, size_t);
#ifndef memstarts
# define memstarts libsimple_memstarts
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memends(const void *, size_t, const void *, size_t);
#ifndef memends
# define memends libsimple_memends
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_memeq(const void *__s1, const void *__s2, size_t __n)
{ return !memcmp(__s1, __s2, __n); }
#ifndef memeq
# define memeq libsimple_memeq
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *libsimple_mempcpy(void *__d, const void *__s, size_t __n)
{ return &((char *)memcpy(__d, __s, __n))[__n]; }
#ifndef mempcpy
# define mempcpy libsimple_mempcpy
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *libsimple_mempset(void *__s, int __c, size_t __n)
{ return &((char *)memset(__s, __c, __n))[__n]; }
#ifndef mempset
# define mempset libsimple_mempset
#endif
