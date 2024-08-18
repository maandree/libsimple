/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


extern inline int libsimple_posix_memalignn(void **, size_t, size_t, ...);


#else
#include "test.h"

int
main(void)
{
	struct allocinfo *info;
	void *ptr;

	assert(libsimple_posix_memalignn(&ptr, 128, 0) == EINVAL && !errno);

	assert(libsimple_posix_memalignn(&ptr, 1024, SIZE_MAX, 2, 0) == ENOMEM && !errno);

	assert(!libsimple_posix_memalignn(&ptr, 2 * sizeof(void *), 12, 12, 3, 0));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 432);
		assert(info->alignment == 2 * sizeof(void *));
		assert(!info->zeroed);
		assert(!((uintptr_t)ptr % (uintptr_t)(info->alignment)));
	}
	free(ptr);

	assert(!errno);

	return 0;
}

#endif
