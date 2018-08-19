/* See LICENSE file for copyright and license details. */


#define assert(EXPR)\
	do {\
		if (EXPR)\
			break;\
		fprintf(stderr, "Failed at %s:%i: %s\n", __FILE__, __LINE__, #EXPR);\
		exit(1);\
	} while (0)
