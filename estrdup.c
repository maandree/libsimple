/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline char *libsimple_estrdup(const char *);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	char *s;

	assert((s = libsimple_estrdup("test")));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 5);
		assert(info->alignment == 1);
		assert(!info->zeroed);
	}
	assert(!strcmp(s, "test"));
	free(s);

	if (have_custom_malloc()) {
		libsimple_default_failure_exit = 15;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_estrdup("test"));
		assert(exit_status == 15);
		assert_stderr("%s: strdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
