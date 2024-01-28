/* See LICENSE file for copyright and license details. */


/**
 * Creates a pseudo-random seed
 *
 * @return  The pseudo-random seed
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__)))
unsigned int libsimple_generate_seed(void); /* TODO add man page */


/**
 * Wrapper for srand(3) that creates a pseudo-random
 * seed with which it seeds the pseudo-random number
 * generator
 */
inline void
libsimple_srand(void) /* TODO add man page */
{
	srand(libsimple_generate_seed());
}
