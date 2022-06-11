/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_envallocz(int, int, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *volatile info;
	void *ptr;
	DEFINE_PAGESIZE;
	DEFINE_CACHELINE;

	assert((ptr = libsimple_envallocz(1, 1, 5 * pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 * pagesize - 1);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_envallocz(1, 0, pagesize - 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == pagesize - 1);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_envallocz(3, 1, 4));
		assert(exit_status == 3);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_envallocz(5, 0, 4));
		assert(exit_status == 5);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

	return 0;
}

#endif
