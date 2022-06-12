/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_enreallocarray(int status, void *ptr, size_t n, size_t m)
{
	void *ret = reallocarray(ptr, n, m);
	if (!ret)
		enprintf(status, "reallocarray:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr, *old;

	assert((ptr = libsimple_enreallocarray(1, NULL, 5, 3)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 15);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_enreallocarray(1, old = ptr, 10, 2)));
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

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enreallocarray(2, NULL, 1, 1));
		assert(exit_status == 2);
		assert_stderr("%s: reallocarray: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
	}

#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Walloc-size-larger-than="
#endif

	assert_exit_ptr(libsimple_enreallocarray(3, NULL, SIZE_MAX, SIZE_MAX));
	assert(exit_status == 3);
	assert_stderr("%s: reallocarray: %s\n", argv0, strerror(ENOMEM));

#if defined(__GNUC__) && !defined(__clang__)
# pragma GCC diagnostic pop
#endif

	return 0;
}

#endif
