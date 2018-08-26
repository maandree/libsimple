/* See LICENSE file for copyright and license details. */
#ifndef LIBSIMPLE_H
#define LIBSIMPLE_H


#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <aio.h>
#include <alloca.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <grp.h>
#include <inttypes.h>
#include <limits.h>
#include <netdb.h>
#include <poll.h>
#include <pwd.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>


#if defined(__GNUC__) && !defined(__clang__)
# define _LIBSIMPLE_GCC_ONLY(x) x
#else
# define _LIBSIMPLE_GCC_ONLY(x)
#endif


extern int libsimple_default_failure_exit;


#ifndef DONT_DEFINE_CLOCK_MONOTONIC_RAW
# ifndef CLOCK_MONOTONIC_RAW
#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
# endif
#endif


#ifdef AF_LOCAL
# ifndef AF_UNIX
#  define AF_UNIX AF_LOCAL
# endif
# ifndef AF_FILE
#  define AF_FILE AF_LOCAL
# endif
#endif

#ifdef AF_UNIX
# ifndef AF_LOCAL
#  define AF_LOCAL AF_UNIX
# endif
# ifndef AF_FILE
#  define AF_FILE AF_UNIX
# endif
#endif

#ifdef AF_FILE
# ifndef AF_LOCAL
#  define AF_LOCAL AF_FILE
# endif
# ifndef AF_UNIX
#  define AF_UNIX AF_FILE
# endif
#endif

#ifdef AF_NETLINK
# ifndef AF_ROUTE
#  define AF_ROUTE AF_NETLINK
# endif
#endif

#ifdef AF_ROUTE
# ifndef AF_NETLINK
#  define AF_NETLINK AF_ROUTE
# endif
#endif

#ifdef PF_LOCAL
# ifndef PF_UNIX
#  define PF_UNIX PF_LOCAL
# endif
# ifndef PF_FILE
#  define PF_FILE PF_LOCAL
# endif
#endif

#ifdef PF_UNIX
# ifndef PF_LOCAL
#  define PF_LOCAL PF_UNIX
# endif
# ifndef PF_FILE
#  define PF_FILE PF_UNIX
# endif
#endif

#ifdef PF_FILE
# ifndef PF_LOCAL
#  define PF_LOCAL PF_FILE
# endif
# ifndef PF_UNIX
#  define PF_UNIX PF_FILE
# endif
#endif

#ifdef PF_NETLINK
# ifndef PF_ROUTE
#  define PF_ROUTE PF_NETLINK
# endif
#endif

#ifdef PF_ROUTE
# ifndef PF_NETLINK
#  define PF_NETLINK PF_ROUTE
# endif
#endif

#if !defined(PF_UNIX) && defined(AF_UNIX)
# define PF_UNIX AF_UNIX
#endif
#if !defined(PF_LOCAL) && defined(AF_LOCAL)
# define PF_LOCAL AF_LOCAL
#endif
#if !defined(PF_FILE) && defined(AF_FILE)
# define PF_FILE AF_FILE
#endif
#if !defined(PF_INET) && defined(AF_INET)
# define PF_INET AF_INET
#endif
#if !defined(PF_INET6) && defined(AF_INET6)
# define PF_INET6 AF_INET6
#endif
#if !defined(PF_NETLINK) && defined(AF_NETLINK)
# define PF_NETLINK AF_NETLINK
#endif
#if !defined(PF_ROUTE) && defined(AF_ROUTE)
# define PF_ROUTE AF_ROUTE
#endif


#ifndef MIN
# define MIN(A, B) ((A) < (B) ? (A) : (B))
#endif


#ifndef MAX
# define MAX(A, B) ((A) > (B) ? (A) : (B))
#endif


#ifndef MIN3
# define MIN3(A, B, C) MIN(MIN((A), (B)), (C))
#endif


#ifndef MAX3
# define MAX3(A, B, C) MAX(MAX((A), (B)), (C))
#endif


#ifndef ELEMSOF
# define ELEMSOF(ARR) (sizeof(ARR) / (sizeof(*(ARR))))
#endif


#ifndef STRLEN
# define STRLEN(STR) (sizeof(STR) - 1)
#endif


#ifndef INTSTRLEN
# define INTSTRLEN(TYPE) ((sizeof(TYPE) == 1 ? 3 : 5 * (sizeof(TYPE) / 2)) + ((TYPE)-1 < 0))
#endif


#ifndef TYPE_MAX
# define TYPE_MAX(TYPE) ((TYPE)(((1ULL << (8 * sizeof(TYPE) - 1)) - 1) << ((TYPE)-1 > 0) | 1))
#endif


#ifndef TYPE_MIN
# define TYPE_MIN(TYPE) ((TYPE)((TYPE)-1 > 0 ? 0 : (TYPE)~0 < (TYPE)-1 ? (TYPE)~0 : (TYPE)(1ULL << (8 * sizeof(TYPE) - 1))))
#endif


#ifndef BLKCNT64_MAX
# define BLKCNT64_MAX   TYPE_MAX(blkcnt64_t)
#endif

#ifndef BLKCNT_MAX
# define BLKCNT_MAX     TYPE_MAX(blkcnt_t)
#endif

#ifndef BLKSIZE_MAX
# define BLKSIZE_MAX    TYPE_MAX(blksize_t)
#endif

#ifndef CC_MAX
# define CC_MAX         TYPE_MAX(cc_t)
#endif

#ifndef CLOCKID_MAX
# define CLOCKID_MAX    TYPE_MAX(clockid_t)
#endif

#ifndef CLOCK_MAX
# define CLOCK_MAX      TYPE_MAX(clock_t)
#endif

#ifndef DEV_MAX
# define DEV_MAX        TYPE_MAX(dev_t)
#endif

#ifndef FSBLKCNT64_MAX
# define FSBLKCNT64_MAX TYPE_MAX(fsblkcnt64_t)
#endif

#ifndef FSBLKCNT_MAX
# define FSBLKCNT_MAX   TYPE_MAX(fsblkcnt_t)
#endif

#ifndef FSFILCNT64_MAX
# define FSFILCNT64_MAX TYPE_MAX(fsfilcnt64_t)
#endif

#ifndef FSFILCNT_MAX
# define FSFILCNT_MAX   TYPE_MAX(fsfilcnt_t)
#endif

#ifndef GID_MAX
# define GID_MAX        TYPE_MAX(gid_t)
#endif

#ifndef ID_MAX
# define ID_MAX         TYPE_MAX(id_t)
#endif

#ifndef INO64_MAX
# define INO64_MAX      TYPE_MAX(ino64_t)
#endif

#ifndef INO_MAX
# define INO_MAX        TYPE_MAX(ino_t)
#endif

#ifndef KEY_MAX
# define KEY_MAX        TYPE_MAX(key_t)
#endif

#ifndef LOFF_MAX
# define LOFF_MAX       TYPE_MAX(loff_t)
#endif

#ifndef MODE_MAX
# define MODE_MAX       TYPE_MAX(mode_t)
#endif

#ifndef NLINK_MAX
# define NLINK_MAX      TYPE_MAX(nlink_t)
#endif

#ifndef OFF64_MAX
# define OFF64_MAX      TYPE_MAX(off64_t)
#endif

#ifndef OFF_MAX
# define OFF_MAX        TYPE_MAX(off_t)
#endif

#ifndef PID_MAX
# define PID_MAX        TYPE_MAX(pid_t)
#endif

#ifndef QUAD_MAX
# define QUAD_MAX       TYPE_MAX(quad_t)
#endif

#ifndef REGISTER_MAX
# define REGISTER_MAX   TYPE_MAX(register_t)
#endif

#ifndef RLIM64_MAX
# define RLIM64_MAX     TYPE_MAX(rlim64_t)
#endif

#ifndef RLIM_MAX
# define RLIM_MAX       TYPE_MAX(rlim_t)
#endif

#ifndef SOCKLEN_MAX
# define SOCKLEN_MAX    TYPE_MAX(socklen_t)
#endif

#ifndef SPEED_MAX
# define SPEED_MAX      TYPE_MAX(speed_t)
#endif

#ifndef SUSECONDS_MAX
# define SUSECONDS_MAX  TYPE_MAX(suseconds_t)
#endif

#ifndef TCFLAG_MAX
# define TCFLAG_MAX     TYPE_MAX(tcflag_t)
#endif

#ifndef TIME_MAX
# define TIME_MAX       TYPE_MAX(time_t)
#endif

#ifndef UID_MAX
# define UID_MAX        TYPE_MAX(uid_t)
#endif

#ifndef USECONDS_MAX
# define USECONDS_MAX   TYPE_MAX(useconds_t)
#endif

#ifndef U_QUAD_MAX
# define U_QUAD_MAX     TYPE_MAX(u_quad_t)
#endif


#ifndef BLKCNT64_MIN
# define BLKCNT64_MIN   TYPE_MIN(blkcnt64_t)
#endif

#ifndef BLKCNT_MIN
# define BLKCNT_MIN     TYPE_MIN(blkcnt_t)
#endif

#ifndef BLKSIZE_MIN
# define BLKSIZE_MIN    TYPE_MIN(blksize_t)
#endif

#ifndef CC_MIN
# define CC_MIN         TYPE_MIN(cc_t)
#endif

#ifndef CLOCKID_MIN
# define CLOCKID_MIN    TYPE_MIN(clockid_t)
#endif

#ifndef CLOCK_MIN
# define CLOCK_MIN      TYPE_MIN(clock_t)
#endif

#ifndef DEV_MIN
# define DEV_MIN        TYPE_MIN(dev_t)
#endif

#ifndef FSBLKCNT64_MIN
# define FSBLKCNT64_MIN TYPE_MIN(fsblkcnt64_t)
#endif

#ifndef FSBLKCNT_MIN
# define FSBLKCNT_MIN   TYPE_MIN(fsblkcnt_t)
#endif

#ifndef FSFILCNT64_MIN
# define FSFILCNT64_MIN TYPE_MIN(fsfilcnt64_t)
#endif

#ifndef FSFILCNT_MIN
# define FSFILCNT_MIN   TYPE_MIN(fsfilcnt_t)
#endif

#ifndef GID_MIN
# define GID_MIN        TYPE_MIN(gid_t)
#endif

#ifndef ID_MIN
# define ID_MIN         TYPE_MIN(id_t)
#endif

#ifndef INO64_MIN
# define INO64_MIN      TYPE_MIN(ino64_t)
#endif

#ifndef INO_MIN
# define INO_MIN        TYPE_MIN(ino_t)
#endif

#ifndef KEY_MIN
# define KEY_MIN        TYPE_MIN(key_t)
#endif

#ifndef LOFF_MIN
# define LOFF_MIN       TYPE_MIN(loff_t)
#endif

#ifndef MODE_MIN
# define MODE_MIN       TYPE_MIN(mode_t)
#endif

#ifndef NLINK_MIN
# define NLINK_MIN      TYPE_MIN(nlink_t)
#endif

#ifndef OFF64_MIN
# define OFF64_MIN      TYPE_MIN(off64_t)
#endif

#ifndef OFF_MIN
# define OFF_MIN        TYPE_MIN(off_t)
#endif

#ifndef PID_MIN
# define PID_MIN        TYPE_MIN(pid_t)
#endif

#ifndef QUAD_MIN
# define QUAD_MIN       TYPE_MIN(quad_t)
#endif

#ifndef REGISTER_MIN
# define REGISTER_MIN   TYPE_MIN(register_t)
#endif

#ifndef RLIM64_MIN
# define RLIM64_MIN     TYPE_MIN(rlim64_t)
#endif

#ifndef RLIM_MIN
# define RLIM_MIN       TYPE_MIN(rlim_t)
#endif

#ifndef SOCKLEN_MIN
# define SOCKLEN_MIN    TYPE_MIN(socklen_t)
#endif

#ifndef SPEED_MIN
# define SPEED_MIN      TYPE_MAX(speed_t)
#endif

#ifndef SUSECONDS_MIN
# define SUSECONDS_MIN  TYPE_MIN(suseconds_t)
#endif

#ifndef TCFLAG_MIN
# define TCFLAG_MIN     TYPE_MAX(tcflag_t)
#endif

#ifndef TIME_MIN
# define TIME_MIN       TYPE_MIN(time_t)
#endif

#ifndef UID_MIN
# define UID_MIN        TYPE_MIN(uid_t)
#endif

#ifndef USECONDS_MIN
# define USECONDS_MIN   TYPE_MIN(useconds_t)
#endif

#ifndef U_QUAD_MIN
# define U_QUAD_MIN     TYPE_MIN(u_quad_t)
#endif


#define FREE(PTR) (free(PTR), (PTR) = NULL, 0) /* TODO test */

#define CLOSE(FD) libsimple_close(&(FD)) /* TODO test */

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline int
libsimple_close(int *__fdp)
{
	int __ret;
	if (*__fdp < 0)
		return 0;
	__ret = close(*__fdp);
	*__fdp = -1;
	return __ret;
}


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
void *libsimple_rawmemchr(const void *, int);
#ifndef rawmemchr
# define rawmemchr libsimple_rawmemchr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
void *libsimple_memrchr(const void *, int, size_t);
#ifndef memrchr
# define memrchr libsimple_memrchr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
void *libsimple_rawmemrchr(const void *, int, size_t);
#ifndef rawmemrchr
# define rawmemrchr libsimple_rawmemrchr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strchrnul(const char *, int);
#ifndef strchrnul
# define strchrnul libsimple_strchrnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline char *libsimple_strend(const char *__s) { return strchr(__s, '\0'); }
#ifndef strend
# define strend libsimple_strend
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_inchrset(int __c, const char *__s) { return __c && strchr(__s, __c); }
#ifndef inchrset
# define inchrset libsimple_inchrset
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __warn_unused_result__)))
void *libsimple_memdup(const void *, size_t);
#ifndef memdup
# define memdup libsimple_memdup
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __warn_unused_result__)))
char *libsimple_strndup(const char *, size_t);
#ifndef strndup
# define strndup libsimple_strndup
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *libsimple_mempcpy(void *__d, const void *__s, size_t __n)
{ return &((char *)memcpy(__d, __s, __n))[__n]; }
#ifndef mempcpy
# define mempcpy libsimple_mempcpy
#endif


#if defined(__GNUC__) || defined(__clang__)
# define libsimple_strdupa(s)\
	({\
		const char *__s = (s);\
		size_t __n = strlen(__s) + 1;\
		char *__r = alloca(__n);\
		memcpy(__r, __s, __n);\
	})
# ifndef strdupa
#  define strdupa(s) libsimple_strdupa(s)
# endif
#endif


#if defined(__GNUC__) || defined(__clang__)
# define libsimple_strndupa(s, n)\
	({\
		const char *__s = (s);\
		size_t __n = (n);\
		size_t __m = strlen(__s);\
		char *__r;\
		__n = __n < __m ? __n : __m;\
		__r = alloca(__n + 1);\
		memcpy(__r, __s, __n);\
		__r[__n] = '\0';\
		__r;\
	})
# ifndef strndupa
#  define strndupa(s, n) libsimple_strndupa(s, n)
# endif
#endif


#if defined(__GNUC__) || defined(__clang__)
# define libsimple_memdupa(s, n)\
	({\
		const char *__s = (s);\
		size_t __n = (n);\
		char *__r = alloca(__n);\
		memcpy(__r, __s, __n);\
	})
# ifndef memdupa
#  define memdupa(s, n) libsimple_memdupa(s, n)
# endif
#endif


/**
 * Check whether a NUL-terminated string is encoded in UTF-8
 * 
 * @param   string              The string
 * @param   allow_modified_nul  Whether Modified UTF-8 is allowed, which allows a two-byte encoding for NUL
 * @return                      1 if good, 0 on encoding error
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_isutf8(const char *, int);
#ifndef isutf8
# define isutf8 libsimple_isutf8
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1, 2), __format__(__printf__, 2, 3))))
int libsimple_asprintf(char **, const char *, ...);
#ifndef asprintf
# define asprintf libsimple_asprintf
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1, 2))))
int libsimple_vasprintf(char **, const char *, va_list);
#ifndef vasprintf
# define vasprintf libsimple_vasprintf
#endif


#if defined(__GNUC__) && !defined(__clang__)
# define libsimple_asprintfa(__fmt, ...) /* TODO test */\
	({\
		const char *__f = (__fmt);\
		char *__ret = NULL;\
		int __r = snprintf(NULL, 0, __f, __VA_ARGS__);\
		if (__r >= 0) {\
			__ret = alloca((size_t)__r + 1);\
			sprintf(__ret, __f, __VA_ARGS__);\
		}\
		__ret;\
	})
# ifndef asprintfa
#  define asprintfa(...) libsimple_asprintfa(__VA_ARGS__)
# endif
#endif


#if defined(__GNUC__) || defined(__clang__)
# define libsimple_vasprintfa(__fmt, __ap) /* TODO test */\
	({\
		const char *__f = (__fmt);\
		va_list __a = (__ap);\
		va_list __a2;\
		char *__ret = NULL;\
		int __r;\
		va_copy(__a2, __a);\
		__r = vsnprintf(NULL, 0, __f, __a);\
		if (__r >= 0) {\
			__ret = alloca((size_t)__r + 1);\
			vsprintf(__ret, __f, __a2);\
		}\
		va_end(__a2);\
		__ret;\
	})
# ifndef vasprintfa
#  define vasprintfa(fmt, ap) libsimple_vasprintfa(fmt, ap)
# endif
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memmem(const void *, size_t, const void *, size_t);
#ifndef memmem
# define memmem libsimple_memmem
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
void *libsimple_memrmem(const void *, size_t, const void *, size_t);
#ifndef memrmem
# define memrmem libsimple_memrmem
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memstarts(const void *, size_t, const void *, size_t);
#ifndef memstarts
# define memstarts libsimple_memstarts
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
int libsimple_memends(const void *, size_t, const void *, size_t);
#ifndef memends
# define memends libsimple_memends
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrstr(const char *, const char *);
#ifndef strrstr
# define strrstr libsimple_strrstr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrnstr(const char *, const char *, size_t); /* TODO test */
#ifndef strrnstr
# define strrnstr libsimple_strrnstr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strnstr(const char *, const char *, size_t); /* TODO test */
#ifndef strnstr
# define strnstr libsimple_strnstr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strrncasestr(const char *, const char *, size_t); /* TODO test */
#ifndef strrncasestr
# define strrncasestr libsimple_strrncasestr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
char *libsimple_strnstr(const char *, const char *, size_t); /* TODO test */
#ifndef strncasestr
# define strncasestr libsimple_strncasestr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_strstarts(const char *, const char *);
#ifndef strstarts
# define strstarts libsimple_strstarts
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strcasestarts(const char *__s, const char *__t) { return !strncasecmp(__s, __t, strlen(__t)); }
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
static inline int libsimple_streq(const char *__a, const char *__b) { return !strcmp(__a, __b); }
#ifndef streq
# define streq libsimple_streq
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strneq(const char *__a, const char *__b, size_t __n) { return !strncmp(__a, __b, __n); }
#ifndef strneq
# define strneq libsimple_strneq
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_streqnul(const char *__a, const char *__b) { return !strcmpnul(__a, __b); }
#ifndef streqnul
# define streqnul libsimple_streqnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strneqnul(const char *__a, const char *__b, size_t __n)
{ return !strncmpnul(__a, __b, __n); }
#ifndef strneqnul
# define strneqnul libsimple_strneqnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strcaseeq(const char *__a, const char *__b) { return !strcasecmp(__a, __b); }
#ifndef strcaseeq
# define strcaseeq libsimple_strcaseeq
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_strncaseeq(const char *__a, const char *__b, size_t __n) { return !strncasecmp(__a, __b, __n); }
#ifndef strncaseeq
# define strncaseeq libsimple_strncaseeq
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strcaseeqnul(const char *__a, const char *__b) { return !strcasecmpnul(__a, __b); }
#ifndef strcaseeqnul
# define strcaseeqnul libsimple_strcaseeqnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __warn_unused_result__)))
static inline int libsimple_strncaseeqnul(const char *__a, const char *__b, size_t __n)
{ return !strncasecmpnul(__a, __b, __n); }
#ifndef strncaseeqnul
# define strncaseeqnul libsimple_strncaseeqnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
void *libsimple_vmalloczn(int, size_t, va_list);
#ifndef vmalloczn
# define vmalloczn libsimple_vmalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *libsimple_vmallocn(size_t __n, va_list __ap) { return libsimple_vmalloczn(0, __n, __ap); } /* TODO test */
#ifndef vmallocn
# define vmallocn libsimple_vmallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *libsimple_vcallocn(size_t __n, va_list __ap) { return libsimple_vmalloczn(1, __n, __ap); } /* TODO test */
#ifndef vcallocn
# define vcallocn libsimple_vcallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
void *libsimple_vreallocn(void *, size_t, va_list); /* TODO test */
#ifndef vreallocn
# define vreallocn libsimple_vreallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *
libsimple_malloczn(int __clear, size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(__clear, __n, __ap);
	va_end(__ap);
}
#ifndef malloczn
# define malloczn libsimple_malloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *
libsimple_mallocn(size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(0, __n, __ap);
	va_end(__ap);
}
#ifndef mallocn
# define mallocn libsimple_mallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *
libsimple_callocn(size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(1, __n, __ap);
	va_end(__ap);
}
#ifndef callocn
# define callocn libsimple_callocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline void *
libsimple_reallocn(void *__ptr, size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vreallocn(__ptr, __n, __ap);
	va_end(__ap);
}
#ifndef reallocn
# define reallocn libsimple_reallocn
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmalloc(int, size_t);
#ifndef enmalloc
# define enmalloc libsimple_enmalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
void *libsimple_encalloc(int, size_t, size_t);
#ifndef encalloc
# define encalloc libsimple_encalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
void *libsimple_enrealloc(int, void *, size_t);
#ifndef enrealloc
# define enrealloc libsimple_enrealloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __warn_unused_result__, __returns_nonnull__)))
char *libsimple_enstrdup(int, const char *);
#ifndef enstrdup
# define enstrdup libsimple_enstrdup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __warn_unused_result__, __returns_nonnull__)))
char *libsimple_enstrndup(int, const char *, size_t);
#ifndef enstrndup
# define enstrndup libsimple_enstrndup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
void *libsimple_enmemdup(int, const void *, size_t);
#ifndef enmemdup
# define enmemdup libsimple_enmemdup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
void *libsimple_envmalloczn(int, int, size_t, va_list);
#ifndef envmalloczn
# define envmalloczn libsimple_envmalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envmallocn(int __st, size_t __n, va_list __ap) { return libsimple_envmalloczn(__st, 0, __n, __ap); } /* TODO test */
#ifndef envmallocn
# define envmallocn libsimple_envmallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_envcallocn(int __st, size_t __n, va_list __ap) { return libsimple_envmalloczn(__st, 1, __n, __ap); } /* TODO test */
#ifndef envcallocn
# define envcallocn libsimple_envcallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
void *libsimple_envreallocn(int, void *, size_t, va_list);
#ifndef envreallocn
# define envreallocn libsimple_envreallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmalloczn(int __status, int __clear, size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(__status, __clear, __n, __ap);
	va_end(__ap);
}
#ifndef enmalloczn
# define enmalloczn libsimple_enmalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enmallocn(int __status, size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(__status, 0, __n, __ap);
	va_end(__ap);
}
#ifndef enmallocn
# define enmallocn libsimple_enmallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_encallocn(int __status, size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(__status, 1, __n, __ap);
	va_end(__ap);
}
#ifndef encallocn
# define encallocn libsimple_encallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_enreallocn(int __status, void *__ptr, size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envreallocn(__status, __ptr, __n, __ap);
	va_end(__ap);
}
#ifndef enreallocn
# define enreallocn libsimple_enreallocn
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_emalloc(size_t __n) { return enmalloc(libsimple_default_failure_exit, __n); } /* TODO test */
#ifndef emalloc
# define emalloc libsimple_emalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ecalloc(size_t __n, size_t __m) { return encalloc(libsimple_default_failure_exit, __n, __m); } /* TODO test */
#ifndef ecalloc
# define ecalloc libsimple_ecalloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_erealloc(void *__ptr, size_t __n) { return enrealloc(libsimple_default_failure_exit, __ptr, __n); } /* TODO test */
#ifndef erealloc
# define erealloc libsimple_erealloc
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, __warn_unused_result__, __returns_nonnull__)))
static inline char *libsimple_estrdup(const char *__s) { return enstrdup(libsimple_default_failure_exit, __s); } /* TODO test */
#ifndef estrdup
# define estrdup libsimple_estrdup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, __warn_unused_result__, __returns_nonnull__)))
static inline char *libsimple_estrndup(const char *__s, size_t __n) { return enstrndup(libsimple_default_failure_exit, __s, __n); } /* TODO test */
#ifndef estrndup
# define estrndup libsimple_estrndup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_ememdup(const void *__s, size_t __n) { return enmemdup(libsimple_default_failure_exit, __s, __n); } /* TODO test */
#ifndef ememdup
# define ememdup libsimple_ememdup
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmalloczn(int __clear, size_t __n, va_list __ap) /* TODO test */
{ return libsimple_envmalloczn(libsimple_default_failure_exit, __clear, __n, __ap); }
#ifndef evmalloczn
# define evmalloczn libsimple_evmalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evmallocn(size_t __n, va_list __ap) /* TODO test */
{ return libsimple_envcallocn(libsimple_default_failure_exit, __n, __ap); }
#ifndef evmallocn
# define evmallocn libsimple_evmallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evcallocn(size_t __n, va_list __ap) /* TODO test */
{ return libsimple_envmallocn(libsimple_default_failure_exit, __n, __ap); }
#ifndef evcallocn
# define evcallocn libsimple_evcallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *libsimple_evreallocn(void *__ptr, size_t __n, va_list __ap) /* TODO test */
{ return libsimple_envreallocn(libsimple_default_failure_exit, __ptr, __n, __ap); }
#ifndef evreallocn
# define evreallocn libsimple_evreallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_emalloczn(int __c, size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(libsimple_default_failure_exit, __c, __n, __ap);
	va_end(__ap);
}
#ifndef emalloczn
# define emalloczn libsimple_emalloczn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_emallocn(size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(libsimple_default_failure_exit, 0, __n, __ap);
	va_end(__ap);
}
#ifndef emallocn
# define emallocn libsimple_emallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ecallocn(size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(libsimple_default_failure_exit, 1, __n, __ap);
	va_end(__ap);
}
#ifndef ecallocn
# define ecallocn libsimple_ecallocn
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__, __returns_nonnull__)))
static inline void *
libsimple_ereallocn(void *__p, size_t __n, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envreallocn(libsimple_default_failure_exit, __p, __n, __ap);
	va_end(__ap);
}
#ifndef ereallocn
# define ereallocn libsimple_ereallocn
#endif


/**
 * Read an environment variable, but handle it as undefined if empty
 * 
 * @param   var  The environment variable's name
 * @return       The environment variable's value, `NULL` if empty or not defined
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __warn_unused_result__)))
static inline char *
libsimple_getenv_ne(const char *__name)
{
	char *__env = getenv(__name);
	return (__env && *__env) ? __env : NULL;
}
#ifndef getenv_ne
# define getenv_ne libsimple_getenv_ne
#endif

/**
 * Read an environment variable, but handle it as empty if undefined
 * 
 * @param   var  The environment variable's name
 * @return       The environment variable's value, "" if empty or not defined
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __warn_unused_result__, __returns_nonnull__)))
static inline const char *
libsimple_getenv_e(const char *__name)
{
	const char *__env = getenv(__name);
	return (__env && *__env) ? __env : "";
}
#ifndef getenv_e
# define getenv_e libsimple_getenv_e
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
int libsimple_vputenvf(const char *, va_list);
#ifndef vputenvf
# define vputenvf libsimple_vputenvf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
void libsimple_envputenvf(int, const char *, va_list);
#ifndef envputenvf
# define envputenvf libsimple_envputenvf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __format__(__printf__, 1, 2))))
static inline int
libsimple_putenvf(const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	return vputenvf(__fmt, __ap);
	va_end(__ap);
}
#ifndef putenvf
# define putenvf libsimple_putenvf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __format__(__printf__, 1, 2))))
static inline void
libsimple_eputenvf(const char *__fmt, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __fmt);
	envputenvf(libsimple_default_failure_exit, __fmt, __ap);
	va_end(__ap);
}
#ifndef eputenvf
# define eputenvf libsimple_eputenvf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline void
libsimple_evputenvf(const char *__fmt, va_list __ap) /* TODO test */
{
	envputenvf(libsimple_default_failure_exit, __fmt, __ap);
}
#ifndef evputenvf
# define evputenvf libsimple_evputenvf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __format__(__printf__, 2, 3))))
static inline void
libsimple_enputenvf(int __status, const char *__fmt, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __fmt);
	envputenvf(__status, __fmt, __ap);
	va_end(__ap);
}
#ifndef enputenvf
# define enputenvf libsimple_enputenvf
#endif



_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
void libsimple_vweprintf(const char *, va_list);
#ifndef vweprintf
# define vweprintf libsimple_vweprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1), __format__(__printf__, 1, 2), __noreturn__)))
static inline void
libsimple_eprintf(const char *__fmt, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __fmt);
	vweprintf(__fmt, __ap);
	va_end(__ap);
	exit(libsimple_default_failure_exit);
}
#ifndef eprintf
# define eprintf libsimple_eprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1), __noreturn__)))
static inline void
libsimple_veprintf(const char *__fmt, va_list __ap) /* TODO test */
{
	vweprintf(__fmt, __ap);
	exit(libsimple_default_failure_exit);
}
#ifndef veprintf
# define veprintf libsimple_veprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __format__(__printf__, 2, 3), __noreturn__)))
static inline void
libsimple_enprintf(int __status, const char *__fmt, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __fmt);
	vweprintf(__fmt, __ap);
	va_end(__ap);
	exit(__status);
}
#ifndef enprintf
# define enprintf libsimple_enprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __noreturn__)))
static inline void
libsimple_venprintf(int __status, const char *__fmt, va_list __ap) /* TODO test */
{
	vweprintf(__fmt, __ap);
	exit(__status);
}
#ifndef venprintf
# define venprintf libsimple_venprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1), __format__(__printf__, 1, 2))))
static inline void
libsimple_weprintf(const char *__fmt, ...) /* TODO test */
{
	va_list __ap;
	va_start(__ap, __fmt);
	vweprintf(__fmt, __ap);
	va_end(__ap);
}
#ifndef weprintf
# define weprintf libsimple_weprintf
#endif


int libsimple_sendfd(int, int);
#ifndef sendfd
# define sendfd libsimple_sendfd
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
int libsimple_recvfd(int);
#ifndef recvfd
# define recvfd libsimple_recvfd
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
ssize_t libsimple_recvfrom_timestamped(int, void *restrict, size_t, int, struct sockaddr *restrict,
                                       socklen_t, struct timespec *restrict);
#ifndef recvfrom_timestamped
# define recvfrom_timestamped libsimple_recvfrom_timestamped
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__warn_unused_result__)))
static inline ssize_t
libsimple_recv_timestamped(int __fd, void *restrict __buf, size_t __n, /* TODO test */
                           int __flags, struct timespec *restrict __ts)
{
	return libsimple_recvfrom_timestamped(__fd, __buf, __n, __flags, NULL, 0, __ts);
}
#ifndef recv_timestamped
# define recv_timestamped libsimple_recv_timestamped
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
int libsimple_sumtimespec(struct timespec *, const struct timespec *, const struct timespec *);
#ifndef sumtimespec
# define sumtimespec libsimple_sumtimespec
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
int libsimple_difftimespec(struct timespec *, const struct timespec *, const struct timespec *);
#ifndef difftimespec
# define difftimespec libsimple_difftimespec
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
int libsimple_multimespec(struct timespec *, const struct timespec *, int);
#ifndef multimespec
# define multimespec libsimple_multimespec
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __warn_unused_result__)))
static inline int
libsimple_cmptimespec(const struct timespec *__a, const struct timespec *__b) /* TODO test */
{
        if (__a->tv_sec != __b->tv_sec)
                return __a->tv_sec < __b->tv_sec ? -1 : +1;
        return __a->tv_nsec < __b->tv_nsec ? -1 : __a->tv_nsec > __b->tv_nsec;
}
#ifndef cmptimespec
# define cmptimespec libsimple_cmptimespec
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
int libsimple_sumtimeval(struct timeval *, const struct timeval *, const struct timeval *);
#ifndef sumtimeval
# define sumtimeval libsimple_sumtimeval
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
int libsimple_difftimeval(struct timeval *, const struct timeval *, const struct timeval *);
#ifndef difftimeval
# define difftimeval libsimple_difftimeval
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
int libsimple_multimeval(struct timeval *, const struct timeval *, int);
#ifndef multimeval
# define multimeval libsimple_multimeval
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __warn_unused_result__)))
static inline int
libsimple_cmptimeval(const struct timeval *__a, const struct timeval *__b) /* TODO test */
{
        if (__a->tv_sec != __b->tv_sec)
                return __a->tv_sec < __b->tv_sec ? -1 : +1;
        return __a->tv_usec < __b->tv_usec ? -1 : __a->tv_usec > __b->tv_usec;
}
#ifndef cmptimeval
# define cmptimeval libsimple_cmptimeval
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline void
libsimple_timeval2timespec(struct timespec *restrict __ts, const struct timeval *restrict __tv)
{
        __ts->tv_sec = __tv->tv_sec;
        __ts->tv_nsec = __tv->tv_usec;
        __ts->tv_nsec *= 1000L;
}
#ifndef timeval2timespec
# define timeval2timespec libsimple_timeval2timespec
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
int libsimple_timespec2timeval(struct timeval *restrict, const struct timespec *restrict);
#ifndef timespec2timeval
# define timespec2timeval libsimple_timespec2timeval
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1, 2))))
int libsimple_strtotimespec(struct timespec *restrict, const char *restrict, char **restrict);
#ifndef strtotimespec
# define strtotimespec libsimple_strtotimespec
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1, 2))))
int libsimple_strtotimeval(struct timeval *restrict, const char *restrict, char **restrict);
#ifndef strtotimeval
# define strtotimeval libsimple_strtotimeval
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
char *libsimple_timespectostr(char *restrict, const struct timespec *restrict);
#ifndef timespectostr
# define timespectostr libsimple_timespectostr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2))))
char *libsimple_timevaltostr(char *restrict, const struct timeval *restrict);
#ifndef timevaltostr
# define timevaltostr libsimple_timevaltostr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline double
libsimple_timespectodouble(const struct timespec *__ts)
{
	double __ret = (double)(__ts->tv_nsec);
	__ret /= (double)1000000000L;
	__ret += (double)(__ts->tv_sec);
	return __ret;
}
#ifndef timespectodouble
# define timespectodouble libsimple_timespectodouble
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline double
libsimple_timevaltodouble(const struct timeval *__tv)
{
	double __ret = (double)(__tv->tv_usec);
	__ret /= (double)1000000L;
	__ret += (double)(__tv->tv_sec);
	return __ret;
}
#ifndef timevaltodouble
# define timevaltodouble libsimple_timevaltodouble
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
void libsimple_doubletotimespec(struct timespec *, double);
#ifndef doubletotimespec
# define doubletotimespec libsimple_doubletotimespec
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
void libsimple_doubletotimeval(struct timeval *, double);
#ifndef doubletotimeval
# define doubletotimeval libsimple_doubletotimeval
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__returns_nonnull__, __nonnull__)))
char *libsimple_minimise_number_string(char *);
#ifndef minimise_number_string
# define minimise_number_string libsimple_minimise_number_string
#endif


#define LIBSIMPLE_UNLIST(LIST, I, NP) libsimple_unlist((LIST), (I), (NP), sizeof(*(LIST)))
#ifndef UNLIST
# define UNLIST(LIST, I, NP) LIBSIMPLE_UNLIST((LIST), (I), (NP))
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline void
libsimple_unlist(void *__list, size_t __i, size_t *__np, size_t __width)
{
        char *__lst = __list;
        memmove(&__lst[__i * __width], &__lst[(__i + 1) * __width], (--*__np - __i) * __width);
}
#ifndef unlist
# define unlist libsimple_unlist
#endif


#endif
