/* See LICENSE file for copyright and license details. */

/* TODO man, doc, test */


#define LIBSIMPLE_CMP_NUMP__(TYPE, L, R)\
	const TYPE *L##_typed = L;\
	const TYPE *R##_typed = R;\
	return *L##_typed < *R##_typed ? -1 : *L##_typed > *R##_typed

#define LIBSIMPLE_CMP_NUMPP__(TYPE, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	return **L##_typed < **R##_typed ? -1 : **L##_typed > **R##_typed

#define LIBSIMPLE_CMP_NUL_NUMPP__(TYPE, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	if (!*L##_typed)\
		return !*R##_typed ? 0 : -1;\
	if (!*R##_typed)\
		return +1;\
	return **L##_typed < **R##_typed ? -1 : **L##_typed > **R##_typed

#define LIBSIMPLE_CMP_NUMPP_NUL__(TYPE, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	if (!*L##_typed)\
		return !*R##_typed ? 0 : +1;\
	if (!*R##_typed)\
		return -1;\
	return **L##_typed < **R##_typed ? -1 : **L##_typed > **R##_typed

#define LIBSIMPLE_CMP_REV_NUMP__(TYPE, L, R)\
	const TYPE *L##_typed = L;\
	const TYPE *R##_typed = R;\
	return *L##_typed > *R##_typed ? -1 : *L##_typed < *R##_typed

#define LIBSIMPLE_CMP_REV_NUMPP__(TYPE, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	return **L##_typed > **R##_typed ? -1 : **L##_typed < **R##_typed

#define LIBSIMPLE_CMP_NUL_REV_NUMPP__(TYPE, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	if (!*L##_typed)\
		return !*R##_typed ? 0 : -1;\
	if (!*R##_typed)\
		return +1;\
	return **L##_typed > **R##_typed ? -1 : **L##_typed < **R##_typed

#define LIBSIMPLE_CMP_REV_NUMPP_NUL__(TYPE, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	if (!*L##_typed)\
		return !*R##_typed ? 0 : +1;\
	if (!*R##_typed)\
		return -1;\
	return **L##_typed > **R##_typed ? -1 : **L##_typed < **R##_typed


#define LIBSIMPLE_CMP_FUNP__(TYPE, FUNC, L, R)\
	TYPE const *L##_typed = L;\
	TYPE const *R##_typed = R;\
	return FUNC(*L##_typed, *R##_typed)

#define LIBSIMPLE_CMP_FUNPP__(TYPE, FUNC, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	return FUNC(**L##_typed, **R##_typed)

#define LIBSIMPLE_CMP_NUL_FUNPP__(TYPE, FUNC, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	if (!*L##_typed)\
		return !*R##_typed ? 0 : -1;\
	if (!*R##_typed)\
		return +1;\
	return FUNC(**L##_typed, **R##_typed)

#define LIBSIMPLE_CMP_FUNPP_NUL__(TYPE, FUNC, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	if (!*L##_typed)\
		return !*R##_typed ? 0 : +1;\
	if (!*R##_typed)\
		return -1;\
	return FUNC(**L##_typed, **R##_typed)

#define LIBSIMPLE_CMP_REV_FUNP__(TYPE, FUNC, L, R)\
	TYPE const *L##_typed = L;\
	TYPE const *R##_typed = R;\
	return -FUNC(*L##_typed, *R##_typed)

#define LIBSIMPLE_CMP_REV_FUNPP__(TYPE, FUNC, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	return -FUNC(**L##_typed, **R##_typed)

#define LIBSIMPLE_CMP_NUL_REV_FUNPP__(TYPE, FUNC, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	if (!*L##_typed)\
		return !*R##_typed ? 0 : -1;\
	if (!*R##_typed)\
		return +1;\
	return -FUNC(**L##_typed, **R##_typed)

#define LIBSIMPLE_CMP_REV_FUNPP_NUL__(TYPE, FUNC, L, R)\
	TYPE *const *L##_typed = L;\
	TYPE *const *R##_typed = R;\
	if (!*L##_typed)\
		return !*R##_typed ? 0 : +1;\
	if (!*R##_typed)\
		return -1;\
	return -FUNC(**L##_typed, **R##_typed)


/* @since  1.6 */
inline int libsimple_cmp_ucharp(const unsigned char *a, const unsigned char *b)
{ LIBSIMPLE_CMP_NUMP__(unsigned char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uchar(unsigned char base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ucharp); }

/* @since  1.6 */
inline int libsimple_cmp_ucharpp(unsigned char *const *a, unsigned char *const *b)
{ LIBSIMPLE_CMP_NUMPP__(unsigned char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ucharp(unsigned char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ucharpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_ucharpp(unsigned char *const *a, unsigned char *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(unsigned char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_ucharp(unsigned char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_ucharpp); }

/* @since  1.6 */
inline int libsimple_cmp_ucharpp_nul(unsigned char *const *a, unsigned char *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(unsigned char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ucharp_nul(unsigned char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ucharpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ucharp(const unsigned char *a, const unsigned char *b)
{ LIBSIMPLE_CMP_REV_NUMP__(unsigned char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uchar(unsigned char base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ucharp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ucharpp(unsigned char *const *a, unsigned char *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(unsigned char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ucharp(unsigned char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ucharpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_ucharpp(unsigned char *const *a, unsigned char *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(unsigned char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_ucharp(unsigned char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_ucharpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ucharpp_nul(unsigned char *const *a, unsigned char *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(unsigned char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ucharp_nul(unsigned char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ucharpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_scharp(const signed char *a, const signed char *b)
{ LIBSIMPLE_CMP_NUMP__(signed char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_schar(signed char base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_scharp); }

/* @since  1.6 */
inline int libsimple_cmp_scharpp(signed char *const *a, signed char *const *b)
{ LIBSIMPLE_CMP_NUMPP__(signed char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_scharp(signed char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_scharpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_scharpp(signed char *const *a, signed char *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(signed char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_scharp(signed char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_scharpp); }

/* @since  1.6 */
inline int libsimple_cmp_scharpp_nul(signed char *const *a, signed char *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(signed char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_scharp_nul(signed char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_scharpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_scharp(const signed char *a, const signed char *b)
{ LIBSIMPLE_CMP_REV_NUMP__(signed char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_schar(signed char base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_scharp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_scharpp(signed char *const *a, signed char *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(signed char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_scharp(signed char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_scharpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_scharpp(signed char *const *a, signed char *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(signed char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_scharp(signed char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_scharpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_scharpp_nul(signed char *const *a, signed char *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(signed char, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_scharp_nul(signed char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_scharpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_shortp(const short int *a, const short int *b)
{ LIBSIMPLE_CMP_NUMP__(short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_short(short int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_shortp); }

/* @since  1.6 */
inline int libsimple_cmp_shortpp(short int *const *a, short int *const *b)
{ LIBSIMPLE_CMP_NUMPP__(short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_shortp(short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_shortpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_shortpp(short int *const *a, short int *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_shortp(short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_shortpp); }

/* @since  1.6 */
inline int libsimple_cmp_shortpp_nul(short int *const *a, short int *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_shortp_nul(short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_shortpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_shortp(const short int *a, const short int *b)
{ LIBSIMPLE_CMP_REV_NUMP__(short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_short(short int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_shortp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_shortpp(short int *const *a, short int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_shortp(short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_shortpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_shortpp(short int *const *a, short int *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_shortp(short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_shortpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_shortpp_nul(short int *const *a, short int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_shortp_nul(short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_shortpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_ushortp(const unsigned short int *a, const unsigned short int *b)
{ LIBSIMPLE_CMP_NUMP__(unsigned short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ushort(unsigned short int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ushortp); }

/* @since  1.6 */
inline int libsimple_cmp_ushortpp(unsigned short int *const *a, unsigned short int *const *b)
{ LIBSIMPLE_CMP_NUMPP__(unsigned short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ushortp(unsigned short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ushortpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_ushortpp(unsigned short int *const *a, unsigned short int *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(unsigned short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_ushortp(unsigned short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_ushortpp); }

/* @since  1.6 */
inline int libsimple_cmp_ushortpp_nul(unsigned short int *const *a, unsigned short int *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(unsigned short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ushortp_nul(unsigned short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ushortpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ushortp(const unsigned short int *a, const unsigned short int *b)
{ LIBSIMPLE_CMP_REV_NUMP__(unsigned short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ushort(unsigned short int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ushortp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ushortpp(unsigned short int *const *a, unsigned short int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(unsigned short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ushortp(unsigned short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ushortpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_ushortpp(unsigned short int *const *a, unsigned short int *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(unsigned short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_ushortp(unsigned short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_ushortpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ushortpp_nul(unsigned short int *const *a, unsigned short int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(unsigned short int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ushortp_nul(unsigned short int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ushortpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_intp(const int *a, const int *b)
{ LIBSIMPLE_CMP_NUMP__(int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int(int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_intp); }

/* @since  1.6 */
inline int libsimple_cmp_intpp(int *const *a, int *const *b)
{ LIBSIMPLE_CMP_NUMPP__(int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_intp(int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_intpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_intpp(int *const *a, int *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_intp(int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_intpp); }

/* @since  1.6 */
inline int libsimple_cmp_intpp_nul(int *const *a, int *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_intp_nul(int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_intpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_intp(const int *a, const int *b)
{ LIBSIMPLE_CMP_REV_NUMP__(int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int(int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_intp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_intpp(int *const *a, int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_intp(int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_intpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_intpp(int *const *a, int *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_intp(int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_intpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_intpp_nul(int *const *a, int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_intp_nul(int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_intpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uintp(const unsigned int *a, const unsigned int *b)
{ LIBSIMPLE_CMP_NUMP__(unsigned int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint(unsigned int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uintp); }

/* @since  1.6 */
inline int libsimple_cmp_uintpp(unsigned int *const *a, unsigned int *const *b)
{ LIBSIMPLE_CMP_NUMPP__(unsigned int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uintp(unsigned int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uintpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uintpp(unsigned int *const *a, unsigned int *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(unsigned int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uintp(unsigned int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uintpp); }

/* @since  1.6 */
inline int libsimple_cmp_uintpp_nul(unsigned int *const *a, unsigned int *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(unsigned int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uintp_nul(unsigned int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uintpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uintp(const unsigned int *a, const unsigned int *b)
{ LIBSIMPLE_CMP_REV_NUMP__(unsigned int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint(unsigned int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uintp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uintpp(unsigned int *const *a, unsigned int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(unsigned int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uintp(unsigned int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uintpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uintpp(unsigned int *const *a, unsigned int *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(unsigned int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uintp(unsigned int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uintpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uintpp_nul(unsigned int *const *a, unsigned int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(unsigned int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uintp_nul(unsigned int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uintpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_longp(const long int *a, const long int *b)
{ LIBSIMPLE_CMP_NUMP__(long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_long(long int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_longp); }

/* @since  1.6 */
inline int libsimple_cmp_longpp(long int *const *a, long int *const *b)
{ LIBSIMPLE_CMP_NUMPP__(long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_longp(long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_longpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_longpp(long int *const *a, long int *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_longp(long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_longpp); }

/* @since  1.6 */
inline int libsimple_cmp_longpp_nul(long int *const *a, long int *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_longp_nul(long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_longpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_longp(const long int *a, const long int *b)
{ LIBSIMPLE_CMP_REV_NUMP__(long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_long(long int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_longp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_longpp(long int *const *a, long int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_longp(long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_longpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_longpp(long int *const *a, long int *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_longp(long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_longpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_longpp_nul(long int *const *a, long int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_longp_nul(long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_longpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_ulongp(const unsigned long int *a, const unsigned long int *b)
{ LIBSIMPLE_CMP_NUMP__(unsigned long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ulong(unsigned long int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ulongp); }

/* @since  1.6 */
inline int libsimple_cmp_ulongpp(unsigned long int *const *a, unsigned long int *const *b)
{ LIBSIMPLE_CMP_NUMPP__(unsigned long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ulongp(unsigned long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ulongpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_ulongpp(unsigned long int *const *a, unsigned long int *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(unsigned long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_ulongp(unsigned long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_ulongpp); }

/* @since  1.6 */
inline int libsimple_cmp_ulongpp_nul(unsigned long int *const *a, unsigned long int *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(unsigned long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ulongp_nul(unsigned long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ulongpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ulongp(const unsigned long int *a, const unsigned long int *b)
{ LIBSIMPLE_CMP_REV_NUMP__(unsigned long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ulong(unsigned long int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ulongp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ulongpp(unsigned long int *const *a, unsigned long int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(unsigned long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ulongp(unsigned long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ulongpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_ulongpp(unsigned long int *const *a, unsigned long int *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(unsigned long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_ulongp(unsigned long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_ulongpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ulongpp_nul(unsigned long int *const *a, unsigned long int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(unsigned long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ulongp_nul(unsigned long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ulongpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_llongp(const long long int *a, const long long int *b)
{ LIBSIMPLE_CMP_NUMP__(long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_llong(long long int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_llongp); }

/* @since  1.6 */
inline int libsimple_cmp_llongpp(long long int *const *a, long long int *const *b)
{ LIBSIMPLE_CMP_NUMPP__(long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_llongp(long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_llongpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_llongpp(long long int *const *a, long long int *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_llongp(long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_llongpp); }

/* @since  1.6 */
inline int libsimple_cmp_llongpp_nul(long long int *const *a, long long int *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_llongp_nul(long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_llongpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_llongp(const long long int *a, const long long int *b)
{ LIBSIMPLE_CMP_REV_NUMP__(long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_llong(long long int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_llongp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_llongpp(long long int *const *a, long long int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_llongp(long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_llongpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_llongpp(long long int *const *a, long long int *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_llongp(long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_llongpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_llongpp_nul(long long int *const *a, long long int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_llongp_nul(long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_llongpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_ullongp(const unsigned long long int *a, const unsigned long long int *b)
{ LIBSIMPLE_CMP_NUMP__(unsigned long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ullong(unsigned long long int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ullongp); }

/* @since  1.6 */
inline int libsimple_cmp_ullongpp(unsigned long long int *const *a, unsigned long long int *const *b)
{ LIBSIMPLE_CMP_NUMPP__(unsigned long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ullongp(unsigned long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ullongpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_ullongpp(unsigned long long int *const *a, unsigned long long int *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(unsigned long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_ullongp(unsigned long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_ullongpp); }

/* @since  1.6 */
inline int libsimple_cmp_ullongpp_nul(unsigned long long int *const *a, unsigned long long int *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(unsigned long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ullongp_nul(unsigned long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ullongpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ullongp(const unsigned long long int *a, const unsigned long long int *b)
{ LIBSIMPLE_CMP_REV_NUMP__(unsigned long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ullong(unsigned long long int base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ullongp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ullongpp(unsigned long long int *const *a, unsigned long long int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(unsigned long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ullongp(unsigned long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ullongpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_ullongpp(unsigned long long int *const *a, unsigned long long int *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(unsigned long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_ullongp(unsigned long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_ullongpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ullongpp_nul(unsigned long long int *const *a, unsigned long long int *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(unsigned long long int, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ullongp_nul(unsigned long long int *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ullongpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_int8p(const int8_t *a, const int8_t *b)
{ LIBSIMPLE_CMP_NUMP__(int8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int8(int8_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int8p); }

/* @since  1.6 */
inline int libsimple_cmp_int8pp(int8_t *const *a, int8_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(int8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int8p(int8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int8pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_int8pp(int8_t *const *a, int8_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(int8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_int8p(int8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_int8pp); }

/* @since  1.6 */
inline int libsimple_cmp_int8pp_nul(int8_t *const *a, int8_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(int8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int8p_nul(int8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int8pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int8p(const int8_t *a, const int8_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(int8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int8(int8_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int8p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int8pp(int8_t *const *a, int8_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(int8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int8p(int8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int8pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_int8pp(int8_t *const *a, int8_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(int8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_int8p(int8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_int8pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int8pp_nul(int8_t *const *a, int8_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(int8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int8p_nul(int8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int8pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uint8p(const uint8_t *a, const uint8_t *b)
{ LIBSIMPLE_CMP_NUMP__(uint8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint8(uint8_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint8p); }

/* @since  1.6 */
inline int libsimple_cmp_uint8pp(uint8_t *const *a, uint8_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uint8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint8p(uint8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint8pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uint8pp(uint8_t *const *a, uint8_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uint8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uint8p(uint8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uint8pp); }

/* @since  1.6 */
inline int libsimple_cmp_uint8pp_nul(uint8_t *const *a, uint8_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uint8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint8p_nul(uint8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint8pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint8p(const uint8_t *a, const uint8_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uint8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint8(uint8_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint8p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint8pp(uint8_t *const *a, uint8_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uint8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint8p(uint8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint8pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uint8pp(uint8_t *const *a, uint8_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uint8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uint8p(uint8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uint8pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint8pp_nul(uint8_t *const *a, uint8_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uint8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint8p_nul(uint8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint8pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_int16p(const int16_t *a, const int16_t *b)
{ LIBSIMPLE_CMP_NUMP__(int16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int16(int16_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int16p); }

/* @since  1.6 */
inline int libsimple_cmp_int16pp(int16_t *const *a, int16_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(int16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int16p(int16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int16pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_int16pp(int16_t *const *a, int16_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(int16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_int16p(int16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_int16pp); }

/* @since  1.6 */
inline int libsimple_cmp_int16pp_nul(int16_t *const *a, int16_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(int16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int16p_nul(int16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int16pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int16p(const int16_t *a, const int16_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(int16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int16(int16_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int16p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int16pp(int16_t *const *a, int16_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(int16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int16p(int16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int16pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_int16pp(int16_t *const *a, int16_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(int16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_int16p(int16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_int16pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int16pp_nul(int16_t *const *a, int16_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(int16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int16p_nul(int16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int16pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uint16p(const uint16_t *a, const uint16_t *b)
{ LIBSIMPLE_CMP_NUMP__(uint16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint16(uint16_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint16p); }

/* @since  1.6 */
inline int libsimple_cmp_uint16pp(uint16_t *const *a, uint16_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uint16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint16p(uint16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint16pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uint16pp(uint16_t *const *a, uint16_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uint16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uint16p(uint16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uint16pp); }

/* @since  1.6 */
inline int libsimple_cmp_uint16pp_nul(uint16_t *const *a, uint16_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uint16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint16p_nul(uint16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint16pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint16p(const uint16_t *a, const uint16_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uint16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint16(uint16_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint16p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint16pp(uint16_t *const *a, uint16_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uint16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint16p(uint16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint16pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uint16pp(uint16_t *const *a, uint16_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uint16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uint16p(uint16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uint16pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint16pp_nul(uint16_t *const *a, uint16_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uint16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint16p_nul(uint16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint16pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_int32p(const int32_t *a, const int32_t *b)
{ LIBSIMPLE_CMP_NUMP__(int32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int32(int32_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int32p); }

/* @since  1.6 */
inline int libsimple_cmp_int32pp(int32_t *const *a, int32_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(int32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int32p(int32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int32pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_int32pp(int32_t *const *a, int32_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(int32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_int32p(int32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_int32pp); }

/* @since  1.6 */
inline int libsimple_cmp_int32pp_nul(int32_t *const *a, int32_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(int32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int32p_nul(int32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int32pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int32p(const int32_t *a, const int32_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(int32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int32(int32_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int32p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int32pp(int32_t *const *a, int32_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(int32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int32p(int32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int32pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_int32pp(int32_t *const *a, int32_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(int32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_int32p(int32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_int32pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int32pp_nul(int32_t *const *a, int32_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(int32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int32p_nul(int32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int32pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uint32p(const uint32_t *a, const uint32_t *b)
{ LIBSIMPLE_CMP_NUMP__(uint32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint32(uint32_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint32p); }

/* @since  1.6 */
inline int libsimple_cmp_uint32pp(uint32_t *const *a, uint32_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uint32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint32p(uint32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint32pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uint32pp(uint32_t *const *a, uint32_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uint32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uint32p(uint32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uint32pp); }

/* @since  1.6 */
inline int libsimple_cmp_uint32pp_nul(uint32_t *const *a, uint32_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uint32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint32p_nul(uint32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint32pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint32p(const uint32_t *a, const uint32_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uint32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint32(uint32_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint32p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint32pp(uint32_t *const *a, uint32_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uint32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint32p(uint32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint32pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uint32pp(uint32_t *const *a, uint32_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uint32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uint32p(uint32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uint32pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint32pp_nul(uint32_t *const *a, uint32_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uint32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint32p_nul(uint32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint32pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_int64p(const int64_t *a, const int64_t *b)
{ LIBSIMPLE_CMP_NUMP__(int64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int64(int64_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int64p); }

/* @since  1.6 */
inline int libsimple_cmp_int64pp(int64_t *const *a, int64_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(int64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int64p(int64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int64pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_int64pp(int64_t *const *a, int64_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(int64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_int64p(int64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_int64pp); }

/* @since  1.6 */
inline int libsimple_cmp_int64pp_nul(int64_t *const *a, int64_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(int64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int64p_nul(int64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int64pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int64p(const int64_t *a, const int64_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(int64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int64(int64_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int64p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int64pp(int64_t *const *a, int64_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(int64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int64p(int64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int64pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_int64pp(int64_t *const *a, int64_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(int64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_int64p(int64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_int64pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int64pp_nul(int64_t *const *a, int64_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(int64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int64p_nul(int64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int64pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uint64p(const uint64_t *a, const uint64_t *b)
{ LIBSIMPLE_CMP_NUMP__(uint64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint64(uint64_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint64p); }

/* @since  1.6 */
inline int libsimple_cmp_uint64pp(uint64_t *const *a, uint64_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uint64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint64p(uint64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint64pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uint64pp(uint64_t *const *a, uint64_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uint64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uint64p(uint64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uint64pp); }

/* @since  1.6 */
inline int libsimple_cmp_uint64pp_nul(uint64_t *const *a, uint64_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uint64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint64p_nul(uint64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint64pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint64p(const uint64_t *a, const uint64_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uint64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint64(uint64_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint64p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint64pp(uint64_t *const *a, uint64_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uint64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint64p(uint64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint64pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uint64pp(uint64_t *const *a, uint64_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uint64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uint64p(uint64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uint64pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint64pp_nul(uint64_t *const *a, uint64_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uint64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint64p_nul(uint64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint64pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_int_least8p(const int_least8_t *a, const int_least8_t *b)
{ LIBSIMPLE_CMP_NUMP__(int_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least8(int_least8_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least8p); }

/* @since  1.6 */
inline int libsimple_cmp_int_least8pp(int_least8_t *const *a, int_least8_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(int_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least8p(int_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least8pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_int_least8pp(int_least8_t *const *a, int_least8_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(int_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_int_least8p(int_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_int_least8pp); }

/* @since  1.6 */
inline int libsimple_cmp_int_least8pp_nul(int_least8_t *const *a, int_least8_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(int_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least8p_nul(int_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least8pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least8p(const int_least8_t *a, const int_least8_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(int_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least8(int_least8_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least8p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least8pp(int_least8_t *const *a, int_least8_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(int_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least8p(int_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least8pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_int_least8pp(int_least8_t *const *a, int_least8_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(int_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_int_least8p(int_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_int_least8pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least8pp_nul(int_least8_t *const *a, int_least8_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(int_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least8p_nul(int_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least8pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least8p(const uint_least8_t *a, const uint_least8_t *b)
{ LIBSIMPLE_CMP_NUMP__(uint_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least8(uint_least8_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least8p); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least8pp(uint_least8_t *const *a, uint_least8_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uint_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least8p(uint_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least8pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uint_least8pp(uint_least8_t *const *a, uint_least8_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uint_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uint_least8p(uint_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uint_least8pp); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least8pp_nul(uint_least8_t *const *a, uint_least8_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uint_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least8p_nul(uint_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least8pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least8p(const uint_least8_t *a, const uint_least8_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uint_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least8(uint_least8_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least8p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least8pp(uint_least8_t *const *a, uint_least8_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uint_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least8p(uint_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least8pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uint_least8pp(uint_least8_t *const *a, uint_least8_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uint_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uint_least8p(uint_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uint_least8pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least8pp_nul(uint_least8_t *const *a, uint_least8_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uint_least8_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least8p_nul(uint_least8_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least8pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_int_least16p(const int_least16_t *a, const int_least16_t *b)
{ LIBSIMPLE_CMP_NUMP__(int_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least16(int_least16_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least16p); }

/* @since  1.6 */
inline int libsimple_cmp_int_least16pp(int_least16_t *const *a, int_least16_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(int_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least16p(int_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least16pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_int_least16pp(int_least16_t *const *a, int_least16_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(int_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_int_least16p(int_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_int_least16pp); }

/* @since  1.6 */
inline int libsimple_cmp_int_least16pp_nul(int_least16_t *const *a, int_least16_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(int_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least16p_nul(int_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least16pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least16p(const int_least16_t *a, const int_least16_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(int_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least16(int_least16_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least16p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least16pp(int_least16_t *const *a, int_least16_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(int_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least16p(int_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least16pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_int_least16pp(int_least16_t *const *a, int_least16_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(int_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_int_least16p(int_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_int_least16pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least16pp_nul(int_least16_t *const *a, int_least16_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(int_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least16p_nul(int_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least16pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least16p(const uint_least16_t *a, const uint_least16_t *b)
{ LIBSIMPLE_CMP_NUMP__(uint_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least16(uint_least16_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least16p); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least16pp(uint_least16_t *const *a, uint_least16_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uint_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least16p(uint_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least16pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uint_least16pp(uint_least16_t *const *a, uint_least16_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uint_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uint_least16p(uint_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uint_least16pp); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least16pp_nul(uint_least16_t *const *a, uint_least16_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uint_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least16p_nul(uint_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least16pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least16p(const uint_least16_t *a, const uint_least16_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uint_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least16(uint_least16_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least16p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least16pp(uint_least16_t *const *a, uint_least16_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uint_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least16p(uint_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least16pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uint_least16pp(uint_least16_t *const *a, uint_least16_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uint_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uint_least16p(uint_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uint_least16pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least16pp_nul(uint_least16_t *const *a, uint_least16_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uint_least16_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least16p_nul(uint_least16_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least16pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_int_least32p(const int_least32_t *a, const int_least32_t *b)
{ LIBSIMPLE_CMP_NUMP__(int_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least32(int_least32_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least32p); }

/* @since  1.6 */
inline int libsimple_cmp_int_least32pp(int_least32_t *const *a, int_least32_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(int_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least32p(int_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least32pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_int_least32pp(int_least32_t *const *a, int_least32_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(int_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_int_least32p(int_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_int_least32pp); }

/* @since  1.6 */
inline int libsimple_cmp_int_least32pp_nul(int_least32_t *const *a, int_least32_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(int_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least32p_nul(int_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least32pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least32p(const int_least32_t *a, const int_least32_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(int_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least32(int_least32_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least32p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least32pp(int_least32_t *const *a, int_least32_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(int_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least32p(int_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least32pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_int_least32pp(int_least32_t *const *a, int_least32_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(int_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_int_least32p(int_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_int_least32pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least32pp_nul(int_least32_t *const *a, int_least32_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(int_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least32p_nul(int_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least32pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least32p(const uint_least32_t *a, const uint_least32_t *b)
{ LIBSIMPLE_CMP_NUMP__(uint_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least32(uint_least32_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least32p); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least32pp(uint_least32_t *const *a, uint_least32_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uint_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least32p(uint_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least32pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uint_least32pp(uint_least32_t *const *a, uint_least32_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uint_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uint_least32p(uint_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uint_least32pp); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least32pp_nul(uint_least32_t *const *a, uint_least32_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uint_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least32p_nul(uint_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least32pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least32p(const uint_least32_t *a, const uint_least32_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uint_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least32(uint_least32_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least32p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least32pp(uint_least32_t *const *a, uint_least32_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uint_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least32p(uint_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least32pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uint_least32pp(uint_least32_t *const *a, uint_least32_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uint_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uint_least32p(uint_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uint_least32pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least32pp_nul(uint_least32_t *const *a, uint_least32_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uint_least32_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least32p_nul(uint_least32_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least32pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_int_least64p(const int_least64_t *a, const int_least64_t *b)
{ LIBSIMPLE_CMP_NUMP__(int_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least64(int_least64_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least64p); }

/* @since  1.6 */
inline int libsimple_cmp_int_least64pp(int_least64_t *const *a, int_least64_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(int_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least64p(int_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least64pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_int_least64pp(int_least64_t *const *a, int_least64_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(int_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_int_least64p(int_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_int_least64pp); }

/* @since  1.6 */
inline int libsimple_cmp_int_least64pp_nul(int_least64_t *const *a, int_least64_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(int_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_int_least64p_nul(int_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_int_least64pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least64p(const int_least64_t *a, const int_least64_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(int_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least64(int_least64_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least64p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least64pp(int_least64_t *const *a, int_least64_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(int_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least64p(int_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least64pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_int_least64pp(int_least64_t *const *a, int_least64_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(int_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_int_least64p(int_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_int_least64pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_int_least64pp_nul(int_least64_t *const *a, int_least64_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(int_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_int_least64p_nul(int_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_int_least64pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least64p(const uint_least64_t *a, const uint_least64_t *b)
{ LIBSIMPLE_CMP_NUMP__(uint_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least64(uint_least64_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least64p); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least64pp(uint_least64_t *const *a, uint_least64_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uint_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least64p(uint_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least64pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uint_least64pp(uint_least64_t *const *a, uint_least64_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uint_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uint_least64p(uint_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uint_least64pp); }

/* @since  1.6 */
inline int libsimple_cmp_uint_least64pp_nul(uint_least64_t *const *a, uint_least64_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uint_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uint_least64p_nul(uint_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uint_least64pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least64p(const uint_least64_t *a, const uint_least64_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uint_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least64(uint_least64_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least64p); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least64pp(uint_least64_t *const *a, uint_least64_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uint_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least64p(uint_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least64pp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uint_least64pp(uint_least64_t *const *a, uint_least64_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uint_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uint_least64p(uint_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uint_least64pp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uint_least64pp_nul(uint_least64_t *const *a, uint_least64_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uint_least64_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uint_least64p_nul(uint_least64_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uint_least64pp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_intmaxp(const intmax_t *a, const intmax_t *b)
{ LIBSIMPLE_CMP_NUMP__(intmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_intmax(intmax_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_intmaxp); }

/* @since  1.6 */
inline int libsimple_cmp_intmaxpp(intmax_t *const *a, intmax_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(intmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_intmaxp(intmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_intmaxpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_intmaxpp(intmax_t *const *a, intmax_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(intmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_intmaxp(intmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_intmaxpp); }

/* @since  1.6 */
inline int libsimple_cmp_intmaxpp_nul(intmax_t *const *a, intmax_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(intmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_intmaxp_nul(intmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_intmaxpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_intmaxp(const intmax_t *a, const intmax_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(intmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_intmax(intmax_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_intmaxp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_intmaxpp(intmax_t *const *a, intmax_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(intmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_intmaxp(intmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_intmaxpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_intmaxpp(intmax_t *const *a, intmax_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(intmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_intmaxp(intmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_intmaxpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_intmaxpp_nul(intmax_t *const *a, intmax_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(intmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_intmaxp_nul(intmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_intmaxpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uintmaxp(const uintmax_t *a, const uintmax_t *b)
{ LIBSIMPLE_CMP_NUMP__(uintmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uintmax(uintmax_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uintmaxp); }

/* @since  1.6 */
inline int libsimple_cmp_uintmaxpp(uintmax_t *const *a, uintmax_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uintmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uintmaxp(uintmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uintmaxpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uintmaxpp(uintmax_t *const *a, uintmax_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uintmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uintmaxp(uintmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uintmaxpp); }

/* @since  1.6 */
inline int libsimple_cmp_uintmaxpp_nul(uintmax_t *const *a, uintmax_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uintmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uintmaxp_nul(uintmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uintmaxpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uintmaxp(const uintmax_t *a, const uintmax_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uintmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uintmax(uintmax_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uintmaxp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uintmaxpp(uintmax_t *const *a, uintmax_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uintmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uintmaxp(uintmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uintmaxpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uintmaxpp(uintmax_t *const *a, uintmax_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uintmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uintmaxp(uintmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uintmaxpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uintmaxpp_nul(uintmax_t *const *a, uintmax_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uintmax_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uintmaxp_nul(uintmax_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uintmaxpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_sizep(const size_t *a, const size_t *b)
{ LIBSIMPLE_CMP_NUMP__(size_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_size(size_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_sizep); }

/* @since  1.6 */
inline int libsimple_cmp_sizepp(size_t *const *a, size_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(size_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_sizep(size_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_sizepp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_sizepp(size_t *const *a, size_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(size_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_sizep(size_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_sizepp); }

/* @since  1.6 */
inline int libsimple_cmp_sizepp_nul(size_t *const *a, size_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(size_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_sizep_nul(size_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_sizepp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_sizep(const size_t *a, const size_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(size_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_size(size_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_sizep); }

/* @since  1.6 */
inline int libsimple_cmp_rev_sizepp(size_t *const *a, size_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(size_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_sizep(size_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_sizepp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_sizepp(size_t *const *a, size_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(size_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_sizep(size_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_sizepp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_sizepp_nul(size_t *const *a, size_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(size_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_sizep_nul(size_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_sizepp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_ssizep(const ssize_t *a, const ssize_t *b)
{ LIBSIMPLE_CMP_NUMP__(ssize_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ssize(ssize_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ssizep); }

/* @since  1.6 */
inline int libsimple_cmp_ssizepp(ssize_t *const *a, ssize_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(ssize_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ssizep(ssize_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ssizepp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_ssizepp(ssize_t *const *a, ssize_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(ssize_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_ssizep(ssize_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_ssizepp); }

/* @since  1.6 */
inline int libsimple_cmp_ssizepp_nul(ssize_t *const *a, ssize_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(ssize_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ssizep_nul(ssize_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ssizepp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ssizep(const ssize_t *a, const ssize_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(ssize_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ssize(ssize_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ssizep); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ssizepp(ssize_t *const *a, ssize_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(ssize_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ssizep(ssize_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ssizepp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_ssizepp(ssize_t *const *a, ssize_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(ssize_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_ssizep(ssize_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_ssizepp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ssizepp_nul(ssize_t *const *a, ssize_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(ssize_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ssizep_nul(ssize_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ssizepp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_intptrp(const intptr_t *a, const intptr_t *b)
{ LIBSIMPLE_CMP_NUMP__(intptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_intptr(intptr_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_intptrp); }

/* @since  1.6 */
inline int libsimple_cmp_intptrpp(intptr_t *const *a, intptr_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(intptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_intptrp(intptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_intptrpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_intptrpp(intptr_t *const *a, intptr_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(intptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_intptrp(intptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_intptrpp); }

/* @since  1.6 */
inline int libsimple_cmp_intptrpp_nul(intptr_t *const *a, intptr_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(intptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_intptrp_nul(intptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_intptrpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_intptrp(const intptr_t *a, const intptr_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(intptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_intptr(intptr_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_intptrp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_intptrpp(intptr_t *const *a, intptr_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(intptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_intptrp(intptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_intptrpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_intptrpp(intptr_t *const *a, intptr_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(intptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_intptrp(intptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_intptrpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_intptrpp_nul(intptr_t *const *a, intptr_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(intptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_intptrp_nul(intptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_intptrpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_uintptrp(const uintptr_t *a, const uintptr_t *b)
{ LIBSIMPLE_CMP_NUMP__(uintptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uintptr(uintptr_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uintptrp); }

/* @since  1.6 */
inline int libsimple_cmp_uintptrpp(uintptr_t *const *a, uintptr_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(uintptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uintptrp(uintptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uintptrpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_uintptrpp(uintptr_t *const *a, uintptr_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(uintptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_uintptrp(uintptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_uintptrpp); }

/* @since  1.6 */
inline int libsimple_cmp_uintptrpp_nul(uintptr_t *const *a, uintptr_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(uintptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_uintptrp_nul(uintptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_uintptrpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uintptrp(const uintptr_t *a, const uintptr_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(uintptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uintptr(uintptr_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uintptrp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uintptrpp(uintptr_t *const *a, uintptr_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(uintptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uintptrp(uintptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uintptrpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_uintptrpp(uintptr_t *const *a, uintptr_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(uintptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_uintptrp(uintptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_uintptrpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_uintptrpp_nul(uintptr_t *const *a, uintptr_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(uintptr_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_uintptrp_nul(uintptr_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_uintptrpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_ptrdiffp(const ptrdiff_t *a, const ptrdiff_t *b)
{ LIBSIMPLE_CMP_NUMP__(ptrdiff_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ptrdiff(ptrdiff_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ptrdiffp); }

/* @since  1.6 */
inline int libsimple_cmp_ptrdiffpp(ptrdiff_t *const *a, ptrdiff_t *const *b)
{ LIBSIMPLE_CMP_NUMPP__(ptrdiff_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ptrdiffp(ptrdiff_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ptrdiffpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_ptrdiffpp(ptrdiff_t *const *a, ptrdiff_t *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(ptrdiff_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_ptrdiffp(ptrdiff_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_ptrdiffpp); }

/* @since  1.6 */
inline int libsimple_cmp_ptrdiffpp_nul(ptrdiff_t *const *a, ptrdiff_t *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(ptrdiff_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_ptrdiffp_nul(ptrdiff_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_ptrdiffpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ptrdiffp(const ptrdiff_t *a, const ptrdiff_t *b)
{ LIBSIMPLE_CMP_REV_NUMP__(ptrdiff_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ptrdiff(ptrdiff_t base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ptrdiffp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ptrdiffpp(ptrdiff_t *const *a, ptrdiff_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(ptrdiff_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ptrdiffp(ptrdiff_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ptrdiffpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_ptrdiffpp(ptrdiff_t *const *a, ptrdiff_t *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(ptrdiff_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_ptrdiffp(ptrdiff_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_ptrdiffpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_ptrdiffpp_nul(ptrdiff_t *const *a, ptrdiff_t *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(ptrdiff_t, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_ptrdiffp_nul(ptrdiff_t *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_ptrdiffpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_floatp(const float *a, const float *b)
{ LIBSIMPLE_CMP_NUMP__(float, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_float(float base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_floatp); }

/* @since  1.6 */
inline int libsimple_cmp_floatpp(float *const *a, float *const *b)
{ LIBSIMPLE_CMP_NUMPP__(float, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_floatp(float *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_floatpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_floatpp(float *const *a, float *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(float, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_floatp(float *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_floatpp); }

/* @since  1.6 */
inline int libsimple_cmp_floatpp_nul(float *const *a, float *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(float, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_floatp_nul(float *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_floatpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_floatp(const float *a, const float *b)
{ LIBSIMPLE_CMP_REV_NUMP__(float, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_float(float base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_floatp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_floatpp(float *const *a, float *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(float, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_floatp(float *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_floatpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_floatpp(float *const *a, float *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(float, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_floatp(float *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_floatpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_floatpp_nul(float *const *a, float *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(float, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_floatp_nul(float *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_floatpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_doublep(const double *a, const double *b)
{ LIBSIMPLE_CMP_NUMP__(double, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_double(double base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_doublep); }

/* @since  1.6 */
inline int libsimple_cmp_doublepp(double *const *a, double *const *b)
{ LIBSIMPLE_CMP_NUMPP__(double, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_doublep(double *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_doublepp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_doublepp(double *const *a, double *const *b)
{ LIBSIMPLE_CMP_NUL_NUMPP__(double, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_doublep(double *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_doublepp); }

/* @since  1.6 */
inline int libsimple_cmp_doublepp_nul(double *const *a, double *const *b)
{ LIBSIMPLE_CMP_NUMPP_NUL__(double, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_doublep_nul(double *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_doublepp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_doublep(const double *a, const double *b)
{ LIBSIMPLE_CMP_REV_NUMP__(double, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_double(double base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_doublep); }

/* @since  1.6 */
inline int libsimple_cmp_rev_doublepp(double *const *a, double *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP__(double, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_doublep(double *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_doublepp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_doublepp(double *const *a, double *const *b)
{ LIBSIMPLE_CMP_NUL_REV_NUMPP__(double, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_doublep(double *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_doublepp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_doublepp_nul(double *const *a, double *const *b)
{ LIBSIMPLE_CMP_REV_NUMPP_NUL__(double, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_doublep_nul(double *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_doublepp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_strp(const char *const *a, const char *const *b)
{ LIBSIMPLE_CMP_FUNP__(const char *, strcmp, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_str(const char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_strp); }

/* @since  1.6 */
inline int libsimple_cmp_strpp(const char **const *a, const char **const *b)
{ LIBSIMPLE_CMP_FUNPP__(const char *, strcmp, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_strp(const char **base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_strpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_strpp(const char **const *a, const char **const *b)
{ LIBSIMPLE_CMP_NUL_FUNPP__(const char *, strcmp, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_strp(const char **base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_strpp); }

/* @since  1.6 */
inline int libsimple_cmp_strpp_nul(const char **const *a, const char **const *b)
{ LIBSIMPLE_CMP_FUNPP_NUL__(const char *, strcmp, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_strp_nul(const char **base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_strpp_nul); }

/* @since  1.6 */
inline int libsimple_cmp_rev_strp(const char *const *a, const char *const *b)
{ LIBSIMPLE_CMP_REV_FUNP__(const char *, strcmp, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_str(const char *base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_strp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_strpp(const char **const *a, const char **const *b)
{ LIBSIMPLE_CMP_REV_FUNPP__(const char *, strcmp, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_strp(const char **base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_strpp); }

/* @since  1.6 */
inline int libsimple_cmp_nul_rev_strpp(const char **const *a, const char **const *b)
{ LIBSIMPLE_CMP_NUL_REV_FUNPP__(const char *, strcmp, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_nul_rev_strp(const char **base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_nul_rev_strpp); }

/* @since  1.6 */
inline int libsimple_cmp_rev_strpp_nul(const char **const *a, const char **const *b)
{ LIBSIMPLE_CMP_REV_FUNPP_NUL__(const char *, strcmp, a, b); }

/* @since  1.6 */
inline void libsimple_qsort_rev_strp_nul(const char **base[], size_t n)
{ qsort(base, n, sizeof(*base), (int (*)(const void *, const void *))&libsimple_cmp_rev_strpp_nul); }


#undef LIBSIMPLE_CMP_NUMP__
#undef LIBSIMPLE_CMP_NUMPP__
#undef LIBSIMPLE_CMP_NUL_NUMPP__
#undef LIBSIMPLE_CMP_NUMPP_NUL__
#undef LIBSIMPLE_CMP_REV_NUMP__
#undef LIBSIMPLE_CMP_REV_NUMPP__
#undef LIBSIMPLE_CMP_NUL_REV_NUMPP__
#undef LIBSIMPLE_CMP_REV_NUMPP_NUL__

#undef LIBSIMPLE_CMP_FUNP__
#undef LIBSIMPLE_CMP_FUNPP__
#undef LIBSIMPLE_CMP_NUL_FUNPP__
#undef LIBSIMPLE_CMP_FUNPP_NUL__
#undef LIBSIMPLE_CMP_REV_FUNP__
#undef LIBSIMPLE_CMP_REV_FUNPP__
#undef LIBSIMPLE_CMP_NUL_REV_FUNPP__
#undef LIBSIMPLE_CMP_REV_FUNPP_NUL__
