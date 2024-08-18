/* See LICENSE file for copyright and license details. */

/* TODO test, doc, man */

#if defined(__GNUC__)

# define LIBSIMPLE_UADD_WOULD_OVERFLOW(A, B, MAX)              (__builtin_add_overflow_p(A, B, &(A)))
# define LIBSIMPLE_USUB_WOULD_OVERFLOW(A, B)                   (__builtin_sub_overflow_p(A, B, &(A)))
# define LIBSIMPLE_UMUL_WOULD_OVERFLOW(A, B, MAX)              (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_UMUL_WOULD_OVERFLOW_NONZERO(A, B, MAX)      (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_UINCR_WOULD_OVERFLOW(A, MAX)                (__builtin_add_overflow_p(A, 1, &(A)))
# define LIBSIMPLE_UDECR_WOULD_OVERFLOW(A)                     (__builtin_sub_overflow_p(A, 1, &(A)))

# define LIBSIMPLE_UADD_OVERFLOW(A, B, RES, MAX)               (__builtin_add_overflow(A, B, RES))
# define LIBSIMPLE_USUB_OVERFLOW(A, B, RES)                    (__builtin_sub_overflow(A, B, RES))
# define LIBSIMPLE_UMUL_OVERFLOW(A, B, RES, MAX)               (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_UMUL_OVERFLOW_NONZERO(A, B, RES, MAX)       (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_UINCR_OVERFLOW(AP, MAX)                     (__builtin_add_overflow(*(AP), 1, AP))
# define LIBSIMPLE_UDECR_OVERFLOW(AP)                          (__builtin_sub_overflow(*(AP), 1, AP))

# define LIBSIMPLE_SADD_WOULD_OVERFLOW(A, B, MIN, MAX)         (__builtin_add_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SADD_WOULD_OVERFLOW_A_NEG(A, B, MIN, MAX)   (__builtin_add_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SADD_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)   (__builtin_add_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SADD_WOULD_OVERFLOW_NONNEG(A, B, MIN, MAX)  (__builtin_add_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SSUB_WOULD_OVERFLOW(A, B, MIN, MAX)         (__builtin_sub_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SSUB_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)   (__builtin_sub_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SSUB_WOULD_OVERFLOW_B_POS(A, B, MIN, MAX)   (__builtin_sub_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW(A, B, MIN, MAX)         (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_NONZERO(A, B, MIN, MAX) (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN(A, B, MIN, MAX)      (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BNZ(A, B, MIN, MAX)  (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BN(A, B, MIN, MAX)   (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BP(A, B, MIN, MAX)   (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP(A, B, MIN, MAX)      (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BNZ(A, B, MIN, MAX)  (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BN(A, B, MIN, MAX)   (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BP(A, B, MIN, MAX)   (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_BN(A, B, MIN, MAX)      (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BN(A, B, MIN, MAX)  (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_BP(A, B, MIN, MAX)      (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BP(A, B, MIN, MAX)  (__builtin_mul_overflow_p(A, B, &(A)))
# define LIBSIMPLE_SDIV_WOULD_OVERFLOW(A, B, MIN, MAX)         ((A) == (MAX) && (B) == -1 && -(MAX) == (MIN))
# define LIBSIMPLE_SINCR_WOULD_OVERFLOW(A, MAX)                (__builtin_add_overflow_p(A, 1, &(A)))
# define LIBSIMPLE_SDECR_WOULD_OVERFLOW(A, MIN)                (__builtin_sub_overflow_p(A, 1, &(A)))

# define LIBSIMPLE_SADD_OVERFLOW(A, B, RES, MIN, MAX)          (__builtin_add_overflow(A, B, RES))
# define LIBSIMPLE_SADD_OVERFLOW_A_NEG(A, B, RES, MIN, MAX)    (__builtin_add_overflow(A, B, RES))
# define LIBSIMPLE_SADD_OVERFLOW_B_NEG(A, B, RES, MIN, MAX)    (__builtin_add_overflow(A, B, RES))
# define LIBSIMPLE_SADD_OVERFLOW_NONNEG(A, B, RES, MIN, MAX)   (__builtin_add_overflow(A, B, RES))
# define LIBSIMPLE_SSUB_OVERFLOW(A, B, RES, MIN, MAX)          (__builtin_sub_overflow(A, B, RES))
# define LIBSIMPLE_SSUB_OVERFLOW_B_NEG(A, B, RES, MIN, MAX)    (__builtin_sub_overflow(A, B, RES))
# define LIBSIMPLE_SSUB_OVERFLOW_B_POS(A, B, RES, MIN, MAX)    (__builtin_sub_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW(A, B, RES, MIN, MAX)          (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_NONZERO(A, B, RES, MIN, MAX)  (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_AN(A, B, RES, MIN, MAX)       (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_AN_BNZ(A, B, RES, MIN, MAX)   (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_AN_BN(A, B, RES, MIN, MAX)    (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_AN_BP(A, B, RES, MIN, MAX)    (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_AP(A, B, RES, MIN, MAX)       (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_AP_BNZ(A, B, RES, MIN, MAX)   (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_AP_BN(A, B, RES, MIN, MAX)    (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_AP_BP(A, B, RES, MIN, MAX)    (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_BN(A, B, RES, MIN, MAX)       (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_ANZ_BN(A, B, RES, MIN, MAX)   (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_BP(A, B, RES, MIN, MAX)       (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SMUL_OVERFLOW_ANZ_BP(A, B, RES, MIN, MAX)   (__builtin_mul_overflow(A, B, RES))
# define LIBSIMPLE_SDIV_OVERFLOW(A, B, RES, MIN, MAX)          (LIBSIMPLE_SDIV_WOULD_OVERFLOW(A, B, MIN, MAX) ? 1 : (*(RES) = (A) / (B), 0))
# define LIBSIMPLE_SINCR_OVERFLOW(AP, MAX)                     (__builtin_add_overflow(*(AP), 1, AP))
# define LIBSIMPLE_SDECR_OVERFLOW(AP, MIN)                     (__builtin_sub_overflow(*(AP), 1, AP))

# define LIBSIMPLE_INCR_WOULD_OVERFLOW(A, MAX)                 (__builtin_add_overflow_p(A, 1, &(A)))
# define LIBSIMPLE_DECR_WOULD_OVERFLOW(A, MIN)                 (__builtin_sub_overflow_p(A, 1, &(A)))

# define LIBSIMPLE_INCR_OVERFLOW(AP, MAX)                      (__builtin_add_overflow(*(AP), 1, AP))
# define LIBSIMPLE_DECR_OVERFLOW(AP, MIN)                      (__builtin_sub_overflow(*(AP), 1, AP))

#else

# define LIBSIMPLE_UADD_WOULD_OVERFLOW(A, B, MAX)              ((A) > (MAX) - (B))
# define LIBSIMPLE_USUB_WOULD_OVERFLOW(A, B)                   ((A) < (B))
# define LIBSIMPLE_UMUL_WOULD_OVERFLOW(A, B, MAX)              ((A) && (B) && (A) > (MAX) / (B))
# define LIBSIMPLE_UMUL_WOULD_OVERFLOW_NONZERO(A, B, MAX)      ((A) > (MAX) / (B))
# define LIBSIMPLE_UINCR_WOULD_OVERFLOW(A, MAX)                ((A) == (MAX))
# define LIBSIMPLE_UDECR_WOULD_OVERFLOW(A)                     (!(A))

# define LIBSIMPLE_UADD_OVERFLOW(A, B, RES, MAX)               (LIBSIMPLE_UADD_WOULD_OVERFLOW(A, B, MAX)         ? 1 : (*(RES) = (A) + (B), 0))
# define LIBSIMPLE_USUB_OVERFLOW(A, B, RES)                    (LIBSIMPLE_USUB_WOULD_OVERFLOW(A, B)              ? 1 : (*(RES) = (A) - (B), 0))
# define LIBSIMPLE_UMUL_OVERFLOW(A, B, RES, MAX)               (LIBSIMPLE_UMUL_WOULD_OVERFLOW(A, B, MAX)         ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_UMUL_OVERFLOW_NONZERO(A, B, RES, MAX)       (LIBSIMPLE_UMUL_WOULD_OVERFLOW_NONZERO(A, B, MAX) ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_UINCR_OVERFLOW(AP, MAX)                     ((*(AP))++ == (MAX))
# define LIBSIMPLE_UDECR_OVERFLOW(AP)                          (!(*(AP))--)

# define LIBSIMPLE_SADD_WOULD_OVERFLOW(A, B, MIN, MAX)         ((B) <= 0 ? (A) < (MIN) - (B) : (A) <= 0 ? (B) < (MIN) - (A) : (A) > (MAX) - (B))
# define LIBSIMPLE_SADD_WOULD_OVERFLOW_A_NEG(A, B, MIN, MAX)   ((B) < (MIN) - (A))
# define LIBSIMPLE_SADD_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)   ((A) < (MIN) - (B))
# define LIBSIMPLE_SADD_WOULD_OVERFLOW_NONNEG(A, B, MIN, MAX)  ((A) > (MAX) - (B))
# define LIBSIMPLE_SSUB_WOULD_OVERFLOW(A, B, MIN, MAX)         ((B) <= 0 ? (A) > (MAX) + (B) : (A) < (MIN) + (B))
# define LIBSIMPLE_SSUB_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)   ((A) > (MAX) + (B))
# define LIBSIMPLE_SSUB_WOULD_OVERFLOW_B_POS(A, B, MIN, MAX)   ((A) < (MIN) + (B))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW(A, B, MIN, MAX)         ((A) && (B) && LIBSIMPLE_SMUL_WOULD_OVERFLOW_NONZERO(A, B, MIN, MAX))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_NONZERO(A, B, MIN, MAX) ((A) < 0 ? LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BNZ(A, B, MIN, MAX) : LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BNZ(A, B, MIN, MAX))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN(A, B, MIN, MAX)      ((B) && LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BNZ(A, B, MIN, MAX))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BNZ(A, B, MIN, MAX)  ((B) < 0 ? LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BN(A, B, MIN, MAX) : LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BP(A, B, MIN, MAX))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BN(A, B, MIN, MAX)   ((A) < -(MAX) / (B))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BP(A, B, MIN, MAX)   ((A) < (MIN) / (B))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP(A, B, MIN, MAX)      ((B) && LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BNZ(A, B, MIN, MAX))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BNZ(A, B, MIN, MAX)  ((B) < 0 ? LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BN(A, B, MIN, MAX) : LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BP(A, B, MIN, MAX))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BN(A, B, MIN, MAX)   ((B) < (MIN) / (A))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BP(A, B, MIN, MAX)   ((A) > (MAX) / (B))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_BN(A, B, MIN, MAX)      ((A) && LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BN(A, B, MIN, MAX))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BN(A, B, MIN, MAX)  ((A) < 0 ? LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BN(A, B, MIN, MAX) : LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BN(A, B, MIN, MAX))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_BP(A, B, MIN, MAX)      ((A) && LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BP(A, B, MIN, MAX))
# define LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BP(A, B, MIN, MAX)  ((A) < 0 ? LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BP(A, B, MIN, MAX) : LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BP(A, B, MIN, MAX))
# define LIBSIMPLE_SDIV_WOULD_OVERFLOW(A, B, MIN, MAX)         ((A) == (MAX) && (B) == -1 && -(MAX) == (MIN))
# define LIBSIMPLE_SINCR_WOULD_OVERFLOW(A, MAX)                ((A) == (MAX))
# define LIBSIMPLE_SDECR_WOULD_OVERFLOW(A, MIN)                ((A) == (MIN))

# define LIBSIMPLE_SADD_OVERFLOW(A, B, RES, MIN, MAX)          (LIBSIMPLE_SADD_WOULD_OVERFLOW(A, B, MIN, MAX)         ? 1 : (*(RES) = (A) + (B), 0))
# define LIBSIMPLE_SADD_OVERFLOW_A_NEG(A, B, RES, MIN, MAX)    (LIBSIMPLE_SADD_WOULD_OVERFLOW_A_NEG(A, B, MIN, MAX)   ? 1 : (*(RES) = (A) - (B), 0))
# define LIBSIMPLE_SADD_OVERFLOW_B_NEG(A, B, RES, MIN, MAX)    (LIBSIMPLE_SADD_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)   ? 1 : (*(RES) = (A) - (B), 0))
# define LIBSIMPLE_SADD_OVERFLOW_NONNEG(A, B, RES, MIN, MAX)   (LIBSIMPLE_SADD_WOULD_OVERFLOW_NONNEG(A, B, MIN, MAX)  ? 1 : (*(RES) = (A) - (B), 0))
# define LIBSIMPLE_SSUB_OVERFLOW(A, B, RES, MIN, MAX)          (LIBSIMPLE_SSUB_WOULD_OVERFLOW(A, B, MIN, MAX)         ? 1 : (*(RES) = (A) - (B), 0))
# define LIBSIMPLE_SSUB_OVERFLOW_B_NEG(A, B, RES, MIN, MAX)    (LIBSIMPLE_SSUB_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)   ? 1 : (*(RES) = (A) - (B), 0))
# define LIBSIMPLE_SSUB_OVERFLOW_B_POS(A, B, RES, MIN, MAX)    (LIBSIMPLE_SSUB_WOULD_OVERFLOW_B_POS(A, B, MIN, MAX)   ? 1 : (*(RES) = (A) - (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW(A, B, RES, MIN, MAX)          (LIBSIMPLE_SMUL_WOULD_OVERFLOW(A, B, MIN, MAX)         ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_NONZERO(A, B, RES, MIN, MAX)  (LIBSIMPLE_SMUL_WOULD_OVERFLOW_NONZERO(A, B, MIN, MAX) ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_AN(A, B, RES, MIN, MAX)       (LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN(A, B, MIN, MAX)      ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_AN_BNZ(A, B, RES, MIN, MAX)   (LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BNZ(A, B, MIN, MAX)  ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_AN_BN(A, B, RES, MIN, MAX)    (LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BN(A, B, MIN, MAX)   ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_AN_BP(A, B, RES, MIN, MAX)    (LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BP(A, B, MIN, MAX)   ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_AP(A, B, RES, MIN, MAX)       (LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP(A, B, MIN, MAX)      ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_AP_BNZ(A, B, RES, MIN, MAX)   (LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BNZ(A, B, MIN, MAX)  ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_AP_BN(A, B, RES, MIN, MAX)    (LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BN(A, B, MIN, MAX)   ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_AP_BP(A, B, RES, MIN, MAX)    (LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BP(A, B, MIN, MAX)   ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_BN(A, B, RES, MIN, MAX)       (LIBSIMPLE_SMUL_WOULD_OVERFLOW_BN(A, B, MIN, MAX)      ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_ANZ_BN(A, B, RES, MIN, MAX)   (LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BN(A, B, MIN, MAX)  ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_BP(A, B, RES, MIN, MAX)       (LIBSIMPLE_SMUL_WOULD_OVERFLOW_BP(A, B, MIN, MAX)      ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SMUL_OVERFLOW_ANZ_BP(A, B, RES, MIN, MAX)   (LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BP(A, B, MIN, MAX)  ? 1 : (*(RES) = (A) * (B), 0))
# define LIBSIMPLE_SDIV_OVERFLOW(A, B, RES, MIN, MAX)          (LIBSIMPLE_SDIV_WOULD_OVERFLOW(A, B, MIN, MAX)         ? 1 : (*(RES) = (A) / (B), 0))
# define LIBSIMPLE_SINCR_OVERFLOW(AP, MAX)                     ((*(AP))++ == (MAX))
# define LIBSIMPLE_SDECR_OVERFLOW(AP, MIN)                     ((*(AP))-- == (MIN))

# define LIBSIMPLE_INCR_WOULD_OVERFLOW(A, MAX)                 ((A) == (MAX))
# define LIBSIMPLE_DECR_WOULD_OVERFLOW(A, MIN)                 ((A) == (MIN))

# define LIBSIMPLE_INCR_OVERFLOW(AP, MAX)                      ((*(AP))++ == (MAX))
# define LIBSIMPLE_DECR_OVERFLOW(AP, MIN)                      ((*(AP))-- == (MIN))

#endif


/* @since  1.1 */
#ifndef UADD_WOULD_OVERFLOW
# define UADD_WOULD_OVERFLOW(A, B, MAX)              LIBSIMPLE_UADD_WOULD_OVERFLOW(A, B, MAX)
#endif

/* @since  1.1 */
#ifndef USUB_WOULD_OVERFLOW
# define USUB_WOULD_OVERFLOW(A, B)                   LIBSIMPLE_USUB_WOULD_OVERFLOW(A, B)
#endif

/* @since  1.1 */
#ifndef UMUL_WOULD_OVERFLOW
# define UMUL_WOULD_OVERFLOW(A, B, MAX)              LIBSIMPLE_UMUL_WOULD_OVERFLOW(A, B, MAX)
#endif

/* @since  1.1 */
#ifndef UMUL_WOULD_OVERFLOW_NONZERO
# define UMUL_WOULD_OVERFLOW_NONZERO(A, B, MAX)      LIBSIMPLE_UMUL_WOULD_OVERFLOW_NONZERO(A, B, MAX)
#endif

/* @since  1.1 */
#ifndef UINCR_WOULD_OVERFLOW
# define UINCR_WOULD_OVERFLOW(A, MAX)                LIBSIMPLE_UINCR_WOULD_OVERFLOW(A, MAX)
#endif

/* @since  1.1 */
#ifndef UDECR_WOULD_OVERFLOW
# define UDECR_WOULD_OVERFLOW(A)                     LIBSIMPLE_UDECR_WOULD_OVERFLOW(A)
#endif

/* @since  1.1 */
#ifndef UADD_OVERFLOW
# define UADD_OVERFLOW(A, B, RES, MAX)               LIBSIMPLE_UADD_OVERFLOW(A, B, RES, MAX)
#endif

/* @since  1.1 */
#ifndef USUB_OVERFLOW
# define USUB_OVERFLOW(A, B, RES)                    LIBSIMPLE_USUB_OVERFLOW(A, B, RES)
#endif

/* @since  1.1 */
#ifndef UMUL_OVERFLOW
# define UMUL_OVERFLOW(A, B, RES, MAX)               LIBSIMPLE_UMUL_OVERFLOW(A, B, RES, MAX)
#endif

/* @since  1.1 */
#ifndef UMUL_OVERFLOW_NONZERO
# define UMUL_OVERFLOW_NONZERO(A, B, RES, MAX)       LIBSIMPLE_UMUL_OVERFLOW_NONZERO(A, B, RES, MAX)
#endif

/* @since  1.1 */
#ifndef UINCR_OVERFLOW
# define UINCR_OVERFLOW(AP, MAX)                     LIBSIMPLE_UINCR_OVERFLOW(AP, MAX)
#endif

/* @since  1.1 */
#ifndef UDECR_OVERFLOW
# define UDECR_OVERFLOW(AP)                          LIBSIMPLE_UDECR_OVERFLOW(AP)
#endif

/* @since  1.1 */
#ifndef SADD_WOULD_OVERFLOW
# define SADD_WOULD_OVERFLOW(A, B, MIN, MAX)         LIBSIMPLE_SADD_WOULD_OVERFLOW(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SADD_WOULD_OVERFLOW_A_NEG
# define SADD_WOULD_OVERFLOW_A_NEG(A, B, MIN, MAX)   LIBSIMPLE_SADD_WOULD_OVERFLOW_A_NEG(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SADD_WOULD_OVERFLOW_B_NEG
# define SADD_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)   LIBSIMPLE_SADD_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SADD_WOULD_OVERFLOW_NONNEG
# define SADD_WOULD_OVERFLOW_NONNEG(A, B, MIN, MAX)  LIBSIMPLE_SADD_WOULD_OVERFLOW_NONNEG(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SSUB_WOULD_OVERFLOW
# define SSUB_WOULD_OVERFLOW(A, B, MIN, MAX)         LIBSIMPLE_SSUB_WOULD_OVERFLOW(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SSUB_WOULD_OVERFLOW_B_NEG
# define SSUB_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)   LIBSIMPLE_SSUB_WOULD_OVERFLOW_B_NEG(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SSUB_WOULD_OVERFLOW_B_POS
# define SSUB_WOULD_OVERFLOW_B_POS(A, B, MIN, MAX)   LIBSIMPLE_SSUB_WOULD_OVERFLOW_B_POS(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW
# define SMUL_WOULD_OVERFLOW(A, B, MIN, MAX)         LIBSIMPLE_SMUL_WOULD_OVERFLOW(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_NONZERO
# define SMUL_WOULD_OVERFLOW_NONZERO(A, B, MIN, MAX) LIBSIMPLE_SMUL_WOULD_OVERFLOW_NONZERO(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_AN
# define SMUL_WOULD_OVERFLOW_AN(A, B, MIN, MAX)      LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_AN_BNZ
# define SMUL_WOULD_OVERFLOW_AN_BNZ(A, B, MIN, MAX)  LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BNZ(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_AN_BN
# define SMUL_WOULD_OVERFLOW_AN_BN(A, B, MIN, MAX)   LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BN(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_AN_BP
# define SMUL_WOULD_OVERFLOW_AN_BP(A, B, MIN, MAX)   LIBSIMPLE_SMUL_WOULD_OVERFLOW_AN_BP(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_AP
# define SMUL_WOULD_OVERFLOW_AP(A, B, MIN, MAX)      LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_AP_BNZ
# define SMUL_WOULD_OVERFLOW_AP_BNZ(A, B, MIN, MAX)  LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BNZ(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_AP_BN
# define SMUL_WOULD_OVERFLOW_AP_BN(A, B, MIN, MAX)   LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BN(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_AP_BP
# define SMUL_WOULD_OVERFLOW_AP_BP(A, B, MIN, MAX)   LIBSIMPLE_SMUL_WOULD_OVERFLOW_AP_BP(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_BN
# define SMUL_WOULD_OVERFLOW_BN(A, B, MIN, MAX)      LIBSIMPLE_SMUL_WOULD_OVERFLOW_BN(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_ANZ_BN
# define SMUL_WOULD_OVERFLOW_ANZ_BN(A, B, MIN, MAX)  LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BN(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_BP
# define SMUL_WOULD_OVERFLOW_BP(A, B, MIN, MAX)      LIBSIMPLE_SMUL_WOULD_OVERFLOW_BP(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_WOULD_OVERFLOW_ANZ_BP
# define SMUL_WOULD_OVERFLOW_ANZ_BP(A, B, MIN, MAX)  LIBSIMPLE_SMUL_WOULD_OVERFLOW_ANZ_BP(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SDIV_WOULD_OVERFLOW
# define SDIV_WOULD_OVERFLOW(A, B, MIN, MAX)         LIBSIMPLE_SDIV_WOULD_OVERFLOW(A, B, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SINCR_WOULD_OVERFLOW
# define SINCR_WOULD_OVERFLOW(A, MAX)                LIBSIMPLE_SINCR_WOULD_OVERFLOW(A, MAX)
#endif

/* @since  1.1 */
#ifndef SDECR_WOULD_OVERFLOW
# define SDECR_WOULD_OVERFLOW(A, MIN)                LIBSIMPLE_SDECR_WOULD_OVERFLOW(A, MIN)
#endif

/* @since  1.1 */
#ifndef SADD_OVERFLOW
# define SADD_OVERFLOW(A, B, RES, MIN, MAX)          LIBSIMPLE_SADD_OVERFLOW(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SADD_OVERFLOW_A_NEG
# define SADD_OVERFLOW_A_NEG(A, B, RES, MIN, MAX)    LIBSIMPLE_SADD_OVERFLOW_A_NEG(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SADD_OVERFLOW_B_NEG
# define SADD_OVERFLOW_B_NEG(A, B, RES, MIN, MAX)    LIBSIMPLE_SADD_OVERFLOW_B_NEG(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SADD_OVERFLOW_NONNEG
# define SADD_OVERFLOW_NONNEG(A, B, RES, MIN, MAX)   LIBSIMPLE_SADD_OVERFLOW_NONNEG(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SSUB_OVERFLOW
# define SSUB_OVERFLOW(A, B, RES, MIN, MAX)          LIBSIMPLE_SSUB_OVERFLOW(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SSUB_OVERFLOW_B_NEG
# define SSUB_OVERFLOW_B_NEG(A, B, RES, MIN, MAX)    LIBSIMPLE_SSUB_OVERFLOW_B_NEG(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SSUB_OVERFLOW_B_POS
# define SSUB_OVERFLOW_B_POS(A, B, RES, MIN, MAX)    LIBSIMPLE_SSUB_OVERFLOW_B_POS(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW
# define SMUL_OVERFLOW(A, B, RES, MIN, MAX)          LIBSIMPLE_SMUL_OVERFLOW(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_NONZERO
# define SMUL_OVERFLOW_NONZERO(A, B, RES, MIN, MAX)  LIBSIMPLE_SMUL_OVERFLOW_NONZERO(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_AN
# define SMUL_OVERFLOW_AN(A, B, RES, MIN, MAX)       LIBSIMPLE_SMUL_OVERFLOW_AN(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_AN_BNZ
# define SMUL_OVERFLOW_AN_BNZ(A, B, RES, MIN, MAX)   LIBSIMPLE_SMUL_OVERFLOW_AN_BNZ(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_AN_BN
# define SMUL_OVERFLOW_AN_BN(A, B, RES, MIN, MAX)    LIBSIMPLE_SMUL_OVERFLOW_AN_BN(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_AN_BP
# define SMUL_OVERFLOW_AN_BP(A, B, RES, MIN, MAX)    LIBSIMPLE_SMUL_OVERFLOW_AN_BP(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_AP
# define SMUL_OVERFLOW_AP(A, B, RES, MIN, MAX)       LIBSIMPLE_SMUL_OVERFLOW_AP(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_AP_BNZ
# define SMUL_OVERFLOW_AP_BNZ(A, B, RES, MIN, MAX)   LIBSIMPLE_SMUL_OVERFLOW_AP_BNZ(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_AP_BN
# define SMUL_OVERFLOW_AP_BN(A, B, RES, MIN, MAX)    LIBSIMPLE_SMUL_OVERFLOW_AP_BN(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_AP_BP
# define SMUL_OVERFLOW_AP_BP(A, B, RES, MIN, MAX)    LIBSIMPLE_SMUL_OVERFLOW_AP_BP(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_BN
# define SMUL_OVERFLOW_BN(A, B, RES, MIN, MAX)       LIBSIMPLE_SMUL_OVERFLOW_BN(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_ANZ_BN
# define SMUL_OVERFLOW_ANZ_BN(A, B, RES, MIN, MAX)   LIBSIMPLE_SMUL_OVERFLOW_ANZ_BN(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_BP
# define SMUL_OVERFLOW_BP(A, B, RES, MIN, MAX)       LIBSIMPLE_SMUL_OVERFLOW_BP(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SMUL_OVERFLOW_ANZ_BP
# define SMUL_OVERFLOW_ANZ_BP(A, B, RES, MIN, MAX)   LIBSIMPLE_SMUL_OVERFLOW_ANZ_BP(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SDIV_OVERFLOW
# define SDIV_OVERFLOW(A, B, RES, MIN, MAX)          LIBSIMPLE_SDIV_OVERFLOW(A, B, RES, MIN, MAX)
#endif

/* @since  1.1 */
#ifndef SINCR_OVERFLOW
# define SINCR_OVERFLOW(AP, MAX)                     LIBSIMPLE_SINCR_OVERFLOW(AP, MAX)
#endif

/* @since  1.1 */
#ifndef SDECR_OVERFLOW
# define SDECR_OVERFLOW(AP, MIN)                     LIBSIMPLE_SDECR_OVERFLOW(AP, MIN)
#endif

/* @since  1.1 */
#ifndef INCR_WOULD_OVERFLOW
# define INCR_WOULD_OVERFLOW(A, MAX)                 LIBSIMPLE_INCR_WOULD_OVERFLOW(A, MAX)
#endif

/* @since  1.1 */
#ifndef DECR_WOULD_OVERFLOW
# define DECR_WOULD_OVERFLOW(A, MIN)                 LIBSIMPLE_DECR_WOULD_OVERFLOW(A, MIN)
#endif

/* @since  1.1 */
#ifndef INCR_OVERFLOW
# define INCR_OVERFLOW(AP, MAX)                      LIBSIMPLE_INCR_OVERFLOW(AP, MAX)
#endif

/* @since  1.1 */
#ifndef DECR_OVERFLOW
# define DECR_OVERFLOW(AP, MIN)                      LIBSIMPLE_DECR_OVERFLOW(AP, MIN)
#endif
