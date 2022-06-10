/* See LICENSE file for copyright and license details. */


/**
 * Converts a string to a `signed char`
 * according to the rules of strtol(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
signed char libsimple_strtohh(const char *restrict, char **restrict, int);
#ifndef strtohh
# define strtohh libsimple_strtohh
#endif


/**
 * Converts a string to a `unsigned char`
 * according to the rules of strtoul(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
unsigned char libsimple_strtouhh(const char *restrict, char **restrict, int);
#ifndef strtouhh
# define strtouhh libsimple_strtouhh
#endif


/**
 * Converts a string to a `signed short int`
 * according to the rules of strtol(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
signed short int libsimple_strtoh(const char *restrict, char **restrict, int);
#ifndef strtoh
# define strtoh libsimple_strtoh
#endif


/**
 * Converts a string to a `unsigned short int`
 * according to the rules of strtoul(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
unsigned short int libsimple_strtouh(const char *restrict, char **restrict, int);
#ifndef strtouh
# define strtouh libsimple_strtouh
#endif


/**
 * Converts a string to a `signed int`
 * according to the rules of strtol(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
signed int libsimple_strtoi(const char *restrict, char **restrict, int);
#ifndef strtoi
# define strtoi libsimple_strtoi
#endif


/**
 * Converts a string to a `unsigned int`
 * according to the rules of strtoul(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
unsigned int libsimple_strtou(const char *restrict, char **restrict, int);
#ifndef strtou
# define strtou libsimple_strtou
#endif


/**
 * Converts a string to a `ssize_t`
 * according to the rules of strtol(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
inline ssize_t
libsimple_strtoz(const char *restrict __nptr, char **restrict __endptr, int __base)
{
	return (ssize_t)strtol(__nptr, __endptr, __base);
}
#ifndef strtoz
# define strtoz libsimple_strtoz
#endif


/**
 * Converts a string to a `size_t`
 * according to the rules of strtol(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
inline size_t
libsimple_strtouz(const char *restrict __nptr, char **restrict __endptr, int __base)
{
	return (size_t)strtoul(__nptr, __endptr, __base);
}
#ifndef strtouz
# define strtouz libsimple_strtouz
#endif


/**
 * Converts a string to a `int8_t`
 * according to the rules of strtol(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
int_least8_t libsimple_strtoi8(const char *restrict, char **restrict, int);
#ifndef strtoi8
# define strtoi8 libsimple_strtoi8
#endif


/**
 * Converts a string to a `uint8_t`
 * according to the rules of strtoul(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
uint_least8_t libsimple_strtou8(const char *restrict, char **restrict, int);
#ifndef strtou8
# define strtou8 libsimple_strtou8
#endif


/**
 * Converts a string to a `int16_t`
 * according to the rules of strtol(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
int_least16_t libsimple_strtoi16(const char *restrict, char **restrict, int);
#ifndef strtoi16
# define strtoi16 libsimple_strtoi16
#endif


/**
 * Converts a string to a `uint16_t`
 * according to the rules of strtoul(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
uint_least16_t libsimple_strtou16(const char *restrict, char **restrict, int);
#ifndef strtou16
# define strtou16 libsimple_strtou16
#endif


/**
 * Converts a string to a `int32_t`
 * according to the rules of strtol(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
int_least32_t libsimple_strtoi32(const char *restrict, char **restrict, int);
#ifndef strtoi32
# define strtoi32 libsimple_strtoi32
#endif


/**
 * Converts a string to a `uint32_t`
 * according to the rules of strtoul(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
uint_least32_t libsimple_strtou32(const char *restrict, char **restrict, int);
#ifndef strtou32
# define strtou32 libsimple_strtou32
#endif


/**
 * Converts a string to a `int64_t`
 * according to the rules of strtol(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
int_least64_t libsimple_strtoi64(const char *restrict, char **restrict, int);
#ifndef strtoi64
# define strtoi64 libsimple_strtoi64
#endif


/**
 * Converts a string to a `uint64_t`
 * according to the rules of strtoul(3)
 * 
 * @param   nptr    The string to parse
 * @param   endptr  Output parameter for the position in `nptr`
 *                  where the first character that is not part
 *                  of the interpreted value resides
 * @param   base    The base the value is encoded in, 0 if
 *                  the function shall accept a prefix to
 *                  specify the base if it is not 10
 * @return          The encoded value (`errno` is unchanges), or
 *                  if out of range (`errno` set to `ERANGE`), the
 *                  closed value that can be represented; 0 on
 *                  failure (unless `errno` not set to `ERANGE`)
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__(2), __warn_unused_result__)))
uint_least64_t libsimple_strtou64(const char *restrict, char **restrict, int);
#ifndef strtou64
# define strtou64 libsimple_strtou64
#endif
