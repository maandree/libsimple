/* See LICENSE file for copyright and license details. */


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
		len__ = sprintf(buf__, __VA_ARGS__);\
		assert(len__ >= 0);\
		assert((size_t)len__ == stderr_n);\
		assert(!memcmp(buf__, (char **)(void *)(&stderr_buf), stderr_n)); \
	} while (0);


struct allocinfo {
	void *real_beginning;
	size_t real_size;
	size_t size;
	size_t extent;
	size_t alignment;
	size_t zeroed;
	size_t refcount;
};


extern char *argv0;

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
