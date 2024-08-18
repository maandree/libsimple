/* See LICENSE file for copyright and license details. */

/* @since  1.1 */
enum libsimple_memalloc_option {
	/* @since  1.1 { */
	LIBSIMPLE_MEMALLOC_END,
	LIBSIMPLE_MEMALLOC_ZERO_INIT,
	LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT,
	LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO,
	LIBSIMPLE_MEMALLOC_NULL_IF_ZERO,
	LIBSIMPLE_MEMALLOC_ALIGNMENT,
	LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	LIBSIMPLE_MEMALLOC_ALIGNMENT_TO_CACHE_LINE,
	LIBSIMPLE_MEMALLOC_ALLOW_CACHE_LINE_SPLITTING,
	LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	LIBSIMPLE_MEMALLOC_ELEMENT_SIZE,
	LIBSIMPLE_MEMALLOC_PRODUCT_SIZE,
	LIBSIMPLE_MEMALLOC_VA_PRODUCT_SIZE,
	LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE,
	LIBSIMPLE_MEMALLOC_VA_LIST
	/* @since  1.1 } */
};
	/* @since  1.1 */
#define libsimple_arrayalloc_option libsimple_memalloc_option

/* @since  1.1 { */
#define LIBSIMPLE_MEMALLOC_END                        LIBSIMPLE_MEMALLOC_END
#define LIBSIMPLE_MEMALLOC_ZERO_INIT                  LIBSIMPLE_MEMALLOC_ZERO_INIT
#define LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT      LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT
#define LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO             LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO
#define LIBSIMPLE_MEMALLOC_NULL_IF_ZERO               LIBSIMPLE_MEMALLOC_NULL_IF_ZERO
#define LIBSIMPLE_MEMALLOC_ALIGNMENT                  LIBSIMPLE_MEMALLOC_ALIGNMENT
#define LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT             LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT
#define LIBSIMPLE_MEMALLOC_ALIGNMENT_TO_CACHE_LINE    LIBSIMPLE_MEMALLOC_ALIGNMENT_TO_CACHE_LINE
#define LIBSIMPLE_MEMALLOC_ALLOW_CACHE_LINE_SPLITTING LIBSIMPLE_MEMALLOC_ALLOW_CACHE_LINE_SPLITTING
#define LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT
#define LIBSIMPLE_MEMALLOC_ELEMENT_SIZE               LIBSIMPLE_MEMALLOC_ELEMENT_SIZE
#define LIBSIMPLE_MEMALLOC_PRODUCT_SIZE               LIBSIMPLE_MEMALLOC_PRODUCT_SIZE
#define LIBSIMPLE_MEMALLOC_VA_PRODUCT_SIZE            LIBSIMPLE_MEMALLOC_VA_PRODUCT_SIZE
#define LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE          LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE
#define LIBSIMPLE_MEMALLOC_VA_LIST                    LIBSIMPLE_MEMALLOC_VA_LIST
/* @since  1.1 } */

/* @since  1.1 { */
#define LIBSIMPLE_ARRAYALLOC_END                        LIBSIMPLE_MEMALLOC_END
#define LIBSIMPLE_ARRAYALLOC_ZERO_INIT                  LIBSIMPLE_MEMALLOC_ZERO_INIT
#define LIBSIMPLE_ARRAYALLOC_CONDITIONAL_ZERO_INIT      LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT
#define LIBSIMPLE_ARRAYALLOC_UNIQUE_IF_ZERO             LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO
#define LIBSIMPLE_ARRAYALLOC_NULL_IF_ZERO               LIBSIMPLE_MEMALLOC_NULL_IF_ZERO
#define LIBSIMPLE_ARRAYALLOC_ALIGNMENT_TO_CACHE_LINE    LIBSIMPLE_MEMALLOC_ALIGNMENT_TO_CACHE_LINE
#define LIBSIMPLE_ARRAYALLOC_ALLOW_CACHE_LINE_SPLITTING LIBSIMPLE_MEMALLOC_ALLOW_CACHE_LINE_SPLITTING
#define LIBSIMPLE_ARRAYALLOC_ROUND_UP_SIZE_TO_ALIGNMENT LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT
#define LIBSIMPLE_ARRAYALLOC_PRODUCT_SIZE               LIBSIMPLE_MEMALLOC_PRODUCT_SIZE
#define LIBSIMPLE_ARRAYALLOC_VA_PRODUCT_SIZE            LIBSIMPLE_MEMALLOC_VA_PRODUCT_SIZE
#define LIBSIMPLE_ARRAYALLOC_1_VA_PRODUCT_SIZE          LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE
#define LIBSIMPLE_ARRAYALLOC_VA_LIST                    LIBSIMPLE_MEMALLOC_VA_LIST
/* @since  1.1 } */

/* @since  1.1 */
#define libsimple_varrayalloc(TYPE, N, AP)\
	libsimple_memalloc(N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                   LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                   LIBSIMPLE_MEMALLOC_VA_LIST, AP, LIBSIMPLE_MEMALLOC_END)

/* @since  1.1 */
#define libsimple_evarrayalloc(TYPE, N, AP)\
	libsimple_ememalloc(N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                    LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                    LIBSIMPLE_MEMALLOC_VA_LIST, AP, LIBSIMPLE_MEMALLOC_END)

/* @since  1.1 */
#define libsimple_envarrayalloc(STATUS, TYPE, N, AP)\
	libsimple_enmemalloc(STATUS, N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                     LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                     LIBSIMPLE_MEMALLOC_VA_LIST, AP, LIBSIMPLE_MEMALLOC_END)

/* @since  1.1 */
#define libsimple_arrayalloc(TYPE, N, ... /*, LIBSIMPLE_ARRAYALLOC_END */)\
	libsimple_memalloc(N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                   LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                   __VA_ARGS__)

/* @since  1.1 */
#define libsimple_earrayalloc(TYPE, N, ... /*, LIBSIMPLE_ARRAYALLOC_END */)\
	libsimple_ememalloc(N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                    LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                    __VA_ARGS__)

/* @since  1.1 */
#define libsimple_enarrayalloc(STATUS, TYPE, N, ... /*, LIBSIMPLE_ARRAYALLOC_END */)\
	libsimple_enmemalloc(STATUS, N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                     LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                     __VA_ARGS__)

/* @since  1.1 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
void *libsimple_vmemalloc(size_t, va_list);

/* @since  1.1 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
void *libsimple_envmemalloc(int, size_t, va_list);

/* @since  1.1 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_evmemalloc(size_t n__, va_list ap__)
{
	return libsimple_envmemalloc(libsimple_default_failure_exit, n__, ap__);
}

/* @since  1.1 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_memalloc(size_t n__, ... /*, LIBSIMPLE_MEMALLOC_END */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_vmemalloc(n__, ap__);
	va_end(ap__);
}

/* @since  1.1 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_enmemalloc(int status__, size_t n__, ... /*, LIBSIMPLE_MEMALLOC_END */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_envmemalloc(status__, n__, ap__);
	va_end(ap__);
}

/* @since  1.1 */
LIBSIMPLE_GCC_ONLY__(__attribute__((__malloc__, __warn_unused_result__)))
inline void *
libsimple_ememalloc(size_t n__, ... /*, LIBSIMPLE_MEMALLOC_END */)
{
	va_list ap__;
	va_start(ap__, n__);
	return libsimple_evmemalloc(n__, ap__);
	va_end(ap__);
}
