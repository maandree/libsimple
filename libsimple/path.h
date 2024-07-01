/* See LICENSE file for copyright and license details. */


/**
 * Get the current working directory
 * 
 * @return  The current working directory, or `NULL` on failure
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__)))
char *libsimple_getcwd(void); /* TODO man */

/**
 * Version of `libsimple_getcwd` that calls `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @return          The current working directory
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __returns_nonnull__)))
char *libsimple_engetcwd(int); /* TODO man */

/**
 * Version of `libsimple_getcwd` that calls `libsimple_eprintf` on error
 * 
 * @return  The current working directory
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __returns_nonnull__)))
inline char *
libsimple_egetcwd(void) /* TODO man */
{
	return libsimple_engetcwd(libsimple_default_failure_exit);
}


/**
 * Turn a path into an absolute path if it is a relative path
 * 
 * @param   path    The path to transform
 * @param   relto   The directory `path` is relative to if it is a relative path,
 *                  `NULL` for the current working directory
 * @return          `path` as an absolute path, or `NULL` on failure
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__(1))))
char *libsimple_abspath(const char *, const char *); /* TODO man */

/**
 * Version of `libsimple_abspath` that calls `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @param   path    The path to transform
 * @param   relto   The directory `path` is relative to if it is a relative path,
 *                  `NULL` for the current working directory
 * @return          `path` as an absolute path
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__(2), __returns_nonnull__)))
char *libsimple_enabspath(int, const char *, const char *); /* TODO man */

/**
 * Version of `libsimple_abspath` that calls `libsimple_eprintf` on error
 * 
 * @param   path    The path to transform
 * @param   relto   The directory `path` is relative to if it is a relative path,
 *                  `NULL` for the current working directory
 * @return          `path` as an absolute path
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__(1), __returns_nonnull__)))
inline char *
libsimple_eabspath(const char *p__, const char *r__) /* TODO man */
{
	return libsimple_enabspath(libsimple_default_failure_exit, p__, r__);
}


LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__)))
char *libsimple_readlinkat(int, const char *); /* TODO man, doc */

LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__, __returns_nonnull__)))
char *libsimple_enreadlinkat(int, int, const char *); /* TODO man, doc */

LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__, __returns_nonnull__)))
inline char *
libsimple_ereadlinkat(int dirfd__, const char *path__) /* TODO man, doc */
{
	return libsimple_enreadlinkat(libsimple_default_failure_exit, dirfd__, path__);
}


LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__)))
inline char *
libsimple_readlink(const char *path__) /* TODO man, doc */
{
	return libsimple_readlinkat(AT_FDCWD, path__);
}

LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__, __returns_nonnull__)))
inline char *
libsimple_enreadlink(int status__, const char *path__) /* TODO man, doc */
{
	return libsimple_enreadlinkat(status__, AT_FDCWD, path__);
}

LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__, __returns_nonnull__)))
inline char *
libsimple_ereadlink(const char *path__) /* TODO man, doc */
{
	return libsimple_enreadlinkat(libsimple_default_failure_exit, AT_FDCWD, path__);
}

LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__)))
inline char *
libsimple_freadlink(int fd__) /* TODO man, doc */
{
	return libsimple_readlinkat(fd__, "");
}

LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__, __returns_nonnull__)))
inline char *
libsimple_enfreadlink(int status__, int fd__) /* TODO man, doc */
{
	return libsimple_enreadlinkat(status__, fd__, "");
}

LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__, __returns_nonnull__)))
inline char *
libsimple_efreadlink(int fd__) /* TODO man, doc */
{
	return libsimple_enreadlinkat(libsimple_default_failure_exit, fd__, "");
}


LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__)))
char *libsimple_readmagiclink(const char *); /* TODO man, doc */

LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__, __returns_nonnull__)))
char *libsimple_enreadmagiclink(int, const char *); /* TODO man, doc */

LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __assume_aligned__(1), __warn_unused_result__, __nonnull__, __returns_nonnull__)))
inline char *
libsimple_ereadmagiclink(const char *path__) /* TODO man, doc */
{
	return libsimple_enreadmagiclink(libsimple_default_failure_exit, path__);
}
