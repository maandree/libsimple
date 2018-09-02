/* See LICENSE file for copyright and license details. */

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
libsimple_cmptimespec(const struct timespec *__a, const struct timespec *__b)
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
libsimple_cmptimeval(const struct timeval *__a, const struct timeval *__b)
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
