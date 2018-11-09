/* See LICENSE file for copyright and license details. */
#ifndef LIBSIMPLE_ARG_H
#define LIBSIMPLE_ARG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * The zeroth command line argument, the name of the process,
 * set by the command line parsing macros
 */
extern char *argv0;


struct longopt {
	const char *long_flag;
	char short_flag;
	int with_arg;
};


/**
 * `ARGBEGIN {} ARGEND;` creates a switch statement
 * instead a loop that parses the command line arguments
 * according to the POSIX specification for default
 * behaviour (extensions of the behaviour is possible)
 * 
 * This macro requires that the variables `argc` and
 * `argv` are defined and that `argv[argc]` is `NULL`,
 * `argc` shall be a non-negative `int` that tells
 * how many elements (all non-`NULL`) are available in
 * `argv`, the list of command line arguments
 * 
 * When parsing stops, `argc` and `argv` are updated
 * shuch that all parsed arguments are removed; the
 * contents of `argv` will not be modified, rather
 * the pointer `argv` will be updated to `&argv[n]`
 * where `n` is the number of parsed elements in `argv`
 * 
 * Inside `{}` in `ARGBEGIN {} ARGEND;` there user
 * shall specify `case` statements for each recognised
 * command line option, and `default` for unrecognised
 * option. For example:
 * 
 *         ARGBEGIN {
 *         case 'a':
 *                 // handle -a
 *                 break;
 *         case 'b':
 *                 // handle -b
 *                 break;
 *         case ARGNUM:
 *                 // handle -0, -1, -2, ..., -9
 *                 break;
 *         default:
 *                 // print usage information for other flags
 *                 usage();
 *         } ARGEND;
 */
#define ARGBEGIN ARGBEGIN3(1, argc, argv)

/**
 * `SUBARGBEGIN {} ARGEND;` is similar to
 * `ARGBEGIN {} ARGEND;`, however, `argv0`
 * is not set to `argv[0]`, instead `argv[0]`
 * is handled like any other element in `argv`
 */
#define SUBARGBEGIN ARGBEGIN3(0, argc, argv)

/**
 * Flexible alternative to `ARGBEGIN`
 * 
 * @param  WITH_ARGV0    If 0, behave like `SUBARGBEGIN`,
 *                       otherwise, behave like `ARGBEGIN`
 * @param  argc:int      The number of elements in `argv`, will be
 *                       update to the number of arguments remaining
 *                       after parsing stopped
 * @param  argv:char **  The command line arguments to parse,
 *                       `argv[argc]` must be `NULL`; will be updated,
 *                       via offseting, to the arguments remaining
 *                       after parsing stopped, `argv[argc]` will
 *                       still be `NULL`
 */
#define ARGBEGIN3(WITH_ARGV0, argc, argv)\
	do {\
		char flag_, *lflag_, *arg_;\
		int brk_ = 0, again_;\
		size_t i_, n_;\
		if (WITH_ARGV0) {\
			argv0 = *argv;\
			argv += !!argv0;\
			argc -= !!argv0;\
		}\
		for (; argv[0] && argv[0][0] && argv[0][1]; argc--, argv++) {\
			lflag_ = argv[0];\
			if (argv[0][0] == '-') {\
				if (argv[0][1] == '-' && !argv[0][2]) {\
					argv++, argc--;\
					break;\
				}\
				for (argv[0]++; argv[0][0]; argv[0]++) {\
					flag_ = argv[0][0];\
					if (flag_ == '-' && &argv[0][-1] != lflag_)\
						usage();\
					arg_ = argv[0][1] ? &argv[0][1] : argv[1];\
					do {\
						again_ = 0;\
						switch (flag_) {

/**
 * TODO doc ARGMAPLONG
 */
#define ARGMAPLONG(LONGOPTS)\
						for (i_ = 0; (LONGOPTS)[i_].long_flag; i_++) {\
							if (TESTLONG((LONGOPTS)[i_].long_flag, (LONGOPTS)[i_].with_arg)) {\
								flag_ = (LONGOPTS)[i_].short_flag;\
								again_ = 1;\
								break;\
							}\
						}\
						if (again_)\
							break

/**
 * Allows flags to start with another symbol than '-'
 * 
 * Usage example:
 *         ARGBEGIN {
 *         case 'a': // handle -a
 *                 break;
 *         default:
 *                 usage();
 *         } ARGALT('+') {
 *         case 'a': // handle +a
 *                 break;
 *         default:
 *                 usage();
 *         } ARGALT('/') {
 *         case 'a': // handle /a
 *                 break;
 *         default:
 *                 usage();
 *         } ARGEND;
 * 
 * @param  SYMBOL:char  The symbol flags should begin with
 */
#define ARGALT(SYMBOL)\
						}\
					} while (again_);\
					if (brk_) {\
						argc -= arg_ == argv[1];\
						argv += arg_ == argv[1];\
						brk_ = 0;\
						break;\
					}\
				}\
			} else if (argv[0][0] == SYMBOL) {\
				if (argv[0][1] == SYMBOL && !argv[0][2])\
					break;\
				for (argv[0]++; argv[0][0]; argv[0]++) {\
					flag_ = argv[0][0];\
					if (flag_ == SYMBOL && &argv[0][-1] != lflag_)\
						usage();\
					arg_ = argv[0][1] ? &argv[0][1] : argv[1];\
					do {\
						again_ = 0;\
						switch (flag_) {

/**
 * Refer to `ARGBEGIN`, `SUBARGBEGIN`, and `ARGBEGIN3`
 */
#define ARGEND\
						}\
					} while (again_);\
					if (brk_) {\
						argc -= arg_ == argv[1];\
						argv += arg_ == argv[1];\
						brk_ = 0;\
						break;\
					}\
				}\
			} else {\
				break;\
			}\
		}\
	} while (0)


/**
 * `case ARGNUM` creates a switch statement case for each digit
 */
#define ARGNUM      '0': case '1': case '2': case '3': case '4':\
               case '5': case '6': case '7': case '8': case '9'

/**
 * Get the flag character, for example in `case 'a'`,
 * 'a' is returned
 * 
 * @return  :char  The option's identifying character
 */
#define FLAG() (flag_)

/**
 * Get the entire argument that is being parsed
 * 
 * Note that an argument can contain multiple options
 * and it can contain the last options value but the
 * value can also be in the next argument
 * 
 * @return  :char *  The current command line argument
 */
#define LFLAG() (lflag_)

/**
 * Get the current option's value, if it
 * does not have a value, call `usage`
 * (which terminates the process)
 * 
 * Using this macro lets the parser knows
 * that the option has a value
 * 
 * @return  :char *  The option's value, never `NULL`
 */
#define ARG() (arg_ ? (brk_ = 1, arg_) : (usage(), NULL))

/**
 * Get the current option's value, if the option
 * does not have a value, `NULL` is returned
 * 
 * Note that the value may appear at the next
 * argument (next element in `argv`) which in that
 * case is returned
 * 
 * Using this macro lets the parser knows
 * that the option has a value
 * 
 * @return  :char *  The option's value, `NULL` if
 *                   the option does not have a value
 */
#define ARGNULL() (arg_ ? (brk_ = 1, arg_) : NULL)

/**
 * Get the remaining part of the current command
 * line argument (element in `argv`) — as well as
 * the character that specifies the flag — as the
 * value of the argument
 * 
 * Using this macro lets the parser knows
 * that the option has a value
 * 
 * Usage example:
 * 
 *     char *arg;
 *     ARGBEGIN {
 *     case ARGNUM:
 *         arg = ARGHERE();
 *         // `arg` is the number after '-', for example,
 *         // if the command line contains the argument
 *         // "-12345", `arg` will be `12345`
 *         break;
 *     case 'n':
 *         arg = &ARGHERE()[1];
 *         if (*arg) {
 *             // flag 'n' has a value (`argv`)
 *         } else {
 *             // flag 'n' does not have a value
 *         }
 *     default:
 *         usage();
 *     } ARGEND;
 * 
 * @return  :char *  The option's value include the flag
 *                   character, never `NULL` or ""
 */
#define ARGHERE() (brk_ = 1, argv[0])


/**
 * `NOFLAG(x);` is an optimised shorthand for
 * 
 *     ARGBEGIN {
 *     default:
 *         usage();
 *     } ARGEND;
 * 
 *     if (x)
 *         usage();
 * 
 * @param  ...  If non-zero, the `usage` function
 *              will be called
 */
#define NOFLAGS(...)\
	do {\
		if (*argv)\
			argv0 = *argv++, argc--;\
		if (argv[0] && argv[0][0] == '-' && argv[0][1] == '-' && !argv[0][2])\
			argv++, argc--;\
		else if (argv[0] && argv[0][0] == '-')\
			usage();\
		if (__VA_ARGS__)\
			usage();\
	} while (0)


/**
 * TODO doc NOFLAGS
 */
#define TESTLONG(FLG, WARG)\
	((WARG)\
	 ? ((!strncmp(lflag_, (FLG), n_ = strlen(FLG)) && lflag_[n_] == '=')\
	    ? (lflag_[n_] = '\0',\
	       (arg_ = &lflag_[n_ + 1]),\
	       (brk_ = 1))\
	    : (!strcmp(lflag_, (FLG))\
	       ? (argv[1]\
	          ? ((arg_ = argv[1]),\
	             (brk_ = 1))\
	          : (usage(), 0))\
	       : 0))\
	 : (!strcmp(lflag_, (FLG))\
	    ? (brk_ = 1)\
	    : 0))


/**
 * Define the function `static void usage(void)`
 * that prints the error message
 *         "usage: %s %s\n", argv0, SYNOPSIS
 * or
 *         "usage: %s\n", argv0
 * if `SYNOPSIS` is `NULL` or "", and then
 * terminate the process with exit value 1
 * 
 * This macro also defines `char *argv0`
 * 
 * @param  SYNOPSIS  Description of the command line argument syntax
 */
#define USAGE(SYNOPSIS)\
	NUSAGE(1, SYNOPSIS)


/**
 * Define the function `static void usage(void)`
 * that prints the error message
 *         "usage: %s %s\n", argv0, SYNOPSIS
 * or
 *         "usage: %s\n", argv0
 * if `SYNOPSIS` is `NULL` or "", and then
 * terminate the process with exit value `STATUS`
 * 
 * This macro also defines `char *argv0`
 * 
 * @param  SYNOPSIS  Description of the command line argument syntax
 * @parma  STATUS    The exit value for the process
 */
#if defined(__GNUC__) || defined(__clang__)
# define NUSAGE(STATUS, SYNOPSIS)\
	__attribute__((noreturn))\
	static void usage(void)\
	{\
		const char *syn = SYNOPSIS ? SYNOPSIS : "";\
		fprintf(stderr, "usage: %s%s%s\n", argv0, *syn ? " " : "", syn);\
		exit(STATUS);\
	}\
	char *argv0 = NULL
#else
# define NUSAGE(STATUS, SYNOPSIS)\
	static void usage(void)\
	{\
		const char *syn = SYNOPSIS ? SYNOPSIS : "";\
		fprintf(stderr, "usage: %s%s%s\n", argv0, *syn ? " " : "", syn);\
		exit(STATUS);\
	}\
	char *argv0 = NULL
#endif


#endif
