/* See LICENSE file for copyright and license details. */


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `*r == c`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 *             within the first `n` bytes
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strnchr(const char *, int, size_t);
#ifndef strnchr
# define strnchr libsimple_strnchr
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 *             within the first `n` bytes
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strncasechr(const char *, int, size_t);
#ifndef strncasechr
# define strncasechr libsimple_strncasechr
#endif


/**
 * Scans for a character in a string, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `*r == c || !*r`,
 *             where `r` is the returned pointer, however if no such
 *             offset exists within the first `n` bytes, `&s[n]` is returned
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strnchrnul(const char *, int, size_t);
#ifndef strnchrnul
# define strnchrnul libsimple_strnchrnul
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c) || !*r`,
 *             where `r` is the returned pointer, however if no such offset
 *             exists within the first `n` bytes, `&s[n]` is returned
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strncasechrnul(const char *, int, size_t);
#ifndef strncasechrnul
# define strncasechrnul libsimple_strncasechrnul
#endif


/**
 * Scans for a character in a string, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a maximal offset such that `*r == c`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrnchr(const char *, int, size_t);
#ifndef strrnchr
# define strrnchr libsimple_strrnchr
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a maximal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrncasechr(const char *, int, size_t);
#ifndef strrncasechr
# define strrncasechr libsimple_strrncasechr
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `*r != c`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 *             within the first `n` bytes
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strnchr_inv(const char *, int, size_t);
#ifndef strnchr_inv
# define strnchr_inv libsimple_strnchr_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `tolower(*r) != tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 *             within the first `n` bytes
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strncasechr_inv(const char *, int, size_t);
#ifndef strncasechr_inv
# define strncasechr_inv libsimple_strncasechr_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `*r != c || !*r`,
 *             where `r` is the returned pointer, however if no such
 *             offset exists within the first `n` bytes, `&s[n]` is returned
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strnchrnul_inv(const char *, int, size_t);
#ifndef strnchrnul_inv
# define strnchrnul_inv libsimple_strnchrnul_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a minimal offset such that `tolower(*r) != tolower(c) || !*r`,
 *             where `r` is the returned pointer, however if no such offset
 *             exists within the first `n` bytes, `&s[n]` is returned
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strncasechrnul_inv(const char *, int, size_t);
#ifndef strncasechrnul_inv
# define strncasechrnul_inv libsimple_strncasechrnul_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a maximal offset such that `*r != c`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrnchr_inv(const char *, int, size_t);
#ifndef strrnchr_inv
# define strrnchr_inv libsimple_strrnchr_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @param   n  Truncate `s` to this length if it is longer
 * @return     `s` with a maximal offset such that `tolower(*r) != tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrncasechr_inv(const char *, int, size_t);
#ifndef strrncasechr_inv
# define strrncasechr_inv libsimple_strrncasechr_inv
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
inline int
libsimple_strncmpnul(const char *a__, const char *b__, size_t n__)
{
	return (!a__ || !b__) ? !b__ - !a__ : strncmp(a__, b__, n__);
}
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
inline int
libsimple_strncasecmpnul(const char *a__, const char *b__, size_t n__)
{
	return (!a__ || !b__) ? !b__ - !a__ : strncasecmp(a__, b__, n__);
}
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
inline int
libsimple_strneq(const char *a__, const char *b__, size_t n__)
{
	return !strncmp(a__, b__, n__);
}
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
inline int
libsimple_strneqnul(const char *a__, const char *b__, size_t n__)
{
	return !strncmpnul(a__, b__, n__);
}
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
inline int
libsimple_strncaseeq(const char *a__, const char *b__, size_t n__)
{
	return !strncasecmp(a__, b__, n__);
}
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
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
inline int
libsimple_strncaseeqnul(const char *a__, const char *b__, size_t n__)
{
	return !libsimple_strncasecmpnul(a__, b__, n__);
}
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
inline size_t
libsimple_strrneqlen(const char *a__, const char *b__, size_t n__)
{
	return libsimple_memreqlen(a__, strnlen(a__, n__), b__, strnlen(b__, n__));
}
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
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
inline size_t
libsimple_strrncaseeqlen(const char *a__, const char *b__, size_t n__)
{
	return libsimple_memrcaseeqlen(a__, strnlen(a__, n__), b__, strnlen(b__, n__));
}
#ifndef strrncaseeqlen
# define strrncaseeqlen libsimple_strrncaseeqlen
#endif


/**
 * Moves a string within a string
 * 
 * @param   d  The location in the string's byte array where the
 *             string should be moved to
 * @param   s  The string to move
 * @param   n  The maximum number of bytes to move
 * @return     `d`
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline char *
libsimple_strnmove(char *d__, const char *s__, size_t n__)
{
	size_t len__ = strnlen(s__, n__);
	return memmove(d__, s__, len__ + (len__ < n__));
}
#ifndef strnmove
# define strnmove libsimple_strnmove
#endif


/**
 * Moves a string within a string
 * 
 * @param   d  The location in the string's byte array where the
 *             string should be moved to
 * @param   s  The string to move
 * @param   n  The maximum number of bytes to move
 * @return     `&d[strnlen(s, n)]`
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline char *
libsimple_stpnmove(char *d__, const char *s__, size_t n__)
{
	size_t len__ = strnlen(s__, n__);
	memmove(d__, s__, len__ + (len__ < n__));
	return &d__[len__];
}
#ifndef stpnmove
# define stpnmove libsimple_stpnmove
#endif


/**
 * Fill a string with a character
 * 
 * @param   s  The string to fill
 * @param   c  The byte to replace all bytes in `s` with
 * @param   n  The maximum number of bytes to write
 * @return     `s`
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline char *
libsimple_strnset(char *s__, int c___, size_t n__)
{
	char c__ = (char)c___, *r__ = s__;
	for (; n__ && *s__; n__--) *s__++ = c__;
	return r__;
}
#ifndef strnset
# define strnset libsimple_strnset
#endif


/**
 * Fill a string with a character
 * 
 * @param   s  The string to fill
 * @param   c  The byte to replace all bytes in `s` with
 * @param   n  The maximum number of bytes to write
 * @return     `&s[strnlen(s, n)]`
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline char *
libsimple_stpnset(char *s__, int c___, size_t n__)
{
	char c__ = (char)c___;
	for (; n__ && *s__; n__--) *s__++ = c__;
	return s__;
}
#ifndef stpnset
# define stpnset libsimple_stpnset
#endif


/**
 * Copy a string, but stop after a specific character
 * the new string will be NUL-terminated if it is
 * shorter than `n` bytes
 * 
 * @param   d  The location the string shall be copied to
 * @param   s  The string to copy
 * @param   c  The character that stops the copying
 * @param   n  The maximum number of bytes to copy
 * @return     `&strchr(d, c)[1]` (after copying) if `c` can be
 *             found in `s`, `NULL` otherwise
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline char *
libsimple_strnccpy(char *restrict d__, const char *restrict s__, int c___, size_t n__)
{
	char c__ = (char)c___, *end__ = &d__[n__];
	do {
		if (!n__)
			break;
		if ((*d__++ = *s__) == c__) {
			if (d__ != end__)
				*d__ = '\0';
			return d__;
		}
		n__--;
	} while (*s__++);
	return NULL;
}
#ifndef strnccpy
# define strnccpy libsimple_strnccpy
#endif


/**
 * Move a string, but stop after a specific character
 * 
 * @param   d  The location the string shall be moved to
 * @param   s  The string to copy
 * @param   c  The character that stops the copying
 * @param   n  The maximum number of bytes to move
 * @return     `&strchr(d, c)[1]` (after copying) if `c` can be
 *             found within the first `n` bytes of `s` (before
 *             copying), `NULL` otherwise
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
char *libsimple_strncmove(char *, const char *, int, size_t);
#ifndef strncmove
# define strncmove libsimple_strncmove
#endif


/**
 * Replace all instances of a character in an string with
 * another character
 * 
 * @param   s    The string
 * @param   old  The value of the characters to replace
 * @param   new  The value to replace the characters with
 * @param   n    The maximum length of `s`
 * @return       `strnchr(s, '\0', n)`
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
inline char *
libsimple_strnreplace(char *s__, int old___, int new___, size_t n__)
{
	char old__ = (char)old___, new__ = (char)new___;
	for (; n__ && *s__; s__++, n__--)
		if (*s__ == old__)
			*s__ = new__;
	return s__;
}
#ifndef strnreplace
# define strnreplace libsimple_strnreplace
#endif


/**
 * Copy a string but convert to lower case
 * 
 * `d` and `s` may overlap; the function has
 * an optimisation for when `d == s`
 * 
 * `d` will be `s` but in lower case
 * 
 * @param   d  The location the string shall be copied to
 * @param   s  The string to copy
 * @param   n  The maximum number of bytes to copy or convert
 * @return     `strnchrnul(d, '\0', n)` (after copying)
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
char *libsimple_stpntolower(char *, const char *, size_t);
#ifndef stpntolower
# define stpntolower libsimple_stpntolower
#endif


/**
 * Copy a string but convert to upper case
 * 
 * `d` and `s` may overlap; the function has
 * an optimisation for when `d == s`
 * 
 * `d` will be `s` but in upper case
 * 
 * @param   d  The location the string shall be copied to
 * @param   s  The string to copy
 * @param   n  The maximum number of bytes to copy or convert
 * @return     `strnchrnul(d, '\0', n)` (after copying)
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
char *libsimple_stpntoupper(char *, const char *, size_t);
#ifndef stpntoupper
# define stpntoupper libsimple_stpntoupper
#endif


/**
 * Copy a string but convert to lower case
 * 
 * `d` and `s` may overlap; the function has
 * an optimisation for when `d == s`
 * 
 * `d` will be `s` but in lower case
 * 
 * @param   d  The location the string shall be copied to
 * @param   s  The string to copy
 * @param   n  The maximum number of bytes to copy or convert
 * @return     `d`
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
inline char *
libsimple_strntolower(char *d__, const char *s__, size_t n__)
{
	libsimple_stpntolower(d__, s__, n__);
	return d__;
}
#ifndef strntolower
# define strntolower libsimple_strntolower
#endif


/**
 * Copy a string but convert to upper case
 * 
 * `d` and `s` may overlap; the function has
 * an optimisation for when `d == s`
 * 
 * `d` will be `s` but in upper case
 * 
 * @param   d  The location the string shall be copied to
 * @param   s  The string to copy
 * @param   n  The maximum number of bytes to copy or convert
 * @return     `d`
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
inline char *
libsimple_strntoupper(char *d__, const char *s__, size_t n__)
{
	libsimple_stpntoupper(d__, s__, n__);
	return d__;
}
#ifndef strntoupper
# define strntoupper libsimple_strntoupper
#endif


/**
 * Check whether a string, that may be or may not be NUL-terminated,
 * is encoded in UTF-8
 * 
 * @param   string              The string
 * @param   n                   The maximum length of `string`, its
 *                              length is `strlen(string)` if there is a
 *                              NUL byte at any position lower than `n`
 * @param   allow_modified_nul  Whether Modified UTF-8 is allowed, which
 *                              allows a two-byte encoding for NUL
 * @return                      1 if good, 0 on encoding error
 * 
 * @since  1.1
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
inline int
libsimple_strnisutf8(const char *string__, size_t n__, int allow_modified_nul__)
{
	return libsimple_memisutf8(string__, strnlen(string__, n__), allow_modified_nul__);
}
#ifndef strnisutf8
# define strnisutf8 libsimple_strnisutf8
#endif
