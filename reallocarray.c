/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_reallocarray(void *, size_t, size_t);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr, *old;

	assert((ptr = libsimple_reallocarray(NULL, 1, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_reallocarray(old = ptr, 10, 10)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 100);
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
		assert(ptr != old);
		free(old);
	}
	free(ptr);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert(!libsimple_reallocarray(NULL, 1, 1) && errno == ENOMEM);
		assert(!alloc_fail_in);
	}

#if defined(__GNUC__) && !defined(__clang)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Walloc-size-larger-than="
#endif

	assert(!libsimple_reallocarray(NULL, SIZE_MAX, SIZE_MAX) && errno == ENOMEM);

#if defined(__GNUC__) && !defined(__clang)
# pragma GCC diagnostic pop
#endif

	return 0;
}

#endif
