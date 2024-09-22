/* See LICENSE file for copyright and license details. */


/**
 * Get area of the the thread's stack space
 * 
 * @param   low   Output parameter for the address of the beginning of the stack space
 * @param   high  Output parameter for the address immediately after the last byte in the stack space
 * @return        0 on success, -1 on failure
 * 
 * @since  1.7
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
int libsimple_get_stack_space(uintptr_t *restrict low, uintptr_t *restrict high); /* TODO man */

/**
 * Get the stack size limit for the thread
 * 
 * @param   soft  Output parameter for the soft limit, or `NULL`
 * @param   hard  Output parameter for the hard limit, or `NULL`
 * @return        0 on success, -1 on failure
 * 
 * @since  1.7
 */
int libsimple_get_stack_limit(size_t *restrict soft, size_t *restrict hard); /* TODO man */

/**
 * Get the direction the stack grows in
 * 
 * @return  +1 if the stack grows upwards (higher addresses),
 *          -1 if the stack grows downwards (lower addresses),
 *          0 on failure
 * 
 * @throws  ENOTSUP  Unable to determine stack growth direction
 * 
 * @since  1.7
 */
int libsimple_get_stack_direction(void); /* TODO man */

/**
 * Check if the some amount of memory can be allowed on the stack
 * 
 * @param   n  The amount of memory
 * @return     1 if `n` bytes can be allocated,
 *             0 if `n` bytes may or may not be allocated,
 *             -1 on failure
 * 
 * @since  1.7
 */
int libsimple_needstack(size_t n); /* TODO man */
#ifndef needstack
# define needstack libsimple_needstack
#endif
