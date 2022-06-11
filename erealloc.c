/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_erealloc(void *, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr, *old;

	assert((ptr = libsimple_erealloc(NULL, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_erealloc(old = ptr, 10)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 10);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		assert(ptr != old);
		free(old);
	}
	free(ptr);

	if (have_custom_malloc()) {
		libsimple_default_failure_exit = 104;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_erealloc(NULL, 1));
		assert(exit_status == 104);
		assert_stderr("%s: realloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
