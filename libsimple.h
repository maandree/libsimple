/* See LICENSE file for copyright and license details. */
#ifndef LIBSIMPLE_H
#define LIBSIMPLE_H


#include <alloca.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>


#if defined(__GNUC__) && !defined(__clang__)
# define _LIBSIMPLE_GCC_ONLY(x) x
#else
# define _LIBSIMPLE_GCC_ONLY(x)
#endif


extern int libsimple_default_failure_exit;


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
void *libsimple_rawmemchr(const void *, int);
#ifndef rawmemchr
# define rawmemchr libsimple_rawmemchr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
void *libsimple_memrchr(const void *, int, size_t);
#ifndef memrchr
# define memrchr libsimple_memrchr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
void *libsimple_rawmemrchr(const void *, int, size_t);
#ifndef rawmemrchr
# define rawmemrchr libsimple_rawmemrchr
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
char *libsimple_strchrnul(const char *, int);
#ifndef strchrnul
# define strchrnul libsimple_strchrnul
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
static inline char *libsimple_strend(const char *__s) { return strchr(__s, '\0'); }
#ifndef strend
# define strend libsimple_strend
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
static inline int libsimple_inchrset(int __c, const char *__s) { return __c && strchr(__s, __c); }
#ifndef inchrset
# define inchrset libsimple_inchrset
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, warn_unused_result)))
void *libsimple_memdup(const void *, size_t);
#ifndef memdup
# define memdup libsimple_memdup
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, warn_unused_result)))
char *libsimple_strndup(const char *, size_t);
#ifndef strndup
# define strndup libsimple_strndup
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result)))
static inline void *libsimple_mempcpy(void *__d, const void *__s, size_t __n)
{ return &((char *)memcpy(__d, __s, __n))[__n]; }
#ifndef mempcpy
# define mempcpy libsimple_mempcpy
#endif


#ifndef strdupa
# if defined(__GNUC__) || defined(__clang__)
#  define strdupa(s)\
	({\
		const char *__s = (s);\
		size_t __n = strlen(__s) + 1;\
		char *__r = alloca(__n);\
		memcpy(__r, __s, __n);\
	})
# endif
#endif


#ifndef strdupa
# if defined(__GNUC__) || defined(__clang__)
#  define strndupa(s, n)\
	({\
		const char *__s = (s);\
		size_t __n = (n);\
		size_t __m = strlen(__s);\
		char *__r;\
		__n = __n < __m ? __n : __m;\
		__r = alloca(__n + 1);\
		memcpy(__r, __s, __n);\
		__r[n] = '\0';\
		__r;\
	})
# endif
#endif


#ifndef strdupa
# if defined(__GNUC__) || defined(__clang__)
#  define memdupa(s, n)\
	({\
		const char *__s = (s);\
		size_t __n = (n);\
		char *__r = alloca(__n);\
		memcpy(__r, __s, __n);\
	})
# endif
#endif


/**
 * Check whether a NUL-terminated string is encoded in UTF-8
 * 
 * @param   string              The string
 * @param   allow_modified_nul  Whether Modified UTF-8 is allowed, which allows a two-byte encoding for NUL
 * @return                      1 if good, 0 on encoding error
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
int libsimple_isutf8(const char *, int);
#ifndef isutf8
# define isutf8 libsimple_isutf8
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull(1, 2), format(printf, 2, 3))))
int libsimple_asprintf(char **, const char *, ...);
#ifndef asprintf
# define asprintf libsimple_asprintf
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull(1, 2))))
int libsimple_vasprintf(char **, const char *, va_list);
#ifndef vasprintf
# define vasprintf libsimple_vasprintf
#endif


#ifndef asprintfa
# if defined(__GNUC__) && !defined(__clang__)
#  define asprintfa(__fmt, ...)\
	({\
		const char *__f = (__fmt);\
		char *__ret = NULL;\
		int __r = snprintf(NULL, 0, __f, __VA_ARGS__);\
		if (__r < 0) {\
			__ret;\
		} else if ((size_t)__r == SIZE_MAX) {\
			errno = ENOMEM;\
			__ret;\
		} else {\
			__ret = alloca((size_t)__r + 1);\
			sprintf(__ret, __f, __VA_ARGS__);\
			__ret;\
		}\
	})
# endif
#endif


#ifndef vasprintfa
# if defined(__GNUC__) || defined(__clang__)
#  define vasprintfa(__fmt, __ap)\
	({\
		const char *__f = (__fmt);\
		va_list __a = (__ap);\
		va_list __a2;\
		char *__ret = NULL;\
		int __r;\
		va_copy(__a2, __a);\
		__r = vsnprintf(NULL, 0, __f, __a);\
		if (__r < 0);\
		else if ((size_t)__r == SIZE_MAX) {\
			errno = ENOMEM;\
		} else {\
			__ret = alloca((size_t)__r + 1);\
			vsprintf(__ret, __f, __a2);\
		}\
		va_end(__a2);\
		__ret;\
	})
# endif
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, warn_unused_result)))
void *libsimple_memmem(const void *, size_t, const void *, size_t);
#ifndef memmem
# define memmem libsimple_memmem
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, warn_unused_result)))
int libsimple_memstarts(const void *, size_t, const void *, size_t);
#ifndef memstarts
# define memstarts libsimple_memstarts
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, warn_unused_result)))
int libsimple_memends(const void *, size_t, const void *, size_t);
#ifndef memends
# define memends libsimple_memends
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
int libsimple_strstarts(const char *, const char *);
#ifndef strstarts
# define strstarts libsimple_strstarts
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
int libsimple_strends(const char *, const char *);
#ifndef strends
# define strends libsimple_strends
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((pure, nonnull, warn_unused_result)))
char *libsimple_strcasestr(const char *, const char *);
#ifndef strcasestr
# define strcasestr libsimple_strcasestr
#endif


#define malloczn(CLEAR, ...) _libsimple_malloczn((CLEAR), __VA_ARGS__, (size_t)0)
#define mallocn(...) malloczn(0, __VA_ARGS__)
#define callocn(...) malloczn(1, __VA_ARGS__)

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result)))
void *libsimple_vmalloczn(int, size_t, va_list);

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result)))
static inline void *libsimple_vmallocn(size_t __n, va_list __ap) { return libsimple_vmalloczn(0, __n, __ap); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result)))
static inline void *libsimple_vcallocn(size_t __n, va_list __ap) { return libsimple_vmalloczn(1, __n, __ap); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result)))
static inline void *
libsimple_malloczn(int __clear, size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(__clear, __n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result)))
static inline void *
libsimple_mallocn(size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(0, __n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result)))
static inline void *
libsimple_callocn(size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmalloczn(1, __n, __ap);
	va_end(__ap);
}


#define reallocn(PTR, ...) _libsimple_reallocn((PTR), __VA_ARGS__, (size_t)0)
_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result)))
void *libsimple_vreallocn(void *, size_t, va_list);

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result)))
static inline void *
libsimple_reallocn(void *__ptr, size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vreallocn(__ptr, __n, __ap);
	va_end(__ap);
}


_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
void *enmalloc(int, size_t);

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
void *encalloc(int, size_t, size_t);

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
void *enrealloc(int, void *, size_t);

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, warn_unused_result, returns_nonnull)))
char *enstrdup(int, const char *);

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, warn_unused_result, returns_nonnull)))
char *enstrndup(int, const char *, size_t);

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
void *enmemdup(int, const void *, size_t);

#define enmalloczn(STATUS, CLEAR, ...) _libsimple_enmalloczn((STATUS), (CLEAR), __VA_ARGS__, (size_t)0)
#define enmallocn(STATUS, ...) _libsimple_enmallocn((STATUS), (CLEAR), __VA_ARGS__, (size_t)0)
#define encallocn(STATUS, ...) _libsimple_encallocn((STATUS), (CLEAR), __VA_ARGS__, (size_t)0)
#define enreallocn(STATUS, PTR, ...) _libsimple_enreallocn((STATUS), (PTR), __VA_ARGS__, (size_t)0)

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
void *libsimple_envmalloczn(int, int, size_t, va_list);

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
void *libsimple_envreallocn(int, void *, size_t, va_list);

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *libsimple_envmallocn(int __st, size_t __n, va_list __ap) { return libsimple_envmalloczn(__st, 0, __n, __ap); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *libsimple_envcallocn(int __st, size_t __n, va_list __ap) { return libsimple_envmalloczn(__st, 1, __n, __ap); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *
libsimple_enmalloczn(int __status, int __clear, size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(__status, __clear, __n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *
libsimple_enmallocn(int __status, size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(__status, 0, __n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *
libsimple_encallocn(int __status, size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(__status, 1, __n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *
libsimple_enreallocn(int __status, void *__ptr, size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envreallocn(__status, __ptr, __n, __ap);
	va_end(__ap);
}


_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *emalloc(size_t __n) { return enmalloc(libsimple_default_failure_exit, __n); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *ecalloc(size_t __n, size_t __m) { return encalloc(libsimple_default_failure_exit, __n, __m); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *erealloc(void *__ptr, size_t __n) { return enrealloc(libsimple_default_failure_exit, __ptr, __n); }

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, warn_unused_result, returns_nonnull)))
static inline char *estrdup(const char *__s) { return enstrdup(libsimple_default_failure_exit, __s); }

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, warn_unused_result, returns_nonnull)))
static inline char *estrndup(const char *__s, size_t __n) { return enstrndup(libsimple_default_failure_exit, __s, __n); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *ememdup(const void *__s, size_t __n) { return enmemdup(libsimple_default_failure_exit, __s, __n); }

#define emalloczn(CLEAR, ...) enmalloczn(libsimple_default_failure_exit, (CLEAR), __VA_ARGS__)
#define emallocn(...) enmallocn(libsimple_default_failure_exit, __VA_ARGS__)
#define ecallocn(...) encallocn(libsimple_default_failure_exit, __VA_ARGS__)
#define ereallocn(PTR, ...) enreallocn(libsimple_default_failure_exit, (PTR), __VA_ARGS__)

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *libsimple_evmalloczn(int __clear, size_t __n, va_list __ap)
{ return libsimple_envmalloczn(libsimple_default_failure_exit, __clear, __n, __ap); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *libsimple_evmallocn(size_t __n, va_list __ap)
{ return libsimple_envcallocn(libsimple_default_failure_exit, __n, __ap); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *libsimple_evcallocn(size_t __n, va_list __ap)
{ return libsimple_envmallocn(libsimple_default_failure_exit, __n, __ap); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *libsimple_evreallocn(void *__ptr, size_t __n, va_list __ap)
{ return libsimple_envreallocn(libsimple_default_failure_exit, __ptr, __n, __ap); }

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *
libsimple_emalloczn(int __c, size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(libsimple_default_failure_exit, __c, __n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *
libsimple_emallocn(size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(libsimple_default_failure_exit, 0, __n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *
libsimple_ecallocn(size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmalloczn(libsimple_default_failure_exit, 1, __n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((warn_unused_result, returns_nonnull)))
static inline void *
libsimple_ereallocn(void *__p, size_t __n, ...)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envreallocn(libsimple_default_failure_exit, __p, __n, __ap);
	va_end(__ap);
}


_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull)))
static inline char *
getenv_ne(const char *__name)
{
	char *__env = getenv(__name);
	return (__env && *__env) ? __env : NULL;
}


_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull)))
int vputenvf(const char *, va_list);

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull)))
void envputenvf(int, const char *, va_list);

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, format(printf, 1, 2))))
static inline int
putenvf(const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	return vputenvf(__fmt, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, format(printf, 1, 2))))
static inline void
eputenvf(const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	envputenvf(1, __fmt, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull)))
static inline void
evputenvf(const char *__fmt, va_list __ap)
{
	envputenvf(libsimple_default_failure_exit, __fmt, __ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull, format(printf, 2, 3))))
static inline void
enputenvf(int __status, const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	envputenvf(__status, __fmt, __ap);
	va_end(__ap);
}



_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull(1))))
void vweprintf(const char *, va_list);

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull(1), format(printf, 1, 2), noreturn)))
static inline void
eprintf(const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	vweprintf(__fmt, __ap);
	va_end(__ap);
	exit(libsimple_default_failure_exit);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull(1), noreturn)))
static inline void
veprintf(const char *__fmt, va_list __ap)
{
	vweprintf(__fmt, __ap);
	exit(libsimple_default_failure_exit);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull(2), format(printf, 2, 3), noreturn)))
static inline void
enprintf(int __status, const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	vweprintf(__fmt, __ap);
	va_end(__ap);
	exit(__status);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull(2), noreturn)))
static inline void
venprintf(int __status, const char *__fmt, va_list __ap)
{
	vweprintf(__fmt, __ap);
	exit(__status);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((nonnull(1), format(printf, 1, 2))))
static inline void
weprintf(const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	vweprintf(__fmt, __ap);
	va_end(__ap);
}


#endif
