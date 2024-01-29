/* See LICENSE file for copyright and license details. */

/* TODO man, doc, test */


/*
 * How to calculate the difference between two signed integers
 * is not obvious, as the result must be unsigned to avoid
 * overflow. The solution is to first covert the number to
 * an unsigned type. Doing this ensure either that the value
 * is unmodified or will be set the maximum value the unsigned
 * type can store plus 1 plus the original negative value —
 * it wraps around just just like if two's completement was
 * used and the bits simply copied, regardless of how signed
 * integers are actually stored. Now the subtraction will
 * work adventurously without any overflow or the subtraction
 * will overflow to the correct value. For example, say
 * we are working with 8-bit integers, calculating (−1) − (−4)
 * works out like so:
 *    (−1) − (−4)
 *    = (256 − 1) − (256 − 4)
 *    = 255 − 252
 *    = 3
 * and calculating 5 − (−5) like so:
 *    5 − (−5)
 *    ≡ 5 − (256 − 5)
 *    = 5 − 251
 *    ≡ 256 + (5 − 251)
 *    = 256 + (−246)
 *    = 256 − 246
 *    = 10
 * Importantly, doing the convertion to unsigned type after
 * the subtraction result in unspecified behaviour as
 * signed integer overflow is unspecified behaviour.
 */


#define LIBSIMPLE_DIFF_(UTYPE, MAX, MIN) (UTYPE)((UTYPE)(MAX) - (UTYPE)(MIN))
#define LIBSIMPLE_IABS_(UTYPE, A, B) ((A) > (B) ? LIBSIMPLE_DIFF_(UTYPE, (A), (B)) : LIBSIMPLE_DIFF_(UTYPE, (B), (A)))
#define LIBSIMPLE_UABS_(UTYPE, A, B) ((UTYPE)((A) > (B) ? (A) - (B) : (B) - (A)))
#define LIBSIMPLE_SIGN_(UTYPE, STYPE, VALUE) ((VALUE) >> (sizeof(UTYPE) * CHAR_BIT - 1) ? (STYPE)(VALUE) : -(STYPE)-(VALUE))


inline unsigned char libsimple_hhdiff(signed char max, signed char min)
{ return LIBSIMPLE_DIFF_(unsigned char, max, min); }

inline unsigned short int libsimple_hdiff(short int max, short int min)
{ return LIBSIMPLE_DIFF_(unsigned short int, max, min); }

inline unsigned int libsimple_diff(int max, int min)
{ return LIBSIMPLE_DIFF_(unsigned int, max, min); }

inline unsigned long int libsimple_ldiff(long int max, long int min)
{ return LIBSIMPLE_DIFF_(unsigned long int, max, min); }

inline unsigned long long int libsimple_lldiff(long long int max, long long int min)
{ return LIBSIMPLE_DIFF_(unsigned long long int, max, min); }

inline size_t libsimple_zdiff(ssize_t max, ssize_t min)
{ return LIBSIMPLE_DIFF_(size_t, max, min); }

inline uint_least8_t libsimple_i8diff(int_least8_t max, int_least8_t min)
{ return LIBSIMPLE_DIFF_(uint_least8_t, max, min); }

inline uint_least16_t libsimple_i16diff(int_least16_t max, int_least16_t min)
{ return LIBSIMPLE_DIFF_(uint_least16_t, max, min); }

inline uint_least32_t libsimple_i32diff(int_least32_t max, int_least32_t min)
{ return LIBSIMPLE_DIFF_(uint_least32_t, max, min); }

inline uint_least64_t libsimple_i64diff(int_least64_t max, int_least64_t min)
{ return LIBSIMPLE_DIFF_(uint_least64_t, max, min); }

inline uintmax_t libsimple_imaxdiff(intmax_t max, intmax_t min)
{ return LIBSIMPLE_DIFF_(uintmax_t, max, min); }

inline uintptr_t libsimple_iptrdiff(intptr_t max, intptr_t min)
{ return LIBSIMPLE_DIFF_(uintptr_t, max, min); }


inline unsigned char libsimple_hhabs(signed char a, signed char b)
{ return LIBSIMPLE_IABS_(unsigned char, a, b); }

inline unsigned short int libsimple_habs(short int a, short int b)
{ return LIBSIMPLE_IABS_(unsigned short int, a, b); }

inline unsigned int libsimple_abs(int a, int b)
{ return LIBSIMPLE_IABS_(unsigned int, a, b); }

inline unsigned long int libsimple_labs(long int a, long int b)
{ return LIBSIMPLE_IABS_(unsigned long int, a, b); }

inline unsigned long long int libsimple_llabs(long long int a, long long int b)
{ return LIBSIMPLE_IABS_(unsigned long long int, a, b); }

inline size_t libsimple_zabs(ssize_t a, ssize_t b)
{ return LIBSIMPLE_IABS_(size_t, a, b); }

inline uint_least8_t libsimple_i8abs(int_least8_t a, int_least8_t b)
{ return LIBSIMPLE_IABS_(uint_least8_t, a, b); }

inline uint_least16_t libsimple_i16abs(int_least16_t a, int_least16_t b)
{ return LIBSIMPLE_IABS_(uint_least16_t, a, b); }

inline uint_least32_t libsimple_i32abs(int_least32_t a, int_least32_t b)
{ return LIBSIMPLE_IABS_(uint_least32_t, a, b); }

inline uint_least64_t libsimple_i64abs(int_least64_t a, int_least64_t b)
{ return LIBSIMPLE_IABS_(uint_least64_t, a, b); }

inline uintmax_t libsimple_imaxabs(intmax_t a, intmax_t b)
{ return LIBSIMPLE_IABS_(uintmax_t, a, b); }

inline uintptr_t libsimple_iptrabs(intptr_t a, intptr_t b)
{ return LIBSIMPLE_IABS_(uintptr_t, a, b); }


inline unsigned char libsimple_uhhabs(unsigned char a, unsigned char b)
{ return LIBSIMPLE_UABS_(unsigned char, a, b); }

inline unsigned short int libsimple_uhabs(unsigned short int a, unsigned short int b)
{ return LIBSIMPLE_UABS_(unsigned short int, a, b); }

inline unsigned int libsimple_uabs(unsigned int a, unsigned int b)
{ return LIBSIMPLE_UABS_(unsigned int, a, b); }

inline unsigned long int libsimple_ulabs(unsigned long int a, unsigned long int b)
{ return LIBSIMPLE_UABS_(unsigned long int, a, b); }

inline unsigned long long int libsimple_ullabs(unsigned long long int a, unsigned long long int b)
{ return LIBSIMPLE_UABS_(unsigned long long int, a, b); }

inline size_t libsimple_uzabs(size_t a, size_t b)
{ return LIBSIMPLE_UABS_(size_t, a, b); }

inline uint_least8_t libsimple_u8abs(uint_least8_t a, uint_least8_t b)
{ return LIBSIMPLE_UABS_(uint_least8_t, a, b); }

inline uint_least16_t libsimple_u16abs(uint_least16_t a, uint_least16_t b)
{ return LIBSIMPLE_UABS_(uint_least16_t, a, b); }

inline uint_least32_t libsimple_u32abs(uint_least32_t a, uint_least32_t b)
{ return LIBSIMPLE_UABS_(uint_least32_t, a, b); }

inline uint_least64_t libsimple_u64abs(uint_least64_t a, uint_least64_t b)
{ return LIBSIMPLE_UABS_(uint_least64_t, a, b); }

inline uintmax_t libsimple_umaxabs(uintmax_t a, uintmax_t b)
{ return LIBSIMPLE_UABS_(uintmax_t, a, b); }

inline uintptr_t libsimple_uptrabs(uintptr_t a, uintptr_t b)
{ return LIBSIMPLE_UABS_(uintptr_t, a, b); }


inline signed char libsimple_toihh(unsigned char value)
{ return LIBSIMPLE_SIGN_(unsigned char, signed char, value); }

inline short int libsimple_toih(unsigned short int value)
{ return LIBSIMPLE_SIGN_(unsigned short int, short int, value); }

inline int libsimple_toi(unsigned int value)
{ return LIBSIMPLE_SIGN_(unsigned int, int, value); }

inline long int libsimple_toil(unsigned long int value)
{ return LIBSIMPLE_SIGN_(unsigned long int, long int, value); }

inline long long int libsimple_toill(unsigned long long int value)
{ return LIBSIMPLE_SIGN_(unsigned long long int, long long int, value); }

inline ssize_t libsimple_toiz(size_t value)
{ return LIBSIMPLE_SIGN_(size_t, ssize_t, value); }

inline int_least8_t libsimple_toi8(uint_least8_t value)
{ return LIBSIMPLE_SIGN_(uint_least8_t, int_least8_t, value); }

inline int_least16_t libsimple_toi16(uint_least16_t value)
{ return LIBSIMPLE_SIGN_(uint_least16_t, int_least16_t, value); }

inline int_least32_t libsimple_toi32(uint_least32_t value)
{ return LIBSIMPLE_SIGN_(uint_least32_t, int_least32_t, value); }

inline int_least64_t libsimple_toi64(uint_least64_t value)
{ return LIBSIMPLE_SIGN_(uint_least32_t, int_least32_t, value); }

inline intmax_t libsimple_toimax(uintmax_t value)
{ return LIBSIMPLE_SIGN_(uintmax_t, intmax_t, value); }

inline intptr_t libsimple_toiptr(uintptr_t value)
{ return LIBSIMPLE_SIGN_(uintptr_t, intptr_t, value); }



#undef LIBSIMPLE_DIFF_
#undef LIBSIMPLE_IABS_
#undef LIBSIMPLE_UABS_
#undef LIBSIMPLE_SIGN_
