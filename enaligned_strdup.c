/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


char *
libsimple_enaligned_strdup(int status, const char *s, size_t alignment)
{
	void *ret = aligned_strdup(s, alignment);
	if (!ret)
		enprintf(status, "aligned_strdup:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *s;

	assert((s = libsimple_enaligned_strdup(1, "hello", 2)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 6);
		assert(info->alignment == 2);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 6));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_strdup(44, "hello", 2));
		assert(exit_status == 44);
		assert_stderr("%s: aligned_strdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
