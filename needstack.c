/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


int
libsimple_needstack(size_t n)
{
	size_t limit1, limit2, limit, used;
	uintptr_t low, high, current;
	void *currentptr;

	currentptr = __builtin_frame_address(0);
	current = (uintptr_t)currentptr;
	if (libsimple_get_stack_space(&low, &high))
		return -1;
	if (libsimple_get_stack_limit(&limit1, NULL))
		return -1;
	limit2 = (size_t)(high - low);
	limit = limit1 < limit2 ? limit1 : limit2;

	switch (libsimple_get_stack_direction()) {
	case +1:
		if (current < low)
			goto enotsup;
		used = (size_t)(current - low);
		break;
	case -1:
		if (current > high)
			goto enotsup;
		used = (size_t)(high - current);
		break;
	default:
	enotsup:
		errno = ENOTSUP;
		return -1;
	}

	/* TODO it would be nice to be able to grow the stack */
	return used <= limit && n <= limit - used;
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
