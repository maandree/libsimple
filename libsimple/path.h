/* See LICENSE file for copyright and license details. */


/**
 * Get the current working directory
 * 
 * @return  The current working directory, or `NULL` on failure
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
char *libsimple_getcwd(void); /* TODO man */

/**
 * Version of `libsimple_getcwd` that calls `libsimple_enprintf` on error
 * 
 * @param   status  Exit value in case of failure
 * @return          The current working directory
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
char *libsimple_engetcwd(int status); /* TODO man */

/**
 * Version of `libsimple_getcwd` that calls `libsimple_eprintf` on error
 * 
 * @return  The current working directory
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__, __returns_nonnull__)))
inline char *
libsimple_egetcwd(void) /* TODO man */
{
	return libsimple_engetcwd(libsimple_default_failure_exit);
}
