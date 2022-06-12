/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


void *
libsimple_enaligned_realloc(int status, void *ptr, size_t alignment, size_t n)
{
	void *ret = aligned_realloc(ptr, alignment, n);
	if (!ret)
		enprintf(status, "aligned_realloc:");
	return ret;
}


#else
#include "test.h"

int
main(void)
{
#ifdef LIBSIMPLE_HAVE_ALIGNED_REALLOC

	struct allocinfo *info;
	void *ptr, *old;
	DEFINE_CACHELINE;

	assert((ptr = libsimple_enaligned_realloc(1, NULL, 16, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 || info->size == info->alignment);
		assert(!info->zeroed);
		ASSERT_ALIGNMENT(info, 16);
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_enaligned_realloc(1, old = ptr, 32, 10)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 10 || info->size == info->alignment);
		assert(!info->zeroed);
		ASSERT_ALIGNMENT(info, 32);
		assert(ptr != old);
		free(old);
	}
	free(ptr);

	assert((ptr = libsimple_ealigned_realloc(NULL, 8, 5)));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 5 || info->size == info->alignment);
		assert(!info->zeroed);
		ASSERT_ALIGNMENT(info, 8);
		info->refcount += 1;
	}
	stpcpy(ptr, "test");
	assert((ptr = libsimple_ealigned_realloc(old = ptr, 64, 10)));
	assert(!strcmp(ptr, "test"));
	if (have_custom_malloc()) {
		assert((info = get_allocinfo(ptr)));
		assert(info->size == 10 || info->size == info->alignment);
		assert(!info->zeroed);
		ASSERT_ALIGNMENT(info, 64);
		assert(ptr != old);
		free(old);
	}
	free(ptr);

	if (have_custom_malloc()) {
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_enaligned_realloc(2, NULL, 8, 1));
		assert(exit_status == 2);
		assert_stderr("%s: aligned_realloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);

		libsimple_default_failure_exit = 104;
		alloc_fail_in = 1;
		assert_exit_ptr(libsimple_ealigned_realloc(NULL, 16, 1));
		assert(exit_status == 104);
		assert_stderr("%s: aligned_realloc: %s\n", argv0, strerror(ENOMEM));
		assert(!alloc_fail_in);
		libsimple_default_failure_exit = 1;
	}

#else

	assert_exit_ptr(libsimple_enaligned_realloc(2, NULL, 8, 1));
	assert(exit_status == 2);
	assert_stderr("%s: aligned_realloc: %s\n", argv0, strerror(ENOSYS));

	libsimple_default_failure_exit = 104;
	alloc_fail_in = 1;
	assert_exit_ptr(libsimple_ealigned_realloc(NULL, 16, 1));
	assert(exit_status == 104);
	assert_stderr("%s: aligned_realloc: %s\n", argv0, strerror(ENOSYS));
	assert(!alloc_fail_in);
	libsimple_default_failure_exit = 1;

#endif

	return 0;
}

#endif
