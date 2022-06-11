/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void libsimple_eposix_memalign(void **, size_t, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr = NULL;

	libsimple_eposix_memalign(&ptr, 8 * sizeof(void *), 4);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4);
		assert(info->alignment == 8 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		libsimple_default_failure_exit = 104;
		alloc_fail_in = 1;
		assert_exit(libsimple_eposix_memalign(&ptr, sizeof(void *), 4));
		assert(exit_status == 104);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
