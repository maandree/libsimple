/* See LICENSE file for copyright and license details. */
#ifndef LIBSIMPLE_ARG_H
#define LIBSIMPLE_ARG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



extern char *argv0;


struct longopt {
	const char *long_flag;
	char short_flag;
	int with_arg;
};


#define ARGBEGIN    ARGBEGIN3(1, argc, argv)
#define SUBARGBEGIN ARGBEGIN3(0, argc, argv)

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


#define ARGNUM         '0': case '1': case '2': case '3': case '4':\
                  case '5': case '6': case '7': case '8': case '9'

#define FLAG()    (flag_)
#define LFLAG()   (lflag_)
#define ARG()     (arg_ ? (brk_ = 1, arg_) : (usage(), (char *)0))
#define ARGHERE() (brk_ = 1, argv[0])


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


#define USAGE(SYNOPSIS)\
	NUSAGE(1, SYNOPSIS)

#if defined(__GNUC__) || defined(__clang__)
# define NUSAGE(STATUS, SYNOPSIS)\
	__attribute__((noreturn))\
	static void usage(void)\
	{\
		const char *syn = SYNOPSIS ? SYNOPSIS : "";\
		fprintf(stderr, "usage: %s%s%s\n", argv0, *syn ? " " : "", syn);\
		exit(STATUS);\
	}\
	char *argv0
#else
# define NUSAGE(STATUS, SYNOPSIS)\
	static void usage(void)\
	{\
		const char *syn = SYNOPSIS ? SYNOPSIS : "";\
		fprintf(stderr, "usage: %s%s%s\n", argv0, *syn ? " " : "", syn);\
		exit(STATUS);\
	}\
	char *argv0
#endif


#endif
