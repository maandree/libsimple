/* See LICENSE file for copyright and license details. */

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

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __format__(__printf__, 1, 2))))
static inline int
libsimple_putenvf(const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	return libsimple_vputenvf(__fmt, __ap);
	va_end(__ap);
}
#ifndef putenvf
# define putenvf libsimple_putenvf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
void libsimple_envputenvf(int, const char *, va_list);
#ifndef envputenvf
# define envputenvf libsimple_envputenvf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __format__(__printf__, 2, 3))))
static inline void
libsimple_enputenvf(int __status, const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	libsimple_envputenvf(__status, __fmt, __ap);
	va_end(__ap);
}
#ifndef enputenvf
# define enputenvf libsimple_enputenvf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline void libsimple_evputenvf(const char *__fmt, va_list __ap)
{ libsimple_envputenvf(libsimple_default_failure_exit, __fmt, __ap); }
#ifndef evputenvf
# define evputenvf libsimple_evputenvf
#endif

_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__, __format__(__printf__, 1, 2))))
static inline void
libsimple_eputenvf(const char *__fmt, ...)
{
	va_list __ap;
	va_start(__ap, __fmt);
	libsimple_evputenvf(__fmt, __ap);
	va_end(__ap);
}
#ifndef eputenvf
# define eputenvf libsimple_eputenvf
#endif
