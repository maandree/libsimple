/* See LICENSE file for copyright and license details. */
#include "libsimple.h"
#ifndef TEST


extern inline void *libsimple_reallocn(void *, size_t, ...);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr, *old;

	assert(!libsimple_reallocn(NULL, 0) && errno == EINVAL);
	errno = 0;

	assert(!libsimple_reallocn(NULL, SIZE_MAX, 2, 0) && errno == ENOMEM);
	errno = 0;

	assert((ptr = libsimple_reallocn(NULL, 5, 0)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5);
		assert(!info->zeroed);
		info->refcount += 1;
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_reallocn(old = ptr, 10, 0)));
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

	assert(!errno);

	return 0;
}

#endif
