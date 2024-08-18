/* See LICENSE file for copyright and license details. */


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * the comparison is case-sensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a minimal offset such that `*r == c`,
 *             where `r` is the returned pointer, `&s[n]` if
 *             no such offset exists within [s, &s[n])
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_memscan(const void *, int, size_t);
#ifndef memscan
# define memscan libsimple_memscan
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * the comparison is case-insensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if
 *             no such offset exists within [s, &s[n])
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memcasechr(const void *, int, size_t);
#ifndef memcasechr
# define memcasechr libsimple_memcasechr
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * the comparison is case-insensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `&s[n]` if
 *             no such offset exists within [s, &s[n])
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_memcasescan(const void *, int, size_t);
#ifndef memcasescan
# define memcasescan libsimple_memcasescan
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified byte value in the specified byte
 * array, its behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @return     `s` with a miminal offset such that `*r == c`,
 *             where `r` is the returned pointer
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemchr(const void *, int);
#ifndef rawmemchr
# define rawmemchr libsimple_rawmemchr
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * the comparison is case-insensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified byte value in the specified byte
 * array, its behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @return     `s` with a miminal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrcasechr(const void *, int, size_t);
#ifndef memrcasechr
# define memrcasechr libsimple_memrcasechr
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified byte value in the specified byte
 * array, its behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `*r == c`,
 *             where `r` is the returned pointer
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrchr(const void *, int, size_t);
#ifndef rawmemrchr
# define rawmemrchr libsimple_rawmemrchr
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * the comparison is case-insensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified byte value in the specified byte
 * array, its behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrcasechr(const void *, int, size_t);
#ifndef rawmemrcasechr
# define rawmemrcasechr libsimple_rawmemrcasechr
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-sensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a minimal offset such that `*r != c`,
 *             where `r` is the returned pointer, `NULL` if
 *             no such offset exists within [s, &s[n])
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memchr_inv(const void *, int, size_t);
#ifndef memchr_inv
# define memchr_inv libsimple_memchr_inv
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-sensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a minimal offset such that `*r != c`,
 *             where `r` is the returned pointer, `&s[n]` if
 *             no such offset exists within [s, &s[n])
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_memscan_inv(const void *, int, size_t);
#ifndef memscan_inv
# define memscan_inv libsimple_memscan_inv
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-insensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a minimal offset such that `tolower(*r) != tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if
 *             no such offset exists within [s, &s[n])
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memcasechr_inv(const void *, int, size_t);
#ifndef memcasechr_inv
# define memcasechr_inv libsimple_memcasechr_inv
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-insensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a minimal offset such that `tolower(*r) != tolower(c)`,
 *             where `r` is the returned pointer, `&s[n]` if
 *             no such offset exists within [s, &s[n])
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_memcasescan_inv(const void *, int, size_t);
#ifndef memcasescan_inv
# define memcasescan_inv libsimple_memcasescan_inv
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of any byte value than the specified byte value in
 * the specified byte array, its behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @return     `s` with a miminal offset such that `*r != c`,
 *             where `r` is the returned pointer
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemchr_inv(const void *, int);
#ifndef rawmemchr_inv
# define rawmemchr_inv libsimple_rawmemchr_inv
#endif


/**
 * Finds the first occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-insensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of any byte value than the specified byte value in
 * the specified byte array, its behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @return     `s` with a miminal offset such that `tolower(*r) != tolower(c)`,
 *             where `r` is the returned pointer
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemcasechr_inv(const void *, int);
#ifndef rawmemcasechr_inv
# define rawmemcasechr_inv libsimple_rawmemcasechr_inv
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-sensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `*r != c`,
 *             where `r` is the returned pointer `NULL` if no
 *             such offset exists within [s, &s[n])
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrchr_inv(const void *, int, size_t);
#ifndef memrchr_inv
# define memrchr_inv libsimple_memrchr_inv
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-insensitive
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `tolower(*r) != tolower(c)`,
 *             where `r` is the returned pointer `NULL` if no
 *             such offset exists within [s, &s[n])
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrcasechr_inv(const void *, int, size_t);
#ifndef memrcasechr_inv
# define memrcasechr_inv libsimple_memrcasechr_inv
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of any byte value than the specified byte value in
 * the specified byte array, its behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `*r != c`,
 *             where `r` is the returned pointer
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrchr_inv(const void *, int, size_t);
#ifndef rawmemrchr_inv
# define rawmemrchr_inv libsimple_rawmemrchr_inv
#endif


/**
 * Finds the last occurence of a byte value in an array of bytes,
 * other than specified byte value, the comparison is case-insensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of any byte value than the specified byte value in
 * the specified byte array, its behaviour is undefined
 * 
 * @param   s  The array of bytes to search
 * @param   c  The byte value to search for
 * @param   n  The number of bytes in the byte array
 * @return     `s` with a maximal offset such that `tolower(*r) != tolower(c)`,
 *             where `r` is the returned pointer
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrcasechr_inv(const void *, int, size_t);
#ifndef rawmemrcasechr_inv
# define rawmemrcasechr_inv libsimple_rawmemrcasechr_inv
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrcasemem(const void *, size_t, const void *, size_t);
#ifndef memrcasemem
# define memrcasemem libsimple_memrcasemem
#endif


/**
 * Checks the beginning of an array of bytes, the comparison is case-sensitive
 * 
 * @param   s  The array of bytes to check
 * @param   n  The length of `s`
 * @param   t  The desired beginning of `s`
 * @param   m  The length of `t`
 * @return     1 if `s` begins with `t`, 0 otherwise
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memstarts(const void *, size_t, const void *, size_t);
#ifndef memstarts
# define memstarts libsimple_memstarts
#endif


/**
 * Checks the beginning of an array of bytes, the comparison is case-insensitive
 * 
 * @param   s  The array of bytes to check
 * @param   n  The length of `s`
 * @param   t  The desired beginning of `s`
 * @param   m  The length of `t`
 * @return     1 if `s` begins with `t`, 0 otherwise
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memcasecmp(const void *, const void *, size_t);
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
inline int
libsimple_memeq(const void *a__, const void *b__, size_t n__)
{
	return !memcmp(a__, b__, n__);
}
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
inline int
libsimple_memcaseeq(const void *a__, const void *b__, size_t n__)
{
	return !memcasecmp(a__, b__, n__);
}
#ifndef memcaseeq
# define memcaseeq libsimple_memcaseeq
#endif


/**
 * Copies an array of bytes into another
 * 
 * @param   d  The array the bytes should be copied into
 * @param   s  The array of bytes that should be copied
 * @param   n  The number of bytes to copy
 * @return     `&d[n]`
 * 
 * @since  1.0
 */
inline void *
libsimple_mempcpy(void *restrict d__, const void *restrict s__, size_t n__)
{
	return &((char *)memcpy(d__, s__, n__))[n__];
}
#ifndef mempcpy
# define mempcpy libsimple_mempcpy
#endif


/**
 * Moves bytes within an array of bytes
 * 
 * @param   d  The location in the array the bytes should be moved to
 * @param   s  The bytes that should be moved
 * @param   n  The number of bytes to move
 * @return     `&d[n]`
 * 
 * @since  1.1
 */
inline void *
libsimple_mempmove(void *d__, const void *s__, size_t n__)
{
	return &((char *)memmove(d__, s__, n__))[n__];
}
#ifndef mempmove
# define mempmove libsimple_mempmove
#endif


/**
 * Fill an array of bytes with a specified byte
 * 
 * @param   s  The array of bytes to fill
 * @param   c  The byte to fill the array with
 * @param   n  The number of bytes to write to `s`
 * @return     `&s[n]`
 * 
 * @since  1.1
 */
inline void *
libsimple_mempset(void *s__, int c__, size_t n__)
{
	return &((char *)memset(s__, c__, n__))[n__];
}
#ifndef mempset
# define mempset libsimple_mempset
#endif


/**
 * Copy an array of bytes, but stop after a specific byte
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified byte value in the specified byte
 * array, its behaviour is undefined
 * 
 * @param   d  The location the byte array shall be copied to
 * @param   s  The byte array to copy
 * @param   c  The byte that stops the copying
 * @return     `&rawmemchr(d, c)[1]` (after copying)
 * 
 * @since  1.1
 */
inline void *
libsimple_rawmemccpy(void *restrict d___, const void *restrict s___, int c___)
{
	char c__ = (char)c___, *restrict d__ = d___;
	const char *restrict s__ = s___;
	for (; (*d__++ = *s__) != c__; s__++);
	return d__;
}
#ifndef rawmemccpy
# define rawmemccpy libsimple_rawmemccpy
#endif


/**
 * Move a string, but stop after a specific character
 * 
 * @param   d  The location the byte array shall be copied to
 * @param   s  The byte array to copy
 * @param   c  The byte that stops the copying
 * @param   n  The length of `s`
 * @return     `&rawmemchr(d, c)[1]` (after copying) if `c` can
 *             be found within the first `n` bytes of `s` (before
 *             copying), `NULL` otherwise
 * 
 * @since  1.1
 */
void *libsimple_memcmove(void *, const void *, int, size_t);
#ifndef memcmove
# define memcmove libsimple_memcmove
#endif


/**
 * Move a string, but stop after a specific character
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified byte value in the specified byte
 * array, its behaviour is undefined
 * 
 * @param   d  The location the byte array shall be copied to
 * @param   s  The byte array to copy
 * @param   c  The byte that stops the copying
 * @return     `&rawmemchr(d, c)[1]` (after copying)
 * 
 * @since  1.1
 */
inline void *
libsimple_rawmemcmove(void *d___, const void *s___, int c___)
{
	char *d__ = d___, *p__, c__ = (char)c___;
	const char *s__ = s___;
	size_t n__;
	if (d__ <= s__) {
		for (; (*d__++ = *s__) != c__; s__++);
		return d__;
	} else {
		for (p__ = *(char **)(void *)&s__; *p__++ != c__;);
		n__ = (size_t)(p__ - s__);
		p__ = &d__[n__];
		while (n__) {
			n__--;
			d__[n__] = s__[n__];
		}
		return p__;
	}
}
#ifndef rawmemcmove
# define rawmemcmove libsimple_rawmemcmove
#endif


/**
 * Replace all instances of a byte in an array of byte with another byte
 * 
 * @param   s    The byte array
 * @param   old  The value of the bytes to replace
 * @param   new  The value to replace the bytes with
 * @param   n    The length of `s`
 * @return       `(void *)&((char *)s)[n]`
 * 
 * @since  1.1
 */
inline void *
libsimple_memreplace(void *s___, int old___, int new___, size_t n__)
{
	char old__ = (char)old___, new__ = (char)new___, *s__ = s___;
	char *ret__ = &s__[n__];
	while (n__)
		if (s__[--n__] == old__)
			s__[n__] = new__;
	return ret__;
}
#ifndef memreplace
# define memreplace libsimple_memreplace
#endif


/**
 * Copy an array of bytes but convert to lower case
 * 
 * `d` and `s` may overlap; the function has an
 * optimisation for when `d == s`
 * 
 * `d` will be `s` but in lower case
 * 
 * @param   d  The location the array shall be copied to
 * @param   s  The byte array to copy
 * @param   n  The number of bytes to copy or covert
 * @return     `&d[n]`
 * 
 * @since  1.1
 */
void *libsimple_memptolower(void *, const void *, size_t);
#ifndef memptolower
# define memptolower libsimple_memptolower
#endif


/**
 * Copy an array of bytes but convert to upper case
 * 
 * `d` and `s` may overlap; the function has an
 * optimisation for when `d == s`
 * 
 * `d` will be `s` but in upper case
 * 
 * @param   d  The location the array shall be copied to
 * @param   s  The byte array to copy
 * @param   n  The number of bytes to copy or covert
 * @return     `&d[n]`
 * 
 * @since  1.1
 */
void *libsimple_memptoupper(void *, const void *, size_t);
#ifndef memptoupper
# define memptoupper libsimple_memptoupper
#endif


/**
 * Copy an array of bytes but convert to lower case
 * 
 * `d` and `s` may overlap; the function has an
 * optimisation for when `d == s`
 * 
 * `d` will be `s` but in lower case
 * 
 * @param   d  The location the array shall be copied to
 * @param   s  The byte array to copy
 * @param   n  The number of bytes to copy or covert
 * @return     `d`
 * 
 * @since  1.1
 */
inline void *
libsimple_memtolower(void *d__, const void *s__, size_t n__)
{
	libsimple_memptolower(d__, s__, n__);
	return d__;
}
#ifndef memtolower
# define memtolower libsimple_memtolower
#endif


/**
 * Copy an array of bytes but convert to upper case
 * 
 * `d` and `s` may overlap; the function has an
 * optimisation for when `d == s`
 * 
 * `d` will be `s` but in upper case
 * 
 * @param   d  The location the array shall be copied to
 * @param   s  The byte array to copy
 * @param   n  The number of bytes to copy or covert
 * @return     `d`
 * 
 * @since  1.1
 */
inline void *
libsimple_memtoupper(void *d__, const void *s__, size_t n__)
{
	libsimple_memptoupper(d__, s__, n__);
	return d__;
}
#ifndef memtoupper
# define memtoupper libsimple_memtoupper
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
size_t libsimple_memrcaseeqlen(const void *, size_t, const void *, size_t);
#ifndef memrcaseeqlen
# define memrcaseeqlen libsimple_memrcaseeqlen
#endif


/**
 * Check whether a string is encoded in UTF-8
 * 
 * @param   string              The string
 * @param   n                   The length of the string
 * @param   allow_modified_nul  Whether Modified UTF-8 is allowed, which
 *                              allows a two-byte encoding for NUL
 * @return                      1 if good, 0 on encoding error
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memisutf8(const char *, size_t, int);
#ifndef memisutf8
# define memisutf8 libsimple_memisutf8
#endif
