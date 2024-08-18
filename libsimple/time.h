/* See LICENSE file for copyright and license details. */


/**
 * Calculates the sum of two `struct timespec`s
 * 
 * @param   sum     Output parameter for the result
 * @param   augend  One of the terms
 * @param   addend  The other term
 * @return          0 on success, -1 on failure
 * @throws  ERANGE  The result is too large or too small to be store; the result
 *                  will be `{.tv_sec = TIME_MAX, .tv_nsec = 999999999L}` if the
 *                  result too large and `{.tv_sec = TIME_MIN, .tv_nsec = 0L}`
 *                  if the result too small
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
int libsimple_sumtimespec(struct timespec *, const struct timespec *, const struct timespec *);
#ifndef sumtimespec
# define sumtimespec libsimple_sumtimespec
#endif


/**
 * Calculates the difference of two `struct timespec`s
 * 
 * @param   diff        Output parameter for the result
 * @param   minuend     The left-hand term
 * @param   subtrahend  The right-hand term
 * @return              0 on success, -1 on failure
 * @throws  ERANGE      The result is too large or too small to be store; the result
 *                      will be `{.tv_sec = TIME_MAX, .tv_nsec = 999999999L}` if the
 *                      result too large and `{.tv_sec = TIME_MIN, .tv_nsec = 0L}`
 *                      if the result too small
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
int libsimple_difftimespec(struct timespec *, const struct timespec *, const struct timespec *);
#ifndef difftimespec
# define difftimespec libsimple_difftimespec
#endif


/**
 * Calculates the product of a `struct timespec` and an integer
 * 
 * @param   prod          Output parameter for the result
 * @param   multiplicand  One of the factors
 * @param   multiplier    The other factor
 * @return                0 on success, -1 on failure
 * @throws  ERANGE        The result is too large or too small to be store; the result
 *                        will be `{.tv_sec = TIME_MAX, .tv_nsec = 999999999L}` if the
 *                        result too large and `{.tv_sec = TIME_MIN, .tv_nsec = 0L}`
 *                        if the result too small
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
int libsimple_multimespec(struct timespec *, const struct timespec *, int);
#ifndef multimespec
# define multimespec libsimple_multimespec
#endif


/**
 * Compares two `struct timespec`s
 * 
 * @param   a  One of the `struct timespec`s
 * @param   b  The other `struct timespec`
 * @return     -1 if `a` < `b`, 0 if `a` = `b`, and +1 if `a` > `b`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __warn_unused_result__)))
inline int
libsimple_cmptimespec(const struct timespec *a__, const struct timespec *b__)
{
        if (a__->tv_sec != b__->tv_sec)
                return a__->tv_sec < b__->tv_sec ? -1 : +1;
        return a__->tv_nsec < b__->tv_nsec ? -1 : a__->tv_nsec > b__->tv_nsec;
}
#ifndef cmptimespec
# define cmptimespec libsimple_cmptimespec
#endif


/**
 * Calculates the sum of two `struct timeval`s
 * 
 * @param   sum     Output parameter for the result
 * @param   augend  One of the terms
 * @param   addend  The other term
 * @return          0 on success, -1 on failure
 * @throws  ERANGE  The result is too large or too small to be store; the result
 *                  will be `{.tv_sec = TIME_MAX, .tv_usec = 999999L}` if the
 *                  result too large and `{.tv_sec = TIME_MIN, .tv_usec = 0L}`
 *                  if the result too small
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
int libsimple_sumtimeval(struct timeval *, const struct timeval *, const struct timeval *);
#ifndef sumtimeval
# define sumtimeval libsimple_sumtimeval
#endif


/**
 * Calculates the difference of two `struct timeval`s
 * 
 * @param   diff        Output parameter for the result
 * @param   minuend     The left-hand term
 * @param   subtrahend  The right-hand term
 * @return              0 on success, -1 on failure
 * @throws  ERANGE      The result is too large or too small to be store; the result
 *                      will be `{.tv_sec = TIME_MAX, .tv_usec = 999999L}` if the
 *                      result too large and `{.tv_sec = TIME_MIN, .tv_usec = 0L}`
 *                      if the result too small
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
int libsimple_difftimeval(struct timeval *, const struct timeval *, const struct timeval *);
#ifndef difftimeval
# define difftimeval libsimple_difftimeval
#endif


/**
 * Calculates the product of a `struct timeval` and an integer
 * 
 * @param   prod          Output parameter for the result
 * @param   multiplicand  One of the factors
 * @param   multiplier    The other factor
 * @return                0 on success, -1 on failure
 * @throws  ERANGE        The result is too large or too small to be store; the result
 *                        will be `{.tv_sec = TIME_MAX, .tv_usec = 999999L}` if the
 *                        result too large and `{.tv_sec = TIME_MIN, .tv_usec = 0L}`
 *                        if the result too small
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
int libsimple_multimeval(struct timeval *, const struct timeval *, int);
#ifndef multimeval
# define multimeval libsimple_multimeval
#endif


/**
 * Compares two `struct timeval`s
 * 
 * @param   a  One of the `struct timeval`s
 * @param   b  The other `struct timeval`
 * @return     -1 if `a` < `b`, 0 if `a` = `b`, and +1 if `a` > `b`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__, __warn_unused_result__)))
inline int
libsimple_cmptimeval(const struct timeval *a__, const struct timeval *b__)
{
        if (a__->tv_sec != b__->tv_sec)
                return a__->tv_sec < b__->tv_sec ? -1 : +1;
        return a__->tv_usec < b__->tv_usec ? -1 : a__->tv_usec > b__->tv_usec;
}
#ifndef cmptimeval
# define cmptimeval libsimple_cmptimeval
#endif


/**
 * Converts a `struct timeval` to a `struct timespec`
 * 
 * @param  ts  Output parameter for the result
 * @param  tv  The value to convert
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline void
libsimple_timeval2timespec(struct timespec *restrict ts__, const struct timeval *restrict tv__)
{
        ts__->tv_sec = tv__->tv_sec;
        ts__->tv_nsec = tv__->tv_usec;
        ts__->tv_nsec *= 1000L;
}
#ifndef timeval2timespec
# define timeval2timespec libsimple_timeval2timespec
#endif


/**
 * Converts a `struct timespec` to a `struct timeval`
 * 
 * @param   tv         The value to convert
 * @param   ts         Output parameter for the result
 * @return             0 on success, -1 on error
 * @throws  EOVERFLOW  The value is too large to be convert, the value will be
 *                     truncated to `{.tv_sec = TIME_MAX, .tv_usec = 999999L}`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
int libsimple_timespec2timeval(struct timeval *restrict, const struct timespec *restrict);
#ifndef timespec2timeval
# define timespec2timeval libsimple_timespec2timeval
#endif


/**
 * Converts a string to `struct timespec`
 * 
 * Repeating decimal are supported ith the repetend inside
 * round brackets or after an additional point, for example
 * "0.1(6)" or "0.1.6" for one sixth
 *
 * @param   ts      Output parameter for the result
 * @param   s       The string to parse
 * @param   end     Output parameter for where the parsing stopped;
 *                  will only be set on success or on ERANGE error
 * @return          0 on success, -1 on error
 * @throws  EINVAL  The input string is invalid (`*end` is not set)
 * @throws  ERANGE  The result is too large or too small to be store; the result
 *                  will be `{.tv_sec = TIME_MAX, .tv_nsec = 999999999L}` if the
 *                  result too large and `{.tv_sec = TIME_MIN, .tv_nsec = 0L}`
 *                  if the result too small (`*end` is set)
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1, 2))))
int libsimple_strtotimespec(struct timespec *restrict, const char *restrict, char **restrict);
#ifndef strtotimespec
# define strtotimespec libsimple_strtotimespec
#endif


/**
 * Converts a string to `struct timeval`
 * 
 * Repeating decimal are supported ith the repetend inside
 * round brackets or after an additional point, for example
 * "0.1(6)" or "0.1.6" for one sixth
 *
 * @param   tv      Output parameter for the result
 * @param   s       The string to parse
 * @param   end     Output parameter for where the parsing stopped;
 *                  will only be set on success or on ERANGE error
 * @return          0 on success, -1 on error
 * @throws  EINVAL  The input string is invalid (`*end` is not set)
 * @throws  ERANGE  The result is too large or too small to be store; the result
 *                  will be `{.tv_sec = TIME_MAX, .tv_usec = 999999L}` if the
 *                  result too large and `{.tv_sec = TIME_MIN, .tv_usec = 0L}`
 *                  if the result too small (`*end` is set)
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1, 2))))
int libsimple_strtotimeval(struct timeval *restrict, const char *restrict, char **restrict);
#ifndef strtotimeval
# define strtotimeval libsimple_strtotimeval
#endif


/**
 * Converts a `struct timespec` to string
 * 
 * The output will always have a sign ("+" or "-") and 9 decimals.
 * 
 * @param   buf     Output buffer to use, if `NULL` a new buffer will be allocated
 * @param   ts      The value to convert
 * @return          The result (same pointer as `buf` unless `buf == NULL`),
 *                  `NULL` on failure
 * @throws  ENOMEM  Output buffer could not be allocated (only if `buf == NULL`)
 * @throws  EINVAL  `ts->tv_nsec` is negative or greater than 999999999
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(2))))
char *libsimple_timespectostr(char *restrict, const struct timespec *restrict);
#ifndef timespectostr
# define timespectostr libsimple_timespectostr
#endif


/**
 * Converts a `struct timeval` to string
 * 
 * The output will always have a sign ("+" or "-") and 6 decimals.
 * 
 * @param   buf     Output buffer to use, if `NULL` a new buffer will be allocated
 * @param   tv      The value to convert
 * @return          The result (same pointer as `buf` unless `buf == NULL`),
 *                  `NULL` on failure
 * @throws  ENOMEM  Output buffer could not be allocated (only if `buf == NULL`)
 * @throws  EINVAL  `ts->tv_usec` is negative or greater than 999999
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(2))))
char *libsimple_timevaltostr(char *restrict, const struct timeval *restrict);
#ifndef timevaltostr
# define timevaltostr libsimple_timevaltostr
#endif


/**
 * Converts a `struct timespec` to `double`
 * 
 * @param   ts  The value to convert
 * @return      The result
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline double
libsimple_timespectodouble(const struct timespec *ts__)
{
	double ret__ = (double)(ts__->tv_nsec);
	ret__ /= (double)1000000000L;
	ret__ += (double)(ts__->tv_sec);
	return ret__;
}
#ifndef timespectodouble
# define timespectodouble libsimple_timespectodouble
#endif


/**
 * Converts a `struct timeval` to `double`
 * 
 * @param   tv  The value to convert
 * @return      The result
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline double
libsimple_timevaltodouble(const struct timeval *tv__)
{
	double ret__ = (double)(tv__->tv_usec);
	ret__ /= (double)1000000L;
	ret__ += (double)(tv__->tv_sec);
	return ret__;
}
#ifndef timevaltodouble
# define timevaltodouble libsimple_timevaltodouble
#endif


/**
 * Converts a double to `struct timespec`
 * 
 * No overflow check is made
 * 
 * @param  ts  Output parameter for the result
 * @param  d   The value to convert
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
void libsimple_doubletotimespec(struct timespec *, double);
#ifndef doubletotimespec
# define doubletotimespec libsimple_doubletotimespec
#endif


/**
 * Converts a double to `struct timeval`
 * 
 * No overflow check is made
 * 
 * @param  tv  Output parameter for the result
 * @param  d   The value to convert
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
void libsimple_doubletotimeval(struct timeval *, double);
#ifndef doubletotimeval
# define doubletotimeval libsimple_doubletotimeval
#endif


/**
 * Minimises a numerical string
 * 
 * This function does not support repeating decimals
 * 
 * @param   s  The string to minimise
 * @return     `s`
 * 
 * @since  1.0
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__returns_nonnull__, __nonnull__)))
char *libsimple_minimise_number_string(char *);
#ifndef minimise_number_string
# define minimise_number_string libsimple_minimise_number_string
#endif


/**
 * Get the current time in the local timezone
 * 
 * This function is leap-second aware
 * 
 * @param   tm  Output parameter for the local time
 * @param   ts  Output parameter for the POSIX time, may be NULL
 * @return      0 on success, -1 on failure
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1))))
int libsimple_localtime(struct tm *, struct timespec *);

/**
 * Get the current time in the local timezone
 * 
 * This function is leap-second aware
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status  The exit value for the process in case of failure
 * @param  tm      Output parameter for the local time
 * @param  ts      Output parameter for the POSIX time, may be NULL
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(2))))
void libsimple_enlocaltime(int, struct tm *, struct timespec *);

/**
 * Get the current time in the local timezone
 * 
 * This function is leap-second aware
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  tm  Output parameter for the local time
 * @param  ts  Output parameter for the POSIX time, may be NULL
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1))))
inline void
libsimple_elocaltime(struct tm *tm__, struct timespec *ts__)
{
	libsimple_enlocaltime(libsimple_default_failure_exit, tm__, ts__);
}


/**
 * Get the current time in the UTC timezone
 * 
 * This function is leap-second aware
 * 
 * @param   tm  Output parameter for the UTC time
 * @param   ts  Output parameter for the POSIX time, may be NULL
 * @return      0 on success, -1 on failure
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1))))
int libsimple_gmtime(struct tm *, struct timespec *);

/**
 * Get the current time in the UTC timezone
 * 
 * This function is leap-second aware
 * 
 * On failure, the `libsimple_enprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_enprintf` for more information
 * 
 * @param  status  The exit value for the process in case of failure
 * @param  tm      Output parameter for the UTC time
 * @param  ts      Output parameter for the POSIX time, may be NULL
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(2))))
void libsimple_engmtime(int, struct tm *, struct timespec *);

/**
 * Get the current time in the UTC timezone
 * 
 * This function is leap-second aware
 * 
 * On failure, the `libsimple_eprintf` function is called,
 * cause the program to print an error message and exit,
 * see `libsimple_eprintf` for more information
 * 
 * @param  tm  Output parameter for the UTC time
 * @param  ts  Output parameter for the POSIX time, may be NULL
 * 
 * @since  1.2
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__(1))))
inline void
libsimple_egmtime(struct tm *tm__, struct timespec *ts__)
{
	libsimple_engmtime(libsimple_default_failure_exit, tm__, ts__);
}
