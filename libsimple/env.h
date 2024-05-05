/* See LICENSE file for copyright and license details. */


/**
 * Read an environment variable, but handle it as undefined if empty
 * 
 * @param   var  The environment variable's name
 * @return       The environment variable's value, `NULL` if empty or not defined
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __warn_unused_result__)))
inline char *
libsimple_getenv_ne(const char *name__)
{
	char *env__ = getenv(name__);
	return (env__ && *env__) ? env__ : NULL;
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
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __warn_unused_result__, __returns_nonnull__)))
inline const char *
libsimple_getenv_e(const char *name__)
{
	const char *env__ = getenv(name__);
	return (env__ && *env__) ? env__ : "";
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __format__(__printf__, 1, 0))))
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __format__(__printf__, 1, 2))))
inline int
libsimple_putenvf(const char *fmt__, ...)
{
	va_list ap__;
	va_start(ap__, fmt__);
	return libsimple_vputenvf(fmt__, ap__);
	va_end(ap__);
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __format__(__printf__, 2, 0))))
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __format__(__printf__, 2, 3))))
inline void
libsimple_enputenvf(int status__, const char *fmt__, ...)
{
	va_list ap__;
	va_start(ap__, fmt__);
	libsimple_envputenvf(status__, fmt__, ap__);
	va_end(ap__);
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __format__(__printf__, 1, 0))))
inline void
libsimple_evputenvf(const char *fmt__, va_list ap__)
{
	libsimple_envputenvf(libsimple_default_failure_exit, fmt__, ap__);
}
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
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __format__(__printf__, 1, 2))))
inline void
libsimple_eputenvf(const char *fmt__, ...)
{
	va_list ap__;
	va_start(ap__, fmt__);
	libsimple_evputenvf(fmt__, ap__);
	va_end(ap__);
}
#ifndef eputenvf
# define eputenvf libsimple_eputenvf
#endif


/*
 * TODO add getenv_first, getenv_first_ne, getenv_first_e
 * TODO add getenv_last, getenv_last_ne, getenv_last_e
 * TODO add unsetenv_first, unsetenv_last, unsetenv_each
 */
