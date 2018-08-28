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


struct allocinfo {
	void *real_beginning;
	size_t real_size;
	size_t size;
	size_t extent;
	size_t alignment;
	size_t zeroed;
	size_t refcount;
};


extern size_t alloc_fail_in;
extern int exit_real;
extern int exit_ok;
extern int exit_status;
extern jmp_buf exit_jmp;
extern char stderr_buf[8 << 10];
extern size_t stderr_n;
extern int stderr_real;


size_t get_pagesize(void);
size_t round_up(size_t);
int have_custom_malloc(void); /* return 0 if run under valgrind(1) */
struct allocinfo *get_allocinfo(void *);
