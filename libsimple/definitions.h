/* See LICENSE file for copyright and license details. */

#ifndef DONT_DEFINE_CLOCK_MONOTONIC_RAW
# ifndef CLOCK_MONOTONIC_RAW
#  define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
# endif
#endif


#ifdef AF_LOCAL
# ifndef AF_UNIX
#  define AF_UNIX AF_LOCAL
# endif
# ifndef AF_FILE
#  define AF_FILE AF_LOCAL
# endif
#endif

#ifdef AF_UNIX
# ifndef AF_LOCAL
#  define AF_LOCAL AF_UNIX
# endif
# ifndef AF_FILE
#  define AF_FILE AF_UNIX
# endif
#endif

#ifdef AF_FILE
# ifndef AF_LOCAL
#  define AF_LOCAL AF_FILE
# endif
# ifndef AF_UNIX
#  define AF_UNIX AF_FILE
# endif
#endif

#ifdef AF_NETLINK
# ifndef AF_ROUTE
#  define AF_ROUTE AF_NETLINK
# endif
#endif

#ifdef AF_ROUTE
# ifndef AF_NETLINK
#  define AF_NETLINK AF_ROUTE
# endif
#endif

#ifdef PF_LOCAL
# ifndef PF_UNIX
#  define PF_UNIX PF_LOCAL
# endif
# ifndef PF_FILE
#  define PF_FILE PF_LOCAL
# endif
#endif

#ifdef PF_UNIX
# ifndef PF_LOCAL
#  define PF_LOCAL PF_UNIX
# endif
# ifndef PF_FILE
#  define PF_FILE PF_UNIX
# endif
#endif

#ifdef PF_FILE
# ifndef PF_LOCAL
#  define PF_LOCAL PF_FILE
# endif
# ifndef PF_UNIX
#  define PF_UNIX PF_FILE
# endif
#endif

#ifdef PF_NETLINK
# ifndef PF_ROUTE
#  define PF_ROUTE PF_NETLINK
# endif
#endif

#ifdef PF_ROUTE
# ifndef PF_NETLINK
#  define PF_NETLINK PF_ROUTE
# endif
#endif

#if !defined(PF_UNIX) && defined(AF_UNIX)
# define PF_UNIX AF_UNIX
#endif
#if !defined(PF_LOCAL) && defined(AF_LOCAL)
# define PF_LOCAL AF_LOCAL
#endif
#if !defined(PF_FILE) && defined(AF_FILE)
# define PF_FILE AF_FILE
#endif
#if !defined(PF_INET) && defined(AF_INET)
# define PF_INET AF_INET
#endif
#if !defined(PF_INET6) && defined(AF_INET6)
# define PF_INET6 AF_INET6
#endif
#if !defined(PF_NETLINK) && defined(AF_NETLINK)
# define PF_NETLINK AF_NETLINK
#endif
#if !defined(PF_ROUTE) && defined(AF_ROUTE)
# define PF_ROUTE AF_ROUTE
#endif


/**
 * Get the smallest of two numerical values
 * 
 * @param   A  One of the values
 * @param   B  The other value
 * @return     The smallest of `A` and `B`
 */
#ifndef MIN
# define MIN(A, B) ((A) < (B) ? (A) : (B))
#endif


/**
 * Get the largest of two numerical values
 * 
 * @param   A  One of the values
 * @param   B  The other value
 * @return     The largest of `A` and `B`
 */
#ifndef MAX
# define MAX(A, B) ((A) > (B) ? (A) : (B))
#endif


/**
 * Get the smallest of three numerical values
 * 
 * @param   A  One of the values
 * @param   B  Another one of the values
 * @param   C  The last value
 * @return     The smallest of `A`, `B`, and `C`
 */
#ifndef MIN3
# define MIN3(A, B, C) MIN(MIN((A), (B)), (C))
#endif


/**
 * Get the largest of three numerical values
 * 
 * @param   A  One of the values
 * @param   B  Another one of the values
 * @param   C  The last value
 * @return     The largest of `A`, `B`, and `C`
 */
#ifndef MAX3
# define MAX3(A, B, C) MAX(MAX((A), (B)), (C))
#endif


/**
 * Get the number of elements in an array
 * 
 * @param   ARR      The array, must not be a pointer
 * @return  :size_t  The number of elements in `ARR` (constant
 *                   expression, unless its size is dynamic)
 */
#ifndef ELEMSOF
# define ELEMSOF(ARR) (sizeof(ARR) / (sizeof(*(ARR))))
#endif

	
/**
 * Get the length of a string literal
 * 
 * This macro does not support the wide-character strings
 * 
 * @param   STR:const char []  The string, must be a literal
 * @return  :size_t            The value of `strlen(STR)` as a constant expression
 */
#ifndef STRLEN
# define STRLEN(STR) (sizeof(STR) - 1)
#endif


/**
 * Get an approximation for the longest string an
 * integer of the specific integer type can be
 * converted to assuming it will not having an
 * explicit '+' sign or any leading zeroes or
 * other superfluous characters
 * 
 * The calculated approximation will not be less
 * than the real limit
 * 
 * @param   TYPE:integer type  The type, must be an integer type, may be signed or unsigned
 * @return  :size_t            A value close to, but not less than, the longest string a
 *                             value of the type `TYPE` can be converted to without any
 *                             superfluous characters (such as explitict '+' or leading zeroes')
 *                             (constant expression)
 */
#ifndef INTSTRLEN
# define INTSTRLEN(TYPE) ((sizeof(TYPE) == 1 ? 3 : 5 * (sizeof(TYPE) / 2)) + ((TYPE)-1 < 0))
#endif


/**
 * Get the maximum value for an integer type
 * 
 * @param   TYPE:integer type  The type, must be an integer type, may be signed or unsigned
 * @return  :TYPE              The largest value that can be stored in `TYPE` (constant expression)
 */
#ifndef TYPE_MAX
# define TYPE_MAX(TYPE) ((TYPE)(((1ULL << (8 * sizeof(TYPE) - 1)) - 1) << ((TYPE)-1 > 0) | 1))
#endif


/**
 * Get the minimum value for an integer type
 * 
 * @param   TYPE:integer type  The type, must be an integer type, may be signed or unsigned
 * @return  :TYPE              The smallest value that can be stored in `TYPE` (constant expression)
 */
#ifndef TYPE_MIN
# define TYPE_MIN(TYPE) ((TYPE)((TYPE)-1 > 0 ? 0 : (TYPE)~0 < (TYPE)-1 ? (TYPE)~0 : (TYPE)(1ULL << (8 * sizeof(TYPE) - 1))))
#endif


/* --- Maximum values --- */

#ifndef BLKCNT64_MAX
# define BLKCNT64_MAX   TYPE_MAX(blkcnt64_t)
#endif

#ifndef BLKCNT_MAX
# define BLKCNT_MAX     TYPE_MAX(blkcnt_t)
#endif

#ifndef BLKSIZE_MAX
# define BLKSIZE_MAX    TYPE_MAX(blksize_t)
#endif

#ifndef CC_MAX
# define CC_MAX         TYPE_MAX(cc_t)
#endif

#ifndef CLOCKID_MAX
# define CLOCKID_MAX    TYPE_MAX(clockid_t)
#endif

#ifndef CLOCK_MAX
# define CLOCK_MAX      TYPE_MAX(clock_t)
#endif

#ifndef DEV_MAX
# define DEV_MAX        TYPE_MAX(dev_t)
#endif

#ifndef FSBLKCNT64_MAX
# define FSBLKCNT64_MAX TYPE_MAX(fsblkcnt64_t)
#endif

#ifndef FSBLKCNT_MAX
# define FSBLKCNT_MAX   TYPE_MAX(fsblkcnt_t)
#endif

#ifndef FSFILCNT64_MAX
# define FSFILCNT64_MAX TYPE_MAX(fsfilcnt64_t)
#endif

#ifndef FSFILCNT_MAX
# define FSFILCNT_MAX   TYPE_MAX(fsfilcnt_t)
#endif

#ifndef GID_MAX
# define GID_MAX        TYPE_MAX(gid_t)
#endif

#ifndef ID_MAX
# define ID_MAX         TYPE_MAX(id_t)
#endif

#ifndef INO64_MAX
# define INO64_MAX      TYPE_MAX(ino64_t)
#endif

#ifndef INO_MAX
# define INO_MAX        TYPE_MAX(ino_t)
#endif

#ifndef KEY_MAX
# define KEY_MAX        TYPE_MAX(key_t)
#endif

#ifndef LOFF_MAX
# define LOFF_MAX       TYPE_MAX(loff_t)
#endif

#ifndef MODE_MAX
# define MODE_MAX       TYPE_MAX(mode_t)
#endif

#ifndef NLINK_MAX
# define NLINK_MAX      TYPE_MAX(nlink_t)
#endif

#ifndef OFF64_MAX
# define OFF64_MAX      TYPE_MAX(off64_t)
#endif

#ifndef OFF_MAX
# define OFF_MAX        TYPE_MAX(off_t)
#endif

#ifndef PID_MAX
# define PID_MAX        TYPE_MAX(pid_t)
#endif

#ifndef QUAD_MAX
# define QUAD_MAX       TYPE_MAX(quad_t)
#endif

#ifndef REGISTER_MAX
# define REGISTER_MAX   TYPE_MAX(register_t)
#endif

#ifndef RLIM64_MAX
# define RLIM64_MAX     TYPE_MAX(rlim64_t)
#endif

#ifndef RLIM_MAX
# define RLIM_MAX       TYPE_MAX(rlim_t)
#endif

#ifndef SOCKLEN_MAX
# define SOCKLEN_MAX    TYPE_MAX(socklen_t)
#endif

#ifndef SPEED_MAX
# define SPEED_MAX      TYPE_MAX(speed_t)
#endif

#ifndef SUSECONDS_MAX
# define SUSECONDS_MAX  TYPE_MAX(suseconds_t)
#endif

#ifndef TCFLAG_MAX
# define TCFLAG_MAX     TYPE_MAX(tcflag_t)
#endif

#ifndef TIME_MAX
# define TIME_MAX       TYPE_MAX(time_t)
#endif

#ifndef UID_MAX
# define UID_MAX        TYPE_MAX(uid_t)
#endif

#ifndef USECONDS_MAX
# define USECONDS_MAX   TYPE_MAX(useconds_t)
#endif

#ifndef U_QUAD_MAX
# define U_QUAD_MAX     TYPE_MAX(u_quad_t)
#endif


/* --- Minimum values --- */

#ifndef BLKCNT64_MIN
# define BLKCNT64_MIN   TYPE_MIN(blkcnt64_t)
#endif

#ifndef BLKCNT_MIN
# define BLKCNT_MIN     TYPE_MIN(blkcnt_t)
#endif

#ifndef BLKSIZE_MIN
# define BLKSIZE_MIN    TYPE_MIN(blksize_t)
#endif

#ifndef CC_MIN
# define CC_MIN         TYPE_MIN(cc_t)
#endif

#ifndef CLOCKID_MIN
# define CLOCKID_MIN    TYPE_MIN(clockid_t)
#endif

#ifndef CLOCK_MIN
# define CLOCK_MIN      TYPE_MIN(clock_t)
#endif

#ifndef DEV_MIN
# define DEV_MIN        TYPE_MIN(dev_t)
#endif

#ifndef FSBLKCNT64_MIN
# define FSBLKCNT64_MIN TYPE_MIN(fsblkcnt64_t)
#endif

#ifndef FSBLKCNT_MIN
# define FSBLKCNT_MIN   TYPE_MIN(fsblkcnt_t)
#endif

#ifndef FSFILCNT64_MIN
# define FSFILCNT64_MIN TYPE_MIN(fsfilcnt64_t)
#endif

#ifndef FSFILCNT_MIN
# define FSFILCNT_MIN   TYPE_MIN(fsfilcnt_t)
#endif

#ifndef GID_MIN
# define GID_MIN        TYPE_MIN(gid_t)
#endif

#ifndef ID_MIN
# define ID_MIN         TYPE_MIN(id_t)
#endif

#ifndef INO64_MIN
# define INO64_MIN      TYPE_MIN(ino64_t)
#endif

#ifndef INO_MIN
# define INO_MIN        TYPE_MIN(ino_t)
#endif

#ifndef KEY_MIN
# define KEY_MIN        TYPE_MIN(key_t)
#endif

#ifndef LOFF_MIN
# define LOFF_MIN       TYPE_MIN(loff_t)
#endif

#ifndef MODE_MIN
# define MODE_MIN       TYPE_MIN(mode_t)
#endif

#ifndef NLINK_MIN
# define NLINK_MIN      TYPE_MIN(nlink_t)
#endif

#ifndef OFF64_MIN
# define OFF64_MIN      TYPE_MIN(off64_t)
#endif

#ifndef OFF_MIN
# define OFF_MIN        TYPE_MIN(off_t)
#endif

#ifndef PID_MIN
# define PID_MIN        TYPE_MIN(pid_t)
#endif

#ifndef QUAD_MIN
# define QUAD_MIN       TYPE_MIN(quad_t)
#endif

#ifndef REGISTER_MIN
# define REGISTER_MIN   TYPE_MIN(register_t)
#endif

#ifndef RLIM64_MIN
# define RLIM64_MIN     TYPE_MIN(rlim64_t)
#endif

#ifndef RLIM_MIN
# define RLIM_MIN       TYPE_MIN(rlim_t)
#endif

#ifndef SOCKLEN_MIN
# define SOCKLEN_MIN    TYPE_MIN(socklen_t)
#endif

#ifndef SPEED_MIN
# define SPEED_MIN      TYPE_MAX(speed_t)
#endif

#ifndef SUSECONDS_MIN
# define SUSECONDS_MIN  TYPE_MIN(suseconds_t)
#endif

#ifndef TCFLAG_MIN
# define TCFLAG_MIN     TYPE_MAX(tcflag_t)
#endif

#ifndef TIME_MIN
# define TIME_MIN       TYPE_MIN(time_t)
#endif

#ifndef UID_MIN
# define UID_MIN        TYPE_MIN(uid_t)
#endif

#ifndef USECONDS_MIN
# define USECONDS_MIN   TYPE_MIN(useconds_t)
#endif

#ifndef U_QUAD_MIN
# define U_QUAD_MIN     TYPE_MIN(u_quad_t)
#endif
