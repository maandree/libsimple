/* See LICENSE file for copyright and license details. */


/* TODO strneqlen */
/* TODO strncaseeqlen */
/* TODO strrneqlen */
/* TODO strrncaseeqlen */


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strnchr(const char *, int, size_t);
#ifndef strnchr
# define strnchr libsimple_strnchr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strncasechr(const char *, int, size_t);
#ifndef strncasechr
# define strncasechr libsimple_strncasechr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strnchrnul(const char *, int, size_t);
#ifndef strnchrnul
# define strnchrnul libsimple_strnchrnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strncasechrnul(const char *, int, size_t);
#ifndef strncasechrnul
# define strncasechrnul libsimple_strncasechrnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrnchr(const char *, int, size_t);
#ifndef strrnchr
# define strrnchr libsimple_strrnchr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrncasechr(const char *, int, size_t);
#ifndef strrncasechr
# define strrncasechr libsimple_strrncasechr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __returns_nonnull__, __warn_unused_result__)))
char *libsimple_strnend(const char *, size_t);
#ifndef strnend
# define strnend libsimple_strnend
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strnstr(const char *, const char *, size_t);
#ifndef strnstr
# define strnstr libsimple_strnstr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strncasestr(const char *, const char *, size_t);
#ifndef strncasestr
# define strncasestr libsimple_strncasestr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrnstr(const char *, const char *, size_t);
#ifndef strrnstr
# define strrnstr libsimple_strrnstr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrncasestr(const char *, const char *, size_t);
#ifndef strrncasestr
# define strrncasestr libsimple_strrncasestr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strnstarts(const char *, const char *, size_t);
#ifndef strnstarts
# define strnstarts libsimple_strnstarts
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strncasestarts(const char *, const char *, size_t);
#ifndef strncasestarts
# define strncasestarts libsimple_strncasestarts
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strnends(const char *, const char *, size_t);
#ifndef strnends
# define strnends libsimple_strnends
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strncaseends(const char *, const char *, size_t);
#ifndef strncaseends
# define strncaseends libsimple_strncaseends
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strncmpnul(const char *__a, const char *__b, size_t __n)
{ return (!__a || !__b) ? !__b - !__a : strncmp(__a, __b, __n); }
#ifndef strncmpnul
# define strncmpnul libsimple_strncmpnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strncasecmpnul(const char *__a, const char *__b, size_t __n)
{ return (!__a || !__b) ? !__b - !__a : strncasecmp(__a, __b, __n); }
#ifndef strncasecmpnul
# define strncasecmpnul libsimple_strncasecmpnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strneq(const char *__a, const char *__b, size_t __n)
{ return !strncmp(__a, __b, __n); }
#ifndef strneq
# define strneq libsimple_strneq
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strneqnul(const char *__a, const char *__b, size_t __n)
{ return !strncmpnul(__a, __b, __n); }
#ifndef strneqnul
# define strneqnul libsimple_strneqnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strncaseeq(const char *__a, const char *__b, size_t __n)
{ return !strncasecmp(__a, __b, __n); }
#ifndef strncaseeq
# define strncaseeq libsimple_strncaseeq
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strncaseeqnul(const char *__a, const char *__b, size_t __n)
{ return !strncasecmpnul(__a, __b, __n); }
#ifndef strncaseeqnul
# define strncaseeqnul libsimple_strncaseeqnul
#endif
