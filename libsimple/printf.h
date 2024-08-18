/* See LICENSE file for copyright and license details. */


/**
 * Exit value for `libsimple_eprintf`
 * 
 * Default value is 1
 * 
 * @since  1.0
 */
extern int libsimple_default_failure_exit;


/**
 * Unless `NULL`, called from `libsimple_vweprintf`
 * before the `eprintf`-family of functions print
 * the message.
 * 
 * `errno` is not necessarily the same value as
 * it was when `libsimple_vweprintf` was called.
 * 
 * Default value is `NULL`
 * 
 * @since  1.1
 */
extern void (*libsimple_eprintf_preprint)(void);


/**
 * Unless `NULL`, called from `libsimple_vweprintf`
 * after the `eprintf`-family of functions print
 * the message.
 * 
 * `errno` is not necessarily the same value as
 * it was when `libsimple_vweprintf` was called.
 * 
 * Default value is `NULL`
 * 
 * @since  1.1
 */
extern void (*libsimple_eprintf_postprint)(void);


/**
 * Version of `printf` that allocates, on the heap, a
 * sufficiently large string and writes the output to it
 * 
 * @param   strp    Output pointer for string, will be set to `NULL`
 *                  on failure, however portable applications should
 *                  assume that it may also be unmodified or a recently
 *                  freed pointer if `asprintf` is used rather than
 *                  `libsimple_asprintf` explicitly
 * @param   fmt     The format string
 * @param   ...     The format argument
 * @return          The length of the output on success, -1 on error
 * @throws  EMFILE  {FOPEN_MAX} streams are currently open in the calling process
 * @throws  ENOMEM  Could not allocate enough memory
 * @throws          Any error specified for `fprintf`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1, 2), __format__(__printf__, 2, 3))))
int libsimple_asprintf(char **, const char *, ...);
#ifndef asprintf
# define asprintf libsimple_asprintf
#endif


/**
 * Version of `vprintf` that allocates, on the heap, a
 * sufficiently large string and writes the output to it
 * 
 * @param   strp    Output pointer for string, will be set to `NULL`
 *                  on failure, however portable applications should
 *                  assume that it may also be unmodified or a recently
 *                  freed pointer if `asprintf` is used rather than
 *                  `libsimple_asprintf` explicitly
 * @param   fmt     The format string
 * @param   ap      The format argument
 * @return          The length of the output on success, -1 on error
 * @throws  EMFILE  {FOPEN_MAX} streams are currently open in the calling process
 * @throws  ENOMEM  Could not allocate enough memory
 * @throws          Any error specified for `fprintf`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1, 2), __format__(__printf__, 2, 0))))
int libsimple_vasprintf(char **, const char *, va_list);
#ifndef vasprintf
# define vasprintf libsimple_vasprintf
#endif


/**
 * Version of `printf` that allocates, on the stack, a
 * sufficiently large string and writes the output to it
 * 
 * This macro does not check whether it can allocate
 * enough memory, if it cannot, the kernel may kill the
 * thread, and possibly the process, with a SIGSEGV signal
 * 
 * @param   fmt  The format string
 * @param   ...  The format argument
 * @return       The formatted string, `NULL` on error
 * @throws       Any error specified for `snprintf`
 * 
 * @since  1.0
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_asprintfa(fmt__, ...)\
	LIBSIMPLE_EXTENSION__\
	({\
		const char *f__ = (fmt__);\
		char *ret__ = NULL;\
		int r__ = snprintf(NULL, 0, f__, __VA_ARGS__);\
		if (r__ >= 0) {\
			ret__ = alloca((size_t)r__ + 1);\
			sprintf(ret__, f__, __VA_ARGS__);\
		}\
		ret__;\
	})
# ifndef asprintfa
#  define asprintfa(...) libsimple_asprintfa(__VA_ARGS__)
# endif
#endif


/**
 * Version of `vprintf` that allocates, on the stack, a
 * sufficiently large string and writes the output to it
 * 
 * This macro does not check whether it can allocate
 * enough memory, if it cannot, the kernel may kill the
 * thread, and possibly the process, with a SIGSEGV signal
 * 
 * @param   fmt  The format string
 * @param   ap   The format argument
 * @return       The formatted string, `NULL` on error
 * @throws       Any error specified for `snprintf`
 * 
 * @since  1.0
 */
#if defined(__GNUC__) || defined(__clang__)
# define libsimple_vasprintfa(fmt__, ap__)\
	LIBSIMPLE_EXTENSION__\
	({\
		const char *f__ = (fmt__);\
		va_list a1__;\
		va_list a2__;\
		char *ret__ = NULL;\
		int r__;\
		va_copy(a1__, ap__);\
		va_copy(a2__, a1__);\
		r__ = vsnprintf(NULL, 0, f__, a1__);\
		if (r__ >= 0) {\
			ret__ = alloca((size_t)r__ + 1);\
			vsprintf(ret__, f__, a2__);\
		}\
		va_end(a2__);\
		va_end(a1__);\
		ret__;\
	})
# ifndef vasprintfa
#  define vasprintfa(fmt, ap) libsimple_vasprintfa(fmt, ap)
# endif
#endif


/**
 * Version of `vprintf` for printing error message;
 * it prints to standard error (rather than standard
 * output) and, unless `fmt` starts with "usage: "
 * and unless `argv0` (global `char *`), prefixes
 * the output with `"%s: ", argv0`; additionally, if
 * `fmt` ends with ':', the output is suffixed with
 * `" %s\n", strerror(errno)`, if `fmt` ends with
 * neither ':' nor '\n', the outpt is suffixed with
 * `\n`
 * 
 * NB! This function uses `strerror` which is not
 * thread-safe
 * 
 * @param  fmt  The format string
 * @param  ap   The format argument
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1), __format__(__printf__, 1, 0))))
void libsimple_vweprintf(const char *, va_list);
#ifndef vweprintf
# define vweprintf libsimple_vweprintf
#endif


/**
 * Version of `vprintf` for printing error message;
 * it prints to standard error (rather than standard
 * output) and, unless `fmt` starts with "usage: "
 * and unless `argv0` (global `char *`), prefixes
 * the output with `"%s: ", argv0`; additionally, if
 * `fmt` ends with ':', the output is suffixed with
 * `" %s\n", strerror(errno)`, if `fmt` ends with
 * neither ':' nor '\n', the outpt is suffixed with
 * `\n`
 * 
 * NB! This function uses `strerror` which is not
 * thread-safe
 * 
 * @param  fmt  The format string
 * @param  ...  The format argument
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1), __format__(__printf__, 1, 2))))
inline void
libsimple_weprintf(const char *fmt__, ...)
{
	va_list ap__;
	va_start(ap__, fmt__);
	libsimple_vweprintf(fmt__, ap__);
	va_end(ap__);
}
#ifndef weprintf
# define weprintf libsimple_weprintf
#endif


/**
 * Version of `vprintf` for printing error message;
 * it prints to standard error (rather than standard
 * output) and, unless `fmt` starts with "usage: "
 * and unless `argv0` (global `char *`), prefixes
 * the output with `"%s: ", argv0`; additionally, if
 * `fmt` ends with ':', the output is suffixed with
 * `" %s\n", strerror(errno)`, if `fmt` ends with
 * neither ':' nor '\n', the outpt is suffixed with
 * `\n`
 * 
 * This function will exit the process
 * 
 * NB! This function uses `strerror` which is not
 * thread-safe
 * 
 * @param  status  Exit value for the process
 * @param  fmt     The format string
 * @param  ap      The format argument
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(2), __format__(__printf__, 2, 0))))
inline LIBSIMPLE_NORETURN void
libsimple_venprintf(int status__, const char *fmt__, va_list ap__)
{
	libsimple_vweprintf(fmt__, ap__);
	exit(status__);
}
#ifndef venprintf
# define venprintf libsimple_venprintf
#endif


/**
 * Version of `vprintf` for printing error message;
 * it prints to standard error (rather than standard
 * output) and, unless `fmt` starts with "usage: "
 * and unless `argv0` (global `char *`), prefixes
 * the output with `"%s: ", argv0`; additionally, if
 * `fmt` ends with ':', the output is suffixed with
 * `" %s\n", strerror(errno)`, if `fmt` ends with
 * neither ':' nor '\n', the outpt is suffixed with
 * `\n`
 * 
 * This function will exit the process
 * 
 * NB! This function uses `strerror` which is not
 * thread-safe
 * 
 * @param  status  Exit value for the process
 * @param  fmt     The format string
 * @param  ...     The format argument
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(2), __format__(__printf__, 2, 3))))
inline LIBSIMPLE_NORETURN void
libsimple_enprintf(int status__, const char *fmt__, ...)
{
	va_list ap__;
	va_start(ap__, fmt__);
	libsimple_venprintf(status__, fmt__, ap__);
	va_end(ap__);
}
#ifndef enprintf
# define enprintf libsimple_enprintf
#endif


/**
 * Version of `vprintf` for printing error message;
 * it prints to standard error (rather than standard
 * output) and, unless `fmt` starts with "usage: "
 * and unless `argv0` (global `char *`), prefixes
 * the output with `"%s: ", argv0`; additionally, if
 * `fmt` ends with ':', the output is suffixed with
 * `" %s\n", strerror(errno)`, if `fmt` ends with
 * neither ':' nor '\n', the outpt is suffixed with
 * `\n`
 * 
 * This function will exit the process with the
 * value `libsimple_default_failure_exit`
 * 
 * NB! This function uses `strerror` which is not
 * thread-safe
 * 
 * @param  fmt  The format string
 * @param  ap   The format argument
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1), __format__(__printf__, 1, 0))))
inline LIBSIMPLE_NORETURN void
libsimple_veprintf(const char *fmt__, va_list ap__)
{
	libsimple_vweprintf(fmt__, ap__);
	exit(libsimple_default_failure_exit);
}
#ifndef veprintf
# define veprintf libsimple_veprintf
#endif


/**
 * Version of `vprintf` for printing error message;
 * it prints to standard error (rather than standard
 * output) and, unless `fmt` starts with "usage: "
 * and unless `argv0` (global `char *`), prefixes
 * the output with `"%s: ", argv0`; additionally, if
 * `fmt` ends with ':', the output is suffixed with
 * `" %s\n", strerror(errno)`, if `fmt` ends with
 * neither ':' nor '\n', the outpt is suffixed with
 * `\n`
 * 
 * This function will exit the process with the
 * value `libsimple_default_failure_exit`
 * 
 * NB! This function uses `strerror` which is not
 * thread-safe
 * 
 * @param  fmt  The format string
 * @param  ...  The format argument
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1), __format__(__printf__, 1, 2))))
inline LIBSIMPLE_NORETURN void
libsimple_eprintf(const char *fmt__, ...)
{
	va_list ap__;
	va_start(ap__, fmt__);
	libsimple_veprintf(fmt__, ap__);
	va_end(ap__);
}
#ifndef eprintf
# define eprintf libsimple_eprintf
#endif
