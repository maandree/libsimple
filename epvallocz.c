/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_epvallocz(int, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *volatile info;
	void *ptr;
	DEFINE_PAGESIZE;
	DEFINE_CACHELINE;

	assert((ptr = libsimple_epvallocz(1, 3 * pagesize + 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 4 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(info->zeroed == info->size);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	assert((ptr = libsimple_epvallocz(0, pagesize + 1)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 2 * pagesize);
		ASSERT_ALIGNMENT(info, pagesize);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);
	ptr = NULL;

	if (have_custom_malloc()) {
		libsimple_default_failure_exit = 102;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_epvallocz(1, 4));
		assert(exit_status == 102);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;

		libsimple_default_failure_exit = 103;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_epvallocz(0, 4));
		assert(exit_status == 103);
		assert_stderr("%s: libsimple_vmemalloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
