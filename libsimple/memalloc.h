/* See LICENSE file for copyright and license details. */

enum libsimple_memalloc_option {
	LIBSIMPLE_MEMALLOC_END,
	LIBSIMPLE_MEMALLOC_ZERO_INIT,
	LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT,
	LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO,
	LIBSIMPLE_MEMALLOC_NULL_IF_ZERO,
	LIBSIMPLE_MEMALLOC_ALIGNMENT,
	LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT,
	LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT,
	LIBSIMPLE_MEMALLOC_ELEMENT_SIZE,
	LIBSIMPLE_MEMALLOC_PRODUCT_SIZE,
	LIBSIMPLE_MEMALLOC_VA_PRODUCT_SIZE,
	LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE,
	LIBSIMPLE_MEMALLOC_VA_LIST,
};
#define libsimple_arrayalloc_option libsimple_memalloc_option

#define LIBSIMPLE_MEMALLOC_END                        LIBSIMPLE_MEMALLOC_END
#define LIBSIMPLE_MEMALLOC_ZERO_INIT                  LIBSIMPLE_MEMALLOC_ZERO_INIT
#define LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT      LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT
#define LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO             LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO
#define LIBSIMPLE_MEMALLOC_NULL_IF_ZERO               LIBSIMPLE_MEMALLOC_NULL_IF_ZERO
#define LIBSIMPLE_MEMALLOC_ALIGNMENT                  LIBSIMPLE_MEMALLOC_ALIGNMENT
#define LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT             LIBSIMPLE_MEMALLOC_PAGE_ALIGNMENT
#define LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT
#define LIBSIMPLE_MEMALLOC_ELEMENT_SIZE               LIBSIMPLE_MEMALLOC_ELEMENT_SIZE
#define LIBSIMPLE_MEMALLOC_PRODUCT_SIZE               LIBSIMPLE_MEMALLOC_PRODUCT_SIZE
#define LIBSIMPLE_MEMALLOC_VA_PRODUCT_SIZE            LIBSIMPLE_MEMALLOC_VA_PRODUCT_SIZE
#define LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE          LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE
#define LIBSIMPLE_MEMALLOC_VA_LIST                    LIBSIMPLE_MEMALLOC_VA_LIST

#define LIBSIMPLE_ARRAYALLOC_END                        LIBSIMPLE_MEMALLOC_END
#define LIBSIMPLE_ARRAYALLOC_ZERO_INIT                  LIBSIMPLE_MEMALLOC_ZERO_INIT
#define LIBSIMPLE_ARRAYALLOC_CONDITIONAL_ZERO_INIT      LIBSIMPLE_MEMALLOC_CONDITIONAL_ZERO_INIT
#define LIBSIMPLE_ARRAYALLOC_UNIQUE_IF_ZERO             LIBSIMPLE_MEMALLOC_UNIQUE_IF_ZERO
#define LIBSIMPLE_ARRAYALLOC_NULL_IF_ZERO               LIBSIMPLE_MEMALLOC_NULL_IF_ZERO
#define LIBSIMPLE_ARRAYALLOC_ROUND_UP_SIZE_TO_ALIGNMENT LIBSIMPLE_MEMALLOC_ROUND_UP_SIZE_TO_ALIGNMENT
#define LIBSIMPLE_ARRAYALLOC_PRODUCT_SIZE               LIBSIMPLE_MEMALLOC_PRODUCT_SIZE
#define LIBSIMPLE_ARRAYALLOC_VA_PRODUCT_SIZE            LIBSIMPLE_MEMALLOC_VA_PRODUCT_SIZE
#define LIBSIMPLE_ARRAYALLOC_1_VA_PRODUCT_SIZE          LIBSIMPLE_MEMALLOC_1_VA_PRODUCT_SIZE
#define LIBSIMPLE_ARRAYALLOC_VA_LIST                    LIBSIMPLE_MEMALLOC_VA_LIST

#define libsimple_varrayalloc(TYPE, N, AP)\
	libsimple_memalloc(N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                   LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                   LIBSIMPLE_MEMALLOC_VA_LIST, AP, LIBSIMPLE_MEMALLOC_END)

#define libsimple_evarrayalloc(TYPE, N, AP)\
	libsimple_ememalloc(N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                    LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                    LIBSIMPLE_MEMALLOC_VA_LIST, AP, LIBSIMPLE_MEMALLOC_END)

#define libsimple_envarrayalloc(STATUS, TYPE, N, AP)\
	libsimple_enmemalloc(STATUS, N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                     LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                     LIBSIMPLE_MEMALLOC_VA_LIST, AP, LIBSIMPLE_MEMALLOC_END)

#define libsimple_arrayalloc(TYPE, N, ... /*, LIBSIMPLE_ARRAYALLOC_END */)\
	libsimple_memalloc(N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                   LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                   __VA_ARGS__)

#define libsimple_earrayalloc(TYPE, N, ... /*, LIBSIMPLE_ARRAYALLOC_END */)\
	libsimple_ememalloc(N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                    LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                    __VA_ARGS__)

#define libsimple_enarrayalloc(STATUS, TYPE, N, ... /*, LIBSIMPLE_ARRAYALLOC_END */)\
	libsimple_enmemalloc(STATUS, N, LIBSIMPLE_MEMALLOC_ELEMENT_SIZE, sizeof(TYPE),\
	                     LIBSIMPLE_MEMALLOC_ALIGNMENT, _Alignof(TYPE),\
	                     __VA_ARGS__)

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
void *libsimple_vmemalloc(size_t, va_list);

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
void *libsimple_envmemalloc(int, size_t, va_list);

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *libsimple_evmemalloc(size_t __n, va_list __ap)
{ return libsimple_envmemalloc(libsimple_default_failure_exit, __n, __ap); }

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_memalloc(size_t __n, ... /*, LIBSIMPLE_MEMALLOC_END */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_vmemalloc(__n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_enmemalloc(int __status, size_t __n, ... /*, LIBSIMPLE_MEMALLOC_END */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_envmemalloc(__status, __n, __ap);
	va_end(__ap);
}

_LIBSIMPLE_GCC_ONLY(__attribute__((__malloc__, __warn_unused_result__)))
static inline void *
libsimple_ememalloc(size_t __n, ... /*, LIBSIMPLE_MEMALLOC_END */)
{
	va_list __ap;
	va_start(__ap, __n);
	return libsimple_evmemalloc(__n, __ap);
	va_end(__ap);
}
