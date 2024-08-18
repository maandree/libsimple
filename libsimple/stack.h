/* See LICENSE file for copyright and license details. */


int libsimple_get_stack_space(uintptr_t *restrict, uintptr_t *restrict); /* TODO man, doc (since 1.7) */
int libsimple_get_stack_limit(size_t *restrict, size_t *restrict); /* TODO man, doc (since 1.7) */
int libsimple_get_stack_direction(void); /* TODO man, doc (since 1.7) */

int libsimple_needstack(size_t); /* TODO man, doc (since 1.7) */
#ifndef needstack
# define needstack libsimple_needstack
#endif
