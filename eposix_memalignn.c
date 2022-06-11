/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void libsimple_eposix_memalignn(void **, size_t, size_t, ...);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr = NULL;

	libsimple_eposix_memalignn(&ptr, 2 * sizeof(void *), 2, 4, 3, 0);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 24);
		assert(info->alignment == 2 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		libsimple_default_failure_exit = 29;
		assert_exit(libsimple_eposix_memalignn(&ptr, sizeof(void *), 1, 0));
		assert(exit_status == 29);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	libsimple_default_failure_exit = 39;
	assert_exit(libsimple_eposix_memalignn(&ptr, sizeof(void *), SIZE_MAX, 2, 0));
	assert(exit_status == 39);
	assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));

	return 0;
}

#endif
