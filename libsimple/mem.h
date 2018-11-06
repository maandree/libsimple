/* See LICENSE file for copyright and license details. */


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * the comparison is case-insensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer `NULL` if no
 *             such offset exists within [s, &s[n])
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
void *libsimple_memcasechr(const void *, int, size_t);
#ifndef memcasechr
# define memcasechr libsimple_memcasechr
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if is no occurence
 * of the specified byte value in the specified byte array, this
 * behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @return     `s` with a miminal offset such that `*r == c`,
 *             where `r` is the returned pointer
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemchr(const void *, int);
#ifndef rawmemchr
# define rawmemchr libsimple_rawmemchr
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * the comparison is case-insensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if is no occurence
 * of the specified byte value in the specified byte array, this
 * behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @return     `s` with a miminal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemcasechr(const void *, int);
#ifndef rawmemcasechr
# define rawmemcasechr libsimple_rawmemcasechr
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * the comparison is case-sensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `*r == c`,
 *             where `r` is the returned pointer `NULL` if no
 *             such offset exists within [s, &s[n])
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
void *libsimple_memrchr(const void *, int, size_t);
#ifndef memrchr
# define memrchr libsimple_memrchr
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * the comparison is case-insensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer `NULL` if no
 *             such offset exists within [s, &s[n])
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
void *libsimple_memrcasechr(const void *, int, size_t);
#ifndef memrcasechr
# define memrcasechr libsimple_memrcasechr
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if is no occurence
 * of the specified byte value in the specified byte array, this
 * behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `*r == c`,
 *             where `r` is the returned pointer
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrchr(const void *, int, size_t);
#ifndef rawmemrchr
# define rawmemrchr libsimple_rawmemrchr
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * the comparison is case-insensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if is no occurence
 * of the specified byte value in the specified byte array, this
 * behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrcasechr(const void *, int, size_t);
#ifndef rawmemrcasechr
# define rawmemrcasechr libsimple_rawmemrcasechr
#endif


/**
 * Finds the first substring in an array of bytes, the comparison is case-sensitive
 * 
 * @param   haystack   The array of bytes to search
 * @param   nhaystack  The length of `haystack`
 * @param   needle     The substring to search for
 * @param   nneedle    The length of `needle`
 * @return             `haystack` with a minimal offset such that,
 *                     `!memcmp(r, needle, nneedle)` where `r` is the
 *                     returned pointer, `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memmem(const void *, size_t, const void *, size_t);
#ifndef memmem
# define memmem libsimple_memmem
#endif


/**
 * Finds the first substring in an array of bytes, the comparison is case-insensitive
 * 
 * @param   haystack   The array of bytes to search
 * @param   nhaystack  The length of `haystack`
 * @param   needle     The substring to search for
 * @param   nneedle    The length of `needle`
 * @return             `haystack` with a minimal offset such that,
 *                     `!memcasecmp(r, needle, nneedle)` where `r` is the
 *                     returned pointer, `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memcasemem(const void *, size_t, const void *, size_t);
#ifndef memcasemem
# define memcasemem libsimple_memcasemem
#endif


/**
 * Finds the last substring in an array of bytes, the comparison is case-sensitive
 * 
 * @param   haystack   The array of bytes to search
 * @param   nhaystack  The length of `haystack`
 * @param   needle     The substring to search for
 * @param   nneedle    The length of `needle`
 * @return             `haystack` with a maximal offset such that,
 *                     `!memcmp(r, needle, nneedle)` where `r` is the
 *                     returned pointer, `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrmem(const void *, size_t, const void *, size_t);
#ifndef memrmem
# define memrmem libsimple_memrmem
#endif


/**
 * Finds the last substring in an array of bytes, the comparison is case-insensitive
 * 
 * @param   haystack   The array of bytes to search
 * @param   nhaystack  The length of `haystack`
 * @param   needle     The substring to search for
 * @param   nneedle    The length of `needle`
 * @return             `haystack` with a maximal offset such that,
 *                     `!memcasecmp(r, needle, nneedle)` where `r` is the
 *                     returned pointer, `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrcasemem(const void *, size_t, const void *, size_t);
#ifndef memrcasemem
# define memrcasemem libsimple_memrcasemem
#endif


/**
 * Finds the first element in an array, the comparison is case-sensitive
 * 
 * @param   haystack   The array of bytes to search
 * @param   nhaystack  The length of `haystack`, divided by `needle`
 * @param   needle     The substring to search for
 * @param   nneedle    The length of `needle`
 * @return             `haystack` with a minimal offset such that,
 *                     `!memcmp(r, needle, nneedle)` where `r` is the
 *                     returned pointer and such that `(r - haystack) % nneedle == 0`,
 *                     `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memelem(const void *, size_t, const void *, size_t);
#ifndef memelem
# define memelem libsimple_memelem
#endif


/**
 * Finds the last element in an array, the comparison is case-sensitive
 * 
 * @param   haystack   The array of bytes to search
 * @param   nhaystack  The length of `haystack`, divided by `needle`
 * @param   needle     The substring to search for
 * @param   nneedle    The length of `needle`
 * @return             `haystack` with a maximal offset such that,
 *                     `!memcmp(r, needle, nneedle)` where `r` is the
 *                     returned pointer and such that `(r - haystack) % nneedle == 0`,
 *                     `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrelem(const void *, size_t, const void *, size_t);
#ifndef memrelem
# define memrelem libsimple_memrelem
#endif


/**
 * Checks the beginning of an array of bytes, the comparison is case-sensitive
 * 
 * @param   s  The array of bytes to check
 * @param   n  The length of `s`
 * @param   t  The desired beginning of `s`
 * @param   m  The length of `t`
 * @return     1 if `s` begins with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memstarts(const void *, size_t, const void *, size_t);
#ifndef memstarts
# define memstarts libsimple_memstarts
#endif


/**
 * Checks the beginning of an array of bytes, the comparison is case-insensitive
 * 
ge  * @param   s  The array of bytes to check
 * @param   n  The length of `s`
 * @param   t  The desired beginning of `s`
 * @param   m  The length of `t`
 * @return     1 if `s` begins with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memcasestarts(const void *, size_t, const void *, size_t);
#ifndef memcasestarts
# define memcasestarts libsimple_memcasestarts
#endif


/**
 * Checks the end of an array of bytes, the comparison is case-sensitive
 * 
 * @param   s  The array of bytes to check
 * @param   n  The length of `s`
 * @param   t  The desired ending of `s`
 * @param   m  The length of `t`
 * @return     1 if `s` ends with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memends(const void *, size_t, const void *, size_t);
#ifndef memends
# define memends libsimple_memends
#endif


/**
 * Checks the end of an array of bytes, the comparison is case-insensitive
 * 
 * @param   s  The array of bytes to check
 * @param   n  The length of `s`
 * @param   t  The desired ending of `s`
 * @param   m  The length of `t`
 * @return     1 if `s` ends with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memcaseends(const void *, size_t, const void *, size_t);
#ifndef memcaseends
# define memcaseends libsimple_memcaseends
#endif


/**
 * Checks two arrays of bytes for equality, the comparison is case-insensitive
 * 
 * @param   a  One of the arrays of bytes
 * @param   b  The other arrays of bytes
 * @param   n  The lengths of the arrays
 * @return     1 if the arrays are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memcasecmp(const void *__a, const void *__b, size_t __n);
#ifndef memcasecmp
# define memcasecmp libsimple_memcasecmp
#endif


/**
 * Checks two arrays of bytes for equality, the comparison is case-sensitive
 * 
 * @param   a  One of the arrays of bytes
 * @param   b  The other arrays of bytes
 * @param   n  The lengths of the arrays
 * @return     1 if the arrays are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_memeq(const void *__a, const void *__b, size_t __n)
{ return !memcmp(__a, __b, __n); }
#ifndef memeq
# define memeq libsimple_memeq
#endif


/**
 * Checks two arrays of bytes for equality, the comparison is case-insensitive
 * 
 * @param   a  One of the arrays of bytes
 * @param   b  The other arrays of bytes
 * @param   n  The lengths of the arrays
 * @return     1 if the arrays are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_memcaseeq(const void *__a, const void *__b, size_t __n)
{ return !memcasecmp(__a, __b, __n); }
#ifndef memcaseeq
# define memcaseeq libsimple_memcaseeq
#endif


/**
 * Copies an array of bytes into another
 * 
 * @param   d  The array the bytes should be copied into
 * @param   s  The array of bytes that should be copied
 * @param   n  The number of bytes to copy
 * @return     `&s[n]`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *libsimple_mempcpy(void *__d, const void *__s, size_t __n)
{ return &((char *)memcpy(__d, __s, __n))[__n]; }
#ifndef mempcpy
# define mempcpy libsimple_mempcpy
#endif


/**
 * Fill an array of bytes with a specified byte
 * 
 * @param   s  The array of bytes to fill
 * @param   c  The byte to fill the array with
 * @param   n  The number of bytes to write to `s`
 * @return     `&s[n]`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *libsimple_mempset(void *__s, int __c, size_t __n)
{ return &((char *)memset(__s, __c, __n))[__n]; }
#ifndef mempset
# define mempset libsimple_mempset
#endif


/**
 * Fills an array with a number of copies of an item
 * 
 * @param   buf     The array to fill
 * @param   item    The element to fill `buf` with
 * @param   size    The size of `item`
 * @param   nitems  The number of copies to fill `buf` with
 * @return          `&buf[nelems * size]`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
void *libsimple_mempsetelem(void *__buf, const void *__item, size_t __size, size_t __nitems);
#ifndef mempsetelem
# define mempsetelem libsimple_mempsetelem
#endif


/**
 * Fills an array with a number of copies of an item
 * 
 * @param   buf     The array to fill
 * @param   item    The element to fill `buf` with
 * @param   size    The size of `item`
 * @param   nitems  The number of copies to fill `buf` with
 * @return          `buf`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *libsimple_memsetelem(void *__buf, const void *__item, size_t __size, size_t __nitems)
{ return __item = libsimple_mempsetelem(__buf, __item, __size, __nitems), __buf; }
#ifndef memsetelem
# define memsetelem libsimple_memsetelem
#endif


/**
 * Compares the beginning of two memory segments, the comparison is case-sensitive
 * 
 * @param   a  One of the arrays
 * @param   n  The length of `a`
 * @param   b  The other array
 * @param   m  The length of `b`
 * @return     The number of bytes `a` and `b` have
 *             in common in their beginnings
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
size_t libsimple_memeqlen(const void *, size_t, const void *, size_t);
#ifndef memeqlen
# define memeqlen libsimple_memeqlen
#endif


/**
 * Compares the beginning of two memory segments, the comparison is case-insensitive
 * 
 * @param   a  One of the arrays
 * @param   n  The length of `a`
 * @param   b  The other array
 * @param   m  The length of `b`
 * @return     The number of bytes `a` and `b` have
 *             in common in their beginnings
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
size_t libsimple_memcaseeqlen(const void *, size_t, const void *, size_t);
#ifndef memcaseeqlen
# define memcaseeqlen libsimple_memcaseeqlen
#endif


/**
 * Compares the end of two memory segments, the comparison is case-sensitive
 * 
 * @param   a  One of the arrays
 * @param   n  The length of `a`
 * @param   b  The other array
 * @param   m  The length of `b`
 * @return     The number of bytes `a` and `b` have
 *             in common in their ends
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
size_t libsimple_memreqlen(const void *, size_t, const void *, size_t);
#ifndef memreqlen
# define memreqlen libsimple_memreqlen
#endif


/**
 * Compares the end of two memory segments, the comparison is case-insensitive
 * 
 * @param   a  One of the arrays
 * @param   n  The length of `a`
 * @param   b  The other array
 * @param   m  The length of `b`
 * @return     The number of bytes `a` and `b` have
 *             in common in their ends
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
size_t libsimple_memrcaseeqlen(const void *, size_t, const void *, size_t);
#ifndef memrcaseeqlen
# define memrcaseeqlen libsimple_memrcaseeqlen
#endif
