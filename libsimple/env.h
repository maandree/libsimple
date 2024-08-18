/* See LICENSE file for copyright and license details. */


/**
 * Read an environment variable, but handle it as undefined if empty
 * 
 * @param   var  The environment variable's name
 * @return       The environment variable's value, `NULL` if empty or not defined
 * 
 * @since  1.0
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
 * 
 * @since  1.0
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


/**
 * Formats a string and adds its as an environment variable,
 * overriding its old value if it already exists
 * 
 * The constructed string should have the format name=value,
 * however, it is possible to add environment variables with
 * only the name, but this can couse problems in some programs
 * and should not done; the name however must not be empty
 * 
 * @param   fmt  Format string, see vsprintf(3)
 * @param   ap   Format arguments, see vsprintf(3)
 * @return       0 on success, -1 on failure
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
int libsimple_vputenvf(const char *, va_list);
#ifndef vputenvf
# define vputenvf libsimple_vputenvf
#endif


/**
 * Formats a string and adds its as an environment variable,
 * overriding its old value if it already exists
 * 
 * The constructed string should have the format name=value,
 * however, it is possible to add environment variables with
 * only the name, but this can couse problems in some programs
 * and should not done; the name however must not be empty
 * 
 * @param   fmt  Format string, see vsprintf(3)
 * @param   ...  Format arguments, see vsprintf(3)
 * @return       0 on success, -1 on failure
 * 
 * @since  1.0
 */
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


/**
 * Formats a string and adds its as an environment variable,
 * overriding its old value if it already exists
 * 
 * The constructed string should have the format name=value,
 * however, it is possible to add environment variables with
 * only the name, but this can couse problems in some programs
 * and should not done; the name however must not be empty
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status  The exit value for the process in case of failure
 * @param  fmt     Format string, see vsprintf(3)
 * @param  ap      Format arguments, see vsprintf(3)
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
void libsimple_envputenvf(int, const char *, va_list);
#ifndef envputenvf
# define envputenvf libsimple_envputenvf
#endif


/**
 * Formats a string and adds its as an environment variable,
 * overriding its old value if it already exists
 * 
 * The constructed string should have the format name=value,
 * however, it is possible to add environment variables with
 * only the name, but this can couse problems in some programs
 * and should not done; the name however must not be empty
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status  The exit value for the process in case of failure
 * @param  fmt     Format string, see vsprintf(3)
 * @param  ap      Format arguments, see vsprintf(3)
 * 
 * @since  1.0
 */
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


/**
 * Formats a string and adds its as an environment variable,
 * overriding its old value if it already exists
 * 
 * The constructed string should have the format name=value,
 * however, it is possible to add environment variables with
 * only the name, but this can couse problems in some programs
 * and should not done; the name however must not be empty
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  fmt  Format string, see vsprintf(3)
 * @param  ap   Format arguments, see vsprintf(3)
 * 
 * @since  1.0
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline void libsimple_evputenvf(const char *__fmt, va_list __ap)
{ libsimple_envputenvf(libsimple_default_failure_exit, __fmt, __ap); }
#ifndef evputenvf
# define evputenvf libsimple_evputenvf
#endif


/**
 * Formats a string and adds its as an environment variable,
 * overriding its old value if it already exists
 * 
 * The constructed string should have the format name=value,
 * however, it is possible to add environment variables with
 * only the name, but this can couse problems in some programs
 * and should not done; the name however must not be empty
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  fmt  Format string, see vsprintf(3)
 * @param  ap   Format arguments, see vsprintf(3)
 * 
 * @since  1.0
 */
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
