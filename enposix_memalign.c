/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void libsimple_enposix_memalign(int, void **, size_t, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr = NULL;

	libsimple_enposix_memalign(1, &ptr, sizeof(void *), 8);
	assert(ptr);
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 8);
		assert(info->alignment == sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit(libsimple_enposix_memalign(7, &ptr, sizeof(void *), 4));
		assert(exit_status == 7);
		assert_stderr("%s: posix_memalign: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

	}

	return 0;
}

#endif
