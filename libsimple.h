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


#if defined(__GNUC__) && !defined(__clang__)
# define _LIBSIMPLE_GCC_ONLY(x) x
#else
# define _LIBSIMPLE_GCC_ONLY(x)
#endif


#include "libsimple/printf.h"
#include "libsimple/definitions.h"
#include "libsimple/memalloc.h"
#include "libsimple/strdup.h"
#include "libsimple/strndup.h"
#include "libsimple/memdup.h"
#include "libsimple/aligned_memdup.h"
#include "libsimple/mallocz.h"
#include "libsimple/malloc.h"
#include "libsimple/calloc.h"
#include "libsimple/realloc.h"
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
#include "libsimple/overflow.h"


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


#endif
