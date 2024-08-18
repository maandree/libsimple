/* See LICENSE file for copyright and license details. */


/**
 * Creates a pseudo-random seed
 *
 * @return  The pseudo-random seed
 * 
 * @since  1.6
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__)))
unsigned int libsimple_generate_seed(void); /* TODO add man page */


/**
 * Wrapper for srand(3) that creates a pseudo-random
 * seed with which it seeds the pseudo-random number
 * generator
 * 
 * @since  1.6
 */
inline void
libsimple_srand(void) /* TODO add man page */
{
	srand(libsimple_generate_seed());
}


/* TODO doc, man (since 1.6) (libsimple_random_float requires -lm) */
uintmax_t libsimple_random_bits(size_t bits, void *unused);
uintmax_t libsimple_random_unsigned(uintmax_t (*rng)(size_t bits, void *user), void *user, uintmax_t min, uintmax_t max);
intmax_t libsimple_random_signed(uintmax_t (*rng)(size_t bits, void *user), void *user, intmax_t min, intmax_t max);
long double libsimple_random_float(uintmax_t (*rng)(size_t bits, void *user), void *user, long double min, long double postmax);
