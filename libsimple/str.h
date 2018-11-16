/* See LICENSE file for copyright and license details. */


/**
 * Scans for a character in a string, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @return     `s` with a minimal offset such that `*r == c || !*r`,
 *             where `r` is the returned pointer
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strchrnul(const char *, int);
#ifndef strchrnul
# define strchrnul libsimple_strchrnul
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strcasechr(const char *, int);
#ifndef strcasechr
# define strcasechr libsimple_strcasechr
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c) || !*r`,
 *             where `r` is the returned pointer
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strcasechrnul(const char *, int);
#ifndef strcasechrnul
# define strcasechrnul libsimple_strcasechrnul
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character for scan for
 * @return     `s` with a maximal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrcasechr(const char *, int);
#ifndef strrcasechr
# define strrcasechr libsimple_strrcasechr
#endif


/**
 * Scans for the end of a string
 * 
 * @param   s  The string
 * @return     `s` with an offset such `!*r`, where `r` is the returned pointer
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline char *libsimple_strend(const char *__s)
{ return strchr(__s, '\0'); }
#ifndef strend
# define strend libsimple_strend
#endif


/**
 * Checks the beginning of a string, the comparison is case-sensitive
 * 
 * @param   s  The string the check
 * @param   t  The string `s` should begin with
 * @return     1 if `s` starts with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strstarts(const char *, const char *);
#ifndef strstarts
# define strstarts libsimple_strstarts
#endif


/**
 * Checks the beginning of a string, the comparison is case-insensitive
 * 
 * @param   s  The string the check
 * @param   t  The string `s` should begin with
 * @return     1 if `s` starts with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strcasestarts(const char *__s, const char *__t)
{ return !strncasecmp(__s, __t, strlen(__t)); }
#ifndef strcasestarts
# define strcasestarts libsimple_strcasestarts
#endif


/**
 * Checks the end of a string, the comparison is case-sensitive
 * 
 * @param   s  The string the check
 * @param   t  The string `s` should begin with
 * @return     1 if `s` ends with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strends(const char *, const char *);
#ifndef strends
# define strends libsimple_strends
#endif


/**
 * Checks the end of a string, the comparison is case-insensitive
 * 
 * @param   s  The string the check
 * @param   t  The string `s` should begin with
 * @return     1 if `s` end with `t`, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strcaseends(const char *, const char *);
#ifndef strcaseends
# define strcaseends libsimple_strcaseends
#endif


/**
 * Scans a string for a substring, the comparison is case-sensitive
 * 
 * @param   haystack  The string to search
 * @param   needle    The string to search for
 * @return            `haystack` with a maximal offset such that the returned
 *                    pointer begins with `needle`, `NULL` if no such offset
 *                    exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrstr(const char *, const char *);
#ifndef strrstr
# define strrstr libsimple_strrstr
#endif


/**
 * Scans a string for a substring, the comparison is case-insensitive
 * 
 * @param   haystack  The string to search
 * @param   needle    The string to search for
 * @return            `haystack` with a minimal offset such that the returned
 *                    pointer begins with `needle`, `NULL` if no such offset
 *                    exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strcasestr(const char *, const char *);
#ifndef strcasestr
# define strcasestr libsimple_strcasestr
#endif


/**
 * Scans a string for a substring, the comparison is case-insensitive
 * 
 * @param   haystack  The string to search
 * @param   needle    The string to search for
 * @return            `haystack` with a maximal offset such that the returned
 *                    pointer begins with `needle`, `NULL` if no such offset
 *                    exists
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrcasestr(const char *, const char *);
#ifndef strrcasestr
# define strrcasestr libsimple_strrcasestr
#endif


/**
 * Compare two strings, and support `NULL` as less than
 * the empty string, the comparison is case-sensitive
 * 
 * @param   a  One of the strings, may be `NULL`
 * @param   b  The other string, may be `NULL`
 * @return     A negative value if `a` is less than `b`,
 *             a positive value if `a` is greater than `b`,
 *             0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strcmpnul(const char *__a, const char *__b)
{ return (!__a || !__b) ? !__b - !__a : strcmp(__a, __b); }
#ifndef strcmpnul
# define strcmpnul libsimple_strcmpnul
#endif


/**
 * Compare two strings, and support `NULL` as less than
 * the empty string, the comparison is case-insensitive
 * 
 * @param   a  One of the strings, may be `NULL`
 * @param   b  The other string, may be `NULL`
 * @return     A negative value if `a` is less than `b`,
 *             a positive value if `a` is greater than `b`,
 *             0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strcasecmpnul(const char *__a, const char *__b)
{ return (!__a || !__b) ? !__b - !__a : strcasecmp(__a, __b); }
#ifndef strcasecmpnul
# define strcasecmpnul libsimple_strcasecmpnul
#endif


/**
 * Compare two strings, without support for `NULL`,
 * the comparison is case-sensitive
 * 
 * @param   a  One of the strings, may not be `NULL`
 * @param   b  The other string, may not be `NULL`
 * @return     1 if the strings are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_streq(const char *__a, const char *__b)
{ return !strcmp(__a, __b); }
#ifndef streq
# define streq libsimple_streq
#endif


/**
 * Compare two strings, with support for `NULL`,
 * the comparison is case-sensitive
 * 
 * @param   a  One of the strings, may be `NULL`
 * @param   b  The other string, may be `NULL`
 * @return     1 if the strings are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_streqnul(const char *__a, const char *__b)
{ return !strcmpnul(__a, __b); }
#ifndef streqnul
# define streqnul libsimple_streqnul
#endif


/**
 * Compare two strings, without support for `NULL`,
 * the comparison is case-insensitive
 * 
 * @param   a  One of the strings, may not be `NULL`
 * @param   b  The other string, may not be `NULL`
 * @return     1 if the strings are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strcaseeq(const char *__a, const char *__b)
{ return !strcasecmp(__a, __b); }
#ifndef strcaseeq
# define strcaseeq libsimple_strcaseeq
#endif


/**
 * Compare two strings, with support for `NULL`,
 * the comparison is case-insensitive
 * 
 * @param   a  One of the strings, may be `NULL`
 * @param   b  The other string, may be `NULL`
 * @return     1 if the strings are equal, 0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strcaseeqnul(const char *__a, const char *__b)
{ return !strcasecmpnul(__a, __b); }
#ifndef strcaseeqnul
# define strcaseeqnul libsimple_strcaseeqnul
#endif


/**
 * Compares the beginning of two strings, the comparison is case-sensitive
 * 
 * @param   a  One of the strings
 * @param   b  The other string
 * @return     The number of bytes `a` and `b` have
 *             in common in their beginnings
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
size_t libsimple_streqlen(const char *, const char *);
#ifndef streqlen
# define streqlen libsimple_streqlen
#endif


/**
 * Compares the beginning of two strings, the comparison is case-insensitive
 * 
 * @param   a  One of the strings
 * @param   b  The other string
 * @return     The number of bytes `a` and `b` have
 *             in common in their beginnings
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
size_t libsimple_strcaseeqlen(const char *, const char *);
#ifndef strcaseeqlen
# define strcaseeqlen libsimple_strcaseeqlen
#endif


/**
 * Compares the end of two strings, the comparison is case-sensitive
 * 
 * @param   a  One of the strings
 * @param   b  The other string
 * @return     The number of bytes `a` and `b` have
 *             in common in their ends
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline size_t libsimple_strreqlen(const char *__a, const char *__b)
{ return memreqlen(__a, strlen(__a), __b, strlen(__b)); }
#ifndef strreqlen
# define strreqlen libsimple_strreqlen
#endif


/**
 * Compares the end of two strings, the comparison is case-insensitive
 * 
 * @param   a  One of the strings
 * @param   b  The other string
 * @return     The number of bytes `a` and `b` have
 *             in common in their ends
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline size_t libsimple_strrcaseeqlen(const char *__a, const char *__b)
{ return memrcaseeqlen(__a, strlen(__a), __b, strlen(__b)); }
#ifndef strrcaseeqlen
# define strrcaseeqlen libsimple_strrcaseeqlen
#endif


/**
 * Check whether a byte is in a string of bytes, the scan is case-sensitive
 * 
 * @param   c  The byte to look for, will not be found if it is the NUL byte
 * @param   s  The string to look in
 * @return     1 if the byte `c` is not the NUL byte and can be found in `s`,
 *             0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_inchrset(int __c, const char *__s)
{ return __c && strchr(__s, __c); }
#ifndef inchrset
# define inchrset libsimple_inchrset
#endif


/**
 * Check whether a byte is in a string of bytes, the scan is case-insensitive
 * 
 * @param   c  The byte to look for, will not be found if it is the NUL byte
 * @param   s  The string to look in
 * @return     1 if the byte `c` is not the NUL byte and can be found in `s`,
 *             0 otherwise
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_inchrcaseset(int __c, const char *__s)
{ return __c && strcasechr(__s, __c); }
#ifndef inchrcaseset
# define inchrcaseset libsimple_inchrcaseset
#endif


/**
 * Moves a string within a string
 * 
 * @param   d  The location in the string's byte array where the
 *             string should be moved to
 * @param   s  The string to move
 * @return     `d`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline char *libsimple_strmove(char *__d, const char *__s) /* TODO test */
{ return memmove(__d, __s, strlen(__s) + 1); }
#ifndef strmove
# define strmove libsimple_strmove
#endif


/**
 * Moves a string within a string
 * 
 * @param   d  The location in the string's byte array where the
 *             string should be moved to
 * @param   s  The string to move
 * @return     `&d[strlen(s)]` (this byte will be a NUL byte)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline char *libsimple_stpmove(char *__d, const char *__s) /* TODO test */
{ size_t __n = strlen(__s); memmove(__d, __s, __n + 1); return &__d[__n]; }
#ifndef stpmove
# define stpmove libsimple_stpmove
#endif


/**
 * Check whether a NUL-terminated string is encoded in UTF-8
 * 
 * @param   string              The string
 * @param   allow_modified_nul  Whether Modified UTF-8 is allowed, which
 *                              allows a two-byte encoding for NUL
 * @return                      1 if good, 0 on encoding error
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strisutf8(const char *__string, int __allow_modified_nul)
{ return libsimple_memisutf8(__string, strlen(__string) ,__allow_modified_nul); }
#ifndef strisutf8
# define strisutf8 libsimple_strisutf8
#endif
