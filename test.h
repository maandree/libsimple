/* See LICENSE file for copyright and license details. */


#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic ignored "-Wunsuffixed-float-constants"
# pragma GCC diagnostic ignored "-Wformat-nonliteral"
#endif

#if defined(__clang__)
# pragma clang diagnostic ignored "-Wformat-nonliteral"
# pragma clang diagnostic ignored "-Wdisabled-macro-expansion"
# pragma clang diagnostic ignored "-Walloca"
#endif


#define assert(EXPR)\
	do {\
		if (EXPR)\
			break;\
		stderr_real = 1;\
		fprintf(stderr, "Failed at %s:%i: %s\n", __FILE__, __LINE__, #EXPR);\
		exit_real = 1;\
		exit(1);\
	} while (0)

#define subassert(EXPR)\
	do {\
		if (EXPR)\
			break;\
		stderr_real = 1;\
		fprintf(stderr, "Failed at %s:%i: %s\n", __FILE__, __LINE__, #EXPR);\
		return 0;\
	} while (0)

#define assert_unreached()\
	assert(*&(volatile int *){0})

#define assert_exit(EXPR)\
	do {\
		volatile int old_stderr_ok__ = stderr_ok;\
		exit_ok = 1;\
		stderr_ok = 1;\
		stderr_n = 0;\
		if (setjmp(exit_jmp)) {\
			exit_ok = 0;\
			stderr_ok = old_stderr_ok__;\
			break;\
		}\
		EXPR;\
		assert_unreached();\
	} while (0)

#define assert_exit_ptr(EXPR)\
	do {\
		void *volatile ptr__;\
		assert_exit((void)(ptr__ = (EXPR)));\
	} while (0)

#define assert_stderr(...)\
	do {\
		char buf__[1024];\
		int len__;\
		size_t i__;\
		int not_same__ = 0;\
		len__ = sprintf(buf__, __VA_ARGS__);\
		assert(len__ >= 0);\
		assert((size_t)len__ == stderr_n);\
		for (i__ = 0; i__ < stderr_n; i__++)\
			not_same__ |= buf__[i__] ^ stderr_buf[i__];\
		assert(!not_same__);\
	} while (0)


struct allocinfo {
	void *real_beginning;
	size_t real_size;
	size_t size;
	size_t extent;
	size_t alignment;
	size_t zeroed;
	size_t refcount;
};


#ifndef LIBSIMPLE_ARG_H
extern char *argv0;
#endif

extern volatile size_t alloc_fail_in;
extern volatile int exit_real;
extern volatile int exit_ok;
extern volatile int exit_status;
extern jmp_buf exit_jmp;
extern volatile char stderr_buf[8 << 10];
extern volatile size_t stderr_n;
extern volatile int stderr_real;
extern volatile int stderr_ok;


size_t get_pagesize(void);
size_t round_up(size_t);
int have_custom_malloc(void); /* return 0 if run under valgrind(1) */
struct allocinfo *get_allocinfo(void *);


int test_vfprintf(FILE *restrict stream, const char *restrict format, va_list ap);

static inline int
test_fprintf(FILE *restrict stream, const char *restrict format, ...)
{
	va_list ap;
	va_start(ap, format);
	return test_vfprintf(stream, format, ap);
	va_end(ap);
}



#if defined(__GNUC__)
__attribute__((__const__))
#endif
static size_t
gcd(size_t u, size_t v)
{
	size_t t;
	int shift = 0;
	/* Not needed because u>0, v>0: if (!(u | v)) return u + v; */
	while (!((u | v) & 1)) {
		u >>= 1;
		v >>= 1;
		shift++;
	}
	while (!(u & 1)) {
		u >>= 1;
	}
	do {
		while (!(v & 1)) {
			v >>= 1;
		}
		if (u > v) {
			t = u;
			u = v;
			v = t;
		}
	} while (v -= u);
	return u << shift;
}

static inline size_t
lcm(size_t u, size_t v)
{
	return u / gcd(u, v) * v;
}

#define ASSERT_ALIGNMENT(INFO, ALIGN)\
	do {\
		assert((INFO)->alignment <= lcm(cacheline, ALIGN));\
		assert(!((INFO)->alignment % (ALIGN)));\
		if ((cacheline - (ALIGN) % cacheline) % cacheline + (INFO)->size % (ALIGN) > cacheline)\
			assert(!((INFO)->alignment % cacheline));\
	} while (0)

#define DEFINE_PAGESIZE size_t pagesize = (size_t)sysconf(_SC_PAGESIZE)

#ifdef _SC_LEVEL1_DCACHE_LINESIZ
#define DEFINE_CACHELINE size_t cacheline = (size_t)sysconf(_SC_LEVEL1_DCACHE_LINESIZE)
#else
#define DEFINE_CACHELINE size_t cacheline = 64
#endif
