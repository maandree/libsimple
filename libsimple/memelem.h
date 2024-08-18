/* See LICENSE file for copyright and license details. */


/**
 * Finds the first element in an array, the comparison is case-sensitive
 * 
 * @param   haystack   The array to search
 * @param   needle     The substring to search for
 * @param   width      The size of `needle` and each element in `haystack`
 * @param   n          The number of elements in `haystack`
 * @return             `haystack` with a minimal offset such that,
 *                     `!memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`,
 *                     `NULL` if no such offset exists
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memelem(const void *, const void *, size_t, size_t);
#ifndef memelem
# define memelem libsimple_memelem
#endif


/**
 * Finds the first element in an array, the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified value in the specified array, its
 * behaviour is undefined
 * 
 * @param   haystack   The array to search
 * @param   needle     The substring to search for
 * @param   width      The size of `needle` and each element in `haystack`
 * @return             `haystack` with a minimal offset such that,
 *                     `!memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemelem(const void *, const void *, size_t);
#ifndef rawmemelem
# define rawmemelem libsimple_rawmemelem
#endif


/**
 * Finds the first element in an array, the comparison is case-sensitive
 * 
 * @param   haystack   The array to search
 * @param   needle     The substring to search for
 * @param   width      The size of `needle` and each element in `haystack`
 * @param   n          The number of elements in `haystack`
 * @return             `haystack` with a minimal offset such that,
 *                     `!memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`,
 *                     `(void *)&((char *)haystack)[n * width]` if no such
 *                     offset exists
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memelemscan(const void *, const void *, size_t, size_t);
#ifndef memelemscan
# define memelemscan libsimple_memelemscan
#endif


/**
 * Finds the last element in an array, the comparison is case-sensitive
 * 
 * @param   haystack   The array to search
 * @param   needle     The substring to search for
 * @param   width      The size of `needle` and each element in `haystack`
 * @param   n          The number of elements in `haystack`
 * @return             `haystack` with a maximal offset such that,
 *                     `!memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`,
 *                     `NULL` if no such offset exists
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrelem(const void *, const void *, size_t, size_t);
#ifndef memrelem
# define memrelem libsimple_memrelem
#endif


/**
 * Finds the last element in an array, the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified value in the specified array, its
 * behaviour is undefined
 * 
 * @param   haystack   The array to search
 * @param   needle     The substring to search for
 * @param   width      The size of `needle` and each element in `haystack`
 * @param   n          The number of elements in `haystack`
 * @return             `haystack` with a maximal offset such that,
 *                     `!memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrelem(const void *, const void *, size_t, size_t);
#ifndef rawmemrelem
# define rawmemrelem libsimple_rawmemrelem
#endif


/**
 * Finds the first element in an array that is different from
 * the specified element, the comparison is case-sensitive
 * 
 * @param   haystack   The array to search
 * @param   needle     The substring to skip over
 * @param   width      The size of `needle` and each element in `haystack`
 * @param   n          The number of elements in `haystack`
 * @return             `haystack` with a minimal offset such that,
 *                     `memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`,
 *                     `NULL` if no such offset exists
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memelem_inv(const void *, const void *, size_t, size_t);
#ifndef memelem_inv
# define memelem_inv libsimple_memelem_inv
#endif


/**
 * Finds the first element in an array that is different from
 * the specified element, the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of any value other than the specified value in the
 * specified array, its behaviour is undefined
 * 
 * @param   haystack   The array to search
 * @param   width      The size of `needle` and each element in `haystack`
 * @param   needle     The substring to skip over
 * @return             `haystack` with a minimal offset such that,
 *                     `memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemelem_inv(const void *, const void *, size_t);
#ifndef rawmemelem_inv
# define rawmemelem_inv libsimple_rawmemelem_inv
#endif


/**
 * Finds the first element in an array that is different from
 * the specified element, the comparison is case-sensitive
 * 
 * @param   haystack   The array to search
 * @param   needle     The substring to skip over
 * @param   width      The size of `needle` and each element in `haystack`
 * @param   n          The number of elements in `haystack`
 * @return             `haystack` with a minimal offset such that,
 *                     `memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`,
 *                     `(void *)&((char *)haystack)[n * width]` if no such
 *                     offset exists
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memelemscan_inv(const void *, const void *, size_t, size_t);
#ifndef memelemscan_inv
# define memelemscan_inv libsimple_memelemscan_inv
#endif


/**
 * Finds the last element in an array that is different from
 * the specified element, the comparison is case-sensitive
 * 
 * @param   haystack   The array to search
 * @param   needle     The substring to skip over
 * @param   width      The size of `needle` and each element in `haystack`
 * @param   n          The number of elements in `haystack`
 * @return             `haystack` with a maximal offset such that,
 *                     `memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`,
 *                     `NULL` if no such offset exists
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrelem_inv(const void *, const void *, size_t, size_t);
#ifndef memrelem_inv
# define memrelem_inv libsimple_memrelem_inv
#endif


/**
 * Finds the last element in an array that is different from
 * the specified element, the comparison is case-sensitive
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of any value other than the specified value in the
 * specified array, its behaviour is undefined
 * 
 * @param   haystack   The array to search
 * @param   needle     The substring to skip over
 * @param   width      The size of `needle` and each element in `haystack`
 * @param   n          The number of elements in `haystack`
 * @return             `haystack` with a maximal offset such that,
 *                     `memcmp(r, needle, width)` where `r` is the returned
 *                     pointer and such that `(r - haystack) % width == 0`
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __returns_nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrelem_inv(const void *, const void *, size_t, size_t);
#ifndef rawmemrelem_inv
# define rawmemrelem_inv libsimple_rawmemrelem_inv
#endif


/**
 * Fills an array with a number of copies of an item
 * 
 * @param   buf    The array to fill
 * @param   item   The element to fill `buf` with
 * @param   width  The size of `item`
 * @param   n      The number of copies to fill `buf` with
 * @return         `&buf[n * width]`
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
void *libsimple_mempsetelem(void *, const void *, size_t, size_t);
#ifndef mempsetelem
# define mempsetelem libsimple_mempsetelem
#endif


/**
 * Fills an array with a number of copies of an item
 * 
 * @param   buf     The array to fill
 * @param   item    The element to fill `buf` with
 * @param   width   The size of `item`
 * @param   n       The number of copies to fill `buf` with
 * @return          `buf`
 * 
 * @since  1.1
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *libsimple_memsetelem(void *__buf, const void *__item, size_t __width, size_t __n)
{ return __item = libsimple_mempsetelem(__buf, __item, __width, __n), __buf; }
#ifndef memsetelem
# define memsetelem libsimple_memsetelem
#endif


/**
 * Copy elements in an array to another array, but stop after a specific element
 * 
 * @param   d      The location the array shall be copied to
 * @param   s      The array to copy
 * @param   elem   The element that stops the copying
 * @param   width  The size of each element
 * @param   n      The maximum number of elements to copy
 * @return         `&rawmemelem(d, c, width)[width]` (after copying) if `elem`
 *                 can be found within the first `n` elements of `s` (before
 *                 copying), `NULL` otherwise
 * 
 * @since  1.1
 */
void *libsimple_memelemcpy(void *restrict, const void *restrict, const void *restrict, size_t, size_t);
#ifndef memelemcpy
# define memelemcpy libsimple_memelemcpy
#endif


/**
 * Move elements in an array, but stop after a specific element
 * 
 * @param   d      The location the array shall be copied to
 * @param   s      The array to copy
 * @param   elem   The element that stops the copying
 * @param   width  The size of each element
 * @param   n      The maximum number of elements to copy
 * @return         `&rawmemelem(d, c, width)[width]` (after copying) if `elem`
 *                 can be found within the first `n` elements of `s` (before
 *                 copying), `NULL` otherwise
 * 
 * @since  1.1
 */
void *libsimple_memelemmove(void *, const void *, const void *restrict, size_t, size_t);
#ifndef memelemmove
# define memelemmove libsimple_memelemmove
#endif


/**
 * Copy elements in an array to another array, but stop after a specific element
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified value in the specified array, its
 * behaviour is undefined
 * 
 * @param   d      The location the array shall be copied to
 * @param   s      The array to copy
 * @param   elem   The element that stops the copying
 * @param   width  The size of each element
 * @return         `&rawmemelem(d, c, width)[width]` (after copying)
 * 
 * @since  1.1
 */
void *libsimple_rawmemelemcpy(void *restrict, const void *restrict, const void *restrict, size_t);
#ifndef rawmemelemcpy
# define rawmemelemcpy libsimple_rawmemelemcpy
#endif


/**
 * Move elements in an array, but stop after a specific element
 * 
 * This function is optimised for instances where it is already
 * known that there is at least one occurence; if there is no
 * occurence of the specified value in the specified array, its
 * behaviour is undefined
 * 
 * @param   d      The location the array shall be copied to
 * @param   s      The array to copy
 * @param   elem   The element that stops the copying
 * @param   width  The size of each element
 * @return         `&rawmemelem(d, c, width)[width]` (after copying)
 * 
 * @since  1.1
 */
void *libsimple_rawmemelemmove(void *, const void *, const void *restrict, size_t);
#ifndef rawmemelemmove
# define rawmemelemmove libsimple_rawmemelemmove
#endif


/**
 * Replace all instances of an element in an array of
 * elements with another element
 * 
 * @param   s      The array
 * @param   old    The value of the elements to replace
 * @param   new    The value to replace the elements with
 * @param   width  The size of each element
 * @param   n      The length of `s`, measured in elements
 * @return         `(void *)&((char *)s)[n * width]`
 * 
 * @since  1.1
 */
void *libsimple_memreplaceelem(void *restrict, const void *, const void *, size_t, size_t);
#ifndef memreplaceelem
# define memreplaceelem libsimple_memreplaceelem
#endif
