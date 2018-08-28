/* See LICENSE file for copyright and license details. */


#define assert(EXPR)\
	do {\
		if (EXPR)\
			break;\
		fprintf(stderr, "Failed at %s:%i: %s\n", __FILE__, __LINE__, #EXPR);\
		exit(1);\
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


size_t get_pagesize(void);
size_t round_up(size_t);
int have_custom_malloc(void); /* return 0 if run under valgrind(1) */
struct allocinfo *get_allocinfo(void *);
