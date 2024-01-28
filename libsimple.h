/* See LICENSE file for copyright and license details. */
#ifndef LIBSIMPLE_H
#define LIBSIMPLE_H


#if defined(__clang__)
# pragma clang diagnostic push
# pragma clang diagnostic ignored "-Wdocumentation"
# pragma clang diagnostic ignored "-Wdocumentation-unknown-command"
# pragma clang diagnostic ignored "-Wreserved-identifier"
# pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
#endif

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


#if defined(__GLIBC__) && (__GLIBC_PREREQ(2, 29) ? defined(_DEFAULT_SOURCE) : (__GLIBC_PREREQ(2, 26) && defined(_GNU_SOURCE)))
# define reallocarray reallocarray
#endif



#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Winline"
#endif



#if defined(__GNUC__) && !defined(__clang__)
# define LIBSIMPLE_GCC_ONLY__(x) x
# define LIBSIMPLE_NON_GCC_ONLY__(x)
#else
# define LIBSIMPLE_GCC_ONLY__(x)
# define LIBSIMPLE_NON_GCC_ONLY__(x) x
#endif

#if defined(__GNUC__)
# define LIBSIMPLE_EXTENSION__ __extension__
#else
# define LIBSIMPLE_EXTENSION__
#endif

#if __STDC_VERSION__ >= 199409L
# define LIBSIMPLE_C95_ONLY__(x) x
# define LIBSIMPLE_PRE_C95_ONLY__(x)
#else
# define LIBSIMPLE_C95_ONLY__(x)
# define LIBSIMPLE_PRE_C95_ONLY__(x) x
#endif

#if __STDC_VERSION__ >= 199901L
# define LIBSIMPLE_C99_ONLY__(x) x
# define LIBSIMPLE_PRE_C99_ONLY__(x)
#else
# define LIBSIMPLE_C99_ONLY__(x)
# define LIBSIMPLE_PRE_C99_ONLY__(x) x
#endif

#if __STDC_VERSION__ >= 201112L
# define LIBSIMPLE_C11_ONLY__(x) x
# define LIBSIMPLE_PRE_C11_ONLY__(x)
#else
# define LIBSIMPLE_C11_ONLY__(x)
# define LIBSIMPLE_PRE_C11_ONLY__(x) x
#endif

#if __STDC_VERSION__ >= 201710L
# define LIBSIMPLE_C17_ONLY__(x) x
# define LIBSIMPLE_PRE_C17_ONLY__(x)
#else
# define LIBSIMPLE_C17_ONLY__(x)
# define LIBSIMPLE_PRE_C17_ONLY__(x) x
#endif


#define libsimple_assume_aligned_as__(TYPE)\
	LIBSIMPLE_C11_ONLY__(__assume_aligned__(_Alignof(TYPE)))\
	LIBSIMPLE_PRE_C11_ONLY__(LIBSIMPLE_GCC_ONLY__(__assume_aligned__(__alignof(TYPE))))


#if __STDC_VERSION__ >= 201112L
# define LIBSIMPLE_NORETURN _Noreturn /* TODO doc, man */
#elif defined(__GNUC__) || defined(__clang__)
# define LIBSIMPLE_NORETURN __attribute__((noreturn))
#else
# define LIBSIMPLE_NORETURN
#endif


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
#include "libsimple/strtoint.h"
#include "libsimple/search.h"
#include "libsimple/random.h"


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
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline int
libsimple_close(int *fdp__)
{
	int ret__;
	if (*fdp__ < 0)
		return 0;
	ret__ = close(*fdp__);
	*fdp__ = -1;
	return ret__;
}


/**
 * Close a range of file descriptors
 *
 * @param   first   The lowest file descriptor to close
 * @param   last    The highest file descriptor to close
 * @param   next    Output parameter for the potentially first unclosed file descriptor; may be `NULL`
 * @return          0 on successful completion, -1 on failure
 * @throws  EINVAL  If `first > last`
 * @throws          Any error for close(3) except EBADF
 */
int libsimple_close_range(unsigned int first, unsigned int last, unsigned int *next);
#define LIBSIMPLE_CLOSE_RANGE_MAX (~0U)


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
LIBSIMPLE_GCC_ONLY__(__attribute__((__nonnull__)))
inline void
libsimple_unlist(void *list__, size_t i__, size_t *np__, size_t width__)
{
        char *lst__ = list__;
        memmove(&lst__[i__ * width__], &lst__[(i__ + 1) * width__], (--*np__ - i__) * width__);
}
#ifndef unlist
# define unlist libsimple_unlist
#endif


#define LIBSIMPLE_REMOVE_CONST__(X, TYPE, ...) (*(TYPE *)(void *)&(X))
#define LIBSIMPLE_REMOVE_CONST(...) LIBSIMPLE_REMOVE_CONST__(__VA_ARGS__, void *) /* TODO test, doc, man */
#ifndef REMOVE_CONST
# define REMOVE_CONST(...) LIBSIMPLE_REMOVE_CONST(__VA_ARGS__)
#endif


#define LIBSIMPLE_PREFETCH_RDONLY(ADDRESS, LOCALITY) /* void */ /* TODO test, doc, man */\
	LIBSIMPLE_GCC_ONLY__(__builtin_prefetch(ADDRESS, 0, LOCALITY))
#ifndef PREFETCH_RDONLY
# define PREFETCH_RDONLY(...) LIBSIMPLE_PREFETCH_RDONLY(__VA_ARGS__)
#endif


#define LIBSIMPLE_PREFETCH_RDWR(ADDRESS, LOCALITY) /* void */ /* TODO test, doc, man */\
	LIBSIMPLE_GCC_ONLY__(__builtin_prefetch(ADDRESS, 1, LOCALITY))
#ifndef PREFETCH_RDWR
# define PREFETCH_RDWR(...) LIBSIMPLE_PREFETCH_RDWR(__VA_ARGS__)
#endif


#define LIBSIMPLE_ASSUME_ALIGNED__(PTR, ALIGNMENT, ...)\
	LIBSIMPLE_GCC_ONLY__(__builtin_assume_aligned(PTR, ALIGNMENT))\
	LIBSIMPLE_NON_GCC_ONLY__(PTR)
#define LIBSIMPLE_ASSUME_ALIGNED(PTR, ...) /* returns PTR */ /* TODO test, doc, man */\
	LIBSIMPLE_ASSUME_ALIGNED__(PTR, ##__VA_ARGS__, LIBSIMPLE_C11_ONLY__(_Alignof(*PTR)) /* no , */\
	                           LIBSIMPLE_PRE_C11_ONLY__(__alignof(*PTR)))
#ifndef ASSUME_ALIGNED
# define ASSUME_ALIGNED(...) LIBSIMPLE_ASSUME_ALIGNED(__VA_ARGS__)
#endif


#define LIBSIMPLE_ASSUME_MISALIGNED(PTR, ALIGNMENT, OFFSET) /* returns PTR */ /* TODO test, doc, man */\
	__builtin_assume_aligned(PTR, ALIGNMENT, OFFSET)
#ifndef ASSUME_MISALIGNED
# define ASSUME_MISALIGNED(...) LIBSIMPLE_ASSUME_MISALIGNED(__VA_ARGS__)
#endif


#define LIBSIMPLE_UNROLLED(N) LIBSIMPLE_GCC_ONLY__(LIBSIMPLE_C11_ONLY__(_Pragma("GCC unroll "#N))) /* TODO test, doc, man */
#ifndef UNROLLED
# define UNROLLED(N) LIBSIMPLE_UNROLLED(N)
#endif


#define LIBSIMPLE_SIMDLOOP LIBSIMPLE_GCC_ONLY__(LIBSIMPLE_C11_ONLY__(_Pragma("GCC ivdep"))) /* TODO test, doc, man */
#ifndef SIMDLOOP
# define SIMDLOOP LIBSIMPLE_SIMDLOOP
#endif




#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic pop
#endif

#if defined(__clang__)
# pragma clang diagnostic pop
#endif


#endif
