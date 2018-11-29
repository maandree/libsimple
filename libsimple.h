/* See LICENSE file for copyright and license details. */
#ifndef LIBSIMPLE_H
#define LIBSIMPLE_H


#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <aio.h>
#include <alloca.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <grp.h>
#include <inttypes.h>
#include <limits.h>
#include <netdb.h>
#include <poll.h>
#include <pwd.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <unistd.h>
#include <wchar.h>
#include <wctype.h>



#if defined(__GNUC__) && !defined(__clang__)
# define _LIBSIMPLE_GCC_ONLY(x) x
# define _LIBSIMPLE_NON_GCC_ONLY(x)
#else
# define _LIBSIMPLE_GCC_ONLY(x)
# define _LIBSIMPLE_NON_GCC_ONLY(x) x
#endif

#if __STDC_VERSION__ >= 199409L
# define _LIBSIMPLE_C95_ONLY(x) x
# define _LIBSIMPLE_PRE_C95_ONLY(x)
#else
# define _LIBSIMPLE_C95_ONLY(x)
# define _LIBSIMPLE_PRE_C95_ONLY(x) x
#endif

#if __STDC_VERSION__ >= 199901L
# define _LIBSIMPLE_C99_ONLY(x) x
# define _LIBSIMPLE_PRE_C99_ONLY(x)
#else
# define _LIBSIMPLE_C99_ONLY(x)
# define _LIBSIMPLE_PRE_C99_ONLY(x) x
#endif

#if __STDC_VERSION__ >= 201112L
# define _LIBSIMPLE_C11_ONLY(x) x
# define _LIBSIMPLE_PRE_C11_ONLY(x)
#else
# define _LIBSIMPLE_C11_ONLY(x)
# define _LIBSIMPLE_PRE_C11_ONLY(x) x
#endif

#if __STDC_VERSION__ >= 201710L
# define _LIBSIMPLE_C17_ONLY(x) x
# define _LIBSIMPLE_PRE_C17_ONLY(x)
#else
# define _LIBSIMPLE_C17_ONLY(x)
# define _LIBSIMPLE_PRE_C17_ONLY(x) x
#endif


#define _libsimple_assume_aligned_as(TYPE)\
	_LIBSIMPLE_C11_ONLY(__assume_aligned__(_Alignof(TYPE)))\
	_LIBSIMPLE_PRE_C11_ONLY(_LIBSIMPLE_GCC_ONLY__assume_aligned__(__alignof(TYPE)))


#include "libsimple/overflow.h"
#include "libsimple/printf.h"
#include "libsimple/definitions.h"
#include "libsimple/memalloc.h"
#include "libsimple/memdup.h"
#include "libsimple/aligned_memdup.h"
#include "libsimple/strdup.h"
#include "libsimple/aligned_strdup.h"
#include "libsimple/strndup.h"
#include "libsimple/aligned_strndup.h"
#include "libsimple/wmemdup.h"
#include "libsimple/aligned_wmemdup.h"
#include "libsimple/wcsdup.h"
#include "libsimple/aligned_wcsdup.h"
#include "libsimple/wcsndup.h"
#include "libsimple/aligned_wcsndup.h"
#include "libsimple/mallocz.h"
#include "libsimple/malloc.h"
#include "libsimple/calloc.h"
#include "libsimple/realloc.h"
#include "libsimple/aligned_realloc.h"
#include "libsimple/memalignz.h"
#include "libsimple/memalign.h"
#include "libsimple/vallocz.h"
#include "libsimple/valloc.h"
#include "libsimple/pvallocz.h"
#include "libsimple/pvalloc.h"
#include "libsimple/aligned_allocz.h"
#include "libsimple/aligned_alloc.h"
#include "libsimple/posix_memalignz.h"
#include "libsimple/posix_memalign.h"
#include "libsimple/env.h"
#include "libsimple/time.h"
#include "libsimple/mem.h"
#include "libsimple/memelem.h"
#include "libsimple/array.h"
#include "libsimple/str.h"
#include "libsimple/strn.h"


/**
 * Wrapper for close(3) that only calls close(3)
 * if the file descriptor number is non-negative,
 * and that will set it to -1 after closing
 * 
 * @param   fdp  Pointer to file descriptor number, will
 *               be update to -1 if it is non-negative
 * @return       Return value of close(3) (0 on success,
 *               -1 on error), 0 if `*fdp < 0`
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline int
libsimple_close(int *__fdp)
{
	int __ret;
	if (*__fdp < 0)
		return 0;
	__ret = close(*__fdp);
	*__fdp = -1;
	return __ret;
}


/**
 * Remove an item from a list, keeping the list ordered
 * 
 * `list` must be non-void pointer to a complete type,
 * the type of the pointer will be used to infer the
 * width of the items in the list
 * 
 * @param  list:non-void pointer  The list
 * @param  i:size_t               The index of the item to remove
 * @param  n:size_t               Pointer to the number of items in the list, will be updated
 */
#define LIBSIMPLE_UNLIST(LIST, I, NP) libsimple_unlist((LIST), (I), (NP), sizeof(*(LIST)))
#ifndef UNLIST
# define UNLIST(LIST, I, NP) LIBSIMPLE_UNLIST((LIST), (I), (NP))
#endif


/**
 * Remove an item from a list, keeping the list ordered
 * 
 * @param  list   The list
 * @param  i      The index of the item to remove
 * @param  n      Pointer to the number of items in the list, will be updated
 * @param  width  The width, in bytes, of each item in the list
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__nonnull__)))
static inline void
libsimple_unlist(void *__list, size_t __i, size_t *__np, size_t __width)
{
        char *__lst = __list;
        memmove(&__lst[__i * __width], &__lst[(__i + 1) * __width], (--*__np - __i) * __width);
}
#ifndef unlist
# define unlist libsimple_unlist
#endif


#define _LIBSIMPLE_REMOVE_CONST(X, TYPE, ...) (*(TYPE *)(void *)&(X))
#define LIBSIMPLE_REMOVE_CONST(...) _LIBSIMPLE_REMOVE_CONST(__VA_ARGS__, void *) /* TODO test, doc, man */
#ifndef REMOVE_CONST
# define REMOVE_CONST(...) LIBSIMPLE_REMOVE_CONST(__VA_ARGS__)
#endif


#define LIBSIMPLE_PREFETCH_RDONLY(ADDRESS, LOCALITY) /* void */ /* TODO test, doc, man */\
	_LIBSIMPLE_GCC_ONLY(__builtin_prefetch(ADDRESS, 0, LOCALITY))
#ifndef PREFETCH_RDONLY
# define PREFETCH_RDONLY(...) LIBSIMPLE_PREFETCH_RDONLY(__VA_ARGS__)
#endif


#define LIBSIMPLE_PREFETCH_RDWR(ADDRESS, LOCALITY) /* void */ /* TODO test, doc, man */\
	_LIBSIMPLE_GCC_ONLY(__builtin_prefetch(ADDRESS, 1, LOCALITY))
#ifndef PREFETCH_RDWR
# define PREFETCH_RDWR(...) LIBSIMPLE_PREFETCH_RDWR(__VA_ARGS__)
#endif


#define _LIBSIMPLE_ASSUME_ALIGNED(PTR, ALIGNMENT, ...)\
	_LIBSIMPLE_GCC_ONLY(__builtin_assume_aligned(PTR, ALIGNMENT))
#if defined(__GNUC__) && !defined(__clang__)
# define LIBSIMPLE_ASSUME_ALIGNED(PTR, ...) /* returns PTR */ /* TODO test, doc, man */\
	_LIBSIMPLE_GCC_ONLY(__builtin_assume_aligned(PTR, ##__VA_ARGS__,\
	                                             _LIBSIMPLE_C11_ONLY(_Alignof(PTR))\
	                                             _LIBSIMPLE_PREC11_ONLY(__alignof(PTR))))
#endif
#ifndef ASSUME_ALIGNED
# define ASSUME_ALIGNED(...) LIBSIMPLE_ASSUME_ALIGNED(__VA_ARGS__)
#endif


#define LIBSIMPLE_ASSUME_MISALIGNED(PTR, ALIGNMENT, OFFSET) /* returns PTR */ /* TODO test, doc, man */\
	__builtin_assume_aligned(PTR, ALIGNMENT, OFFSET)
#ifndef ASSUME_MISALIGNED
# define ASSUME_MISALIGNED(...) LIBSIMPLE_ASSUME_MISALIGNED(__VA_ARGS__)
#endif


#define LIBSIMPLE_UNROLLED(N) _LIBSIMPLE_GCC_ONLY(_LIBSIMPLE_C11_ONLY(_Pragma("GCC unroll "#N))) /* TODO test, doc, man */
#ifndef UNROLLED
# define UNROLLED(N) LIBSIMPLE_UNROLLED(N)
#endif


#define LIBSIMPLE_SIMDLOOP _LIBSIMPLE_GCC_ONLY(_LIBSIMPLE_C11_ONLY(_Pragma("GCC ivdep"))) /* TODO test, doc, man */
#ifndef SIMDLOOP
# define SIMDLOOP LIBSIMPLE_SIMDLOOP
#endif



#endif
