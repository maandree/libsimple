/* See LICENSE file for copyright and license details. */


#define assert(EXPR)\
	do {\
		if (EXPR)\
			break;\
		fprintf(stderr, "Failed at %s:%i: %s\n", __FILE__, __LINE__, #EXPR);\
		exit(1);\
	} while (0)



#define strcmp(...) test_strcmp(__VA_ARGS__)
static inline int
test_strcmp(const char *a, const char *b)
{
	return (!a || !b) ? !b - !a : (strcmp)(a, b);
}
