/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


char *
libsimple_enstrdup(int status, const char *s)
{
	size_t n = strlen(s) + 1;
	char *ret = aligned_alloc(1, n);
	if (!ret)
		enprintf(status, "strdup:");
	memcpy(ret, s, n);
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	char *s;

	assert((s = libsimple_enstrdup(1, "hello")));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 1);
		assert(!info->zeroed);
	}
	assert(!strcmp(s, "hello"));
	free(s);

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
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enstrdup(14, "hello"));
		assert(exit_status == 14);
		assert_stderr("%s: strdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

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
