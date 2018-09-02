/* See LICENSE file for copyright and license details. */

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strchrnul(const char *, int);
#ifndef strchrnul
# define strchrnul libsimple_strchrnul
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline char *libsimple_strend(const char *__s)
{ return strchr(__s, '\0'); }
#ifndef strend
# define strend libsimple_strend
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strstarts(const char *, const char *);
#ifndef strstarts
# define strstarts libsimple_strstarts
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strcasestarts(const char *__s, const char *__t)
{ return !strncasecmp(__s, __t, strlen(__t)); }
#ifndef strcasestarts
# define strcasestarts libsimple_strcasestarts
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strends(const char *, const char *);
#ifndef strends
# define strends libsimple_strends
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strcaseends(const char *, const char *);
#ifndef strcaseends
# define strcaseends libsimple_strcaseends
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrstr(const char *, const char *);
#ifndef strrstr
# define strrstr libsimple_strrstr
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strcasestr(const char *, const char *);
#ifndef strcasestr
# define strcasestr libsimple_strcasestr
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrcasestr(const char *, const char *);
#ifndef strrcasestr
# define strrcasestr libsimple_strrcasestr
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strcmpnul(const char *__a, const char *__b)
{ return (!__a || !__b) ? !__b - !__a : strcmp(__a, __b); }
#ifndef strcmpnul
# define strcmpnul libsimple_strcmpnul
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strcasecmpnul(const char *__a, const char *__b)
{ return (!__a || !__b) ? !__b - !__a : strcasecmp(__a, __b); }
#ifndef strcasecmpnul
# define strcasecmpnul libsimple_strcasecmpnul
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_streq(const char *__a, const char *__b)
{ return !strcmp(__a, __b); }
#ifndef streq
# define streq libsimple_streq
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_streqnul(const char *__a, const char *__b)
{ return !strcmpnul(__a, __b); }
#ifndef streqnul
# define streqnul libsimple_streqnul
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strcaseeq(const char *__a, const char *__b)
{ return !strcasecmp(__a, __b); }
#ifndef strcaseeq
# define strcaseeq libsimple_strcaseeq
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strcaseeqnul(const char *__a, const char *__b)
{ return !strcasecmpnul(__a, __b); }
#ifndef strcaseeqnul
# define strcaseeqnul libsimple_strcaseeqnul
#endif
