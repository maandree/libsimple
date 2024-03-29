/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_enmemdup(int status, const void *s, size_t n)
{
	void *ret = memdup(s, n);
	if (!ret)
		enprintf(status, "memdup:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *s;

	assert((s = libsimple_enmemdup(1, "hello", 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(s)));
		assert(info->size == 5);
		assert(!info->zeroed);
	}
	assert(!memcmp(s, "hello", 5));
	free(s);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enmemdup(44, "hello", 2));
		assert(exit_status == 44);
		assert_stderr("%s: memdup: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
