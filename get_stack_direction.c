/* See LICENSE file for copyright and license details. */
#include "common.h"
#ifndef TEST


#ifdef SUPPORTED
# undef SUPPORTED
#endif


#if defined(__GNUC__)
# define SUPPORTED

__attribute__((__noinline__))
static void *
get_callee_frame_address(void)
{
	return __builtin_frame_address(0);
}


__attribute__((__noinline__))
static int
get_stack_direction(void)
{
	void *callerptr, *calleeptr;
	uintptr_t caller, callee;
	callerptr = __builtin_frame_address(0);
	calleeptr = get_callee_frame_address();
	caller = (uintptr_t)callerptr;
	callee = (uintptr_t)calleeptr;
	return callee > caller ? +1 : callee < caller ? -1 : 0;
}

#endif


int
libsimple_get_stack_direction(void)
{
#ifdef SUPPORTED
	int r = get_stack_direction();
	if (!r)
		errno = ENOTSUP;
	return r;
#else
	errno = ENOTSUP;
	return 0;
#endif
}


#else
#include "test.h"

int
main(void)
{
	return 0;
}

#endif
