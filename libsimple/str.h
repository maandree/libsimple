/* See LICENSE file for copyright and license details. */


/**
 * Scans for a character in a string, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @return     `s` with a minimal offset such that `*r == c || !*r`,
 *             where `r` is the returned pointer
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strchrnul(const char *, int);
#ifndef strchrnul
# define strchrnul libsimple_strchrnul
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strcasechr(const char *, int);
#ifndef strcasechr
# define strcasechr libsimple_strcasechr
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @return     `s` with a minimal offset such that `tolower(*r) == tolower(c) || !*r`,
 *             where `r` is the returned pointer
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strcasechrnul(const char *, int);
#ifndef strcasechrnul
# define strcasechrnul libsimple_strcasechrnul
#endif


/**
 * Scans for a character in a string, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to scan for
 * @return     `s` with a maximal offset such that `tolower(*r) == tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrcasechr(const char *, int);
#ifndef strrcasechr
# define strrcasechr libsimple_strrcasechr
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @return     `s` with a minimal offset such that `*r != c`, where `r`
 *             is the returned pointer, `NULL` if no such offset exists
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strchr_inv(const char *, int);
#ifndef strchr_inv
# define strchr_inv libsimple_strchr_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @return     `s` with a minimal offset such that `*r != c || !*r`,
 *             where `r` is the returned pointer
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strchrnul_inv(const char *, int);
#ifndef strchrnul_inv
# define strchrnul_inv libsimple_strchrnul_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @return     `s` with a minimal offset such that `tolower(*r) != tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strcasechr_inv(const char *, int);
#ifndef strcasechr_inv
# define strcasechr_inv libsimple_strcasechr_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @return     `s` with a minimal offset such that `tolower(*r) != tolower(c) || !*r`,
 *             where `r` is the returned pointer
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strcasechrnul_inv(const char *, int);
#ifndef strcasechrnul_inv
# define strcasechrnul_inv libsimple_strcasechrnul_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-sensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @return     `s` with a maximal offset such that `*r != c`, where `r`
 *             is the returned pointer, `NULL` if no such offset exists
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrchr_inv(const char *, int);
#ifndef strrchr_inv
# define strrchr_inv libsimple_strrchr_inv
#endif


/**
 * Scans for a character in a string with any other value that the
 * specified value, the scan is case-insensitive
 * 
 * @param   s  The string to scan
 * @param   c  The character to skip over
 * @return     `s` with a maximal offset such that `tolower(*r) != tolower(c)`,
 *             where `r` is the returned pointer, `NULL` if no such offset exists
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrcasechr_inv(const char *, int);
#ifndef strrcasechr_inv
# define strrcasechr_inv libsimple_strrcasechr_inv
#endif


/**
 * Scans for the end of a string
 * 
 * @param   s  The string
 * @return     `s` with an offset such `!*r`, where `r` is the returned pointer
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline char *
libsimple_strend(const char *s__)
{
	return strchr(s__, '\0');
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int
libsimple_strcasestarts(const char *s__, const char *t__)
{
	return !strncasecmp(s__, t__, strlen(t__));
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
static inline int
libsimple_strcmpnul(const char *a__, const char *b__)
{
	return (!a__ || !b__) ? !b__ - !a__ : strcmp(a__, b__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
static inline int
libsimple_strcasecmpnul(const char *a__, const char *b__)
{
	return (!a__ || !b__) ? !b__ - !a__ : strcasecmp(a__, b__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int
libsimple_streq(const char *a__, const char *b__)
{
	return !strcmp(a__, b__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
static inline int
libsimple_streqnul(const char *a__, const char *b__)
{
	return !libsimple_strcmpnul(a__, b__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int
libsimple_strcaseeq(const char *a__, const char *b__)
{
	return !strcasecmp(a__, b__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __warn_unused_result__)))
static inline int
libsimple_strcaseeqnul(const char *a__, const char *b__)
{
	return !libsimple_strcasecmpnul(a__, b__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline size_t
libsimple_strreqlen(const char *a__, const char *b__)
{
	return libsimple_memreqlen(a__, strlen(a__), b__, strlen(b__));
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline size_t
libsimple_strrcaseeqlen(const char *a__, const char *b__)
{
	return libsimple_memrcaseeqlen(a__, strlen(a__), b__, strlen(b__));
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int
libsimple_inchrset(int c__, const char *s__)
{
	return c__ && strchr(s__, c__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int
libsimple_inchrcaseset(int c__, const char *s__)
{
	return c__ && strcasechr(s__, c__);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
static inline char *
libsimple_strmove(char *d__, const char *s__)
{
	return memmove(d__, s__, strlen(s__) + 1);
}
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
static inline char *
libsimple_stpmove(char *d__, const char *s__)
{
	size_t n__ = strlen(s__);
	memmove(d__, s__, n__ + 1);
	return &d__[n__];
}
#ifndef stpmove
# define stpmove libsimple_stpmove
#endif


/**
 * Fill a string with a character
 * 
 * @param   s  The string to fill
 * @param   c  The byte to replace all bytes in `s` with
 * @return     `s`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
static inline char *
libsimple_strset(char *s__, int c___)
{
	char c__ = (char)c___, *r__ = s__;
	while (*s__) *s__++ = c__;
	return r__;
}
#ifndef strset
# define strset libsimple_strset
#endif


/**
 * Fill a string with a character
 * 
 * @param   s  The string to fill
 * @param   c  The byte to replace all bytes in `s` with
 * @return     `&s[strlen(s)]`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
static inline char *
libsimple_stpset(char *s__, int c___)
{
	char c__ = (char)c___;
	while (*s__) *s__++ = c__;
	return s__;
}
#ifndef stpset
# define stpset libsimple_stpset
#endif


/**
 * Copy a string, but stop after a specific character,
 * the new string will be NUL-terminated
 * 
 * @param   d  The location the string shall be copied to
 * @param   s  The string to copy
 * @param   c  The character that stops the copying
 * @return     `&strchr(d, c)[1]` (after copying) if `c` can be
 *             found in `s`, `NULL` otherwise
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
static inline char *
libsimple_strccpy(char *restrict d__, const char *restrict s__, int c___)
{
	char c__ = (char)c___;
	do {
		if ((*d__++ = *s__) == c__) {
			*d__ = '\0';
			return d__;
		}
	} while (*s__++);
	return NULL;
}
#ifndef strccpy
# define strccpy libsimple_strccpy
#endif


/**
 * Move a string, but stop after a specific character
 * 
 * @param   d  The location the string shall be moved to
 * @param   s  The string to copy
 * @param   c  The character that stops the copying
 * @return     `&strchr(d, c)[1]` (after copying) if `c` can be
 *             found in `s` (before copying), `NULL` otherwise
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
char *libsimple_strcmove(char *, const char *, int);
#ifndef strcmove
# define strcmove libsimple_strcmove
#endif


/**
 * Replace all instances of a character in an string with
 * another character
 * 
 * @param   s    The string
 * @param   old  The value of the characters to replace
 * @param   new  The value to replace the characters with
 * @return       `strchr(s, '\0')`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
static inline char *
libsimple_strreplace(char *s__, int old___, int new___)
{
	char old__ = (char)old___, new__ = (char)new___;
	for (; *s__; s__++)
		if (*s__ == old__)
			*s__ = new__;
	return s__;
}
#ifndef strreplace
# define strreplace libsimple_strreplace
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
 * @return     `strchr(d, '\0')` (after copying)
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
char *libsimple_stptolower(char *, const char *);
#ifndef stptolower
# define stptolower libsimple_stptolower
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
 * @return     `strchr(d, '\0')` (after copying)
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
char *libsimple_stptoupper(char *, const char *);
#ifndef stptoupper
# define stptoupper libsimple_stptoupper
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
 * @return     `d`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
static inline char *
libsimple_strtolower(char *d__, const char *s__)
{
	libsimple_stptolower(d__, s__);
	return d__;
}
#ifndef strtolower
# define strtolower libsimple_strtolower
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
 * @return     `d`
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __returns_nonnull__)))
static inline char *
libsimple_strtoupper(char *d__, const char *s__)
{
	libsimple_stptoupper(d__, s__);
	return d__;
}
#ifndef strtoupper
# define strtoupper libsimple_strtoupper
#endif


/**
 * Check whether a NUL-terminated string is encoded in UTF-8
 * 
 * @param   string              The string
 * @param   allow_modified_nul  Whether Modified UTF-8 is allowed, which
 *                              allows a two-byte encoding for NUL
 * @return                      1 if good, 0 on encoding error
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int
libsimple_strisutf8(const char *string__, int allow_modified_nul__)
{
	return libsimple_memisutf8(string__, strlen(string__), allow_modified_nul__);
}
#ifndef strisutf8
# define strisutf8 libsimple_strisutf8
#endif
