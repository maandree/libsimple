/* See LICENSE file for copyright and license details. */


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `*r == c`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 *             within the first `n` bytes
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strnchr(const char *, int, size_t); /* TODO doc */
#ifndef strnchr
# define strnchr libsimple_strnchr
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 *             within the first `n` bytes
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strncasechr(const char *, int, size_t); /* TODO doc */
#ifndef strncasechr
# define strncasechr libsimple_strncasechr
#endif


/**
 * Scans for a character in a string, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `*r == c || !*r`,
 *             where `r` is the returned pointer, however if no such
 *             offset exists within the first `n` bytes, `&s[n]` is returned
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strnchrnul(const char *, int, size_t); /* TODO doc */
#ifndef strnchrnul
# define strnchrnul libsimple_strnchrnul
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c) || !*r`,
 *             where `r` is the returned pointer, however if no such offset
 *             exists within the first `n` bytes, `&s[n]` is returned
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strncasechrnul(const char *, int, size_t); /* TODO doc */
#ifndef strncasechrnul
# define strncasechrnul libsimple_strncasechrnul
#endif


/**
 * Scans for a character in a string, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a maximal offset such that `*r == c`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrnchr(const char *, int, size_t); /* TODO doc */
#ifndef strrnchr
# define strrnchr libsimple_strrnchr
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a maximal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrncasechr(const char *, int, size_t); /* TODO doc */
#ifndef strrncasechr
# define strrncasechr libsimple_strrncasechr
#endif


/**
 * Scans for the end of a string
 * 
 * @param   s  The string
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with an offset such `!*r`, where `r`
 *             is the returned pointer, however if there
 *             is not NUL byte within the first `n` bytes
 *             if `s`, `&s[n]` is returned
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strnend(const char *, size_t);
#ifndef strnend
# define strnend libsimple_strnend
#endif


/**
 * Checks the beginning of a string, the comparison is case-sensitive
 * 
 * @param   s  The string the check
 * @param   t  The string `s` should begin with
 * @param   n  Truncate `s` to this length if it is longer
 * @return     1 if `s` starts with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strnstarts(const char *, const char *, size_t);
#ifndef strnstarts
# define strnstarts libsimple_strnstarts
#endif


/**
 * Checks the beginning of a string, the comparison is case-insensitive
 * 
 * @param   s  The string the check
 * @param   t  The string `s` should begin with
 * @param   n  Truncate `s` to this length if it is longer
 * @return     1 if `s` starts with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strncasestarts(const char *, const char *, size_t);
#ifndef strncasestarts
# define strncasestarts libsimple_strncasestarts
#endif


/**
 * Checks the end of a string, the comparison is case-sensitive
 * 
 * @param   s  The string the check
 * @param   t  The string `s` should begin with
 * @param   n  Truncate `s` to this length if it is longer
 * @return     1 if `s` ends with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strnends(const char *, const char *, size_t);
#ifndef strnends
# define strnends libsimple_strnends
#endif


/**
 * Checks the end of a string, the comparison is case-insensitive
 * 
 * @param   s  The string the check
 * @param   t  The string `s` should begin with
 * @param   n  Truncate `s` to this length if it is longer
 * @return     1 if `s` end with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strncaseends(const char *, const char *, size_t);
#ifndef strncaseends
# define strncaseends libsimple_strncaseends
#endif


/**
 * Scans a string for a substring, the comparison is case-sensitive
 * 
 * @param   haystack  The string to search
 * @param   needle    The string to search for
 * @param   n         Truncate `haystack` to this length if it is longer
 * @return            `haystack` with a minimal offset such that the returned
 *                    pointer begins with `needle`, `NULL` if no such offset
 *                    exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strnstr(const char *, const char *, size_t);
#ifndef strnstr
# define strnstr libsimple_strnstr
#endif


/**
 * Scans a string for a substring, the comparison is case-insensitive
 * 
 * @param   haystack  The string to search
 * @param   needle    The string to search for
 * @param   n         Truncate `haystack` to this length if it is longer
 * @return            `haystack` with a minimal offset such that the returned
 *                    pointer begins with `needle`, `NULL` if no such offset
 *                    exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strncasestr(const char *, const char *, size_t);
#ifndef strncasestr
# define strncasestr libsimple_strncasestr
#endif


/**
 * Scans a string for a substring, the comparison is case-sensitive
 * 
 * @param   haystack  The string to search
 * @param   needle    The string to search for
 * @param   n         Truncate `haystack` to this length if it is longer
 * @return            `haystack` with a maximal offset such that the returned
 *                    pointer begins with `needle`, `NULL` if no such offset
 *                    exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrnstr(const char *, const char *, size_t);
#ifndef strrnstr
# define strrnstr libsimple_strrnstr
#endif


/**
 * Scans a string for a substring, the comparison is case-insensitive
 * 
 * @param   haystack  The string to search
 * @param   needle    The string to search for
 * @param   n         Truncate `haystack` to this length if it is longer
 * @return            `haystack` with a maximal offset such that the returned
 *                    pointer begins with `needle`, `NULL` if no such offset
 *                    exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrncasestr(const char *, const char *, size_t);
#ifndef strrncasestr
# define strrncasestr libsimple_strrncasestr
#endif


/**
 * Compare two strings, and support `NULL` as less than
 * the empty string, the comparison is case-sensitive
 * 
 * @param   a  One of the strings, may be `NULL`
 * @param   b  The other string, may be `NULL`
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     A negative value if `a` is less than `b`,
 *             a positive value if `a` is greater than `b`,
 *             0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strncmpnul(const char *__a, const char *__b, size_t __n)
{ return (!__a || !__b) ? !__b - !__a : strncmp(__a, __b, __n); }
#ifndef strncmpnul
# define strncmpnul libsimple_strncmpnul
#endif


/**
 * Compare two strings, and support `NULL` as less than
 * the empty string, the comparison is case-insensitive
 * 
 * @param   a  One of the strings, may be `NULL`
 * @param   b  The other string, may be `NULL`
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     A negative value if `a` is less than `b`,
 *             a positive value if `a` is greater than `b`,
 *             0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strncasecmpnul(const char *__a, const char *__b, size_t __n)
{ return (!__a || !__b) ? !__b - !__a : strncasecmp(__a, __b, __n); }
#ifndef strncasecmpnul
# define strncasecmpnul libsimple_strncasecmpnul
#endif


/**
 * Compare two strings, without support for `NULL`,
 * the comparison is case-sensitive
 * 
 * @param   a  One of the strings, may not be `NULL`
 * @param   b  The other string, may not be `NULL`
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     1 if the strings are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strneq(const char *__a, const char *__b, size_t __n)
{ return !strncmp(__a, __b, __n); }
#ifndef strneq
# define strneq libsimple_strneq
#endif


/**
 * Compare two strings, with support for `NULL`,
 * the comparison is case-sensitive
 * 
 * @param   a  One of the strings, may be `NULL`
 * @param   b  The other string, may be `NULL`
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     1 if the strings are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strneqnul(const char *__a, const char *__b, size_t __n)
{ return !strncmpnul(__a, __b, __n); }
#ifndef strneqnul
# define strneqnul libsimple_strneqnul
#endif


/**
 * Compare two strings, without support for `NULL`,
 * the comparison is case-insensitive
 * 
 * @param   a  One of the strings, may not be `NULL`
 * @param   b  The other string, may not be `NULL`
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     1 if the strings are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strncaseeq(const char *__a, const char *__b, size_t __n)
{ return !strncasecmp(__a, __b, __n); }
#ifndef strncaseeq
# define strncaseeq libsimple_strncaseeq
#endif


/**
 * Compare two strings, with support for `NULL`,
 * the comparison is case-insensitive
 * 
 * @param   a  One of the strings, may be `NULL`
 * @param   b  The other string, may be `NULL`
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     1 if the strings are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strncaseeqnul(const char *__a, const char *__b, size_t __n)
{ return !strncasecmpnul(__a, __b, __n); }
#ifndef strncaseeqnul
# define strncaseeqnul libsimple_strncaseeqnul
#endif


/**
 * Compares the beginning of two strings, the comparison is case-sensitive
 * 
 * @param   a  One of the strings
 * @param   b  The other string
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     The number of bytes `a` and `b` have
 *             in common in their beginnings
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
size_t libsimple_strneqlen(const char *, const char *, size_t);
#ifndef strneqlen
# define strneqlen libsimple_strneqlen
#endif


/**
 * Compares the beginning of two strings, the comparison is case-insensitive
 * 
 * @param   a  One of the strings
 * @param   b  The other string
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     The number of bytes `a` and `b` have
 *             in common in their beginnings
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
size_t libsimple_strncaseeqlen(const char *, const char *, size_t);
#ifndef strncaseeqlen
# define strncaseeqlen libsimple_strncaseeqlen
#endif


/**
 * Compares the end of two strings, the comparison is case-sensitive
 * 
 * @param   a  One of the strings
 * @param   b  The other string
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     The number of bytes `a` and `b` have
 *             in common in their ends
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline size_t libsimple_strrneqlen(const char *__a, const char *__b, size_t __n)
{ return memreqlen(__a, (strnlen)(__a, __n), __b, (strnlen)(__b, __n)); }
#ifndef strrneqlen
# define strrneqlen libsimple_strrneqlen
#endif


/**
 * Compares the end of two strings, the comparison is case-insensitive
 * 
 * @param   a  One of the strings
 * @param   b  The other string
 * @param   n  Truncate each input string that is
 *             longer than this to this length
 * @return     The number of bytes `a` and `b` have
 *             in common in their ends
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline size_t libsimple_strrncaseeqlen(const char *__a, const char *__b, size_t __n)
{ return memrcaseeqlen(__a, (strnlen)(__a, __n), __b, (strnlen)(__b, __n)); }
#ifndef strrncaseeqlen
# define strrncaseeqlen libsimple_strrncaseeqlen
#endif
