/* See LICENSE file for copyright and license details. */

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

#if defined(__GNUC__) || defined(__clang__)
# define libsimple_asprintfa(__fmt, ...)\
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
# define libsimple_vasprintfa(__fmt, __ap)\
	({\
		const char *__f = (__fmt);\
		va_list __a1;\
		va_list __a2;\
		char *__ret = NULL;\
		int __r;\
		va_copy(__a1, __ap);\
		va_copy(__a2, __a1);\
		__r = vsnprintf(NULL, 0, __f, __a1);\
		if (__r >= 0) {\
			__ret = alloca((size_t)__r + 1);\
			vsprintf(__ret, __f, __a2);\
		}\
		va_end(__a2);\
		va_end(__a1);\
		__ret;\
	})
# ifndef vasprintfa
#  define vasprintfa(fmt, ap) libsimple_vasprintfa(fmt, ap)
# endif
#endif


_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
void libsimple_vweprintf(const char *, va_list);
#ifndef vweprintf
# define vweprintf libsimple_vweprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1), __format__(__printf__, 1, 2))))
static inline void
libsimple_weprintf(const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	libsimple_vweprintf(__fmt, __ap);
	va_end(__ap);
}
#ifndef weprintf
# define weprintf libsimple_weprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __noreturn__)))
static inline void
libsimple_venprintf(int __status, const char *__fmt, va_list __ap)
{
	libsimple_vweprintf(__fmt, __ap);
	exit(__status);
}
#ifndef venprintf
# define venprintf libsimple_venprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __format__(__printf__, 2, 3), __noreturn__)))
static inline void
libsimple_enprintf(int __status, const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	libsimple_venprintf(__status, __fmt, __ap);
	va_end(__ap);
}
#ifndef enprintf
# define enprintf libsimple_enprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1), __noreturn__)))
static inline void
libsimple_veprintf(const char *__fmt, va_list __ap)
{
	libsimple_vweprintf(__fmt, __ap);
	exit(libsimple_default_failure_exit);
}
#ifndef veprintf
# define veprintf libsimple_veprintf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1), __format__(__printf__, 1, 2), __noreturn__)))
static inline void
libsimple_eprintf(const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	libsimple_veprintf(__fmt, __ap);
	va_end(__ap);
}
#ifndef eprintf
# define eprintf libsimple_eprintf
#endif
