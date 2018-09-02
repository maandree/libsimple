/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


void *
libsimple_envreallocn(int status, void *ptr, size_t n, va_list ap)
{
	void *ret = libsimple_vreallocn(ptr, n, ap);
	if (!ret)
		enprintf(status, "realloc:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr, *old;

	assert((ptr = libsimple_enreallocn(1, NULL, 5, 3, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 15);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_enreallocn(1, old = ptr, 10, 2, 0)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 20);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		assert(ptr != old);
		free(old);
	}
	free(ptr);

	assert((ptr = libsimple_ereallocn(NULL, 5, 4, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 20);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_ereallocn(old = ptr, 10, 11, 0)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 110);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		assert(ptr != old);
		free(old);
	}
	free(ptr);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enreallocn(2, NULL, 1, 0));
		assert(exit_status == 2);
		assert_stderr("%s: realloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 104;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ereallocn(NULL, 1, 0));
		assert(exit_status == 104);
		assert_stderr("%s: realloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

	return 0;
}

#endif
