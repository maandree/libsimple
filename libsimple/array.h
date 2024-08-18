/* See LICENSE file for copyright and license details. */

/* TODO test, doc, man */


/* @since  1.1 */
#define libsimple_arraydupa(array, alignment, n) libsimple_aligned_memdupa(array, _Alignof(*(array)), n)
#ifndef aligned_arraydupa
# define aligned_arraydupa(...) libsimple_aligned_arraydupa(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arraydup(array, n) libsimple_aligned_memdup(array, _Alignof(*(array)), n)
#ifndef arraydup
# define arraydup(...) libsimple_arraydup(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_earraydup(array, n) libsimple_ealigned_memdup(array, _Alignof(*(array)), n)
#ifndef earraydup
# define earraydup(...) libsimple_earraydup(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_enarraydup(status, array, n) libsimple_enaligned_memdup(status, array, _Alignof(*(array)), n)
#ifndef enarraydup
# define enarraydup(...) libsimple_enarraydup(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_aligned_arraydupa(array, alignment, n) libsimple_aligned_memdupa(array, alignment, n)
#ifndef aligned_arraydupa
# define aligned_arraydupa(...) libsimple_aligned_arraydupa(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_aligned_arraydup(array, alignment, n) libsimple_aligned_memdup(array, alignment, n)
#ifndef aligned_arraydup
# define aligned_arraydup(...) libsimple_aligned_arraydup(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_ealigned_arraydup(array, alignment, n) libsimple_ealigned_memdup(array, alignment, n)
#ifndef ealigned_arraydup
# define ealigned_arraydup(...) libsimple_ealigned_arraydup(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_enaligned_arraydup(status, array, alignment, n) libsimple_enaligned_memdup(status, array, alignment, n)
#ifndef enaligned_arraydup
# define enaligned_arraydup(...) libsimple_enaligned_arraydup(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayelem(haystack, needle, n) libsimple_memelem(haystack, needle, sizeof *(haystack), n)
#ifndef arrayelem
# define arrayelem(...) libsimple_arrayelem(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_rawarrayelem(haystack, needle, n) libsimple_rawmemelem(haystack, needle, sizeof *(haystack), n)
#ifndef rawarrayelem
# define rawarrayelem(...) libsimple_rawarrayelem(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayscan(haystack, needle, n) libsimple_memelemscan(haystack, needle, sizeof *(haystack), n)
#ifndef arrayscan
# define arrayscan(...) libsimple_arrayscan(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayrelem(haystack, needle, n) libsimple_memrelem(haystack, needle, sizeof *(haystack), n)
#ifndef arrayrelem
# define arrayrelem(...) libsimple_arrayrelem(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_rawarrayrelem(haystack, needle, n) libsimple_rawmemrelem(haystack, needle, sizeof *(haystack), n)
#ifndef rawarrayrelem
# define rawarrayrelem(...) libsimple_rawarrayrelem(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayelem_inv(haystack, needle, n) libsimple_memelem_inv(haystack, needle, sizeof *(haystack), n)
#ifndef arrayelem_inv
# define arrayelem_inv(...) libsimple_arrayelem_inv(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_rawarrayelem_inv(haystack, needle, n) libsimple_rawmemelem_inv(haystack, needle, sizeof *(haystack), n)
#ifndef rawarrayelem_inv
# define rawarrayelem_inv(...) libsimple_rawarrayelem_inv(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayscan_inv(haystack, needle, n) libsimple_memelemscan_inv(haystack, needle, sizeof *(haystack), n)
#ifndef arrayscan_inv
# define arrayscan_inv(...) libsimple_arrayscan_inv(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayrelem_inv(haystack, needle, n) libsimple_memrelem_inv(haystack, needle, sizeof *(haystack), n)
#ifndef arrayrelem_inv
# define arrayrelem_inv(...) libsimple_arrayrelem_inv(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_rawarrayrelem_inv(haystack, needle, n) libsimple_rawmemrelem_inv(haystack, needle, sizeof *(haystack), n)
#ifndef rawarrayrelem_inv
# define rawarrayrelem_inv(...) libsimple_rawarrayrelem_inv(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayset(buf, item, n) libsimple_memsetelem(buf, item, sizeof *(buf), n)
#ifndef arrayset
# define arrayset(...) libsimple_arrayset(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arraypset(buf, item, n) libsimple_mempsetelem(buf, item, sizeof *(buf), n)
#ifndef arraypset
# define arraypset(...) libsimple_arraypset(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arraycpy(d, s, n) memcpy(d, s, (n) * sizeof *(s))
#ifndef arraycpy
# define arraycpy(...) libsimple_arraycpy(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arraymove(d, s, n) memmove(d, s, (n) * sizeof *(s))
#ifndef arraymove
# define arraymove(...) libsimple_arraymove(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayelemcpy(d, s, elem, n) libsimple_memelemcpy(d, s, elem, sizeof *(s), n)
#ifndef arrayelemcpy
# define arrayelemcpy(...) libsimple_arrayelemcpy(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayelemmove(d, s, elem, n) libsimple_memelemmove(d, s, elem, sizeof *(s), n)
#ifndef arrayelemmove
# define arrayelemmove(...) libsimple_arrayelemmove(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_rawarrayelemcpy(d, s, elem) libsimple_rawmemelemcpy(d, s, elem, sizeof *(s))
#ifndef rawarrayelemcpy
# define rawarrayelemcpy(...) libsimple_rawarrayelemcpy(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_rawarrayelemmove(d, s, elem) libsimple_rawmemelemmove(d, s, elem, sizeof *(s))
#ifndef rawarrayelemmove
# define rawarrayelemmove(...) libsimple_rawarrayelemmove(__VA_ARGS__)
#endif


/* @since  1.1 */
#define libsimple_arrayreplace(s, old, new, n) libsimple_memreplaceelem(s, old, new, sizeof *(s), n)
#ifndef arrayreplace
# define arrayreplace(...) libsimple_arrayreplace(__VA_ARGS__)
#endif


/* @since  1.5 */
#define libsimple_arrayfill(buf, item) libsimple_memsetelem(buf, item, sizeof *(buf), sizeof (buf) / sizeof *(buf))
#ifndef arrayfill
# define arrayfill(...) libsimple_arrayfill(__VA_ARGS__)
#endif


/* @since  1.5 */
#define libsimple_arraynull(buf) libsimple_memsetelem(buf, (void *)0, sizeof *(buf), sizeof (buf) / sizeof *(buf))
#ifndef arraynull
# define arraynull(...) libsimple_arraynull(__VA_ARGS__)
#endif
