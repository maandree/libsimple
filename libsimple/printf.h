/* See LICENSE file for copyright and license details. */


/**
 * Exit value for `libsimple_eprintf`
 * 
 * Default value is 1
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1, 2), __format__(__printf__, 2, 3))))
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1, 2))))
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
 */
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
 */
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
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(1))))
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
 */
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
 */
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
 */
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
 */
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
 */
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
