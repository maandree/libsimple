/* See LICENSE file for copyright and license details. */
#ifndef LIBSIMPLE_H
#define LIBSIMPLE_H


#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
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


extern int libsimple_default_failure_exit;


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
#include "libsimple/printf.h"
#include "libsimple/mem.h"
#include "libsimple/str.h"
#include "libsimple/strn.h"


#define FREE(PTR) ((void)(free(PTR), (PTR) = NULL))

#define CLOSE(FD) libsimple_close(&(FD))

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

_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
static inline int libsimple_inchrset(int __c, const char *__s)
{ return __c && strchr(__s, __c); }
#ifndef inchrset
# define inchrset libsimple_inchrset
#endif

/**
 * Check whether a NUL-terminated string is encoded in UTF-8
 * 
 * @param   string              The string
 * @param   allow_modified_nul  Whether Modified UTF-8 is allowed, which allows a two-byte encoding for NUL
 * @return                      1 if good, 0 on encoding error
 */
_LIBSIMPLE_GCC_ONLY(__attribute__((__pure__, __nonnull__, __warn_unused_result__)))
int libsimple_isutf8(const char *, int);
#ifndef isutf8
# define isutf8 libsimple_isutf8
#endif

#define LIBSIMPLE_UNLIST(LIST, I, NP) libsimple_unlist((LIST), (I), (NP), sizeof(*(LIST)))
#ifndef UNLIST
# define UNLIST(LIST, I, NP) LIBSIMPLE_UNLIST((LIST), (I), (NP))
#endif

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
