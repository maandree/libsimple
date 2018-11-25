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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
{ return !libsimple_strncasecmpnul(__a, __b, __n); }
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
{ return libsimple_memreqlen(__a, strnlen(__a, __n), __b, strnlen(__b, __n)); }
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
{ return libsimple_memrcaseeqlen(__a, strnlen(__a, __n), __b, strnlen(__b, __n)); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline char *libsimple_strnmove(char *__d, const char *__s, size_t __n)
{ size_t __len = strnlen(__s, __n); return memmove(__d, __s, __len + (__len < __n)); }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline char *
libsimple_stpnmove(char *__d, const char *__s, size_t __n)
{
	size_t __len = strnlen(__s, __n);
	memmove(__d, __s, __len + (__len < __n));
	return &__d[__len];
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline char *
libsimple_strnset(char *__s, int __c_, size_t __n)
{
	char __c = (char)__c_, *__r = __s;
	for (; __n && *__s; __n--) *__s++ = __c;
	return __r;
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline char *
libsimple_stpnset(char *__s, int __c_, size_t __n)
{
	char __c = (char)__c_;
	for (; __n && *__s; __n--) *__s++ = __c;
	return __s;
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline char *
libsimple_strnccpy(char *restrict __d, const char *restrict __s, int __c_, size_t __n)
{
	char __c = (char)__c_, *__end = &__d[__n];
	do {
		if (!__n)
			break;
		if ((*__d++ = *__s) == __c) {
			if (__d != __end)
				*__d = '\0';
			return __d;
		}
		__n--;
	} while (*__s++);
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __returns_nonnull__)))
static inline char *
libsimple_strnreplace(char *__s, int __old_, int __new_, size_t __n)
{
	char __old = (char)__old_, __new = (char)__new_;
	for (; __n && *__s; __s++, __n--)
		if (*__s == __old)
			*__s = __new;
	return __s;
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __returns_nonnull__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __returns_nonnull__)))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __returns_nonnull__)))
static inline char *libsimple_strntolower(char *__d, const char *__s, size_t __n)
{ libsimple_stpntolower(__d, __s, __n); return __d; }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __returns_nonnull__)))
static inline char *libsimple_strntoupper(char *__d, const char *__s, size_t __n)
{ libsimple_stpntoupper(__d, __s, __n); return __d; }
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strnisutf8(const char *__string, size_t __n, int __allow_modified_nul)
{ return libsimple_memisutf8(__string, strnlen(__string, __n) ,__allow_modified_nul); }
#ifndef strnisutf8
# define strnisutf8 libsimple_strnisutf8
#endif
