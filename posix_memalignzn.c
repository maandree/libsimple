/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_posix_memalignzn(void **, int, size_t, size_t, ...);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr;

	assert(libsimple_posix_memalignzn(&ptr, 0, 128, 0) == EINVAL && !errno);
	assert(libsimple_posix_memalignzn(&ptr, 1, 128, 0) == EINVAL && !errno);

	assert(libsimple_posix_memalignzn(&ptr, 0, 1024, SIZE_MAX, 2, 0) == ENOMEM && !errno);
	assert(libsimple_posix_memalignzn(&ptr, 1, 1024, SIZE_MAX, 2, 0) == ENOMEM && !errno);

	assert(!libsimple_posix_memalignzn(&ptr, 0, sizeof(void *), 12, 12, 0));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 144);
		assert(info->alignment == sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert(!libsimple_posix_memalignzn(&ptr, 1, 2 * sizeof(void *), 12, 12, 2, 0));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 288);
		assert(info->alignment == 2 * sizeof(void *));
		assert(info->zeroed == 288);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert(!errno);

	return 0;
}

#endif
