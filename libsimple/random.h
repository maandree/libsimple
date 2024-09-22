/* See LICENSE file for copyright and license details. */


/**
 * Creates a pseudo-random seed
 *
 * @return  The pseudo-random seed
 * 
 * @since  1.6
 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__warn_unused_result__)))
unsigned int libsimple_generate_seed(void); /* TODO man */

/**
 * Wrapper for srand(3) that creates a pseudo-random
 * seed with which it seeds the pseudo-random number
 * generator
 * 
 * @since  1.6
 */
inline void
libsimple_srand(void) /* TODO man */
{
	srand(libsimple_generate_seed());
}

/**
 * Generate a set of uniformly random bits
 * 
 * @param   bits    The number of bits to generate
 * @param   unused  This parameter is unused, but is provided so that
 *                  the function has a prototype that is compatible
 *                  with alternative functions that need an extra
 *                  argument to make it reenterent
 * @return          An integer with it's lowest `bits` bits independently
 *                  randomly set, each bit has a 50 % chance of being
 *                  cleared and 50 a % chance of being set, any excess
 *                  bit will be cleared
 * 
 * @since  1.6
 */
uintmax_t libsimple_random_bits(size_t bits, void *unused); /* TODO man */

/**
 * Generate a uniformally random, unsigned integer with [`min`, `max`]
 * 
 * @param   rng   Random bit generating function, `libsimple_random_bits`
 *                can be used, if any other function is used, it must
 *                have the same specification: the first argument is
 *                the number of bits to generate, the second argument
 *                will be `user` and is either unused or defined by the
 *                function, and the returned value shall have it's `bits`
 *                lowest bits randomly set and all other bits cleared
 * @param   user  Pass into `*rng` as it's second argument
 * @param   min   The lower, inclusive, boundary for the random value
 * @param   max   The upper, inclusive, boundary for the random value
 * @return        A uniformally random, unsigned integer within [`min`, `max`]
 * 
 * @since  1.6
 */
uintmax_t libsimple_random_unsigned(uintmax_t (*rng)(size_t bits, void *user), void *user, uintmax_t min, uintmax_t max); /* TODO man */

/**
 * Generate a uniformally random, signed integer with [`min`, `max`]
 * 
 * @param   rng   Random bit generating function, `libsimple_random_bits`
 *                can be used, if any other function is used, it must
 *                have the same specification: the first argument is
 *                the number of bits to generate, the second argument
 *                will be `user` and is either unused or defined by the
 *                function, and the returned value shall have it's `bits`
 *                lowest bits randomly set and all other bits cleared
 * @param   user  Pass into `*rng` as it's second argument
 * @param   min   The lower, inclusive, boundary for the random value
 * @param   max   The upper, inclusive, boundary for the random value
 * @return        A uniformally random, signed integer within [`min`, `max`]
 * 
 * @since  1.6
 */
intmax_t libsimple_random_signed(uintmax_t (*rng)(size_t bits, void *user), void *user, intmax_t min, intmax_t max); /* TODO man */

/**
 * Generate a uniformally random, real number with [`min`, `postmax`)
 * 
 * @param   rng   Random bit generating function, `libsimple_random_bits`
 *                can be used, if any other function is used, it must
 *                have the same specification: the first argument is
 *                the number of bits to generate, the second argument
 *                will be `user` and is either unused or defined by the
 *                function, and the returned value shall have it's `bits`
 *                lowest bits randomly set and all other bits cleared
 * @param   user  Pass into `*rng` as it's second argument
 * @param   min   The lower, inclusive, boundary for the random value
 * @param   max   The upper, exclusive, boundary for the random value
 * @return        A uniformally random, real number within [`min`, `postmax`)
 * 
 * @linkwith  -lm
 * 
 * @since  1.6
 */
long double libsimple_random_float(uintmax_t (*rng)(size_t bits, void *user), void *user, long double min, long double postmax); /* TODO man */

/**
 * Generate a set uniformally random bytes
 * 
 * @param   rng     Random bit generating function, `libsimple_random_bits`
 *                  can be used, if any other function is used, it must
 *                  have the same specification: the first argument is
 *                  the number of bits to generate, the second argument
 *                  will be `user` and is either unused or defined by the
 *                  function, and the returned value shall have it's `bits`
 *                  lowest bits randomly set and all other bits cleared
 * @param   user    Pass into `*rng` as it's second argument
 * @param   buffer  Output buffer for the random bytes
 * @param   bytes   The number of bytes to generate
 * @return          The end of `buffer`
 * 
 * @since  1.7
 */
void *libsimple_random_bytes(uintmax_t (*rng)(size_t bits, void *user), void *user, void *buffer, size_t bytes); /* TODO man */
