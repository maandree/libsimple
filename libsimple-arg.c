/* See LICENSE file for copyright and license details. */
#include <setjmp.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libsimple-arg.h"
#include "test.h"


#define PARSER_BEGIN\
	int old_argc = argc;\
	char **old_argv = argv;\
	/* { */


#define PARSER_END\
	/* } */\
	assert(argv0 == old_argv[0]);\
	assert(argv == &old_argv[old_argc - argc]);\
	return argc


#define PARSER_END_NO_ARGV0\
	/* } */\
	assert(argv0 == NULL);\
	assert(argv == &old_argv[old_argc - argc]);\
	return argc


#define SHORT_WITHOUT_ARG(SHORT_FLAG)\
	do {\
		assert(nparsed < sizeof(parsed) / sizeof(*parsed));\
		assert(FLAG() == (SHORT_FLAG)[1]);\
		parsed[nparsed].short_used = 1;\
		parsed[nparsed].long_used = 0;\
		parsed[nparsed].have_arg = 0;\
		parsed[nparsed].short_flag[0] = (SHORT_FLAG)[0];\
		parsed[nparsed].short_flag[1] = (SHORT_FLAG)[1];\
		parsed[nparsed].short_flag[2] = '\0';\
		parsed[nparsed].long_flag[0] = '\0';\
		parsed[nparsed].argument[0] = '\0';\
		nparsed += 1;\
	} while (0)


#define SHORT_WITH_ARG(SHORT_FLAG)\
	do {\
		char *arg__;\
		assert(nparsed < sizeof(parsed) / sizeof(*parsed));\
		assert(FLAG() == (SHORT_FLAG)[1]);\
		parsed[nparsed].short_used = 1;\
		parsed[nparsed].long_used = 0;\
		parsed[nparsed].have_arg = 1;\
		parsed[nparsed].short_flag[0] = (SHORT_FLAG)[0];\
		parsed[nparsed].short_flag[1] = (SHORT_FLAG)[1];\
		parsed[nparsed].short_flag[2] = '\0';\
		parsed[nparsed].long_flag[0] = '\0';\
		assert(strlen(ARG()) < sizeof(parsed[nparsed].argument));\
		assert((arg__ = ARG()));\
		assert(arg__ == ARGNULL());\
		stpcpy(parsed[nparsed].argument, ARG());\
		nparsed += 1;\
	} while (0)


#define SHORT_WITH_MISSING_ARG(SHORT_FLAG)\
	do {\
		assert(!ARGNULL());\
		ARG();\
	} while (0)


#define SHORT_WITH_ARGHERE(SHORT_FLAG)\
	do {\
		assert(nparsed < sizeof(parsed) / sizeof(*parsed));\
		assert(FLAG() == ARGHERE()[0]);\
		parsed[nparsed].short_used = 1;\
		parsed[nparsed].long_used = 0;\
		parsed[nparsed].have_arg = 1;\
		parsed[nparsed].short_flag[0] = (SHORT_FLAG)[0];\
		parsed[nparsed].short_flag[1] = (SHORT_FLAG)[1];\
		parsed[nparsed].short_flag[2] = '\0';\
		parsed[nparsed].long_flag[0] = '\0';\
		assert(strlen(ARGHERE()) < sizeof(parsed[nparsed].argument));\
		stpcpy(parsed[nparsed].argument, ARGHERE());\
		nparsed += 1;\
	} while (0)


#define LONG_WITHOUT_ARG(LONG_FLAG)\
	do {\
		assert(nparsed < sizeof(parsed) / sizeof(*parsed));\
		assert(FLAG() == LONG_FLAG[1]);\
		assert(!strcmp(LFLAG(), LONG_FLAG));\
		parsed[nparsed].short_used = 0;\
		parsed[nparsed].long_used = 1;\
		parsed[nparsed].have_arg = 0;\
		parsed[nparsed].short_flag[0] = '\0';\
		parsed[nparsed].short_flag[1] = '\0';\
		parsed[nparsed].short_flag[2] = '\0';\
		stpcpy(parsed[nparsed].long_flag, LONG_FLAG);\
		parsed[nparsed].argument[0] = '\0';\
		nparsed += 1;\
	} while (0)


#define LONG_WITH_ARG(LONG_FLAG)\
	do {\
		char *arg__;\
		assert(nparsed < sizeof(parsed) / sizeof(*parsed));\
		assert(FLAG() == LONG_FLAG[1]);\
		assert(!strcmp(LFLAG(), LONG_FLAG) || !strncmp(LFLAG(), LONG_FLAG"=", sizeof(LONG_FLAG"=")));\
		parsed[nparsed].short_used = 0;\
		parsed[nparsed].long_used = 1;\
		parsed[nparsed].have_arg = 1;\
		parsed[nparsed].short_flag[0] = '\0';\
		parsed[nparsed].short_flag[1] = '\0';\
		parsed[nparsed].short_flag[2] = '\0';\
		stpcpy(parsed[nparsed].long_flag, LONG_FLAG);\
		assert(strlen(ARG()) < sizeof(parsed[nparsed].argument));\
		assert((arg__ = ARG()));\
		assert(arg__ == ARGNULL());\
		stpcpy(parsed[nparsed].argument, ARG());\
		nparsed += 1;\
	} while (0)


#define LONG_WITH_MISSING_ARG(LONG_FLAG)\
	do {\
		assert_unreached();\
	} while (0)


#define ASSERT_ENTRY(SHORT_FLAG, LONG_FLAG, ARGUMENT)\
	do {\
		const char *volatile short_flag__ = (SHORT_FLAG);\
		const char *volatile long_flag__  = (LONG_FLAG);\
		const char *volatile argument__   = (ARGUMENT);\
		assert(parsedi < nparsed);\
		assert(parsed[parsedi].short_used == !!short_flag__);\
		if (short_flag__) assert(!strcmp(parsed[parsedi].short_flag, short_flag__));\
		assert(parsed[parsedi].long_used == !!long_flag__);\
		if (long_flag__) assert(!strcmp(parsed[parsedi].long_flag, long_flag__));\
		assert(parsed[parsedi].have_arg == !!argument__);\
		if (argument__) assert(!strcmp(parsed[parsedi].argument, argument__));\
		parsedi += 1;\
	} while (0)


#define ASSERT_END()\
	do {\
		assert(parsedi == nparsed);\
		parsedi = 0;\
	} while (0)


struct entry {
	char short_used;
	char long_used;
	char have_arg;
	char short_flag[3];
	char long_flag[256];
	char argument[256];
};


static struct entry parsed[100];
static size_t nparsed = 0;
static size_t parsedi = 0;
static jmp_buf usage_jmp;
extern char *argv0_1;
extern char *argv0_2;
extern char *argv0_3;
extern char *argv0_0;


#define usage usage1
#define argv0 argv0_1
USAGE("-1");
#undef usage
#undef argv0

#define usage usage2
#define argv0 argv0_2
NUSAGE(2, "-2");
#undef usage
#undef argv0

#define usage usage3
#define argv0 argv0_3
NUSAGE(3, "");
#undef usage
#undef argv0

#define usage usage0
#define argv0 argv0_0
NUSAGE(0, NULL);
#undef usage
#undef argv0


#define apply(...) apply_(__VA_ARGS__, NULL)
static int
apply_(int (*func)(int argc, char *argv[]), ...)
{
	va_list ap;
	char **argv, **old_argv;
	const char *arg;
	size_t argc = 0, i;
	int ret;

	va_start(ap, func);
	while (va_arg(ap, const char *))
		argc += 1;
	va_end(ap);
	assert((argv = calloc(argc + 1, sizeof(*argv))));
	assert((old_argv = calloc(argc + 1, sizeof(*argv))));
	va_start(ap, func);
	for (i = 0; i < argc; i++) {
		assert((arg = va_arg(ap, const char *)));
		assert((argv[i] = strdup(arg)));
	}
	va_end(ap);
	memcpy(old_argv, argv, (argc + 1) * sizeof(*argv));

	if (setjmp(usage_jmp)) {
		ret = -1;
		goto out;
	}

	nparsed = 0;
	argv0 = NULL;
	ret = func((int)argc, argv);
out:
	va_start(ap, func);
	for (i = 0; i < argc - (size_t)ret; i++) {
		va_arg(ap, const char *);
		free(old_argv[i]);
	}
	for (; i < argc; i++) {
		assert(argv[i] == old_argv[i]);
		assert(!strcmp(argv[i], va_arg(ap, const char *)));
		free(old_argv[i]);
	}
	va_end(ap);
	free(argv);
	free(old_argv);
	return ret;
}


static void
usage(void)
{
	longjmp(usage_jmp, 1);
}


static int
parser1(int argc, char *argv[])
{
	PARSER_BEGIN {
		ARGBEGIN {
		case 'a': SHORT_WITHOUT_ARG("-a"); break;
		case 'b': SHORT_WITHOUT_ARG("-b"); break;
		case 'c': SHORT_WITHOUT_ARG("-c"); break;
		case 'd': SHORT_WITHOUT_ARG("-d"); break;
		case 'e': SHORT_WITHOUT_ARG("-e"); break;
		case 'A': SHORT_WITHOUT_ARG("-A"); break;
		case 'B': SHORT_WITHOUT_ARG("-B"); break;
		case 'C': SHORT_WITHOUT_ARG("-C"); break;
		case 'D': SHORT_WITHOUT_ARG("-D"); break;
		case 'E': SHORT_WITHOUT_ARG("-E"); break;
		case 'x': SHORT_WITH_ARG("-x"); break;
		case 'y': SHORT_WITH_ARG("-y"); break;
		case 'z': SHORT_WITH_ARG("-z"); break;
		case 'X': SHORT_WITH_ARG("-X"); break;
		case 'Y': SHORT_WITH_ARG("-Y"); break;
		case 'Z': SHORT_WITH_ARG("-Z"); break;
		case '-': SHORT_WITHOUT_ARG("--"); break;
		case ARGNUM: SHORT_WITH_ARGHERE("-#"); break;
		case '@': SHORT_WITH_MISSING_ARG("-@"); break;
		default:
		usage();
		} ARGEND;
	} PARSER_END;
}


static int
parser2(int argc, char *argv[])
{
	PARSER_BEGIN {
		SUBARGBEGIN {
		case 'a': SHORT_WITHOUT_ARG("-a"); break;
		case 'b': SHORT_WITHOUT_ARG("-b"); break;
		case 'c': SHORT_WITHOUT_ARG("-c"); break;
		case 'd': SHORT_WITHOUT_ARG("-d"); break;
		case 'e': SHORT_WITHOUT_ARG("-e"); break;
		case 'A': SHORT_WITHOUT_ARG("-A"); break;
		case 'B': SHORT_WITHOUT_ARG("-B"); break;
		case 'C': SHORT_WITHOUT_ARG("-C"); break;
		case 'D': SHORT_WITHOUT_ARG("-D"); break;
		case 'E': SHORT_WITHOUT_ARG("-E"); break;
		case 'x': SHORT_WITH_ARG("-x"); break;
		case 'y': SHORT_WITH_ARG("-y"); break;
		case 'z': SHORT_WITH_ARG("-z"); break;
		case 'X': SHORT_WITH_ARG("-X"); break;
		case 'Y': SHORT_WITH_ARG("-Y"); break;
		case 'Z': SHORT_WITH_ARG("-Z"); break;
		case '-': SHORT_WITHOUT_ARG("--"); break;
		case ARGNUM: SHORT_WITH_ARGHERE("-#"); break;
		case '@': SHORT_WITH_MISSING_ARG("-@"); break;
		default:
			usage();
		} ARGEND;
	} PARSER_END_NO_ARGV0;
}


static int
parser3(int argc, char *argv[])
{
	PARSER_BEGIN {
		NOFLAGS(0);
	} PARSER_END;
}


static int
parser4(int argc, char *argv[])
{
	PARSER_BEGIN {
		NOFLAGS(argc);
	} PARSER_END;
}


static int
parser5(int argc, char *argv[])
{
	PARSER_BEGIN {
		ARGBEGIN {
		case 'a': SHORT_WITHOUT_ARG("-a"); break;
		case 'x': SHORT_WITHOUT_ARG("-x"); break;
		case '-': SHORT_WITHOUT_ARG("--"); break;
		default:
			usage();
		} ARGALT('+') {
		case 'a': SHORT_WITHOUT_ARG("+a"); break;
		case 'y': SHORT_WITHOUT_ARG("+y"); break;
		case '+': SHORT_WITHOUT_ARG("++"); break;
		default:
			usage();
		} ARGALT('/') {
		case 'a': SHORT_WITHOUT_ARG("/a"); break;
		case 'z': SHORT_WITHOUT_ARG("/z"); break;
		case '/': SHORT_WITHOUT_ARG("//"); break;
		default:
			usage();
		} ARGALT('x') {
		case 'a': SHORT_WITHOUT_ARG("xa"); break;
		case 'b': SHORT_WITHOUT_ARG("xb"); break;
		case 'x': SHORT_WITHOUT_ARG("xx"); break;
		default:
			usage();
		} ARGEND;
	} PARSER_END;
}


static int
parser6(int argc, char *argv[])
{
	PARSER_BEGIN {
		ARGBEGIN2(1, 1) {
		default:
			assert(ARGHERE() == &LFLAG()[1]);
			argv[0] = LFLAG();
			goto stop;
		} ARGALT('+') {
		case 'a': SHORT_WITHOUT_ARG("+a"); break;
		case 'b': SHORT_WITHOUT_ARG("+b"); break;
		case 'c': SHORT_WITHOUT_ARG("+c"); break;
		case 'd': SHORT_WITHOUT_ARG("+d"); break;
		case 'e': SHORT_WITHOUT_ARG("+e"); break;
		case 'A': SHORT_WITHOUT_ARG("+A"); break;
		case 'B': SHORT_WITHOUT_ARG("+B"); break;
		case 'C': SHORT_WITHOUT_ARG("+C"); break;
		case 'D': SHORT_WITHOUT_ARG("+D"); break;
		case 'E': SHORT_WITHOUT_ARG("+E"); break;
		case 'x': SHORT_WITH_ARG("+x"); break;
		case 'y': SHORT_WITH_ARG("+y"); break;
		case 'z': SHORT_WITH_ARG("+z"); break;
		case 'X': SHORT_WITH_ARG("+X"); break;
		case 'Y': SHORT_WITH_ARG("+Y"); break;
		case 'Z': SHORT_WITH_ARG("+Z"); break;
		case '+': SHORT_WITHOUT_ARG("++"); break;
		case ARGNUM: SHORT_WITH_ARGHERE("+#"); break;
		case '@': SHORT_WITH_MISSING_ARG("+@"); break;
		default:
			usage();
		} ARGEND;
	stop:;
	} PARSER_END;
}


static int
parser7(int argc, char *argv[])
{
	PARSER_BEGIN {
		ARGBEGIN {
		case '-':
			if (TESTLONG("--alpha", 0))
				LONG_WITHOUT_ARG("--alpha");
			else if (TESTLONG("--alpha=", 0))
				LONG_WITHOUT_ARG("--alpha=");
			else if (TESTLONG("--beta", 1))
				LONG_WITH_ARG("--beta");
			else if (TESTLONG("--gamma=", 1))
				LONG_WITH_ARG("--gamma");
			else if (TESTLONG("--gamma", 0))
				LONG_WITHOUT_ARG("--gamma");
			else if (TESTLONG("--missing", 1))
				LONG_WITH_MISSING_ARG("--missing");
			else
				usage();
			break;
		default:
			usage();
		} ARGALT('+') {
		case '+':
			if (TESTLONG("++alpha", 0))
				LONG_WITHOUT_ARG("++alpha");
			else if (TESTLONG("++alpha=", 0))
				LONG_WITHOUT_ARG("++alpha=");
			else if (TESTLONG("++beta", 1))
				LONG_WITH_ARG("++beta");
			else if (TESTLONG("++gamma=", 1))
				LONG_WITH_ARG("++gamma");
			else if (TESTLONG("++gamma", 0))
				LONG_WITHOUT_ARG("++gamma");
			else if (TESTLONG("++missing", 1))
				LONG_WITH_MISSING_ARG("++missing");
			else
				usage();
			break;
		default:
			usage();
		} ARGEND;
	} PARSER_END;
}


static int
parser8(int argc, char *argv[])
{
	PARSER_BEGIN {
		ARGBEGIN {
		case 'a': SHORT_WITHOUT_ARG("-a"); break;
		case 'A': SHORT_WITHOUT_ARG("-A"); break;
		case 'b': SHORT_WITH_ARG("-b"); break;
		case 'g': SHORT_WITH_ARG("-g"); break;
		case 'G': SHORT_WITHOUT_ARG("-G"); break;
		case 'm': SHORT_WITH_MISSING_ARG("-m"); break;
		case '-':
			ARGMAPLONG(((struct longopt []){
				{"--alpha", 'a', 0},
				{"--alpha=", 'A', 0},
				{"--beta", 'b', 1},
				{"--gamma=", 'g', 1},
				{"--gamma", 'G', 0},
				{"--missing", 'm', 1},
				{NULL, '\0', 0},
			}));
			/* fall through */
		default:
			usage();
		} ARGALT('+') {
		case 'a': SHORT_WITHOUT_ARG("+a"); break;
		case 'A': SHORT_WITHOUT_ARG("+A"); break;
		case 'b': SHORT_WITH_ARG("+b"); break;
		case 'g': SHORT_WITH_ARG("+g"); break;
		case 'G': SHORT_WITHOUT_ARG("+G"); break;
		case 'm': SHORT_WITH_MISSING_ARG("+m"); break;
		case '+':
			ARGMAPLONG(((struct longopt []){
				{"++alpha", 'a', 0},
				{"++alpha=", 'A', 0},
				{"++beta", 'b', 1},
				{"++gamma=", 'g', 1},
				{"++gamma", 'G', 0},
				{"++missing", 'm', 1},
				{NULL, '\0', 0},
			}));
			/* fall through */
		default:
			usage();
		} ARGEND;
	} PARSER_END;
}


int
main(void)
{
	char buf[10];
	const char *a1;
	size_t i;

	assert(apply(parser1) == 0);
	ASSERT_END();

	assert(apply(parser1, "-a") == 0);
	ASSERT_END();

	assert(apply(parser1, "-a", "-a", "-o") == -1);
	ASSERT_ENTRY("-a", NULL, NULL);
	ASSERT_END();

	assert(apply(parser1, "-a", "-a", "-Y") == -1);
	ASSERT_ENTRY("-a", NULL, NULL);
	ASSERT_END();

	for (i = 0; i < 5; i++) {
		a1 = ((const char *[]){"--", "z", "-", "", "+a"})[i];
		assert(apply(parser1, "argv[0]", "-abdexhello world", "-x", "hi", "-y", "-Y", a1, "-Z", "z") == 2 + !!i);
		ASSERT_ENTRY("-a", NULL, NULL);
		ASSERT_ENTRY("-b", NULL, NULL);
		ASSERT_ENTRY("-d", NULL, NULL);
		ASSERT_ENTRY("-e", NULL, NULL);
		ASSERT_ENTRY("-x", NULL, "hello world");
		ASSERT_ENTRY("-x", NULL, "hi");
		ASSERT_ENTRY("-y", NULL, "-Y");
		ASSERT_END();
	}

	assert(apply(parser1, "", "-a1000", "-200") == 0);
	ASSERT_ENTRY("-a", NULL, NULL);
	ASSERT_ENTRY("-#", NULL, "1000");
	ASSERT_ENTRY("-#", NULL, "200");
	ASSERT_END();

	assert(apply(parser1, "", "-a", "-@") == -1);
	ASSERT_ENTRY("-a", NULL, NULL);
	ASSERT_END();

	assert(apply(parser1, "", "-a-") == -1);
	ASSERT_ENTRY("-a", NULL, NULL);
	ASSERT_END();

	for (i = 0; i < 5; i++) {
		a1 = ((const char *[]){"--", "z", "-", "", "+a"})[i];
		assert(apply(parser2, "-abdexhello world", "-x", "hi", "-y", "-Y", a1, "-Z", "z") == 2 + !!i);
		ASSERT_ENTRY("-a", NULL, NULL);
		ASSERT_ENTRY("-b", NULL, NULL);
		ASSERT_ENTRY("-d", NULL, NULL);
		ASSERT_ENTRY("-e", NULL, NULL);
		ASSERT_ENTRY("-x", NULL, "hello world");
		ASSERT_ENTRY("-x", NULL, "hi");
		ASSERT_ENTRY("-y", NULL, "-Y");
		ASSERT_END();
	}

	assert(apply(parser3, "x") == 0);               ASSERT_END();
	assert(apply(parser3, "y", "z") == 1);          ASSERT_END();
	assert(apply(parser3, "x", "z", "-a") == 2);    ASSERT_END();
	assert(apply(parser3, "y", "-z", "a") == -1);   ASSERT_END();
	assert(apply(parser3, "x", "--", "-a") == 1);   ASSERT_END();
	assert(apply(parser3, "", "--") == 0);          ASSERT_END();
	assert(apply(parser3, "-", "--x") == -1);       ASSERT_END();
	assert(apply(parser3, "", "+") == 1);           ASSERT_END();
	assert(apply(parser3, "-", "") == 1);           ASSERT_END();
	assert(apply(parser3, "", "-") == 1);           ASSERT_END();

	assert(apply(parser4, "x") == 0);               ASSERT_END();
	assert(apply(parser4, "y", "z") == -1);         ASSERT_END();
	assert(apply(parser4, "", "z", "-a") == -1);    ASSERT_END();
	assert(apply(parser4, "-", "-z", "a") == -1);   ASSERT_END();
	assert(apply(parser4, "", "--", "-a") == -1);   ASSERT_END();
	assert(apply(parser4, "-", "--") == 0);         ASSERT_END();
	assert(apply(parser4, "", "--x") == -1);        ASSERT_END();
	assert(apply(parser4, "-", "+") == -1);         ASSERT_END();
	assert(apply(parser4, "", "") == -1);           ASSERT_END();
	assert(apply(parser4, "-", "-") == -1);         ASSERT_END();

	for (i = 0; i < 4; i++) {
		a1 = ((const char *[]){"--", "++", "//", "xx"})[i];
		assert(apply(parser5, "<>", "-a", "+a", "/a", "xa", "-x", "+y", "/z", "xb", a1, "yy") == 1 + !!i);
		ASSERT_ENTRY("-a", NULL, NULL);
		ASSERT_ENTRY("+a", NULL, NULL);
		ASSERT_ENTRY("/a", NULL, NULL);
		ASSERT_ENTRY("xa", NULL, NULL);
		ASSERT_ENTRY("-x", NULL, NULL);
		ASSERT_ENTRY("+y", NULL, NULL);
		ASSERT_ENTRY("/z", NULL, NULL);
		ASSERT_ENTRY("xb", NULL, NULL);
		ASSERT_END();
	}

	assert(apply(parser5, "<>", "-y") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "-z") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "-b") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "+x") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "+z") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "+b") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "/x") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "/y") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "/b") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "xy") == -1);  ASSERT_END();
	assert(apply(parser5, "<>", "xz") == -1);  ASSERT_END();

	for (i = 0; i < 6; i++) {
		a1 = ((const char *[]){"++", "z", "+", "", "-a", "--"})[i];
		assert(apply(parser6, "0", "+abdexhello world", "+x", "hi", "+y", "+Y", a1, "+Z", "z") == 3);
		ASSERT_ENTRY("+a", NULL, NULL);
		ASSERT_ENTRY("+b", NULL, NULL);
		ASSERT_ENTRY("+d", NULL, NULL);
		ASSERT_ENTRY("+e", NULL, NULL);
		ASSERT_ENTRY("+x", NULL, "hello world");
		ASSERT_ENTRY("+x", NULL, "hi");
		ASSERT_ENTRY("+y", NULL, "+Y");
		ASSERT_END();
	}

	assert(apply(parser7, "", "--alpha", "++alpha", "--alpha=", "++alpha=", "--missing") == -1);
	ASSERT_ENTRY(NULL, "--alpha", NULL);
	ASSERT_ENTRY(NULL, "++alpha", NULL);
	ASSERT_ENTRY(NULL, "--alpha=", NULL);
	ASSERT_ENTRY(NULL, "++alpha=", NULL);
	ASSERT_END();

	assert(apply(parser7, "", "++alpha", "--alpha", "++alpha=", "--alpha=", "++missing") == -1);
	ASSERT_ENTRY(NULL, "++alpha", NULL);
	ASSERT_ENTRY(NULL, "--alpha", NULL);
	ASSERT_ENTRY(NULL, "++alpha=", NULL);
	ASSERT_ENTRY(NULL, "--alpha=", NULL);
	ASSERT_END();

	assert(apply(parser7, "", "--beta", "abc", "--beta=xyz", "--betax") == -1);
	ASSERT_ENTRY(NULL, "--beta", "abc");
	ASSERT_ENTRY(NULL, "--beta", "xyz");
	ASSERT_END();

	assert(apply(parser7, "", "++beta", "abc", "++beta=xyz", "++betax") == -1);
	ASSERT_ENTRY(NULL, "++beta", "abc");
	ASSERT_ENTRY(NULL, "++beta", "xyz");
	ASSERT_END();

	assert(apply(parser7, "", "--gamma=123", "--gamma=", "--gamma", "789") == 1);
	ASSERT_ENTRY(NULL, "--gamma", "123");
	ASSERT_ENTRY(NULL, "--gamma", "");
	ASSERT_ENTRY(NULL, "--gamma", NULL);
	ASSERT_END();

	assert(apply(parser7, "", "++gamma=123", "++gamma=", "++gamma", "789") == 1);
	ASSERT_ENTRY(NULL, "++gamma", "123");
	ASSERT_ENTRY(NULL, "++gamma", "");
	ASSERT_ENTRY(NULL, "++gamma", NULL);
	ASSERT_END();

	assert(apply(parser8, "", "--alpha", "++alpha", "--alpha=", "++alpha=", "--missing") == -1);
	ASSERT_ENTRY("-a", NULL, NULL);
	ASSERT_ENTRY("+a", NULL, NULL);
	ASSERT_ENTRY("-A", NULL, NULL);
	ASSERT_ENTRY("+A", NULL, NULL);
	ASSERT_END();

	assert(apply(parser8, "", "++alpha", "--alpha", "++alpha=", "--alpha=", "++missing") == -1);
	ASSERT_ENTRY("+a", NULL, NULL);
	ASSERT_ENTRY("-a", NULL, NULL);
	ASSERT_ENTRY("+A", NULL, NULL);
	ASSERT_ENTRY("-A", NULL, NULL);
	ASSERT_END();

	assert(apply(parser8, "", "--beta", "abc", "--beta=xyz", "--betax") == -1);
	ASSERT_ENTRY("-b", NULL, "abc");
	ASSERT_ENTRY("-b", NULL, "xyz");
	ASSERT_END();

	assert(apply(parser8, "", "++beta", "abc", "++beta=xyz", "++betax") == -1);
	ASSERT_ENTRY("+b", NULL, "abc");
	ASSERT_ENTRY("+b", NULL, "xyz");
	ASSERT_END();

	assert(apply(parser8, "", "--gamma=123", "--gamma=", "--gamma", "789") == 1);
	ASSERT_ENTRY("-g", NULL, "123");
	ASSERT_ENTRY("-g", NULL, "");
	ASSERT_ENTRY("-G", NULL, NULL);
	ASSERT_END();

	assert(apply(parser8, "", "++gamma=123", "++gamma=", "++gamma", "789") == 1);
	ASSERT_ENTRY("+g", NULL, "123");
	ASSERT_ENTRY("+g", NULL, "");
	ASSERT_ENTRY("+G", NULL, NULL);
	ASSERT_END();

	argv0_1 = strcpy(buf, "[1]");
	assert_exit(usage1());
	assert(exit_status == 1);
	assert_stderr("usage: [1] -1\n");

	argv0_2 = strcpy(buf, "[2]");
	assert_exit(usage2());
	assert_stderr("usage: [2] -2\n");
	assert(exit_status == 2);

	argv0_3 = strcpy(buf, "[3]");
	assert_exit(usage3());
	assert_stderr("usage: [3]\n");
	assert(exit_status == 3);

	argv0_0 = strcpy(buf, "[0]");
	assert_exit(usage0());
	assert_stderr("usage: [0]\n");
	assert(exit_status == 0);

	return 0;
}
